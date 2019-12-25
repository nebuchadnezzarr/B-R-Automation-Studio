/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1577186486_2_
#define _BUR_1577186486_2_

#include <bur/plctypes.h>

/* Constants */
#ifdef _REPLACE_CONST
#else
#endif


/* Variables */
_GLOBAL unsigned char oSetPos;
_GLOBAL unsigned char iActPos;
_GLOBAL plcbit iNegHwEnd;
_GLOBAL plcbit iPosHwEnd;
_GLOBAL_RETAIN struct FB_Axis axis_X;
_GLOBAL unsigned short pwm_period;
_GLOBAL struct FB_Regulator fb_regulator;
_GLOBAL signed short coil_pwm_value;
_GLOBAL plcbit coil_powered;
_GLOBAL signed short gAxis05_MotorStep0;
_GLOBAL struct SdcDiDoIf_typ gAxis05_DiDoIf;
_GLOBAL struct SdcDrvIf16_typ gAxis05_DrvIf;
_GLOBAL struct SdcHwCfg_typ gAxis05_HW;
_GLOBAL struct ACP10AXIS_typ gAxis05;
_GLOBAL struct ACP10AXIS_typ gAxis04;
_GLOBAL struct ARNC0CNC_typ CNCsys;
_GLOBAL struct SdcDiDoIf_typ gAxis03_DiDoIf;
_GLOBAL struct SdcDrvIf16_typ gAxis03_DrvIf;
_GLOBAL struct SdcHwCfg_typ gAxis03_HW;
_GLOBAL struct ACP10AXIS_typ gAxis03;
_GLOBAL struct SdcDiDoIf_typ gAxisTest_DiDoIf;
_GLOBAL struct SdcDrvIf16_typ gAxisTest_DrvIf;
_GLOBAL struct SdcEncIf16_typ gAxis03_EncIf;
_GLOBAL struct SdcEncIf16_typ gAxis05_EncIf;
_GLOBAL struct SdcHwCfg_typ gAxisTest_HW;
_GLOBAL unsigned char New_Variable;
_GLOBAL struct ACP10AXIS_typ gAxisTest;
_GLOBAL struct ACP10AXIS_typ gAxis02;
_GLOBAL struct ACP10AXIS_typ gAxis01;
_GLOBAL struct SdcHwCfg_typ AxisX_HW;
_GLOBAL struct SdcDiDoIf_typ AxisX_DiDoIf;
_GLOBAL struct SdcDrvIf16_typ AxisX_DrvIf;
_GLOBAL struct SdcEncIf16_typ AxisX_EncIf;
_GLOBAL struct ACP10AXIS_typ AxisX;





__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/Global.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Library/Library.fun\\\" scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1577186486_2_ */

