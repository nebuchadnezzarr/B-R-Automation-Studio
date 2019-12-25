

#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

void increase_counters(void);
void Homing(void);

void _INIT ProgramInit(void)
{
	//Устанваливаем типы SDC модулей
	gAxis03_HW.EncIf1_Typ = ncSDC_ENC16;
	gAxis03_HW.DiDoIf_Typ = ncSDC_DIDO;
	gAxis03_HW.DrvIf_Typ = ncSDC_DRVSERVO16;
	
	//Устанавливаем имена переменных
	strcpy(gAxis03_HW.EncIf1_Name, "gAxis03_EncIf");
	strcpy(gAxis03_HW.DrvIf_Name, "gAxis03_DrvIf");
	strcpy(gAxis03_HW.DiDoIf_Name, "gAxis03_DiDoIf");
		
	//Устанавливаем входы готовности и нормальной работы
	gAxis03_EncIf.iEncOK = 1;
	gAxis03_DrvIf.iDrvOK = 1;
	gAxis03_DrvIf.iStatusEnable = 1;
	gAxis03_DiDoIf.iDriveReady = 1;

	fb_regulator.dt = 0.002;
	fb_regulator.k_i = 0.16;
	fb_regulator.k_p = 0.0064;
	fb_regulator.max_abc_value = 24.0;
	
	pwm_period = 200;
}

void _CYCLIC ProgramCyclic(void)
{
	increase_counters();
	gAxis03_EncIf.iActTime = (INT)AsIOTimeCyclicStart();
	gAxis03_DiDoIf.iPosHwEnd = gaxis03.endswitch_a_reached;	
	gAxis03_DiDoIf.iNegHwEnd = gaxis03.endswitch_b_reached;
	
	if(coil_powered_Y == 1)
	{
		/*if(!Already_Homed)
		{
			Homing();		
		}
		else
		{*/
		increase_counters();
		gaxis03.reset_counter = 0;
		FB_Axis(&gaxis03);
		coil_pwm_value = 32767;
		gAxis03_DiDoIf.iPosHwEnd = gaxis03.endswitch_a_reached;	
		gAxis03_DiDoIf.iNegHwEnd = gaxis03.endswitch_b_reached;
		FB_Axis(&gaxis03);
		
		fb_regulator.e = (gAxis03_DrvIf.oSetPos*100)  - gaxis03.speed;//oSetPos;
		FB_Regulator(&fb_regulator);
		
		gaxis03.u = fb_regulator.u ;
		FB_Axis(&gaxis03);//}		
	}
	else
	{
		coil_pwm_value = 0;
		fb_regulator.e = 0 ;
		FB_Regulator(&fb_regulator);
		gaxis03.u = 0;
		FB_Axis(&gaxis03);
		
	}
	// COUNTER1 = axis_X.counter
	
	//COUNTER2 += axis_X.counter - COUNTER1;
}

void increase_counters(void)
{
	gAxis03_EncIf.iLifeCnt++;
	gAxis03_DiDoIf.iLifeCntDriveEnable++; 
	gAxis03_DiDoIf.iLifeCntDriveReady++; 
	gAxis03_DiDoIf.iLifeCntNegHwEnd++; 
	gAxis03_DiDoIf.iLifeCntPosHwEnd++; 
	gAxis03_DiDoIf.iLifeCntReference++;
	gAxis03_DrvIf.iLifeCnt++;
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

