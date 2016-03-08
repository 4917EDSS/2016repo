#include "AutoLowBarGrp.h"
#include "RobotMap.h"
#include "DriveStraightCmd.h"
#include "IntakeUntilLimitHitGrp.h"
#include "ZeroTurretTiltEncCmd.h"

AutoLowBarGrp::AutoLowBarGrp()
{
	AddParallel (new IntakeUntilLimitHitGrp());
	AddParallel (new ZeroTurretTiltEncCmd());
	AddSequential(new DriveStraightCmd(CROSS_LOW_BAR_FAST_DISTANCE, LOW_BAR_DEFENSE_SPEED));
	AddSequential(new DriveStraightCmd(CROSS_LOW_BAR_DISTANCE, CROSS_BASIC_DEFENSE_SPEED));
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
