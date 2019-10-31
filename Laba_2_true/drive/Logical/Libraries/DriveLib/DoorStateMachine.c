
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "DriveLib.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void DoorStateMachine(struct DoorStateMachine* inst)
{
	inst->direction=!inst->direction;
	
	//State init
	/*if(inst->sw1==0 && inst->sw2==0 && inst->sw3==0 && inst->sw4==0)
	{
		inst->state = ST_INIT;
	}
	if(inst->state == ST_INIT)
	{
		
		inst->state = ST_UNKNOWN;
	}
	//state unknown
	if(inst->state == ST_UNKNOWN)
	{
		inst->state = ST_CLOSE ;		
	}*/
	
	//открытие двери
	if(/*inst->state == ST_CLOSE &&*/ inst->sw1 != inst->osw1 && inst->direction==0)
	{
		inst->state = ST_ACC_POS ;
		inst->speed = -200;
	}
	
	if(/*inst->state == ST_ACC_POS &&*/ inst->sw2 != inst->osw2 && inst->direction == 0)
	{
		inst->state = ST_POS ;
		inst->speed = -600;
	}
	
	if(/*inst->state == ST_POS  &&*/ inst->sw3 != inst->osw3 && inst->direction == 0)
	{
		inst->state = ST_DEC_POS;
		inst->speed = -200;
	}
	
	if(/*inst->state == ST_DEC_POS &&*/ inst->sw4 != inst->osw4 && inst->direction == 0)
	{
		inst->state = ST_OPEN;
		inst->speed = 0;
	}
	
	//закрытие двери
	if(/*inst->state == ST_OPEN &&*/ inst->sw4 != inst->osw4 && inst->direction==1)
	{
		inst->state = ST_ACC_NEG;
		inst->speed = 200;
	}
	
	if(/*inst->state == ST_ACC_NEG &&*/ inst->sw3 != inst->osw3 && inst->direction == 1)
	{
		inst->state = ST_NEG;
		inst->speed = 600;
	}
	
	if(/*inst->state == ST_NEG &&*/ inst->sw2 != inst->osw2 && inst->direction == 1)
	{
		inst->state = ST_DEC_NEG;
		inst->speed = 200;
	}
	
	if(/*inst->state == ST_DEC_NEG &&*/ inst->sw1 != inst->osw1 && inst->direction == 1)
	{
		inst->state = ST_CLOSE;
		inst->speed = 0;
	}
	inst->osw1 = inst->sw1;
	inst->osw2 = inst->sw2;
	inst->osw3 = inst->sw3;
	inst->osw4 = inst->sw4;
	
	

	
}
