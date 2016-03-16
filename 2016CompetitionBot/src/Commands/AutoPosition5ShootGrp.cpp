#include "AutoPosition5ShootGrp.h"
#include "RobotMap.h"
#include "Commands/PrepareShotCmd.h"
#include "Commands/BallToShooterCmd.h"
#include "Commands/DriveStraightCmd.h"
#include "Commands/DriveTurnCmd.h"

AutoPosition5ShootGrp::AutoPosition5ShootGrp()
{
	AddParallel(new PrepareShotCmd());
	AddSequential(new DriveStraightCmd(POSITION_FIVE_APPROACH_DISTANCE, CROSS_BASIC_DEFENSE_SPEED));
	AddSequential(new DriveTurnCmd(POSITION_FIVE_TURN_TO_SHOOT));
	AddSequential(new WaitCommand(AIM_TIME_AUTO));
	AddSequential(new BallToShooterCmd());
	AddSequential(new DriveTurnCmd(POSITION_FIVE_TURN_TO_DEFENCE));
	AddSequential(new DriveStraightCmd(-POSITION_FIVE_APPROACH_DISTANCE, CROSS_BASIC_DEFENSE_SPEED));

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
