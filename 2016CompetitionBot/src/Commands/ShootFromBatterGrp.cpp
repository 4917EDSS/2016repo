#include "RobotMap.h"
#include "ShootFromBatterGrp.h"
#include "SetHoodHeightCmd.h"
#include "SetTurretRotateCmd.h"

ShootFromBatterGrp::ShootFromBatterGrp(int side)
{
	AddParallel(new SetHoodHeightCmd(BATTER_WALL_HOOD_HEIGHT, false));
	if (side == LEFT_SIDE) {
		AddParallel(new SetTurretRotateCmd(BATTER_WALL_TURRET_ENC_LEFT, true));
	} else {
		AddParallel(new SetTurretRotateCmd(BATTER_WALL_TURRET_ENC_RIGHT, true));
	}
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
