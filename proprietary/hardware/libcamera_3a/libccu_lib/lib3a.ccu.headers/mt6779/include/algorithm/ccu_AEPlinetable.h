

#ifndef _CCU_AEPLINETABLE_H_
#define _CCU_AEPLINETABLE_H_

#include "ccu_ext_interface/ccu_types.h"

#define MAX_PLINE_MAP_TABLE (30)

// AE mode definition ==> need to change the AE Pline table
typedef enum
{
    CCU_LIB3A_AE_SCENE_UNSUPPORTED = -1,
    CCU_LIB3A_AE_SCENE_OFF = 0,           // disable AE
    CCU_LIB3A_AE_SCENE_AUTO = 1,           // auto mode   full auto ,EV ISO LCE .. is inactive
    CCU_LIB3A_AE_SCENE_NIGHT = 2,           // preview Night Scene mode
    CCU_LIB3A_AE_SCENE_ACTION = 3,           // AE Action mode
    CCU_LIB3A_AE_SCENE_BEACH = 4,           // AE beach mode
    CCU_LIB3A_AE_SCENE_CANDLELIGHT = 5,           // AE Candlelight mode
    CCU_LIB3A_AE_SCENE_FIREWORKS = 6,            // AE firework mode
    CCU_LIB3A_AE_SCENE_LANDSCAPE = 7,            // AE landscape mode
    CCU_LIB3A_AE_SCENE_PORTRAIT = 8,            // AE portrait mode
    CCU_LIB3A_AE_SCENE_NIGHT_PORTRAIT = 9,            // AE night portrait mode
    CCU_LIB3A_AE_SCENE_PARTY = 10,           // AE party mode
    CCU_LIB3A_AE_SCENE_SNOW = 11,           // AE snow mode
    CCU_LIB3A_AE_SCENE_SPORTS = 12,           // AE sport mode
    CCU_LIB3A_AE_SCENE_STEADYPHOTO = 13,           // AE steadyphoto mode
    CCU_LIB3A_AE_SCENE_SUNSET = 14,           // AE sunset mode
    CCU_LIB3A_AE_SCENE_THEATRE = 15,           // AE theatre mode
    CCU_LIB3A_AE_SCENE_ISO_ANTI_SHAKE = 16,           // AE ISO anti shake mode
    CCU_LIB3A_AE_SCENE_BACKLIGHT = 17,           // ADD BACKLIGHT MODE
    CCU_LIB3A_AE_SCENE_ISO22 = 22,
    CCU_LIB3A_AE_SCENE_ISO40 = 40,
    CCU_LIB3A_AE_SCENE_ISO50 = 50,
    CCU_LIB3A_AE_SCENE_ISO64 = 64,
    CCU_LIB3A_AE_SCENE_ISO80 = 80,
    CCU_LIB3A_AE_SCENE_ISO100 = 100,
    CCU_LIB3A_AE_SCENE_ISO125 = 125,
    CCU_LIB3A_AE_SCENE_ISO150 = 150,
    CCU_LIB3A_AE_SCENE_ISO160 = 160,
    CCU_LIB3A_AE_SCENE_ISO200 = 101,
    CCU_LIB3A_AE_SCENE_ISO250 = 250,
    CCU_LIB3A_AE_SCENE_ISO300 = 300,
    CCU_LIB3A_AE_SCENE_ISO320 = 400,
    CCU_LIB3A_AE_SCENE_ISO400 = 102,
    CCU_LIB3A_AE_SCENE_ISO500 = 500,
    CCU_LIB3A_AE_SCENE_ISO600 = 600,
    CCU_LIB3A_AE_SCENE_ISO640 = 640,
    CCU_LIB3A_AE_SCENE_ISO800 = 103,
    CCU_LIB3A_AE_SCENE_ISO1000 = 1000,
    CCU_LIB3A_AE_SCENE_ISO1200 = 1200,
    CCU_LIB3A_AE_SCENE_ISO1250 = 1250,
    CCU_LIB3A_AE_SCENE_ISO1600 = 104,
    CCU_LIB3A_AE_SCENE_ISO2000 = 2000,
    CCU_LIB3A_AE_SCENE_ISO2400 = 2400,
    CCU_LIB3A_AE_SCENE_ISO3200 = 105,
    CCU_LIB3A_AE_SCENE_ISO6400 = 106,
    CCU_LIB3A_AE_SCENE_ISO12800 = 107,
    CCU_LIB3A_AE_SCENE_CSHOT = 200,
    CCU_LIB3A_AE_SCENE_SWEEP_PANORAMA = 201,
} CCU_LIB3A_AE_SCENE_T;

