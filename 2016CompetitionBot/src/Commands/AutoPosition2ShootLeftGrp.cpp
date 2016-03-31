#include "AutoPosition2ShootLeftGrp.h"
#include "RobotMap.h"
#include "Commands/PrepareShotCmd.h"
#include "Commands/BallToShooterGrp.h"
#include "Commands/DriveStraightCmd.h"
#include "Commands/DriveTurnCmd.h"

AutoPosition2ShootLeftGrp::AutoPosition2ShootLeftGrp()

{
	AddParallel(new PrepareShotCmd());
	AddSequential(new DriveStraightCmd(POSITION_TWO_LEFT_APPROACH_DISTANCE, CROSS_BASIC_DEFENSE_SPEED));
	AddSequential(new DriveTurnCmd(POSITION_TWO_LEFT_TURN_TO_SHOOT));
	AddSequential(new WaitCommand(AIM_TIME_AUTO));
	AddSequential(new BallToShooterGrp());
	AddSequential(new DriveTurnCmd(POSITION_TWO_LEFT_TURN_TO_DEFENCE));
	AddSequential(new DriveStraightCmd(-POSITION_TWO_LEFT_APPROACH_DISTANCE, CROSS_BASIC_DEFENSE_SPEED));
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
