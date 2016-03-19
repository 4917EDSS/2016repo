#include "AutoMoatGrp.h"
#include "RobotMap.h"
#include "DriveStraightCmd.h"
#include "IntakeUntilLimitHitCmd.h"
#include "ZeroTurretTiltEncCmd.h"
#include "SetIntakeHeightCmd.h"

AutoMoatGrp::AutoMoatGrp()
{
	AddParallel (new ZeroTurretTiltEncCmd());
	AddParallel(new DriveStraightCmd(CROSS_BASIC_DEFENSE_DISTANCE, CROSS_BASIC_DEFENSE_SPEED));
	AddSequential (new IntakeUntilLimitHitCmd());
	AddParallel (new SetIntakeHeightCmd(SIMPLE_DEFENSE_INTAKE_HEIGHT_EV));

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
