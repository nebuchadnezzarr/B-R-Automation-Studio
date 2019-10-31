
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC ProgramCyclic(void)
{
	DoorStateMachine(&DoorSM);
	DriveSM.speed = DoorSM.speed;
	DriveStateMachine(&DriveSM);
	LedSM.state = DoorSM.state;
	LedStateMachine(&LedSM);
	/*
	DriveSM.speed = 250;
	DriveStateMachine(&DriveSM);
*/
}
