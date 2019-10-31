
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
void LedStateMachine(struct LedStateMachine* inst)
{
	
	if(inst->state == ST_ACC_POS)
	{
		inst->led1 = 0;
		if(inst->timer == 3 )
		{
			inst->led2 = !inst->led2;  
		}
		inst->led3 = 1;
		inst->led4 = 1;
	}
	
	if(inst->state == ST_POS)
	{
		inst->led1 = 0;
		inst->led2 = 0;
		inst->led3 = !inst->led3;   
		inst->led4 = 1;
	}
	
	if(inst->state == ST_DEC_POS)
	{
		
		inst->led1 = 0;
		inst->led2 = 0;  
		inst->led3 = 0;  
		if(inst->timer == 3 )
		{
			inst->led4 = !inst->led4;  
		}  
	}
	
	if(inst->state == ST_OPEN)
	{
		inst->led1 = 0;
		inst->led2 = 0;  
		inst->led3 = 0;  
		inst->led4 = 0; 
	}
	
	//закрытие двери
	if(inst->state == ST_ACC_NEG )
	{
		inst->led1 = 0;
		inst->led2 = 0;  
		if(inst->timer == 3 )
		{
			inst->led3 = !inst->led3;  
		}  
		inst->led4 = 1; 
	}
	
	if(inst->state == ST_NEG)
	{
		inst->led1 = 0;
		inst->led2 =!inst->led2;
		inst->led3 = 1;  
		inst->led4 = 1;  
	}
	
	if(inst->state == ST_DEC_NEG )
	{
		if(inst->timer == 3 )
		{
			inst->led1 = !inst->led1;  
		}   
		inst->led2 = 1; 
		inst->led3 = 1;  
		inst->led4 = 1; 
	}
	
	if(inst->state == ST_CLOSE)
	{
		inst->led1 = 1;  
		inst->led2 = 1;  
		inst->led3 = 1;  
		inst->led4 = 1; 
	}
	
	if(inst->timer == 3)
		inst->timer = 0;
	
	
	inst->timer++;
}
