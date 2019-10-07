#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

void _CYCLIC ProgramCyclic(void)
{
	if(enable)
	{
		count+=10;
		if(count<=2500)
		{
			speed=0;
		}
		else
		{
			speed=6;
			if(count>=5000)
			{
				count=0;
			}
		}
	}
	fb_regulator.e=speed - fb_motor.w;
	fb_motor2.u=speed;
	FB_Regulator(&fb_regulator);
	fb_motor.u=fb_regulator.u;
	FB_Motor(&fb_motor);
	FB_Motor(&fb_motor2);
}