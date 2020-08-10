#ifndef __ISP_FUNCTION_CAM_H__
#define __ISP_FUNCTION_CAM_H__

#include "isp_function.h"
#include "isp_function.timestamp.h"
#include "isp_drv_cam.h"
#include "uni_drv.h"
#include <mtkcam/drv/iopipe/CamIO/Cam_Notify.h>
#include "ispio_stddef.h"

#include <Cam_Notify_datatype.h>

#include <Cam/buf_que_ctrl.h>
#include "cam_capibility.h"


//CQ sw wrok around for:
/**
a.after hw reset, cq under all modes,no matter what event trig/immediate or continuous, will be read at the very 1st p1_done after cq_en pulled high.
b.descriptor in cq can't be all nop cmd.
*/
#define CQ_SW_WORK_AROUND  1

/**
DMX_ID in CAM_A is 0,CAM_B is 1 at most of case , only 8lane-sensor is exclusive.
Because of HW reg initial value is 0, sw need to over write the pix ID of CAM_B even if CAM_B is not needed currently.
This operation can prevent Interrupt false alarm at CAM_B.
*/
#define DMX_ID_SW_WORK_AROUND 0

/**
    this solution is for CAM_B always have sw p1 done under twin mode.
    And this behavior will break the CQ link-list.
    Side effect of current work around solution:
        sw only have (n-1)/n * (time of p1_sof to sw_p1_don) to program whole enque.
*/
#define TWIN_SW_P1_DONE_WROK_AROUND 1

/**
    For main cam support dynamic-twin with slave cam suspend/resume flow, hw physical regs will be
    overwritten by main cam's twin part. When resume, all regs on CQ needs to be reload. Enable
    this flag to support all p1 internal setting load from cq for every frame.
    (Tuning setting in internal module not included in this flag, due to 3A is resposible for load
    full tuning setting along with enque request come with resume API)
*/
#define P1_STANDBY_DTWIN_SUPPORT    1

/**
    top dcm must be disabeld when using HW timestamp
*/
#define TOP_DCM_SW_WORK_AROUND  1

/**
    SOF sig. of IMGO with IMG_SEL=TG will be 1T earlier than RRZO, which causes drop status check fail.
    Enque IMGO IMG_SEL=TG and RRZO when drop frame, then next frame IMGO_FBC drop_cnt and fbc_cnt will
    both increase, due to drop frame group is set for both IMGO & RRZO
*/
#define FBC_DRPGRP_SW_WORK_AROUND  0



/**
    ISP4.0 can't support DMAO cropping offset!! this function is conflicted with Header Output.
    this bug will be fixed at P18!!!
*/
#define DMAO_DISABLE_CROPPING_OFFSET 1


/**
    need to close subsample done function under drop frame, otherwise, subsample hw counter will work abnormally.
*/
#define SUBSAMPLE_SW_WORK_AROUND    1

/**
    can't support arbitrary crop , plz reference to define:HW_TIMESTAMP_WORKAROUND.
    if output is cam_b only , there is no timestamp anymore.
*/
#if (HW_TIMESTAMP_WORKAROUND==1)
#define Arbitrary_Crop  (0)
#else
#define Arbitrary_Crop  (1)
#endif

/**
    Per-frame timeout
*/
#define MIN_GRPFRM_TIME_MS          (200)  //subsampled frame time minimum difference
#define MAX_RECENT_GRPFRM_TIME      (2)

/////////////////////////////////////////////////////////////////////////////
/*    ISP Function ID                                                      */
/////////////////////////////////////////////////////////////////////////////

/**
    individual sub-module existed in isp function.
*/
enum {
    CAM_TG  = 0,    //0
    CAM_TOP,
    CAM_RAW,
    CAM_RGB,
    CAM_YUV,
    CAM_DMA_CQ0I,   //5
    CAM_DMA_CQ1I,
    CAM_DMA_CQ2I,
    CAM_DMA_CQ3I,
    CAM_DMA_CQ4I,
    CAM_DMA_CQ5I,   //10
    CAM_DMA_CQ6I,
    CAM_DMA_CQ7I,
    CAM_DMA_CQ8I,
    CAM_DMA_CQ9I,
    CAM_DMA_CQ10I,  //15
    CAM_DMA_CQ11I,
    CAM_DMA_CQ12I,
    CAM_DMA_BPCI,
    CAM_DMA_LSCI,
    CAM_DMA_CACI,    //20
    CAM_DMA_PDI,
    CAM_DMA_IMGO,
    CAM_DMA_UFEO,
    CAM_DMA_RRZO,
    CAM_DMA_AFO,    //25
    CAM_DMA_AAO,
    CAM_DMA_PDO,
    CAM_DMA_LCSO,
    CAM_DMA_PSO,
    CAM_BUFFER_CTRL, //30
    CAM_TWIN,

    UNI_TOP,
    UNI_DMA_RAWI,
    UNI_DMA_EISO,
    UNI_DMA_FLKO,
    UNI_DMA_RSSO,
    CAM_FUNCTION_MAX_NUM,
};


//isp top register range
//TG
#define ISP_TG_BASE             (ISP_BASE_HW + 0x4000)
#define ISP_TG_REG_RANGE        (0x0)
//
#define ISP_TOP_BASE            (ISP_BASE_HW + 0x4000)
#define ISP_TOP_REG_RANGE       (0x0)
//ISP_RAW
#define ISP_RAW_BASE            (ISP_TOP_BASE + 0x0)
#define ISP_RAW_REG_RANGE       ISP_TOP_REG_RANGE
//ISP_RGB
#define ISP_RGB_BASE            (ISP_TOP_BASE + 0x0)
#define ISP_RGB_REG_RANGE       ISP_TOP_REG_RANGE
//ISP_YUV
#define ISP_YUV_BASE            (ISP_TOP_BASE + 0x0)
#define ISP_YUV_REG_RANGE       ISP_TOP_REG_RANGE
//ISP_DMA_TWIN
#define ISP_TWIN_BASE           (ISP_TOP_BASE + 0x6000)
#define ISP_TWIN_REG_RANGE      (0x0)
//ISP_DMA_BPCI
#define DMA_BPCI_BASE           (ISP_TOP_BASE + 0x3250)
#define DMA_BPCI_REG_RANGE      (0x0)
//ISP_DMA_PDI
#define DMA_PDI_BASE           (ISP_TOP_BASE + 0x0D50)
#define DMA_PDI_REG_RANGE      (0x0)
//ISP_DMA_LSCI
#define DMA_LSCI_BASE           (ISP_TOP_BASE + 0x326C)
#define DMA_LSCI_REG_RANGE      (0x0)
//ISP_DMA_CACI
#define DMA_CACI_BASE           (ISP_TOP_BASE + 0x326C)
#define DMA_CACI_REG_RANGE      (0x0)
//ISP_DMA_IMGO
#define DMA_IMGO_BASE           (ISP_TOP_BASE + 0x3300)
#define DMA_IMGO_REG_RANGE       (0x0)
//ISP_DMA_RRZO
#define DMA_RRZO_BASE           (ISP_TOP_BASE + 0x3320)
#define DMA_RRZO_REG_RANGE      (0x0)
//ISP_DMA_LCSO
#define DMA_LCSO_BASE           (ISP_TOP_BASE + 0x3340)
#define DMA_LCSO_REG_RANGE      (0x0)
//UNI_DMA_EISO
#define DMA_EISO_BASE           (ISP_TOP_BASE + 0x335C)
#define DMA_EISO_REG_RANGE      (0x0)
//UNI_DMA_FLKO
#define DMA_FLKO_BASE           (ISP_TOP_BASE + 0x335C)
#define DMA_FLKO_REG_RANGE      (0x0)
//UNI_DMA_RSSO
#define DMA_RSSO_BASE           (ISP_TOP_BASE + 0x335C)
#define DMA_RSSO_REG_RANGE      (0x0)
//UNI_DMA_RAWI
#define DMA_RAWI_BASE           (ISP_TOP_BASE + 0x335C)
#define DMA_RAWI_REG_RANGE      (0x0)
//ISP_DMA_AFO
#define DMA_AFO_BASE            (ISP_TOP_BASE + 0x3364)
#define DMA_AFO_REG_RANGE       (0x0)
//ISP_DMA_PDO
#define DMA_PDO_BASE            (ISP_TOP_BASE + 0x336C)
#define DMA_PDO_REG_RANGE       (0x0)
//ISP_DMA_AAO
#define DMA_AAO_BASE            (ISP_TOP_BASE + 0x3388)
#define DMA_AAO_REG_RANGE       (0x0)
//ISP_DMA_PSO
#define DMA_PSO_BASE            (ISP_TOP_BASE + 0x0) //no use
#define DMA_PSO_REG_RANGE       (0x0)
//ISP_DMA_UFEO
#define DMA_UFEO_BASE           (ISP_TOP_BASE + 0x33C4)
#define DMA_UFEO_REG_RANGE      (0x0)
//ISP_DMA_CQ0I
#define DMA_CQI_BASE            (ISP_TOP_BASE + 0x3210)
#define DMA_CQI_REG_RANGE       (0x0)


typedef enum{
    IF_CAM_A,
    IF_CAM_B,
    IF_RAWI_CAM_A,
    IF_RAWI_CAM_B,
    IF_CAM_MAX,
}ENUM_IF_CAM;



///////////////////////////////////////////////////////////////////////////////
/**
    Class for TG module
*/
class CAM_TG_CTRL : public IspFunction_B
{
public:
    MBOOL               m_continuous;   //signle or continuous mode
    MUINT32             m_SubSample;      //signal subample . 0: no subsample. Vsync/SOF/P1_DONE use the sample subsample
    IspRect             m_Crop;
    typedef enum{
        _1_pix_ = 0,
        _2_pix_ = 1,
        _4_pix_ = 2,
    }E_PIX;
    E_PIX               m_PixMode;

