#include "AutoPosition3ShootRightGrp.h"
#include "RobotMap.h"
#include "Commands/PrepareShotCmd.h"
#include "Commands/BallToShooterGrp.h"
#include "Commands/DriveStraightCmd.h"
#include "Commands/DriveTurnCmd.h"

AutoPosition3ShootRightGrp::AutoPosition3ShootRightGrp()
{
	AddParallel(new PrepareShotCmd());
	AddSequential(new DriveTurnCmd(POSITION_THREE_RIGHT_TURN_TO_APPROACH));
	AddSequential(new DriveStraightCmd(POSITION_THREE_RIGHT_APPROACH_DISTANCE, CROSS_FAST_DEFENSE_SPEED));
	AddSequential(new DriveTurnCmd(POSITION_THREE_RIGHT_TURN_TO_SHOOT));
	AddSequential(new WaitCommand(AIM_TIME_AUTO));
	AddSequential(new BallToShooterGrp());
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
