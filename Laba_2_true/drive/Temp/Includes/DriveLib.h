/* Automation Studio generated header file */
/* Do not edit ! */
/* DriveLib  */

#ifndef _DRIVELIB_
#define _DRIVELIB_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
/* Constants */
#ifdef _REPLACE_CONST
 #define CMD_SWITCHED_ON 7U
 #define CMD_DISABLE_VOLTAGE 0U
 #define CMD_ENABLED 15U
 #define CMD_SHUTDOWN 6U
 #define STATE_READY 33U
 #define STATE_DISABLED 64U
 #define STATE_SWITCHED_ON 35U
 #define ST_INIT 0U
 #define ST_UNKNOWN 1U
 #define ST_OPEN 2U
 #define ST_CLOSE 3U
 #define ST_ACC_POS 4U
 #define ST_ACC_NEG 5U
 #define ST_POS 6U
 #define ST_NEG 7U
 #define ST_DEC_POS 8U
 #define ST_DEC_NEG 9U
#else
 _GLOBAL_CONST unsigned char CMD_SWITCHED_ON;
 _GLOBAL_CONST unsigned char CMD_DISABLE_VOLTAGE;
 _GLOBAL_CONST unsigned char CMD_ENABLED;
 _GLOBAL_CONST unsigned char CMD_SHUTDOWN;
 _GLOBAL_CONST unsigned char STATE_READY;
 _GLOBAL_CONST unsigned char STATE_DISABLED;
 _GLOBAL_CONST unsigned char STATE_SWITCHED_ON;
 _GLOBAL_CONST unsigned char ST_INIT;
 _GLOBAL_CONST unsigned char ST_UNKNOWN;
 _GLOBAL_CONST unsigned char ST_OPEN;
 _GLOBAL_CONST unsigned char ST_CLOSE;
 _GLOBAL_CONST unsigned char ST_ACC_POS;
 _GLOBAL_CONST unsigned char ST_ACC_NEG;
 _GLOBAL_CONST unsigned char ST_POS;
 _GLOBAL_CONST unsigned char ST_NEG;
 _GLOBAL_CONST unsigned char ST_DEC_POS;
 _GLOBAL_CONST unsigned char ST_DEC_NEG;
#endif




/* Datatypes and datatypes of function blocks */
typedef struct DriveStateMachine
{
	/* VAR_INPUT (analog) */
	unsigned short state;
	signed short speed;
	/* VAR_OUTPUT (analog) */
	unsigned short command;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DriveStateMachine_typ;

typedef struct DoorStateMachine
{
	/* VAR_OUTPUT (analog) */
	signed short speed;
	unsigned short state;
	/* VAR_INPUT (digital) */
	plcbit sw1;
	plcbit sw2;
	plcbit sw3;
	plcbit sw4;
	plcbit direction;
	/* VAR (digital) */
	plcbit osw1;
	plcbit osw2;
	plcbit osw3;
	plcbit osw4;
} DoorStateMachine_typ;

typedef struct LedStateMachine
{
	/* VAR_INPUT (analog) */
	unsigned short state;
	/* VAR_OUTPUT (analog) */
	signed short timer;
	/* VAR_OUTPUT (digital) */
	plcbit led1;
	plcbit led2;
	plcbit led3;
	plcbit led4;
} LedStateMachine_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void DriveStateMachine(struct DriveStateMachine* inst);
_BUR_PUBLIC void DoorStateMachine(struct DoorStateMachine* inst);
_BUR_PUBLIC void LedStateMachine(struct LedStateMachine* inst);


#ifdef __cplusplus
};
#endif
#endif /* _DRIVELIB_ */