    typedef enum{
        _tg_normal_     = 0,
        _tg_dual_pix_   = 1,
        _tg_yuv_        = 2
    }E_DatPat;
    E_DatPat            m_Datapat;
public:
    CAM_TG_CTRL();

    virtual MUINT32     id( void )                    {   return CAM_TG;  }
    virtual const char* name_Str( void )              {   return "CAM_TG";}
    virtual MUINTPTR    reg_Base_Addr_Phy( void )     {   return ISP_TG_BASE;  }
    virtual MUINTPTR    reg_Range( void )             {   return ISP_TG_REG_RANGE;  }
    virtual MBOOL       checkBusy( MUINTPTR param ){param;return MFALSE;}

protected:
    virtual MINT32 _config( void );
    virtual MINT32 _enable( void* pParam  );
    virtual MINT32 _disable( void* pParam = NULL );
    virtual MINT32 _write2CQ( void ){return 0;}
private:
            ISP_DRV_CAM*    m_pDrv;     //for casting type , coding convenience only
};

///////////////////////////////////////////////////////////////////////////////
/**
    Class for CAM Top module
*/
class CAM_TOP_CTRL : public IspFunction_B
{
friend class CAM_TWIN_PIPE;
public:
    CAM_TOP_CTRL();

    virtual MUINT32     id( void )                    {   return CAM_TOP;  }
    virtual const char* name_Str( void )              {   return "CAM_TOP";}
    virtual MUINTPTR    reg_Base_Addr_Phy( void )     {   return ISP_TOP_BASE;  }
    virtual MUINTPTR    reg_Range( void )             {   return ISP_TOP_REG_RANGE;  }
    virtual MBOOL       checkBusy( MUINTPTR param );

            MBOOL       suspend(void){return MFALSE;}
            MBOOL       resume(void){return MFALSE;}
            MBOOL       HW_recover(MUINT32 step); //set 0:stop pipeline. set 1:restart pipeline
protected:
    virtual MINT32 _config( void );
    virtual MINT32 _enable( void* pParam  );
    virtual MINT32 _disable( void* pParam = NULL );
    virtual MINT32 _write2CQ( void );


public:
    ST_CAM_TOP_CTRL     cam_top_ctl;

    ENUM_IF_CAM         CAM_Path;       //only used for TG_IN or DMAI

    MUINT32             SubSample;      //signal subample . 0: no subsample. Vsync/SOF/P1_DONE use the sample subsample

private:
            MBOOL           m_bBusy;
            ISP_DRV_CAM*    m_pDrv;     //for casting type , coding convenience only
#if DMX_ID_SW_WORK_AROUND
            MBOOL           m_bCfg;
#endif
            //for recover fbc cnt
            CAM_REG_FBC_IMGO_CTL2     fbc_IMGO;
            CAM_REG_FBC_RRZO_CTL2     fbc_RRZO;
            CAM_REG_FBC_UFEO_CTL2     fbc_UFEO;
            CAM_REG_FBC_AFO_CTL2      fbc_AFO;
            CAM_REG_FBC_AAO_CTL2      fbc_AAO;
            CAM_REG_FBC_LCSO_CTL2     fbc_LCSO;
            CAM_REG_FBC_PDO_CTL2      fbc_PDO;
            CAM_REG_FBC_PSO_CTL2      fbc_PSO;
};


/////////////////////////////////////////////////////////////////////////////////
/**
    class for UNI
*/
class UNI_TOP_CTRL : public IspFunction_B
{
public:
    ST_UNI_TOP_CTRL uni_top_ctl;

    ENUM_IF_CAM     UNI_Source;
    IspRect         m_Crop;         //this struct is used if and only if RAWI

    UniDrvImp*      m_pUniDrv;
public:
    UNI_TOP_CTRL();

    virtual MUINT32     id( void )                    {   return UNI_TOP;  }
    virtual const char* name_Str( void )              {   return "UNI_TOP";}
    virtual MUINTPTR    reg_Base_Addr_Phy( void )     {   return 0;  }
    virtual MUINTPTR    reg_Range( void )             {   return 0;  }

            //special case for uni streaming stop.
            //incase of cmdq being switch during uni_stop.
            MINT32      ClrUniFunc(void);


            MBOOL       suspend(void){return MFALSE;}
            MBOOL       resume(void){return MFALSE;}
            MBOOL       HW_recover(MUINT32 step); //set 0:stop pipeline. set 1:restart pipeline

protected:
    virtual MINT32 _config( void );
    virtual MINT32 _enable( void* pParam  );
    virtual MINT32 _disable( void* pParam = NULL );
    virtual MINT32 _write2CQ( void );

private:
            ISP_DRV_CAM*    m_pDrv;     //for casting type , coding convenience only

            CAM_UNI_REG_FBC_EISO_A_CTL2     fbc_EISO;
            CAM_UNI_REG_FBC_FLKO_A_CTL2     fbc_FLKO;
            CAM_UNI_REG_FBC_RSSO_A_CTL2     fbc_RSSO;
};

/**
*/
typedef struct _T_XMXO
{
    E_PIX_MODE pix_mode_dmxi;
    E_PIX_MODE pix_mode_dmxo;
    E_PIX_MODE pix_mode_bmxo;
    E_PIX_MODE pix_mode_rmxo;
    E_PIX_MODE pix_mode_amxo;   //useless, cureent pipeline always 1pix mode
    E_PIX_MODE pix_mode_pmxo;   //useless, cureent pipeline always 1pix mode

    _T_XMXO()
    : pix_mode_dmxi(_1_pix_)
    , pix_mode_dmxo(_1_pix_)
    , pix_mode_bmxo(_1_pix_)
    , pix_mode_rmxo(_1_pix_)
    , pix_mode_amxo(_1_pix_)
    , pix_mode_pmxo(_1_pix_)
    {}
}T_XMXO;

/**
    class for DMX contrl
*/
class CAM_RAW_PIPE;
class CAM_XMX_CTRL
{
public:
    CAM_XMX_CTRL(){m_hwModule = CAM_MAX;m_pRaw_p = NULL;}
    virtual ~CAM_XMX_CTRL(){}

    MINT32 config(CAM_RAW_PIPE* _this);

private:
    virtual MINT32 _config(void){return -1;}

protected:
    CAM_RAW_PIPE*   m_pRaw_p;
    ISP_HW_MODULE   m_hwModule;
};

class CAM_DMX_CTRL:public CAM_XMX_CTRL
{
private:
    virtual MINT32 _config( void );
};


/**
    class for PMX  contrl
*/
class CAM_PMX_CTRL:public CAM_XMX_CTRL
{
private:
    virtual MINT32 _config( void );

};


/**
    class for BMX contrl
*/
class CAM_BMX_CTRL:public CAM_XMX_CTRL
{
public:
    virtual MINT32 _config( void );

};

/**
    class for AMX contrl
*/
class CAM_AMX_CTRL:public CAM_XMX_CTRL
{
private:
    virtual MINT32 _config( void );

};

/**
    class for RMX contrl
*/
class CAM_RMX_CTRL:public CAM_XMX_CTRL
{
private:
    virtual MINT32 _config( void );

};

/**
    class for RCP contrl
*/
class CAM_RCP_CTRL:public CAM_XMX_CTRL
{
private:
    virtual MINT32 _config( void );

};


/**
    class for RCP3 contrl
*/
class CAM_RCP3_CTRL:public CAM_XMX_CTRL
{
private:
    typedef enum _rcp3_sel{
        E_rcp3_0 = 0,
        E_rcp3_1,
        E_rcp3_2,
        E_rcp3_3,
    }E_RCP3_SEL;
    virtual MINT32 _config( void );

};

///////////////////////////////////////////////////////////////////////////////
/**
    class for CAM when input data type is Bayer, change raw pipe setting under streaming
*/
class CAM_RAW_PIPE:public IspFunction_B
{
public:
    friend class CAM_XMX_CTRL;
    friend class CAM_DMX_CTRL;
    friend class CAM_PMX_CTRL;
    friend class CAM_BMX_CTRL;
    friend class CAM_RMX_CTRL;
    friend class CAM_AMX_CTRL;
    friend class CAM_RCP_CTRL;
    friend class CAM_RCP3_CTRL;

public:
    typedef enum{
        E_FromTG    = 0,
        E_BeforLSC  = 1,
        E_AFTERLSC  = 2,
    }E_RawType;
    E_RawType           m_RawType;

    ENUM_IF_CAM         m_Source;
    UniDrvImp*          m_pUniDrv;      //for rawi/ eiso case
    P1_TUNING_NOTIFY*   m_pP1Tuning;
    T_XMXO              m_xmxo;



    CAM_RAW_PIPE();
    virtual ~CAM_RAW_PIPE();

public:
    virtual MUINT32     id( void )                    {   return CAM_RAW;  }
    virtual const char* name_Str( void )              {   return "CAM_RAW";}
    virtual MUINTPTR    reg_Base_Addr_Phy( void )      {   return ISP_RAW_BASE;  }
    virtual MUINTPTR    reg_Range( void )             {   return ISP_RAW_REG_RANGE;  }

            MBOOL   setEIS(void);                       //because of EIS have the requirement of real time sync with rrz. so, need additional process
            MBOOL   setLCS(void);                       //because of LCS of sync requirement when LCS croping r needed.
            MBOOL   setSGG2(void);                  //sgg2 have 2 user:eis/rss, so using CB method the same as EIS/LCS. avoid Racing condition
            MBOOL   setRSS(void);
            MBOOL   setIMG_SEL(void);
			MBOOL	dumpCQReg(void);
			inline void CBTimeChk(char *str, MBOOL bStartT);
            MUINT32 getCurPixMode(_isp_dma_enum_ dmao);
protected:
    virtual MINT32 _config( void );             //for initial only, work with _config() in CAM_TOP_CTRL
    virtual MINT32 _write2CQ( void );

