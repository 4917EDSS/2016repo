#include "DrivetrainSub.h"
#include "../RobotMap.h"
#include "Commands/DriveWithJoystickCmd.h"
#include "Components/PidAhrs.h"

DrivetrainSub::DrivetrainSub() :
		Subsystem("DrivetrainSub")
{
	leftMotor = new Talon(LeftDrive1PWM);
	rightMotor = new Talon(RightDrive1PWM);
	driveLiftShifter = new DoubleSolenoid(ShifterSolenoid1PNC, ShifterSolenoid2PNC);
	leftDistanceEncoder = new Encoder(LeftDriveEncoder1DIO, LeftDriveEncoder2DIO);
	rightDistanceEncoder = new Encoder(RightDriveEncoder1DIO, RightDriveEncoder2DIO);
	leftDistanceEncoder->SetDistancePerPulse(DISTANCE_PER_PULSE_EV*ENCODER_CONVERSION_FACTOR);
	rightDistanceEncoder->SetDistancePerPulse(DISTANCE_PER_PULSE_EV*ENCODER_CONVERSION_FACTOR);
	motorBalancer = new MotorBalancer();
	motorTurner = new MotorBalancer();

	// Initialize the navX-mxp IMU (accelerometer, gyro, compass, aka Attitude Heading Reference System)
	ahrs = new AHRS(AHRSInterface); // Options are:  SerialPort::kMXP, SPI::kMXP, I2C::kMXP or SerialPort::kUSB
	if(!ahrs){
		std::cerr << "ahrs not connecting";
	}
	else{
		std::cerr << "ahrs connected";
	}

	Preferences *prefs = Preferences::GetInstance();
	driveBalanceController = new PIDController(prefs->GetFloat("DriveBalanceP", DRIVE_BALANCE_P),
											   prefs->GetFloat("DriveBalanceI", DRIVE_BALANCE_I),
											   prefs->GetFloat("DriveBalanceD", DRIVE_BALANCE_D),
											   new PidAhrs(ahrs), motorBalancer);
	driveBalanceController->SetAbsoluteTolerance(prefs->GetFloat("DriveBalanceTolerance", DRIVE_BALANCE_TOLERANCE));
	driveBalanceController->SetOutputRange(-1.0, 1.0);
	driveBalanceController->Disable();

	driveTurnController = new PIDController(prefs->GetFloat("DriveTurnP", DRIVE_TURN_P),
											prefs->GetFloat("DriveTurnI", DRIVE_TURN_I),
											prefs->GetFloat("DriveTurnD", DRIVE_TURN_D),
											new PidAhrs(ahrs), motorTurner);
	driveTurnController->SetAbsoluteTolerance(prefs->GetFloat("DriveTurnTolerance", DRIVE_TURN_TOLERANCE));
	driveTurnController->SetOutputRange(-1.0, 1.0);
	driveTurnController->Disable();

	controlState = TANK_DRIVE_CONTROLS;
	accelThreshold = ACCELERATION_THRESHOLD;

	LiveWindow::GetInstance()->AddActuator("Drivetrain", "leftMotor1", leftMotor);
	LiveWindow::GetInstance()->AddSensor("Drivetrain", "leftDistanceEncoder", leftDistanceEncoder);
	LiveWindow::GetInstance()->AddActuator("Drivetrain", "rightMotor", rightMotor);
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
	leftMotor->Set(-leftSpeed);
	rightMotor->Set(rightSpeed);
}

void DrivetrainSub::EnableBalancerPID(float setPoint){
	Preferences *prefs = Preferences::GetInstance();
	driveBalanceController->SetPID(prefs->GetFloat("DriveBalanceP", DRIVE_BALANCE_P), prefs->GetFloat("DriveBalanceI", DRIVE_BALANCE_I), prefs->GetFloat("DriveBalanceD", DRIVE_BALANCE_D));
	driveBalanceController->SetAbsoluteTolerance(prefs->GetFloat("DriveBalanceTolerance", DRIVE_BALANCE_TOLERANCE));
	driveBalanceController->SetSetpoint(setPoint);
	motorBalancer->Reset();
	driveBalanceController->Enable();
}

void DrivetrainSub::DisableBalancerPID(){
	driveBalanceController->Disable();
}

void DrivetrainSub::PIDDrive(float speed)
{
	leftMotor->Set(-speed - motorBalancer->GetDifference());
	rightMotor->Set(speed - motorBalancer->GetDifference());
}

void DrivetrainSub::EnableTurnPID(float setPoint){
	Preferences *prefs = Preferences::GetInstance();
	driveTurnController->SetPID(prefs->GetFloat("DriveTurnP", DRIVE_TURN_P), prefs->GetFloat("DriveTurnI", DRIVE_TURN_I), prefs->GetFloat("DriveTurnD", DRIVE_TURN_D));
	driveTurnController->SetAbsoluteTolerance(prefs->GetFloat("DriveTurnTolerance", DRIVE_TURN_TOLERANCE));
	driveTurnController->SetSetpoint(setPoint);
	driveTurnController->Enable();
	std::cout << "PID" << driveTurnController->GetP() << " " << driveTurnController->GetI()<< " " << driveTurnController->GetD()<< std::endl;
}

void DrivetrainSub::DisableTurnPID(){
	driveTurnController->Disable();
}

void DrivetrainSub::PIDTurn()
{
	std::cout << motorTurner->GetDifference() << std::endl;
	leftMotor->Set(-motorTurner->GetDifference());
	rightMotor->Set(-motorTurner->GetDifference());
}

bool DrivetrainSub::IsTurnFinished(){
	return driveTurnController->OnTarget();
}

bool DrivetrainSub::GetTryingToDrive() {
	return leftMotor->Get() != 0 || rightMotor->Get() != 0;
}

float DrivetrainSub::GetYaw(){
	return ahrs->GetYaw();
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

AHRS* DrivetrainSub::GetAHRS() {
	return ahrs;
}

void DrivetrainSub::ResetDrive(){
	// This also resets the virtual speed encoders
	leftDistanceEncoder->Reset();
	rightDistanceEncoder->Reset();
	motorBalancer->Reset();
	if(ahrs)
	{
		ahrs->ZeroYaw();
	}
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
