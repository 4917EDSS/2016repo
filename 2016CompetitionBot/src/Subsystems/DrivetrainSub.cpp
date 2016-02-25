#include "DrivetrainSub.h"
#include "../RobotMap.h"
#include "Commands/DriveWithJoystickCmd.h"

DrivetrainSub::DrivetrainSub() :
		Subsystem("DrivetrainSub")
{
	leftMotor1 = new Talon(LeftDrive1PWM);
	rightMotor1 = new Talon(RightDrive1PWM);
	driveLiftShifter = new DoubleSolenoid(ShifterSolenoid1PNC, ShifterSolenoid2PNC);
	leftDistanceEncoder = new Encoder(LeftDriveEncoder1DIO, LeftDriveEncoder2DIO);
	rightDistanceEncoder = new Encoder(RightDriveEncoder1DIO, RightDriveEncoder2DIO);

	controlState = TANK_DRIVE_CONTROLS;
	accelThreshold = ACCELERATION_THRESHOLD;

	LiveWindow::GetInstance()->AddActuator("Drivetrain", "leftMotor1", leftMotor1);
	LiveWindow::GetInstance()->AddSensor("Drivetrain", "leftDistanceEncoder", leftDistanceEncoder);
	LiveWindow::GetInstance()->AddActuator("Drivetrain", "rightMotor1", rightMotor1);
	LiveWindow::GetInstance()->AddSensor("Drivetrain", "rightDistanceEncoder", rightDistanceEncoder);
	LiveWindow::GetInstance()->AddActuator("Drivetrain", "driveLiftShifter", driveLiftShifter);
}

void DrivetrainSub::InitDefaultCommand()
{
	SetDefaultCommand(new DriveWithJoystickCmd());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void DrivetrainSub::Drive(float leftSpeed, float rightSpeed)
{
	leftMotor1->Set(-leftSpeed);
	//leftMotor2->Set(leftSpeed);
	rightMotor1->Set(rightSpeed);
	//rightMotor2->Set(rightSpeed);
}

void DrivetrainSub::ToggleControls(){
	if(controlState == FPS_DRIVE_CONTROLS){
		controlState = TANK_DRIVE_CONTROLS;
	}
	else{
		controlState = FPS_DRIVE_CONTROLS;
	}
}
int DrivetrainSub::GetControls()
{
	return controlState;
}

float DrivetrainSub::GetAccelThresh()
{
	return accelThreshold;
}

void DrivetrainSub::SetAccelThresh(float accelThresh)
{
	accelThreshold = accelThresh;
}

int DrivetrainSub::GetRawLeftEnc(){
	return (int) leftDistanceEncoder->GetRaw();
}

int DrivetrainSub::GetLeftEnc(){
	return (int) leftDistanceEncoder->GetDistance();
}

int DrivetrainSub::GetRawRightEnc(){
	return (int) rightDistanceEncoder->GetRaw();
}

int DrivetrainSub::GetRightEnc(){
	return (int) rightDistanceEncoder->GetDistance();
}

void DrivetrainSub::ShiftDrive(bool isDrive){
	if (isDrive)
	{
		driveLiftShifter->Set(DoubleSolenoid::kForward);
	}
	else
	{
		driveLiftShifter->Set(DoubleSolenoid::kReverse);
	}
}

bool DrivetrainSub::GetGear(){
	if (driveLiftShifter->Get() == DoubleSolenoid::kForward)
	{
		return IS_DRIVE;
	}
	else
	{
		return IS_SHIFTER;
	}

}

void DrivetrainSub::ResetDrive(){
	// This also resets the virtual speed encoders
	leftDistanceEncoder->Reset();
	rightDistanceEncoder->Reset();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