    virtual MINT32 _enable( void* pParam  ) {(void)pParam;return 0;}
    virtual MINT32 _disable( void* pParam = NULL ) {(void)pParam;return 0;}

protected:
    ISP_DRV_CAM*    m_pDrv;

    MBOOL m_bTwin;
    CAM_REG_TG_SEN_GRAB_PXL m_TG_W;
    CAM_REG_TG_SEN_GRAB_LIN m_TG_H;
	CQ_DUMP_INFO			m_dumpInput;//for RegDumpCB use

    CAM_DMX_CTRL m_Dmx;
    CAM_PMX_CTRL m_Pmx;
    CAM_BMX_CTRL m_Bmx;
    CAM_RMX_CTRL m_Rmx;
    CAM_AMX_CTRL m_Amx;
    CAM_RCP_CTRL m_Rcp;
    CAM_RCP3_CTRL m_Rcp3;
};


/////////////////////////////////////////////////////////////////////////////////////
class CAM_DPD_CTRL: public CAM_RAW_PIPE
{
protected:
    virtual MINT32 _config( void );
    virtual MINT32 _write2CQ( void );

    virtual MINT32 _enable( void* pParam  ) {(void)pParam;return 0;}
    virtual MINT32 _disable( void* pParam = NULL ) {(void)pParam;return 0;}


public:
    typedef enum{
        _level_1    = 0,
        _level_2    = 1,
        _level_max  = 2,
    }E_Density;
    E_Density       m_Density;
};



/////////////////////////////////////////////////////////////////////////////////////
/**
    spare register of Frame Header mapping function
*/
#define E_HEADER_MAX    (16)
class HEADER_PARSER
{
protected:
    virtual ~HEADER_PARSER(){}
public:

    virtual void Header_Enque(MUINT32 Tag,ISP_DRV_CAM* DrvPtr,MUINT32 value) = 0;
    virtual void Header_Deque(MUINTPTR FH_VA,void* pOut) = 0;

public:
            ISP_HW_MODULE   m_hwModule;
};

/**
    spare register of Frame Header mapping function for imgo
*/
class Header_IMGO: public HEADER_PARSER
{
public:
    enum {
        E_TimeStamp         = 0,    //spare1
        E_Magic             = 1,    //spare2 ,
        E_ENQUE_SOF         = 2,    //spare3    buf_ctrl dbg log
        E_RAW_TYPE          = 3,    //spare4,
        E_PIX_ID            = 4,    //spare5,
        E_FMT               = 5,    //spare6,
        E_CROP_START        = 6,    //spare7.   [31:16]:start_y, [15:0]: start_x
        E_CROP_SIZE         = 7,    //spare8.   [31:16]:size_h, [15:0]: size_w
        E_ENQUE_CNT         = 8,    //spare9.
        E_IMG_PA            = 9,
        E_SRC_SIZE          = 10,   //spare11 [31]:dbn_on/off [30:16]: size_h, [15:0]: size_w
        E_MAX               = 11
    };
public:
    Header_IMGO()
    {
        m_hwModule = CAM_MAX;
    }

    virtual void    Header_Enque(MUINT32 Tag,ISP_DRV_CAM* DrvPtr,MUINT32 value);
    virtual void    Header_Deque(MUINTPTR FH_VA,void* pOut);
            void    Header_Flash(MUINTPTR FH_VA);
};

/**
    spare register of Frame Header mapping function for rrzo
*/
class Header_RRZO: public HEADER_PARSER
{
public:

    enum {
        E_TimeStamp         = 0,    //spare1
        E_Magic             = 1,    //spare2 ,
        E_ENQUE_SOF         = 2,    //spare3    buf_ctrl dbg log
        E_PIX_ID            = 3,    //spare4,
        E_FMT               = 4,    //spare5,
        E_RRZ_CRP_START     = 5,    //spare6,   [31:16]:start_y, [15:0]: start_x
        E_RRZ_CRP_SIZE      = 6,    //sapre7,   [31:16]:size_h, [15:0]: size_w
        E_RRZ_DST_SIZE      = 7,    //spare8,   [31:16]:dst_h,  [15:0]: dst_w
        E_ENQUE_CNT         = 8,    //spare9
        E_IMG_PA            = 9,
        E_MAX               = 10
    };
public:
    Header_RRZO(){
        m_hwModule = CAM_MAX;
    }

    virtual void    Header_Enque(MUINT32 Tag,ISP_DRV_CAM* DrvPtr,MUINT32 value);
    virtual void    Header_Deque(MUINTPTR FH_VA,void* pOut);
            void    Header_Flash(MUINTPTR FH_VA);
            MUINT32 GetRegInfo(MUINT32 Tag,IspDrv* DrvPtr);    //for pipe chk use
     static MUINT32 GetTagAddr(MUINT32 Tag);
};

/**
    spare register of Frame Header mapping function for ufeo
*/
class Header_UFEO: public HEADER_PARSER
{
public:
    enum {
        E_TimeStamp         = 0,    //spare1
        E_Magic             = 1,    //spare2 ,
        E_ENQUE_SOF         = 2,    //spare3buf_ctrl dbg log
        E_IMG_PA            = 3,
        E_ENQUE_CNT         = 4,
        E_FMT               = 5,    //spare6,
        E_MAX               = 6
    };
public:
    Header_UFEO(){
        m_hwModule = CAM_MAX;
    }

    virtual void    Header_Enque(MUINT32 Tag,ISP_DRV_CAM* DrvPtr,MUINT32 value);
    virtual void    Header_Deque(MUINTPTR FH_VA,void* pOut);
            void    Header_Flash(MUINTPTR FH_VA);
};

/**
    spare register of Frame Header mapping function for AAO
*/
class Header_AAO: public HEADER_PARSER
{
public:
    enum {
        E_TimeStamp         = 0,    //spare1
        E_Magic             = 1,    //spare2 ,
        E_ENQUE_SOF         = 2,    //spare3buf_ctrl dbg log
        E_IMG_PA            = 3,
        E_MAX               = 4
    };
public:
    Header_AAO(){
        m_hwModule = CAM_MAX;
    }

    virtual void    Header_Enque(MUINT32 Tag,ISP_DRV_CAM* DrvPtr,MUINT32 value);
    virtual void    Header_Deque(MUINTPTR FH_VA,void* pOut);
            void    Header_Flash(MUINTPTR FH_VA);
};

/**
    spare register of Frame Header mapping function for AAO
*/
class Header_PSO: public HEADER_PARSER
{
public:
    enum {
        E_TimeStamp         = 0,    //spare1
        E_Magic             = 1,    //spare2 ,
        E_ENQUE_SOF         = 2,    //spare3buf_ctrl dbg log
        E_IMG_PA            = 3,
        E_MAX               = 4
    };
public:
    Header_PSO(){
        m_hwModule = CAM_MAX;
    }

    virtual void    Header_Enque(MUINT32 Tag,ISP_DRV_CAM* DrvPtr,MUINT32 value);
    virtual void    Header_Deque(MUINTPTR FH_VA,void* pOut);
            void    Header_Flash(MUINTPTR FH_VA);
};


/**
    spare register of Frame Header mapping function for AFO
*/
class Header_AFO: public HEADER_PARSER
{
public:
    enum {
        E_TimeStamp         = 0,    //spare1
        E_Magic             = 1,    //spare2 ,
        E_STRIDE            = 2,    //spare3,
        E_IMG_PA            = 3,    //spare4
        /* FH correctness guarantee to first 4 spare registers only.
         * FOLLOWING SPARE REGS COULD BE OVERWRITTEN BY THE OTHER CAM'S
         * FH OUTPUT UNDER TAF WITH TWIN CASE. */
        E_ENQUE_SOF         = 4,    //spare5,buf_ctrl dbg log
        E_MAX               = 5
    };
public:
    Header_AFO(){
        m_hwModule = CAM_MAX;
    }

    virtual void    Header_Enque(MUINT32 Tag,ISP_DRV_CAM* DrvPtr,MUINT32 value);
    virtual void    Header_Deque(MUINTPTR FH_VA,void* pOut);
            void    Header_Flash(MUINTPTR FH_VA);
};


/**
    spare register of Frame Header mapping function for LCSO
*/
class Header_LCSO: public HEADER_PARSER
{
public:
    enum {
        E_TimeStamp         = 0,    //spare1
        E_Magic             = 1,    //spare2 , buf_ctrl dbg log
        E_ENQUE_SOF         = 2,    //spare3
        E_IMG_PA            = 3,
        E_ENQUE_CNT         = 4,
        E_MAX               = 5
    };
public:
    Header_LCSO(){
        m_hwModule = CAM_MAX;
    }

    virtual void    Header_Enque(MUINT32 Tag,ISP_DRV_CAM* DrvPtr,MUINT32 value);
    virtual void    Header_Deque(MUINTPTR FH_VA,void* pOut);
            void    Header_Flash(MUINTPTR FH_VA);
};

/**
    spare register of Frame Header mapping function for PDO
*/
class Header_PDO: public HEADER_PARSER
{
public:
    enum {
        E_TimeStamp         = 0,    //spare1
        E_Magic             = 1,    //spare2 ,
        E_STRIDE            = 2,    //spare3,
        E_PMX_A_CROP        = 3,    //spare4,  horizontal cropping start/end.[31~16:end , 15~0:start]
        E_PMX_B_CROP        = 4,    //spare5,  horizontal cropping start/end.[31~16:end , 15~0:start]
        E_BMX_A_CROP        = 5,    //spare6,  horizontal cropping start/end.[31~16:end , 15~0:start]
        E_BMX_B_CROP        = 6,    //spare7,  horizontal cropping start/end.[31~16:end , 15~0:start]
        E_IMG_PA_OFSET      = 7,
        E_ENQUE_SOF         = 8,    //spare9    buf_ctrl dbg log
        E_IMG_PA            = 9,    //spare10
        E_MAX               = 10
    };
public:
    Header_PDO(){
        m_hwModule = CAM_MAX;
    }

