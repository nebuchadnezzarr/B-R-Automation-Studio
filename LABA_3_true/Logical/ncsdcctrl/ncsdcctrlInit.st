
PROGRAM _INIT

(* ### BEGIN gAxis05 ### *)
      
(* initialize general interfaces *)
      gAxis05.size := gAxis05.size;
      gAxis05_HW.DrvIf_Typ := ncSDC_DRVSM16;
      brsstrcpy( ADR(gAxis05_HW.DrvIf_Name[0]), ADR('gAxis05_DrvIf') );
      gAxis05_HW.DiDoIf_Typ := ncSDC_DIDO;
      brsstrcpy( ADR(gAxis05_HW.DiDoIf_Name[0]), ADR('gAxis05_DiDoIf') );
      gAxis05_HW.EncIf1_Typ := ncSDC_ENC16;
      brsstrcpy( ADR(gAxis05_HW.EncIf1_Name[0]), ADR('gAxis05_EncIf1') );
      gAxis05_EncIf1.iLifeCnt := gAxis05_EncIf1.iLifeCnt;
      
(* initialize old-value for delta step calculation *)
      gAxis05_oSetPosOld := gAxis05_DrvIf.oSetPos;
       
(* ### END gAxis05 ### *)

END_PROGRAM

