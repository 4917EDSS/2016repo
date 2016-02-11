#include "DrivetrainSub.h"
#include "../RobotMap.h"
#include "Commands/DriveWithJoystickCmd.h"

DrivetrainSub::DrivetrainSub(int leftMotor1C, int rightMotor1C, int leftEncoder1C, int leftEncoder2C,
		int rightEncoder1C, int rightEncoder2C, int driveLiftShift1C, int driveLiftShift2C) :
		Subsystem("DrivetrainSub")
{
	leftMotor1 = new Talon(leftMotor1C);
	//leftMotor2 = new Talon(leftMotor2C);
	rightMotor1 = new Talon(rightMotor1C);
	//rightMotor2 = new Talon(rightMotor2C);
	driveLiftShifter = new DoubleSolenoid(driveLiftShift1C, driveLiftShift2C);
	leftDistanceEncoder = new Encoder(leftEncoder1C, leftEncoder2C);
	rightDistanceEncoder = new Encoder(rightEncoder1C, rightEncoder2C);

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
	leftMotor1->Set(leftSpeed);
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
