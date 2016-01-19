#include "AutoParameterizedDriveCmd.h"

#define DEFAULT_LEFT_SPEED	0.5		// Range -1.0 to 1.0
#define DEFAULT_RIGHT_SPEED 0.5		// Range -1.0 to 1.0
#define DEFAULT_RUN_TIME 	2.0		// In seconds


AutoParameterizedDriveCmd::AutoParameterizedDriveCmd()
{
	remainingTicks = 0;

	// Use Requires() here to declare subsystem dependencies
	Requires(drivetrainSub);
}

// Called just before this Command runs the first time
void AutoParameterizedDriveCmd::Initialize()
{
	float leftSpeed;
	float rightSpeed;
	float runTime;
	Preferences *prefs = Preferences::GetInstance();

	leftSpeed = prefs->GetFloat("AutoLeftSpeed", DEFAULT_LEFT_SPEED);
	rightSpeed = prefs->GetFloat("AutoRightSpeed", DEFAULT_RIGHT_SPEED);

	// Running for a set time is generally bad but will work for this example
	runTime = prefs->GetFloat("RunTime", DEFAULT_RUN_TIME);
	// Using the scheduler as a timer is even worse... but this is just a test
	remainingTicks = runTime * 50; // ~50 ticks per second

	drivetrainSub->Drive(leftSpeed, rightSpeed);
}

// Called repeatedly when this Command is scheduled to run
void AutoParameterizedDriveCmd::Execute()
{
	remainingTicks--;
}

// Make this return true when this Command no longer needs to run execute()
bool AutoParameterizedDriveCmd::IsFinished()
{
	if( remainingTicks > 0 )
	{
		return false;
	}
	else
	{
		return false;
	}
}

// Called once after isFinished returns true
void AutoParameterizedDriveCmd::End()
{
	remainingTicks = 0;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoParameterizedDriveCmd::Interrupted()
{
	remainingTicks = 0;
}