    virtual void    Header_Enque(MUINT32 Tag,ISP_DRV_CAM* DrvPtr,MUINT32 value);
    virtual void    Header_Deque(MUINTPTR FH_VA,void* pOut);
            void    Header_Flash(MUINTPTR FH_VA);
};

/**
    spare register of Frame Header mapping function for EISO
*/
class Header_EISO: public HEADER_PARSER
{
public:
    enum {
        E_TimeStamp         = 0,    //spare1
        E_Magic             = 1,    //spare2 ,
        E_ENQUE_SOF         = 2,    //spare3    buf_ctrl dbg log
        E_IMG_PA            = 3,
        E_ENQUE_CNT         = 4,
        E_MAX               = 5
    };
public:
    Header_EISO(){
        m_hwModule = CAM_MAX;
    }

    virtual void    Header_Enque(MUINT32 Tag,ISP_DRV_CAM* DrvPtr,MUINT32 value);
    virtual void    Header_Deque(MUINTPTR FH_VA,void* pOut);
            void    Header_Flash(MUINTPTR FH_VA);
};


/**
    spare register of Frame Header mapping function for FLKO
*/
class Header_FLKO: public HEADER_PARSER
{
public:
    enum {
        E_TimeStamp         = 0,    //spare1
        E_Magic             = 1,    //spare2 ,
        E_ENQUE_SOF         = 2,    //spare3 buf_ctrl dbg log
        E_IMG_PA            = 3,
        E_MAX               = 4
    };
public:
    Header_FLKO(){
        m_hwModule = CAM_MAX;
    }

    virtual void    Header_Enque(MUINT32 Tag,ISP_DRV_CAM* DrvPtr,MUINT32 value);
    virtual void    Header_Deque(MUINTPTR FH_VA,void* pOut);
            void    Header_Flash(MUINTPTR FH_VA);
};

/**
    spare register of Frame Header mapping function for RSSO
*/
class Header_RSSO: public HEADER_PARSER
{
public:
    enum {
        E_TimeStamp         = 0,    //spare1
        E_Magic             = 1,    //spare2 ,
        E_ENQUE_SOF         = 2,    //spare3    buf_ctrl dbg log
        E_IMG_PA            = 3,
        E_ENQUE_CNT         = 4,
        E_DST_SIZE          = 5, //[31:16]:dst_h,  [15:0]: dst_w
        E_MAX               = 6
    };
public:
    Header_RSSO(){
        m_hwModule = CAM_MAX;
    }

    virtual void    Header_Enque(MUINT32 Tag,ISP_DRV_CAM* DrvPtr,MUINT32 value);
    virtual void    Header_Deque(MUINTPTR FH_VA,void* pOut);
            void    Header_Flash(MUINTPTR FH_VA);
};



/**
    class for RRZ contrl
*/
class CAM_RRZ_CTRL: public CAM_RAW_PIPE
{
public:
    IspRect rrz_in_roi;
    IspSize rrz_out_size;
    MUINT32 rrz_rlb_offset;


    class RRZ_PQ{
    public:
        RRZ_PQ():
            PRF_BLD(0),
            PRF(0),
            BLD_SL(16),
            CR_MODE(1),
            TH_MD(80),
            TH_HI(40),
            TH_LO(80),
            TH_MD2(0)
        {};
    public:
        MUINT8  PRF_BLD;
        MUINT8  PRF;
        MUINT8  BLD_SL;
        MUINT8  CR_MODE;
        MUINT8  TH_MD;
        MUINT8  TH_HI;
        MUINT8  TH_LO;
        MUINT8  TH_MD2;
    };

    RRZ_PQ  PicQ;
public:
    CAM_RRZ_CTRL(){rrz_rlb_offset = 0;};
public:
    virtual MINT32 _config( void );
    virtual MINT32 _write2CQ( void ){return 0;}

private:
            MUINT32 calCoefStep(MUINT32 in,MUINT32 crop,MUINT32 crop_ofst,MUINT32 crop_sub_ofst,MUINT32 out);
            MUINT32 getCoefTbl(MUINT32 resize_in,MUINT32 resize_out);
};

//////////////////////////////////////////////////////////////////////////////////
/**
    class for CAM under twin control
*/
class CAM_TWIN_PIPE:public CAM_RAW_PIPE
{
public:
    CAM_TWIN_PIPE()
    {
        m_pTwinIspDrv = NULL;
        m_twinHwModule = CAM_MAX;
        m_subsample = 0;
        m_rrz_out_wd = 0;
        m_af_vld_xstart = m_af_blk_xsize = m_af_x_win_num =0;
        m_lsc_lwidth = m_lsc_win_num_x = 0;
        m_suspend_Rcnt = 0;
    };

public:
    virtual MBOOL       checkBusy( MUINTPTR param ){(void)param;return 0;}
    virtual MUINT32     id( void )                    {   return CAM_TWIN;  }
    virtual const char* name_Str( void )              {   return "CAM_TWIN";}
    virtual MUINTPTR    reg_Base_Addr_Phy( void )     {   return ISP_TWIN_BASE;  }
    virtual MUINTPTR    reg_Range( void )             {   return ISP_TWIN_REG_RANGE;  }

            MINT32 update_beforeRunTwin(void);
            MINT32 update_afterRunTwin(void);
    typedef struct{
        ISP_HW_MODULE   module;
        _isp_dma_enum_  channel;
        MUINT32         offsetAdr;  // this is for patch header address
        MBOOL           bFrameEnd;
    }T_TWIN_DMA;
    typedef vector<T_TWIN_DMA> L_T_TWIN_DMA; //this list is for multi-cam
            MINT32 get_RunTwinRst(MUINT32 dmachannel,vector<L_T_TWIN_DMA>& channel,MBOOL bDeque = MFALSE);
            MINT32 clr_RunTwinRst(MUINT32 dmachannel);

            MINT32 suspend( void ); //pause via CQ
            MINT32 resume( void );  //resume via CQ
            MINT32 resume_check(void);  //check slave cam which is really configured with setting of resume.Due to slave cam's page may be different at execution suspend() & resumse()

            MBOOL  HW_recover(MUINT32 step); //set 0:stop pipeline. set 1:restart pipeline
            MINT32 updateTwinInfo(MBOOL bEn);    //update twin's info perframe

     static MBOOL  GetTwinRegAddr(ISP_HW_MODULE module,MUINT32* pAddr);
private:
    MINT32 update_afterRunTwin_Dma(void);
    MINT32 update_cq(void);
protected:
    virtual MINT32 _config( void );             //for initial only, work with _config() in CAM_TOP_CTRL, via CQ
    virtual MINT32 _enable( void* pParam  );    //via CQ
    virtual MINT32 _disable(void* pParam = NULL );  //write to phy reg directly
    virtual MINT32 _write2CQ( void );

public:
    //CAM_TOP_CTRL    m_TopCtrl;

    //ENUM_IF_TWIN    m_Twin_type;
    //input info for ifunc_twin
    ISP_DRV_CAM*    m_pTwinIspDrv;
    MUINT32         m_subsample;

    //output info for twin drv
    MUINT32         m_rrz_out_wd;
    IspRect         m_rrz_roi;
    IspSize         m_rrz_in;

    MUINT32         m_af_vld_xstart;
    MUINT32         m_af_blk_xsize;
    MUINT32         m_af_x_win_num;

    MUINT32         m_lsc_lwidth;
    MUINT32         m_lsc_win_num_x;

private:
    ISP_HW_MODULE   m_twinHwModule;

    vector<L_T_TWIN_DMA>    m_dma_imgo_L; //this list is for multi-frame,subsample is included
    vector<L_T_TWIN_DMA>    m_dma_rrzo_L; //this list is for multi-frame,subsample is included

    MUINT32         m_suspend_Rcnt;

    mutable Mutex   m_muList;   //protect lsit's push/pop

    //for recover fbc cnt
    CAM_REG_FBC_IMGO_CTL2     fbc_IMGO;
    CAM_REG_FBC_RRZO_CTL2     fbc_RRZO;
    CAM_REG_FBC_UFEO_CTL2     fbc_UFEO;
    CAM_REG_FBC_AFO_CTL2      fbc_AFO;
};


///////////////////////////////////////////////////////////////////////////////
/**
    class for CAM  when input data type is YUV
*/
class CAM_YUV_PIPE: public IspFunction_B
{
public:
    P1_TUNING_NOTIFY*   m_pP1Tuning;
    UniDrvImp*          m_pUniDrv;  //for eiso
public:
    CAM_YUV_PIPE()
    {
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
        m_pP1Tuning = NULL;
        m_pUniDrv = NULL;
    };

public:

    virtual MUINT32     id( void )                    {   return CAM_YUV;  }
    virtual const char* name_Str( void )              {   return "CAM_YUV";}
    virtual MUINTPTR    reg_Base_Addr_Phy( void )     {   return ISP_YUV_BASE;  }
    virtual MUINTPTR    reg_Range( void )             {   return ISP_YUV_REG_RANGE;  }

            MBOOL   setEIS(void);                       //because of EIS have the requirement of real time sync with rrz. so, need additional process
            MBOOL   setLCS(void);                       //because of LCS of sync requirement when LCS croping r needed.
            MBOOL   setSGG2(void);                  //sgg2 have 2 user:eis/rss, so using CB method the same as EIS/LCS. avoid Racing condition
            MBOOL   setRSS(void);

