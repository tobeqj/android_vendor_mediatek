 //ptr->writeReg(0x1320, 0x57c17e00, CAM_A);              //CAM.CAM_A.DMA.UFGO_BASE_ADDR
 //ptr->writeReg(0x10e0, 0x52035600, CAM_A);              //CAM.CAM_A.DMA.LCSO_BASE_ADDR
 //ptr->writeReg(0x1004, 0xe72888b9, CAM_A);              //CAM.CAM_A.DMA.CQ0I_BASE_ADDR
 //ptr->writeReg(0x1020, 0x502e4a00, CAM_A);              //CAM.CAM_A.DMA.IMGO_BASE_ADDR
 //ptr->writeReg(0x1050, 0x57bf3600, CAM_A);              //CAM.CAM_A.DMA.RRZO_BASE_ADDR
 //ptr->writeReg(0x1080, 0x54ed6000, CAM_A);              //CAM.CAM_A.DMA.AAO_BASE_ADDR
 //ptr->writeReg(0x10b0, 0x572a7c00, CAM_A);              //CAM.CAM_A.DMA.AFO_BASE_ADDR
 //ptr->writeReg(0x1110, 0x5696f000, CAM_A);              //CAM.CAM_A.DMA.UFEO_BASE_ADDR
 //ptr->writeReg(0x1140, 0x51889800, CAM_A);              //CAM.CAM_A.DMA.PDO_BASE_ADDR
 //ptr->writeReg(0x1170, 0x558dac00, CAM_A);              //CAM.CAM_A.DMA.BPCI_BASE_ADDR
 //ptr->writeReg(0x11a0, 0x82c95e64, CAM_A);              //CAM.CAM_A.DMA.CACI_BASE_ADDR
 //ptr->writeReg(0x11d0, 0x55a67800, CAM_A);              //CAM.CAM_A.DMA.LSCI_BASE_ADDR
 //ptr->writeReg(0x1200, 0x823966c2, CAM_A);              //CAM.CAM_A.DMA.LSC3I_BASE_ADDR
 //ptr->writeReg(0x1230, 0x51662000, CAM_A);              //CAM.CAM_A.DMA.PDI_BASE_ADDR
 //ptr->writeReg(0x1260, 0x52ecac00, CAM_A);              //CAM.CAM_A.DMA.PSO_BASE_ADDR
 //ptr->writeReg(0x1290, 0x55117600, CAM_A);              //CAM.CAM_A.DMA.LMVO_BASE_ADDR
 //ptr->writeReg(0x12c0, 0x561d0400, CAM_A);              //CAM.CAM_A.DMA.FLKO_BASE_ADDR
 //ptr->writeReg(0x12f0, 0x52282600, CAM_A);              //CAM.CAM_A.DMA.RSSO_A_BASE_ADDR
 //ptr->writeReg(0x1404, 0x53323c00, CAM_A);              //CAM.CAM_A.DMA.IMGO_FH_BASE_ADDR
 //ptr->writeReg(0x1408, 0x50f1ac00, CAM_A);              //CAM.CAM_A.DMA.RRZO_FH_BASE_ADDR
 //ptr->writeReg(0x140c, 0x5153f800, CAM_A);              //CAM.CAM_A.DMA.AAO_FH_BASE_ADDR
 //ptr->writeReg(0x1410, 0x539a6000, CAM_A);              //CAM.CAM_A.DMA.AFO_FH_BASE_ADDR
 //ptr->writeReg(0x1414, 0x55d13400, CAM_A);              //CAM.CAM_A.DMA.LCSO_FH_BASE_ADDR
 //ptr->writeReg(0x1418, 0x5455be00, CAM_A);              //CAM.CAM_A.DMA.UFEO_FH_BASE_ADDR
 //ptr->writeReg(0x141c, 0x5017de00, CAM_A);              //CAM.CAM_A.DMA.PDO_FH_BASE_ADDR
 //ptr->writeReg(0x1420, 0x567d8200, CAM_A);              //CAM.CAM_A.DMA.PSO_FH_BASE_ADDR
 //ptr->writeReg(0x1424, 0x531b4800, CAM_A);              //CAM.CAM_A.DMA.LMVO_FH_BASE_ADDR
 //ptr->writeReg(0x1428, 0x51dac000, CAM_A);              //CAM.CAM_A.DMA.FLKO_FH_BASE_ADDR
 //ptr->writeReg(0x142c, 0x567cc200, CAM_A);              //CAM.CAM_A.DMA.RSSO_A_FH_BASE_ADDR
 //ptr->writeReg(0x1430, 0x55e22a00, CAM_A);              //CAM.CAM_A.DMA.UFGO_FH_BASE_ADDR
 ptr->writeReg(0x0198, 0x52493800, CAM_A);              //CAM.CAM_A.CQ.THR0_BASEADDR
 ptr->writeReg(0x019c, 0x4f8, CAM_A);                   //CAM.CAM_A.CQ.THR0_DESC_SIZE
 ptr->writeReg(0x0194, 0x11, CAM_A);                    //CAM.CAM_A.CQ.THR0_CTL
 ptr->writeReg(0x118c, 0x80000020, CAM_A);              //CAM.CAM_A.DMA.BPCI_CON
 ptr->writeReg(0x11ec, 0x80000020, CAM_A);              //CAM.CAM_A.DMA.LSCI_CON
 ptr->writeReg(0x0190, 0x101, CAM_A);                   //CAM.CAM_A.CQ.EN
 ptr->writeReg(0x1018, 0xe9000000, CAM_A);              //CAM.CAM_A.DMA.SPECIAL_FUN_EN
 ptr->writeReg(0x0234, 0x1002, CAM_A);                  //CAM.CAM_A.TG.VF_CON (add from camsys_star_2.c) 