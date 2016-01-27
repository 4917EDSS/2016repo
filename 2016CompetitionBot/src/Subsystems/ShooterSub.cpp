#include "ShooterSub.h"
#include "../Commands/SpinupCmd.h"
#include "../Commands/ControlTurretWithJoystickCmd.h"
#include "../RobotMap.h"
#include "../Components/Encoder4917.h"

ShooterSub::ShooterSub(int shooterMotorC, int shooterEncoder1C, int shooterEncoder2C, int turretRotateC, int turretTiltC) :
		Subsystem("ExampleSubsystem")
{
	spinnerMotor = new Talon(shooterMotorC);
	rotateTurretMotor = new Talon(turretRotateC);
	tiltTurretMotor = new Talon(turretTiltC);

	shooterEncoder = new  Encoder4917(shooterEncoder1C, shooterEncoder2C);


}


void ShooterSub::Spin(float spinSpeed)
{
	spinnerMotor->Set(spinSpeed);
}

void ShooterSub::SetTurretRotate(float speed)
{
	rotateTurretMotor->Set(speed);
}

void ShooterSub::SetTurretTilt(float speed)
{
	tiltTurretMotor->Set(speed);
}

void ShooterSub::InitDefaultCommand()
{
	SetDefaultCommand(new ControlTurretWithJoystickCmd());
	//SetDefaultCommand(new SpinupCmd());

	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