// AE ISO speed
typedef enum
{
    CCU_LIB3A_AE_ISO_SPEED_UNSUPPORTED = -1,
    CCU_LIB3A_AE_ISO_SPEED_AUTO = 0,
    CCU_LIB3A_AE_ISO_SPEED_22 = 22,
    CCU_LIB3A_AE_ISO_SPEED_40 = 40,
    CCU_LIB3A_AE_ISO_SPEED_50 = 50,
    CCU_LIB3A_AE_ISO_SPEED_64 = 64,
    CCU_LIB3A_AE_ISO_SPEED_80 = 80,
    CCU_LIB3A_AE_ISO_SPEED_100 = 100,
    CCU_LIB3A_AE_ISO_SPEED_125 = 125,
    CCU_LIB3A_AE_ISO_SPEED_150 = 150,
    CCU_LIB3A_AE_ISO_SPEED_160 = 160,
    CCU_LIB3A_AE_ISO_SPEED_200 = 200,
    CCU_LIB3A_AE_ISO_SPEED_250 = 250,
    CCU_LIB3A_AE_ISO_SPEED_300 = 300,
    CCU_LIB3A_AE_ISO_SPEED_320 = 320,
    CCU_LIB3A_AE_ISO_SPEED_400 = 400,
    CCU_LIB3A_AE_ISO_SPEED_500 = 500,
    CCU_LIB3A_AE_ISO_SPEED_600 = 600,
    CCU_LIB3A_AE_ISO_SPEED_640 = 640,
    CCU_LIB3A_AE_ISO_SPEED_800 = 800,
    CCU_LIB3A_AE_ISO_SPEED_1000 = 1000,
    CCU_LIB3A_AE_ISO_SPEED_1200 = 1200,
    CCU_LIB3A_AE_ISO_SPEED_1250 = 1250,
    CCU_LIB3A_AE_ISO_SPEED_1600 = 1600,
    CCU_LIB3A_AE_ISO_SPEED_2000 = 2000,
    CCU_LIB3A_AE_ISO_SPEED_2400 = 2400,
    CCU_LIB3A_AE_ISO_SPEED_3200 = 3200,
    CCU_LIB3A_AE_ISO_SPEED_6400 = 6400,
    CCU_LIB3A_AE_ISO_SPEED_12800 = 12800,
    CCU_LIB3A_AE_ISO_SPEED_MAX = CCU_LIB3A_AE_ISO_SPEED_12800,
} CCU_LIB3A_AE_ISO_SPEED_T;