    enum{
        _unkonw_pix = 0,
        _1_pix_     = 1,
        _2_pix_     = 2,
        _4_pix_     = 4
    };
            MUINT32 getCurPixMode(_isp_dma_enum_ dmao=_imgo_);

protected:
    virtual MINT32 _config( void );             //for initial only, work with _config() in CAM_TOP_CTRL
    virtual MINT32 _write2CQ( void );

    virtual MINT32 _enable( void* pParam  ) {(void)pParam;return 0;}
    virtual MINT32 _disable( void* pParam = NULL ) {(void)pParam;return 0;}

protected:
    ISP_DRV_CAM*    m_pDrv;

};

///////////////////////////////////////////////////////////////////////////////
/**
    class for magic number update
*/
class CAM_MAGIC_CTRL: public CAM_RAW_PIPE, public CAM_YUV_PIPE
{
public:
    MUINT32 m_nMagic;
public:
    IspDrvVir*          m_pIspDrv;              // obj for new frame
    ISP_HW_MODULE       m_hwModule;
public:
    CAM_MAGIC_CTRL():
        m_nMagic(0x0fffffff)
    {
        m_pIspDrv = NULL;
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
        m_pIspDrv = NULL;
        m_hwModule = CAM_MAX;
    };
public://_config defined as public member is to avoid abstract data type
    virtual MINT32 _config( void );
private:
    ISP_DRV_CAM*    m_pDrv;
};


///////////////////////////////////////////////////////////////////////////////
/**
    class for CAM tuning
*/
class CAM_TUNING_CTRL: public CAM_RAW_PIPE, public CAM_YUV_PIPE
{
public:
    CAM_TUNING_CTRL():
        m_Magic(NULL),
        m_SenDev(0xFFFFFFFF),
        m_BQNum(0),
        m_pIspDrv(NULL),
        m_pUniDrv(NULL),
        m_hwModule (CAM_MAX),
        m_pDrv(NULL),
        m_pTuningDrv(NULL)
    {};
public://_config defined as public member is to avoid abstract data type
    virtual MINT32  _config( void );
    virtual MINT32  _enable( void* pParam );
    virtual MINT32  _disable( void* pParam = NULL );

            MINT32  update(void);
            MINT32  update_end(void);

public:
            MUINT32* m_Magic;
            MUINT32 m_SenDev;
            MUINT32 m_BQNum;
            IspDrvVir*          m_pIspDrv;              // obj for new frame
            UniDrvImp*          m_pUniDrv;              // uni is linked to current path is not NULL
            ISP_HW_MODULE       m_hwModule;
private:
    ISP_DRV_CAM*    m_pDrv;
    void*           m_pTuningDrv;
};




///////////////////////////////////////////////////////////////////////////////
/**
    Class for DMAI modules
*/
class DMAI_B:public DMA_B
{
public:
    DMAI_B();

protected:
    virtual MINT32 _config( void );
    virtual MINT32 _enable( void* pParam );
    virtual MINT32 _disable( void* pParam = NULL );
    virtual MINT32 _write2CQ( void );
protected:
    ISP_DRV_CAM*    m_pDrv;     //for casting type , coding convenience only
    MUINT32         m_updatecnt;//only workable in CQ0
public:
    UniDrvImp*      m_pUniDrv;
};

///////////////////////////////////////////////////////////////////////////////
/**
    Class for DMAO modules
*/
class DMAO_B:public DMA_B
{
public:
    DMAO_B();

    //
            MUINT32 BusSizeCal(MUINT32& pixMode);
            MINT32  setBaseAddr(void);
            MBOOL   Init(void);             //for stt dmao
protected:
    virtual MINT32 _config( void ); //config all dma but baseaddress
    virtual MINT32 _enable( void* pParam );
    virtual MINT32 _disable( void* pParam = NULL );
    virtual MINT32 _write2CQ( void );

protected:
    ISP_DRV_CAM*    m_pDrv;     //for casting type , coding convenience only
public:
    UniDrvImp*      m_pUniDrv;
    MUINT32         Header_Addr;
    MUINT32         m_fps;
};

///////////////////////////////////////////////////////////////////////////////
/**
    class for BPCI
*/
class DMA_BPCI:public DMAI_B
{
public:
    DMA_BPCI(){
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
    };

public:
    virtual MUINT32 id( void )                {    return     CAM_DMA_BPCI;  }
    virtual const char*   name_Str( void )          {    return     "CAM_DMA_BPCI";}
    virtual MUINTPTR    reg_Base_Addr_Phy( void )  {    return     DMA_BPCI_BASE;     }
    virtual MUINTPTR    reg_Range( void )         {    return     DMA_BPCI_REG_RANGE;     }
};

///////////////////////////////////////////////////////////////////////////////
/**
    class for PDI
*/
class DMA_PDI:public DMAI_B
{
public:
    DMA_PDI(){
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
    };

public:
    virtual MUINT32 id( void )                {    return     CAM_DMA_PDI;  }
    virtual const char*   name_Str( void )          {    return     "CAM_DMA_PDI";}
    virtual MUINTPTR    reg_Base_Addr_Phy( void )  {    return     DMA_PDI_BASE;     }
    virtual MUINTPTR    reg_Range( void )         {    return     DMA_PDI_REG_RANGE;     }
};

///////////////////////////////////////////////////////////////////////////////
/**
    class for LSCI
*/
class DMA_LSCI:public DMAI_B
{
public:
    DMA_LSCI(){
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
    };

public:
    virtual MUINT32 id( void )                {    return     CAM_DMA_LSCI;  }
    virtual const char*   name_Str( void )          {    return     "CAM_DMA_LSCI";}
    virtual MUINTPTR    reg_Base_Addr_Phy( void )  {    return     DMA_LSCI_BASE;     }
    virtual MUINTPTR    reg_Range( void )         {    return     DMA_LSCI_REG_RANGE;     }
};

///////////////////////////////////////////////////////////////////////////////
/**
    class for CACI
*/
class DMA_CACI:public DMAI_B
{
public:
    DMA_CACI(){
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
    };

public:
    virtual MUINT32 id( void )                {    return     CAM_DMA_CACI;  }
    virtual const char*   name_Str( void )          {    return     "CAM_DMA_CACI";}
    virtual MUINTPTR    reg_Base_Addr_Phy( void )  {    return     DMA_CACI_BASE;     }
    virtual MUINTPTR    reg_Range( void )         {    return     DMA_CACI_REG_RANGE;     }
};


///////////////////////////////////////////////////////////////////////////////
/**
    class for CQ0I
*/
class DMA_CQ0:public DMAI_B
{
public:
    DMA_CQ0(){
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
        m_bSubsample = MFALSE;
        m_updatecnt = 0;
    };
    typedef enum{
        _p1_done_once_ = 0,
        _immediate_,
        _continuouse_
    }E_MODE;
    typedef enum{
        _inner_,
        _outer_,
    }E_LoadMode;
    typedef enum{
        _cq_add_,
        _cq_delete_,
    }E_Write2CQ;

            MBOOL   setCQTriggerMode(E_MODE mode,void* ptr = NULL);
            MBOOL   TrigCQ(MBOOL bWait = MTRUE);
            MBOOL   setBaseAddr_byCQ(void);     //for cq link-list
            MBOOL   setSlaveAddr_byCQ(void);    //master cam to program slave cam's baseaddress
            MBOOL   setLoadMode(E_LoadMode mode, MBOOL bPhysical);
            MBOOL   setDoneSubSample(ISP_DRV_CAM* pSrcObj,MBOOL bEn,MUINT32 nSub=0); //for high speed case
            MBOOL   SetCQupdateCnt(void);
            UINT32  GetCQupdateCnt(MBOOL bPhy);


protected:
    virtual MINT32      _config( void ); //config all dma but baseaddress
    virtual MINT32      _write2CQ( void );

public:
    virtual MUINT32     id( void )                {    return     CAM_DMA_CQ0I;  }
    virtual const char* name_Str( void )          {    return     "CAM_DMA_CQ0I";}
    virtual MUINTPTR    reg_Base_Addr_Phy( void )  {    return     DMA_CQI_BASE;     }
    virtual MUINTPTR    reg_Range( void )         {    return     DMA_CQI_REG_RANGE;     }


    virtual MINT32      IO2CQ(E_Write2CQ op);

#if CQ_SW_WORK_AROUND
            void    DummyDescriptor(void);
#endif

public:
            MBOOL   m_bSubsample;
};

///////////////////////////////////////////////////////////////////////////////
/**
    class for CQ1I
*/
class DMA_CQ1:public DMAI_B
{
public:
    DMA_CQ1(){
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
        m_bSubsample = MFALSE;
    };
    typedef enum{
        _p1_done_once_ = 0,
        //_immediate_,
        //_continuouse_
    }E_MODE;
            MBOOL   setCQTriggerMode(E_MODE mode);
            MBOOL   TrigCQ(void);

            MBOOL   setCQContent(MUINTPTR arg1,MUINTPTR arg2);
            MBOOL   setBaseAddr_byCQ(void);     //for cq link-list
public:
    virtual MUINT32     id( void )                {    return     CAM_DMA_CQ1I;  }
    virtual const char* name_Str( void )          {    return     "CAM_DMA_CQ1I";}
    virtual MUINTPTR    reg_Base_Addr_Phy( void )  {    return     DMA_CQI_BASE;     }
    virtual MUINTPTR    reg_Range( void )         {    return     DMA_CQI_REG_RANGE;     }

public:
            MBOOL   m_bSubsample;


};

