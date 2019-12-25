

#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

void increase_counters(void);
void Homing(void);

void _INIT ProgramInit(void)
{
	//Устанваливаем типы SDC модулей
	gAxis05_HW.EncIf1_Typ = ncSDC_ENC16;
	gAxis05_HW.DiDoIf_Typ = ncSDC_DIDO;
	gAxis05_HW.DrvIf_Typ = ncSDC_DRVSERVO16;
	
	//Устанавливаем имена переменных
	strcpy(gAxis05_HW.EncIf1_Name, "gAxis05_EncIf");
	strcpy(gAxis05_HW.DrvIf_Name, "gAxis05_DrvIf");
	strcpy(gAxis05_HW.DiDoIf_Name, "gAxis05_DiDoIf");
		
	//Устанавливаем входы готовности и нормальной работы
	gAxis05_EncIf.iEncOK = 1;
	gAxis05_DrvIf.iDrvOK = 1;
	gAxis05_DrvIf.iStatusEnable = 1;
	gAxis05_DiDoIf.iDriveReady = 1;

	fb_regulator.dt = 0.002;
	fb_regulator.k_i = 0.16;
	fb_regulator.k_p = 0.0064;
	fb_regulator.max_abc_value = 24.0;
	
	pwm_period = 200;
}

void _CYCLIC ProgramCyclic(void)
{
	increase_counters();
	gAxis05_EncIf.iActTime = (INT)AsIOTimeCyclicStart();
	gAxis05_DiDoIf.iPosHwEnd = gaxis05.endswitch_a_reached;	
	gAxis05_DiDoIf.iNegHwEnd = gaxis05.endswitch_b_reached;
	
	if(coil_powered_Z == 1)
	{
		/*if(!Already_Homed)
		{
			Homing();		
		}
		else
		{*/
		increase_counters();
		gaxis05.reset_counter = 0;
		FB_Axis(&gaxis05);
		coil_pwm_value = 32767;
		gAxis05_DiDoIf.iPosHwEnd = gaxis05.endswitch_a_reached;	
		gAxis05_DiDoIf.iNegHwEnd = gaxis05.endswitch_b_reached;
		FB_Axis(&gaxis05);
		
		fb_regulator.e = (gAxis05_DrvIf.oSetPos*100)  - gaxis05.speed;//oSetPos;
		FB_Regulator(&fb_regulator);
		
		gaxis05.u = fb_regulator.u ;
		FB_Axis(&gaxis05);//}		
	}
	else
	{
		coil_pwm_value = 0;
		fb_regulator.e = 0 ;
		FB_Regulator(&fb_regulator);
		gaxis05.u = 0;
		FB_Axis(&gaxis05);
		
	}
	// COUNTER1 = axis_X.counter
	
	//COUNTER2 += axis_X.counter - COUNTER1;
}

void increase_counters(void)
{
	gAxis05_EncIf.iLifeCnt++;
	gAxis05_DiDoIf.iLifeCntDriveEnable++; 
	gAxis05_DiDoIf.iLifeCntDriveReady++; 
	gAxis05_DiDoIf.iLifeCntNegHwEnd++; 
	gAxis05_DiDoIf.iLifeCntPosHwEnd++; 
	gAxis05_DiDoIf.iLifeCntReference++;
	gAxis05_DrvIf.iLifeCnt++;
}


void Homing(void)
{/*
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
	*/
}

void _EXIT ProgramExit(void)
{
	// Insert code here 

}