//AE Parameter Structure
typedef enum
{
    CCU_AETABLE_RPEVIEW_AUTO = 0,     // default 60Hz
    CCU_AETABLE_CAPTURE_AUTO,
    CCU_AETABLE_VIDEO_AUTO,
    CCU_AETABLE_VIDEO1_AUTO,
    CCU_AETABLE_VIDEO2_AUTO,
    CCU_AETABLE_CUSTOM1_AUTO,
    CCU_AETABLE_CUSTOM2_AUTO,
    CCU_AETABLE_CUSTOM3_AUTO,
    CCU_AETABLE_CUSTOM4_AUTO,
    CCU_AETABLE_CUSTOM5_AUTO,
    CCU_AETABLE_VIDEO_NIGHT,
    CCU_AETABLE_CAPTURE_ISO50,
    CCU_AETABLE_CAPTURE_ISO100,
    CCU_AETABLE_CAPTURE_ISO150,
    CCU_AETABLE_CAPTURE_ISO200,
    CCU_AETABLE_CAPTURE_ISO300,
    CCU_AETABLE_CAPTURE_ISO400,
    CCU_AETABLE_CAPTURE_ISO600,
    CCU_AETABLE_CAPTURE_ISO800,
    CCU_AETABLE_CAPTURE_ISO1200,
    CCU_AETABLE_CAPTURE_ISO1600,
    CCU_AETABLE_CAPTURE_ISO2400,
    CCU_AETABLE_CAPTURE_ISO3200,
    CCU_AETABLE_STROBE,
    CCU_AETABLE_SCENE_INDEX1,                           // for mode used of capture
    CCU_AETABLE_SCENE_INDEX2,
    CCU_AETABLE_SCENE_INDEX3,
    CCU_AETABLE_SCENE_INDEX4,
    CCU_AETABLE_SCENE_INDEX5,
    CCU_AETABLE_SCENE_INDEX6,
    CCU_AETABLE_SCENE_INDEX7,
    CCU_AETABLE_SCENE_INDEX8,
    CCU_AETABLE_SCENE_INDEX9,
    CCU_AETABLE_SCENE_INDEX10,
    CCU_AETABLE_SCENE_INDEX11,
    CCU_AETABLE_SCENE_INDEX12,
    CCU_AETABLE_SCENE_INDEX13,
    CCU_AETABLE_SCENE_INDEX14,
    CCU_AETABLE_SCENE_INDEX15,
    CCU_AETABLE_SCENE_INDEX16,
    CCU_AETABLE_SCENE_INDEX17,
    CCU_AETABLE_SCENE_INDEX18,
    CCU_AETABLE_SCENE_INDEX19,
    CCU_AETABLE_SCENE_INDEX20,
    CCU_AETABLE_SCENE_INDEX21,
    CCU_AETABLE_SCENE_INDEX22,
    CCU_AETABLE_SCENE_INDEX23,
    CCU_AETABLE_SCENE_INDEX24,
    CCU_AETABLE_SCENE_INDEX25,
    CCU_AETABLE_SCENE_INDEX26,
    CCU_AETABLE_SCENE_INDEX27,
    CCU_AETABLE_SCENE_INDEX28,
    CCU_AETABLE_SCENE_INDEX29,
    CCU_AETABLE_SCENE_INDEX30,
    CCU_AETABLE_SCENE_INDEX31,
    CCU_AETABLE_SCENE_MAX
} CCU_eAETableID;

typedef struct
{
    MUINT32 u4Eposuretime;
    MUINT32 u4AfeGain;
    MUINT32 u4IspGain;
    MUINT8  uIris;
    MUINT8  uSensorMode;
    MUINT8  uFlag;
} CCU_strEvSetting;

typedef struct
{
    CCU_strEvSetting sPlineTable[200];   // Pline structure table
} CCU_strEvPline;

typedef struct
{
    CCU_strEvSetting sPlineTable[2000];   // Finer EV Pline structure table
} CCU_strFinerEvPline;

typedef struct
{
    CCU_LIB3A_AE_SCENE_T eAEScene;
    CCU_eAETableID ePLineID[11];
} CCU_strAEPLineMapping;

typedef struct
{
    MUINT32 u4TotalNum;
    MUINT16 u2SensorGainStep[1024];
} CCU_strAEPLineGainList;

typedef struct
{
    CCU_strAEPLineMapping    sAESceneMapping[MAX_PLINE_MAP_TABLE];   // Get PLine ID for different AE mode
}CCU_strAESceneMapping;

#endif