///////////////////////////////////////////////////////////////////////////////
/**
    class for CQ2I
*/
class DMA_CQ2:public DMAI_B
{
public:
    DMA_CQ2(){
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
    };
public:
    virtual MUINT32 id( void )                {    return     CAM_DMA_CQ2I;  }
    virtual const char*   name_Str( void )          {    return     "CAM_DMA_CQ2I";}
    virtual MUINTPTR    reg_Base_Addr_Phy( void )  {    return     DMA_CQI_BASE;     }
    virtual MUINTPTR    reg_Range( void )         {    return     DMA_CQI_REG_RANGE;     }
protected:
    virtual MINT32 _config( void ){return 1;}
    virtual MINT32 _enable( void* pParam ){(void)pParam;return 1;}
    virtual MINT32 _disable( void* pParam = NULL ){(void)pParam;return 1;}
    virtual MINT32 _write2CQ( void ){return 1;}
};

///////////////////////////////////////////////////////////////////////////////
/**
    class for CQ3I
*/
class DMA_CQ3:public DMAI_B
{
public:
    DMA_CQ3(){
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
    };
public:
    virtual MUINT32 id( void )                {    return     CAM_DMA_CQ3I;  }
    virtual const char*   name_Str( void )          {    return     "CAM_DMA_CQ3I";}
    virtual MUINTPTR    reg_Base_Addr_Phy( void )  {    return     DMA_CQI_BASE;     }
    virtual MUINTPTR    reg_Range( void )         {    return     DMA_CQI_REG_RANGE;     }
protected:
    virtual MINT32 _config( void ){return 1;}
    virtual MINT32 _enable( void* pParam ){(void)pParam;return 1;}
    virtual MINT32 _disable( void* pParam = NULL ){(void)pParam;return 1;}
    virtual MINT32 _write2CQ( void ){return 1;}

};

///////////////////////////////////////////////////////////////////////////////
/**
    class for CQ4I
*/
class DMA_CQ4:public DMAI_B
{
public:
    DMA_CQ4(){
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
    };

    typedef enum{
        _p1_done_once_ = 0,
        _immediate_,
        _continuouse_
    }E_MODE;
            MBOOL   setCQTriggerMode(E_MODE mode);
            MBOOL   TrigCQ(void);

public:
    virtual MUINT32     id( void )                {    return     CAM_DMA_CQ4I;  }
    virtual const char* name_Str( void )          {    return     "CAM_DMA_CQ4I";}
    virtual MUINTPTR    reg_Base_Addr_Phy( void )  {    return     DMA_CQI_BASE;     }
    virtual MUINTPTR    reg_Range( void )         {    return     DMA_CQI_REG_RANGE;     }
};

///////////////////////////////////////////////////////////////////////////////
/**
    class for CQ5I
*/
class DMA_CQ5:public DMAI_B
{
public:
    DMA_CQ5(){
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
    };

    typedef enum{
        _p1_done_once_ = 0,
        _immediate_,
        _continuouse_
    }E_MODE;
            MBOOL   setCQTriggerMode(E_MODE mode);
            MBOOL   TrigCQ(void);

public:
    virtual MUINT32 id( void )                {    return     CAM_DMA_CQ5I;  }
    virtual const char*   name_Str( void )          {    return     "CAM_DMA_CQ5I";}
    virtual MUINTPTR    reg_Base_Addr_Phy( void )  {    return     DMA_CQI_BASE;     }
    virtual MUINTPTR    reg_Range( void )         {    return     DMA_CQI_REG_RANGE;     }
};

///////////////////////////////////////////////////////////////////////////////
/**
    class for CQ6I
*/
class DMA_CQ6:public DMAI_B
{
public:
    DMA_CQ6(){
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
    };
public:
    virtual MUINT32 id( void )                {    return     CAM_DMA_CQ6I;  }
    virtual const char*   name_Str( void )          {    return     "CAM_DMA_CQ6I";}
    virtual MUINTPTR reg_Base_Addr_Phy( void )  {    return     DMA_CQI_BASE;     }
    virtual MUINTPTR reg_Range( void )         {    return     DMA_CQI_REG_RANGE;     }
};

///////////////////////////////////////////////////////////////////////////////
/**
    class for CQ7I
*/
class DMA_CQ7:public DMAI_B
{
public:
    DMA_CQ7(){
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
    };

    typedef enum{
        _p1_done_once_ = 0,
        _immediate_,
        _continuouse_
    }E_MODE;
            MBOOL   setCQTriggerMode(E_MODE mode);
            MBOOL   TrigCQ(void);

public:
    virtual MUINT32 id( void )                {    return     CAM_DMA_CQ7I;  }
    virtual const char*   name_Str( void )          {    return     "CAM_DMA_CQ7I";}
    virtual MUINTPTR reg_Base_Addr_Phy( void )  {    return     DMA_CQI_BASE;     }
    virtual MUINTPTR reg_Range( void )         {    return     DMA_CQI_REG_RANGE;     }
};

///////////////////////////////////////////////////////////////////////////////
/**
    class for CQ8I
*/
class DMA_CQ8:public DMAI_B
{
public:
    DMA_CQ8(){
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
    };

    typedef enum{
        _p1_done_once_ = 0,
        _immediate_,
        _continuouse_
    }E_MODE;
            MBOOL   setCQTriggerMode(E_MODE mode);
            MBOOL   TrigCQ(void);

public:
    virtual MUINT32 id( void )                {    return     CAM_DMA_CQ8I;  }
    virtual const char*   name_Str( void )          {    return     "CAM_DMA_CQ8I";}
    virtual MUINTPTR reg_Base_Addr_Phy( void )  {    return     DMA_CQI_BASE;     }
    virtual MUINTPTR reg_Range( void )         {    return     DMA_CQI_REG_RANGE;     }
};

///////////////////////////////////////////////////////////////////////////////
/**
    class for CQ9I
*/
class DMA_CQ9:public DMAI_B
{
public:
    DMA_CQ9(){
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
    };
public:
    virtual MUINT32 id( void )                {    return     CAM_DMA_CQ9I;  }
    virtual const char*   name_Str( void )          {    return     "CAM_DMA_CQ9I";}
    virtual MUINTPTR reg_Base_Addr_Phy( void )  {    return     DMA_CQI_BASE;     }
    virtual MUINTPTR reg_Range( void )         {    return     DMA_CQI_REG_RANGE;     }
};

///////////////////////////////////////////////////////////////////////////////
/**
    class for CQ10I
*/
class DMA_CQ10:public DMAI_B
{
public:
    DMA_CQ10(){
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
    };

    //CQ10 is dedicated for CQ11, to loading CQ11 inner BA only under high-speed mode
    //because of device tree, CPU can't program inner BA directly.
    typedef enum{
        _immediate_ = 1,
    }E_MODE;
            MBOOL   setCQTriggerMode(E_MODE mode);
            MBOOL   TrigCQ(void);
public:
    virtual MUINT32 id( void )                {    return     CAM_DMA_CQ10I;  }
    virtual const char*   name_Str( void )          {    return     "CAM_DMA_CQ10I";}
    virtual MUINTPTR reg_Base_Addr_Phy( void )  {    return     DMA_CQI_BASE;     }
    virtual MUINTPTR reg_Range( void )         {    return     DMA_CQI_REG_RANGE;     }

protected:
    virtual MINT32  _write2CQ( void );
};

///////////////////////////////////////////////////////////////////////////////
/**
    class for CQ11I
*/
class DMA_CQ11:public DMAI_B
{
public:
    DMA_CQ11(){
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
        m_prvSOF = 0xFFFF;
    };
    typedef enum{
        _event_trig = 0,
    }E_MODE;
            MBOOL   setCQTriggerMode(E_MODE mode);
            MBOOL   TrigCQ(void);

            MBOOL   setCQContent(MUINTPTR arg1,MUINTPTR arg2);

protected:
    virtual MINT32 _write2CQ( void ){return 1;};
    virtual MINT32 _disable( void* pParam = NULL );

public:
    virtual MUINT32 id( void )                {    return     CAM_DMA_CQ11I;  }
    virtual const char*   name_Str( void )          {    return     "CAM_DMA_CQ11I";}
    virtual MUINTPTR reg_Base_Addr_Phy( void )  {    return     DMA_CQI_BASE;     }
    virtual MUINTPTR reg_Range( void )         {    return     DMA_CQI_REG_RANGE;     }

private:
            MUINT32 m_prvSOF;
};

///////////////////////////////////////////////////////////////////////////////
/**
    class for CQ12I
*/
class DMA_CQ12:public DMAI_B
{
public:
    DMA_CQ12(){
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
    };

    typedef enum{
        _p1_done_once_ = 0,
        _immediate_,
        _continuouse_
    }E_MODE;
            MBOOL   setCQTriggerMode(E_MODE mode);
            MBOOL   TrigCQ(void);

public:
    virtual MUINT32     id( void )                {    return     CAM_DMA_CQ12I;  }
    virtual const char* name_Str( void )          {    return     "CAM_DMA_CQ12I";}
    virtual MUINTPTR    reg_Base_Addr_Phy( void )  {    return     DMA_CQI_BASE;     }
    virtual MUINTPTR    reg_Range( void )         {    return     DMA_CQI_REG_RANGE;     }
};

///////////////////////////////////////////////////////////////////////////////
/**
    class for IMGO
*/
class DMA_IMGO:public DMAO_B
{
public:
    DMA_IMGO(){};

public:
    virtual MUINT32 id( void )                {    return     CAM_DMA_IMGO;  }
    virtual const char*   name_Str( void )          {    return     "CAM_DMA_IMGO";}
    virtual MUINTPTR reg_Base_Addr_Phy( void )  {    return     DMA_IMGO_BASE;     }
    virtual MUINTPTR reg_Range( void )         {    return     DMA_IMGO_REG_RANGE;     }
};

