
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_Axis(struct FB_Axis* inst)
{
	if (inst->endswitch_a_reached == 1 )
	{
		inst->dir = 1;
	}
	if (inst->endswitch_b_reached == 1 )
	{	
		inst->dir = 0;	
	}
	
		
	if(inst->dir == 1)
	{
		//inst->reset_counter = 0;
		inst->u = -inst->u;
		inst->pwm_value = (inst->u/24.0) * 32767;	
	}
	if(inst->dir == 0)
	{
		//inst->reset_counter = 0;
		inst->pwm_value = (inst->u/24.0) * 32767;
	}
	if (inst->i == 1000)		
	{
		inst->speed = (inst->counter - inst->last_counter)/2;	
		inst->last_counter = inst->counter;
		inst->i = 0;
	}
	inst->spid = inst->speed;
	inst->i++;
}
