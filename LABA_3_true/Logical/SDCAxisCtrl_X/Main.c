
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void increase_counters(void);
void Homing(void);

void _INIT ProgramInit(void)
{
	//Устанваливаем типы SDC модулей
	AxisX_HW.EncIf1_Typ = ncSDC_ENC16;
	AxisX_HW.DiDoIf_Typ = ncSDC_DIDO;
	AxisX_HW.DrvIf_Typ = ncSDC_DRVSERVO16;
	
	//Устанавливаем имена переменных
	strcpy(AxisX_HW.EncIf1_Name, "AxisX_EncIf");
	strcpy(AxisX_HW.DrvIf_Name, "AxisX_DrvIf");
	strcpy(AxisX_HW.DiDoIf_Name, "AxisX_DiDoIf");
		
	//Устанавливаем входы готовности и нормальной работы
	AxisX_EncIf.iEncOK = 1;
	AxisX_DrvIf.iDrvOK = 1;
	AxisX_DrvIf.iStatusEnable = 1;
	AxisX_DiDoIf.iDriveReady = 1;

	fb_regulator.dt = 0.002;
	fb_regulator.k_i = 0.16;
	fb_regulator.k_p = 0.0064;
	fb_regulator.max_abc_value = 24.0;
	
	pwm_period = 200;
}

void _CYCLIC ProgramCyclic(void)
{
	increase_counters();
	AxisX_EncIf.iActTime = (INT)AsIOTimeCyclicStart();
	iPosHwEnd = axis_X.endswitch_a_reached;	
	iNegHwEnd = axis_X.endswitch_b_reached;
	
	if(coil_powered == 1)
	{
		if(!Already_Homed)
		{
			Homing();		
		}
		else
		{
			increase_counters();
			axis_X.reset_counter = 0;
			FB_Axis(&axis_X);
			coil_pwm_value = 32767;
			iPosHwEnd = axis_X.endswitch_a_reached;	
			iNegHwEnd = axis_X.endswitch_b_reached;
			FB_Axis(&axis_X);
		
			fb_regulator.e = (AxisX_DrvIf.oSetPos*10)  - axis_X.speed;//oSetPos;
			FB_Regulator(&fb_regulator);
		
			axis_X.u = fb_regulator.u ;
			FB_Axis(&axis_X);}		
	}
	else
	{
		coil_pwm_value = 0;
		fb_regulator.e = 0 ;
		FB_Regulator(&fb_regulator);
		axis_X.u = 0;
		FB_Axis(&axis_X);
		
	}
	// COUNTER1 = axis_X.counter
	
	//COUNTER2 += axis_X.counter - COUNTER1;
}

void increase_counters(void)
{
	AxisX_EncIf.iLifeCnt++;
	AxisX_DiDoIf.iLifeCntDriveEnable++; 
	AxisX_DiDoIf.iLifeCntDriveReady++; 
	AxisX_DiDoIf.iLifeCntNegHwEnd++; 
	AxisX_DiDoIf.iLifeCntPosHwEnd++; 
	AxisX_DiDoIf.iLifeCntReference++;
	AxisX_DrvIf.iLifeCnt++;
}


void Homing(void)
{
	increase_counters();
	coil_pwm_value = 32767;
	iPosHwEnd = axis_X.endswitch_a_reached;	
	iNegHwEnd = axis_X.endswitch_b_reached;
	FB_Axis(&axis_X);
		
	fb_regulator.e = (AxisX_DrvIf.oSetPos * 10) - axis_X.speed;//oSetPos;
	FB_Regulator(&fb_regulator);
		
	axis_X.u = fb_regulator.u ;
	FB_Axis(&axis_X);	
	if (iPosHwEnd)
	{
		coil_pwm_value = 0;
		fb_regulator.e = 0;
		FB_Regulator(&fb_regulator);
		axis_X.u = 0;
		FB_Axis(&axis_X);
		axis_X.reset_counter = 1;
		FB_Axis(&axis_X);
		if(k == 200) 
		{
			Already_Homed = 1;
			FB_Axis(&axis_X);
		}
		k++;
			
	}
	
}

void _EXIT ProgramExit(void)
{
	// Insert code here 

}