///////////////////////////////////////////////////////////////////////////////
/**
    class for RRZO
*/
class DMA_RRZO:public DMAO_B
{
public:
    DMA_RRZO(){};

public:
    virtual MUINT32 id( void )                {    return     CAM_DMA_RRZO;  }
    virtual const char*   name_Str( void )          {    return     "CAM_DMA_RRZO";}
    virtual MUINTPTR reg_Base_Addr_Phy( void )  {    return     DMA_RRZO_BASE;     }
    virtual MUINTPTR reg_Range( void )         {    return     DMA_RRZO_REG_RANGE;     }
};


///////////////////////////////////////////////////////////////////////////////
/**
    class for LCSO
*/
class DMA_LCSO:public DMAO_B
{
public:
    DMA_LCSO(){};

public:
    virtual MUINT32 id( void )                {    return     CAM_DMA_LCSO;  }
    virtual const char*   name_Str( void )          {    return     "CAM_DMA_LCSO";}
    virtual MUINTPTR reg_Base_Addr_Phy( void )  {    return     DMA_LCSO_BASE;     }
    virtual MUINTPTR reg_Range( void )         {    return     DMA_LCSO_REG_RANGE;     }
};



///////////////////////////////////////////////////////////////////////////////
/**
    class for AAO
*/
class DMA_AAO:public DMAO_B
{
public:
    DMA_AAO(){};

public:
    virtual MUINT32 id( void )                {    return     CAM_DMA_AAO;  }
    virtual const char*   name_Str( void )          {    return     "CAM_DMA_AAO";}
    virtual MUINTPTR reg_Base_Addr_Phy( void )  {    return     DMA_AAO_BASE;     }
    virtual MUINTPTR reg_Range( void )         {    return     DMA_AAO_REG_RANGE;     }
};



///////////////////////////////////////////////////////////////////////////////
/**
    class for AFO
*/
class DMA_AFO:public DMAO_B
{
public:
    DMA_AFO(){};

public:
    virtual MUINT32 id( void )                {    return     CAM_DMA_AFO;  }
    virtual const char*   name_Str( void )          {    return     "CAM_DMA_AFO";}
    virtual MUINTPTR reg_Base_Addr_Phy( void )  {    return     DMA_AFO_BASE;     }
    virtual MUINTPTR reg_Range( void )         {    return     DMA_AFO_REG_RANGE;     }
};

///////////////////////////////////////////////////////////////////////////////
/**
    class for PSO
*/
class DMA_PSO:public DMAO_B
{
public:
    DMA_PSO(){};

public:
    virtual MUINT32 id( void )                {    return     CAM_DMA_PSO;  }
    virtual const char*   name_Str( void )          {    return     "CAM_DMA_PSO";}
    virtual MUINTPTR reg_Base_Addr_Phy( void )  {    return     DMA_PSO_BASE;     }
    virtual MUINTPTR reg_Range( void )         {    return     DMA_PSO_REG_RANGE;     }
};


///////////////////////////////////////////////////////////////////////////////
/**
    class for UFEO
*/
class DMA_UFEO:public DMAO_B
{
public:
    DMA_UFEO(){};

public:
    virtual MUINT32 id( void )                {    return     CAM_DMA_UFEO;  }
    virtual const char*   name_Str( void )          {    return     "CAM_DMA_UFEO";}
    virtual MUINTPTR reg_Base_Addr_Phy( void )  {    return     DMA_UFEO_BASE;     }
    virtual MUINTPTR reg_Range( void )         {    return     DMA_UFEO_REG_RANGE;     }
protected:
};
///////////////////////////////////////////////////////////////////////////////
/**
    class for PDO
*/
class DMA_PDO:public DMAO_B
{
public:
    DMA_PDO(){};

public:
    virtual MUINT32 id( void )                {    return     CAM_DMA_PDO;  }
    virtual const char*   name_Str( void )          {    return     "CAM_DMA_PDO";}
    virtual MUINTPTR reg_Base_Addr_Phy( void )  {    return     DMA_PDO_BASE;     }
    virtual MUINTPTR reg_Range( void )         {    return     DMA_PDO_REG_RANGE;     }
protected:
};


///////////////////////////////////////////////////////////////////////////////
/**
    class for EISO
*/
class DMA_EISO:public DMAO_B
{
public:
    DMA_EISO(){};

public:
    virtual MUINT32 id( void )                {    return     UNI_DMA_EISO;  }
    virtual const char*   name_Str( void )          {    return     "UNI_DMA_EISO";}
    virtual MUINTPTR reg_Base_Addr_Phy( void )  {    return     DMA_EISO_BASE;     }
    virtual MUINTPTR reg_Range( void )         {    return     DMA_EISO_REG_RANGE;     }
};

///////////////////////////////////////////////////////////////////////////////
/**
    class for FLKO
*/
class DMA_FLKO:public DMAO_B
{
public:
    DMA_FLKO(){};

public:
    virtual MUINT32 id( void )                {    return     UNI_DMA_FLKO;  }
    virtual const char*   name_Str( void )          {    return     "UNI_DMA_FLKO";}
    virtual MUINTPTR reg_Base_Addr_Phy( void )  {    return     DMA_FLKO_BASE;     }
    virtual MUINTPTR reg_Range( void )         {    return     DMA_FLKO_REG_RANGE;     }
};

///////////////////////////////////////////////////////////////////////////////
/**
    class for RSSO
*/
class DMA_RSSO:public DMAO_B
{
public:
    DMA_RSSO(){};

public:
    virtual MUINT32 id( void )                {    return     UNI_DMA_RSSO;  }
    virtual const char*   name_Str( void )          {    return     "UNI_DMA_RSSO";}
    virtual MUINTPTR reg_Base_Addr_Phy( void )  {    return     DMA_RSSO_BASE;     }
    virtual MUINTPTR reg_Range( void )         {    return     DMA_RSSO_REG_RANGE;     }
};

///////////////////////////////////////////////////////////////////////////////
/**
    class for RAWI
*/
class DMA_RAWI:public DMAI_B
{
public:
    DMA_RAWI(){};

public:
    virtual MUINT32 id( void )                {    return     UNI_DMA_RAWI;  }
    virtual const char*   name_Str( void )          {    return     "UNI_DMA_RAWI";}
    virtual MUINTPTR reg_Base_Addr_Phy( void )  {    return     DMA_RAWI_BASE;     }
    virtual MUINTPTR reg_Range( void )         {    return     DMA_RAWI_REG_RANGE;     }
};



///////////////////////////////////////////////////////////////////////////////
class PIPE_CHECK
{
    public:
        PIPE_CHECK(void)
            :m_pUniDrv(NULL)
            ,m_pDrv(NULL)
            {}
        ~PIPE_CHECK(void){}

        MBOOL   DMAO_STATUS(void);
        MBOOL   FIFO_FULL_STATUS(void);
        MBOOL   UFE_CHECK(void);
        MBOOL   AA_CHECK(void);
        MBOOL   FLK_CHECK(void);
        MBOOL   LCS_CHECK(void);
        MBOOL   EIS_CHECK(void);
        MBOOL   RSS_CHECK(void);
        MBOOL   LSC_CHECK(void);
        MBOOL   AF_CHECK(void);
        MBOOL   PDO_CHECK(void);
        MBOOL   TG_CHECK(MUINT32 intErrStatus);
        MBOOL   PS_CHECK(void);

        MBOOL   ENQUE_CHECK(void);
        MBOOL   TWIN_CHECK(ISP_DRV_CAM* pTwin);
        MBOOL   RRZ_CHECK(void);
        MBOOL   XMX_CHECK(void);
    public:

        UniDrvImp*      m_pUniDrv;
        ISP_DRV_CAM*    m_pDrv;
        static MUINTPTR m_BPCI_VA;
        static MUINTPTR m_PDI_VA;
};


///////////////////////////////////////////////////////////////////////////////
typedef enum{
    eCmd_Fail = 0,          //fail
    eCmd_Pass = 1,          //ok
    eCmd_Stop_Pass,         //this state is for stopped already
    eCmd_Suspending_Pass,   //this state is for starting suspending
}E_BC_STATUS;

/**
    class for CAM DAMO ctrl, support only deque/enque 1 image at 1 time.
*/
class CAM_BUF_CTRL : public IspFunction_B
{
public:
    CAM_BUF_CTRL(void);
    ~CAM_BUF_CTRL(void){};

    virtual MUINT32 id( void )                    {   return 0xffffffff;  }
    virtual const char*   name_Str( void )              {   return "CAM_BUFFER_CTRL";}
    virtual MUINTPTR reg_Base_Addr_Phy( void )     {   return (MUINT32)NULL;  }
    virtual MUINTPTR reg_Range( void )             {   return (MUINT32)NULL;  }

    /**
        check if any ready image on dram.
    */
    virtual E_BC_STATUS waitBufReady(CAM_STATE_NOTIFY *pNotify = NULL);
    /**
        push empty buffer into hw
    */
            E_BC_STATUS enqueueHwBuf( stISP_BUF_INFO& buf_info,MBOOL bImdMode = 0);

    /**
        retrieve available buffer on dram
    */
            E_BC_STATUS dequeueHwBuf(NSImageio::NSIspio::BufInfo& buf_info );

    virtual E_BC_STATUS dropEnqueueHwBuf(void);

private:
    #define MAX_DEPTH (64)

protected:
        mutable Mutex   m_bufctrl_lock;//protect deque/enque behavior

        QueueMgr<ST_BUF_INFO>   m_Queue;
        QueueMgr<MUINTPTR>  m_Queue_deque_ptr;

protected:
    virtual MINT32  _config( void );
    virtual MINT32  _enable( void* pParam  ) ;
    virtual MINT32  _disable( void* pParam = NULL ) ;
    virtual MINT32  _write2CQ( void ) ;

            MBOOL   PipeCheck(void);

