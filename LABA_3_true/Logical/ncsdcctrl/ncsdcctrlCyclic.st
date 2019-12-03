
PROGRAM _CYCLIC

(* ### BEGIN gAxis05 ### *)
      
(* life counter emulation of digital inputs *)
      gAxis05_DiDoIf.iLifeCntReference := gAxis05_DiDoIf.iLifeCntReference + 1;
      gAxis05_DiDoIf.iLifeCntNegHwEnd  := gAxis05_DiDoIf.iLifeCntNegHwEnd  + 1;
      gAxis05_DiDoIf.iLifeCntPosHwEnd  := gAxis05_DiDoIf.iLifeCntPosHwEnd  + 1;
       
(* default function model of ACOPOSmicro: convert absolute steps to delta steps - overflow save delta calculation *)
      gAxis05_MotorStep0 := gAxis05_DrvIf.oSetPos - gAxis05_oSetPosOld;
      gAxis05_oSetPosOld := gAxis05_DrvIf.oSetPos;
       
(* ### END gAxis05 ### *)

END_PROGRAM

