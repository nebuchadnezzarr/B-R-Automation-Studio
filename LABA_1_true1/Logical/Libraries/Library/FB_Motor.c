
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif
/* motor */
void FB_Motor(struct FB_Motor* inst)
{
	inst->integrator.in=(inst->u/inst->Ke-inst->w)*inst->dt/inst->Tm;
	inst->integrator.out=inst->w;
	FB_Integrator(&(inst->integrator));
	inst->w=inst->integrator.out;
	inst->integrator.in=inst->w*inst->dt;
	inst->integrator.out=inst->phi;
	FB_Integrator(&(inst->integrator));
	inst->phi=inst->integrator.out;
}