    virtual void    FBC_STATUS(IspDrv* ptr){(void)ptr;}
    virtual void    Header_Parser(MUINTPTR fh_va,NSImageio::NSIspio::BufInfo& buf_info,MUINT32* header_data ,char* pStr){(void)fh_va;(void)buf_info;(void)header_data;(void)pStr;}
            MUINT32 estimateTimeout(MUINT32 subSample);
public:
    static  MBOOL   updateFrameTime(MUINT32 timeInMs, MUINT32 reqOffset, ISP_HW_MODULE camModule);

    typedef enum {
        eCamState_runnable = 0,     //resume flow is ready(no wait)
        eCamState_stop,             //already stopped
        eCamState_suspending,       //starting suspend flow
        eCamState_suspend,          //already suspened, for dynamic twin.
        eCamState_max
    } E_CAM_STATE;
    typedef enum {
        eCamDmaType_main = 0,
        eCamDmaType_stt,
        eCamDmaType_max
    } E_CAM_DMA_TYPE;
    //virtual cam is not supported!(due to only phy cam is supported at waitbufready())
    typedef enum{
        eSus_HWOFF  = 0x01,
        eSus_HW_SW_STATE  = 0x02,
        eSus_SIGNAL = 0x04,
        eSus_ALL    = 0x07,
    }E_SUSPEND_OP;
    static  MBOOL   suspend(ISP_HW_MODULE camModule, ISP_DRV_CAM *pDrvCam, UniDrvImp* pUniDrv,E_SUSPEND_OP op = eSus_ALL);
    static  MBOOL   resume(ISP_HW_MODULE camModule, ISP_DRV_CAM *pDrvCam);
    static  MBOOL   updateState(E_CAM_STATE camState, ISP_HW_MODULE camModule, E_CAM_DMA_TYPE dmaType);

public:
    UniDrvImp*              m_pUniDrv;      //for EISO/FLKO/RSSO
    static MUINT32          m_fps[CAM_MAX]; //fps here is sw operation frequency, m_fps = sensor fps / signal subsample.
    static MUINT32          m_recentFrmTimeMs[CAM_MAX][MAX_RECENT_GRPFRM_TIME]; //upadted through normalpipe enque, for dynamic change deque timeout
    static E_CAM_STATE      m_CamState[CAM_MAX];
    static E_CAM_STATE      m_SttState[CAM_MAX];

#if TEMP_SW_TIMESTAMP
    CAM_TIMESTAMP           m_TimeStamp;
#endif
    //only workable when TEMP_SW_TIMESTAMP==0
    CAM_TIMESTAMP*          m_pTimeStamp;

    typedef enum {
        eExtArg_VirUni = 0,
        eExtArg_PhyUni = 1
    }E_EXT_ARG;
    MUINTPTR                extArg;


protected:
    ISP_DRV_CAM*    m_pDrv;

    MUINT32         m_buf_cnt;
    MINT32          m_tail_idx;
};

class BUF_CTRL_IMGO: public CAM_BUF_CTRL
{
public:
    BUF_CTRL_IMGO()
    {
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
    }
    virtual const char* name_Str(void)  {   return "BUF_CTRL_IMGO";}
    virtual MUINT32     id(void)            {   return _imgo_;  }

    //virtual MBOOL waitBufReady( MBOOL bClear, CAM_STATE_NOTIFY *pNotify = NULL);
protected:
    virtual void    FBC_STATUS(IspDrv* ptr);
    virtual void    Header_Parser(MUINTPTR fh_va,NSImageio::NSIspio::BufInfo& buf_info,MUINT32* header_data ,char* pStr);


};

class BUF_CTRL_RRZO: public CAM_BUF_CTRL
{
public:
    BUF_CTRL_RRZO()
    {
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
    }
    virtual const char* name_Str(void)  {   return "BUF_CTRL_RRZO";}
    virtual MUINT32     id(void)            {   return _rrzo_;  }

    //virtual MBOOL waitBufReady( MBOOL bClear, CAM_STATE_NOTIFY *pNotify = NULL);

protected:
    virtual void    FBC_STATUS(IspDrv* ptr);
    virtual void    Header_Parser(MUINTPTR fh_va,NSImageio::NSIspio::BufInfo& buf_info,MUINT32* header_data ,char* pStr);


};

class BUF_CTRL_UFEO: public CAM_BUF_CTRL
{
public:
    BUF_CTRL_UFEO()
    {
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
    }
    virtual const char* name_Str(void)  {   return "BUF_CTRL_UFEO";}
    virtual MUINT32     id(void)            {   return _ufeo_;  }

protected:
    virtual void    FBC_STATUS(IspDrv* ptr);
    virtual void    Header_Parser(MUINTPTR fh_va,NSImageio::NSIspio::BufInfo& buf_info,MUINT32* header_data ,char* pStr);
};

class BUF_CTRL_LCSO: public CAM_BUF_CTRL
{
public:
    BUF_CTRL_LCSO()
    {
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
    }
    virtual const char* name_Str(void)  {   return "BUF_CTRL_LCSO";}
    virtual MUINT32     id(void)            {   return _lcso_;  }

protected:
    virtual void    FBC_STATUS(IspDrv* ptr);
    virtual void    Header_Parser(MUINTPTR fh_va,NSImageio::NSIspio::BufInfo& buf_info,MUINT32* header_data ,char* pStr);
};

class BUF_CTRL_EISO: public CAM_BUF_CTRL
{
public:
    BUF_CTRL_EISO()
    {
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
    }
    virtual const char* name_Str(void)  {   return "BUF_CTRL_EISO";}
    virtual MUINT32     id(void)            {   return _eiso_;  }

protected:
    virtual void    FBC_STATUS(IspDrv* ptr);
    virtual void    Header_Parser(MUINTPTR fh_va,NSImageio::NSIspio::BufInfo& buf_info,MUINT32* header_data ,char* pStr);
};

class BUF_CTRL_RSSO: public CAM_BUF_CTRL
{
public:
    BUF_CTRL_RSSO()
    {
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
    }
    virtual const char* name_Str(void)  {   return "BUF_CTRL_RSSO";}
    virtual MUINT32     id(void)            {   return _rsso_;  }

protected:
    virtual void    FBC_STATUS(IspDrv* ptr);
    virtual void    Header_Parser(MUINTPTR fh_va,NSImageio::NSIspio::BufInfo& buf_info,MUINT32* header_data ,char* pStr);
};


class BUF_CTRL_AAO: public CAM_BUF_CTRL
{
public:
    BUF_CTRL_AAO()
    {
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
    }
    virtual const char* name_Str(void)  {   return "BUF_CTRL_AAO";}
    virtual MUINT32     id(void)            {   return _aao_;  }

    virtual E_BC_STATUS waitBufReady(CAM_STATE_NOTIFY *pNotify = NULL);

protected:
    virtual void    FBC_STATUS(IspDrv* ptr);
    virtual void    Header_Parser(MUINTPTR fh_va,NSImageio::NSIspio::BufInfo& buf_info,MUINT32* header_data ,char* pStr);

};

class BUF_CTRL_AFO: public CAM_BUF_CTRL
{
public:
    BUF_CTRL_AFO()
    {
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
        m_bClear = MFALSE;
    }
    virtual const char* name_Str(void)  {   return "BUF_CTRL_AFO";}
    virtual MUINT32     id(void)            {   return _afo_;  }

    using CAM_BUF_CTRL::waitBufReady;
    virtual E_BC_STATUS waitBufReady( MBOOL bClear, CAM_STATE_NOTIFY *pNotify = NULL);

protected:
    virtual void    FBC_STATUS(IspDrv* ptr);
    virtual void    Header_Parser(MUINTPTR fh_va,NSImageio::NSIspio::BufInfo& buf_info,MUINT32* header_data ,char* pStr);
private:
    MBOOL   m_bClear;

};

class BUF_CTRL_FLKO: public CAM_BUF_CTRL
{
public:
    BUF_CTRL_FLKO()
    {
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
    }
    virtual const char* name_Str(void)  {   return "BUF_CTRL_FLKO";}
    virtual MUINT32     id(void)            {   return _flko_;  }

    virtual E_BC_STATUS waitBufReady(CAM_STATE_NOTIFY *pNotify = NULL);

protected:
    virtual void    FBC_STATUS(IspDrv* ptr);
    virtual void    Header_Parser(MUINTPTR fh_va,NSImageio::NSIspio::BufInfo& buf_info,MUINT32* header_data ,char* pStr);

};

class BUF_CTRL_PDO: public CAM_BUF_CTRL
{
public:
    BUF_CTRL_PDO()
    {
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
    }
    virtual const char* name_Str(void)  {   return "BUF_CTRL_PDO";}
    virtual MUINT32     id(void)            {   return _pdo_;  }

    virtual E_BC_STATUS waitBufReady( CAM_STATE_NOTIFY *pNotify = NULL);
protected:
    virtual void    FBC_STATUS(IspDrv* ptr);
    virtual void    Header_Parser(MUINTPTR fh_va,NSImageio::NSIspio::BufInfo& buf_info,MUINT32* header_data ,char* pStr);
};

class BUF_CTRL_PSO: public CAM_BUF_CTRL
{
public:
    BUF_CTRL_PSO()
    {
        m_pDrv = (ISP_DRV_CAM*)m_pIspDrv;
    }
    virtual const char* name_Str(void)  {   return "BUF_CTRL_PSO";}
    virtual MUINT32     id(void)            {   return _pso_;  }

    virtual E_BC_STATUS waitBufReady(CAM_STATE_NOTIFY *pNotify = NULL);

protected:
    virtual void    FBC_STATUS(IspDrv* ptr);
    virtual void    Header_Parser(MUINTPTR fh_va,NSImageio::NSIspio::BufInfo& buf_info,MUINT32* header_data ,char* pStr);

};

#endif