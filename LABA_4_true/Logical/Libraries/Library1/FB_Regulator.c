
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library1.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_Regulator(struct FB_Regulator* inst)
{
	float BON(float x)
	{
		if(x < 0)
		{
			if(x < -inst->max_abc_value)
				return -inst->max_abc_value;
			else
				return x;
		}
		else
		{
			if(x > inst->max_abc_value)
				return inst->max_abc_value;
			else
				return x;
		}
			
		
	}
	inst->integrator.in = inst->e * inst->k_i * inst->dt + inst->iyOld;
	FB_Integrator(&inst->integrator);
	inst->u = BON((BON(inst->e * inst->k_p) + inst->integrator.out));
	
	inst->iyOld = inst->u - (BON(inst->e * inst->k_p) + inst->integrator.out);
}
