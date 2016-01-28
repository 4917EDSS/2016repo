#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "AHRS.h"

class Robot: public IterativeRobot
{
	AHRS *ahrs = NULL;

private:
	std::unique_ptr<Command> autonomousCommand;
	SendableChooser *chooser;

	void RobotInit()
	{
		CommandBase::init();
		chooser = new SendableChooser();
		chooser->AddDefault("Default Auto", new ExampleCommand());
		//chooser->AddObject("My Auto", new MyAutoCommand());
		SmartDashboard::PutData("Auto Modes", chooser);

		ahrs = new AHRS(SerialPort::Port::kUSB);
	}

	/**
     * This function is called once each time the robot enters Disabled mode.
     * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
     */
	void DisabledInit()
	{
	}

	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString code to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional commands to the chooser code above (like the commented example)
	 * or additional comparisons to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit()
	{
		/* std::string autoSelected = SmartDashboard::GetString("Auto Selector", "Default");
		if(autoSelected == "My Auto") {
			autonomousCommand.reset(new MyAutoCommand());
		} else {
			autonomousCommand.reset(new ExampleCommand());
		} */

		autonomousCommand.reset((Command *)chooser->GetSelected());

		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
	}

	void TeleopPeriodic()
	{
		if( ahrs )
		{
			SmartDashboard::PutBoolean( "IMU_Connected", ahrs->IsConnected());
			SmartDashboard::PutNumber(  "IMU_Yaw",              ahrs->GetYaw());
			SmartDashboard::PutNumber(  "IMU_Pitch",            ahrs->GetPitch());
			SmartDashboard::PutNumber(  "IMU_Roll",             ahrs->GetRoll());
			SmartDashboard::PutNumber(  "IMU_CompassHeading",   ahrs->GetCompassHeading());
			SmartDashboard::PutNumber(  "IMU_Update_Count",     ahrs->GetUpdateCount());
			SmartDashboard::PutNumber(  "IMU_Byte_Count",       ahrs->GetByteCount());

			/* These functions are compatible w/the WPI Gyro Class */
			SmartDashboard::PutNumber(  "IMU_TotalYaw",         ahrs->GetAngle());
			SmartDashboard::PutNumber(  "IMU_YawRateDPS",       ahrs->GetRate());

			SmartDashboard::PutNumber(  "IMU_Accel_X",          ahrs->GetWorldLinearAccelX());
			SmartDashboard::PutNumber(  "IMU_Accel_Y",          ahrs->GetWorldLinearAccelY());
			SmartDashboard::PutBoolean( "IMU_IsMoving",         ahrs->IsMoving());
			SmartDashboard::PutNumber(  "IMU_Temp_C",           ahrs->GetTempC());
			SmartDashboard::PutBoolean( "IMU_IsCalibrating",    ahrs->IsCalibrating());

			SmartDashboard::PutNumber(  "Velocity_X",           ahrs->GetVelocityX() );
			SmartDashboard::PutNumber(  "Velocity_Y",           ahrs->GetVelocityY() );
			SmartDashboard::PutNumber(  "Displacement_X",       ahrs->GetDisplacementX() );
			SmartDashboard::PutNumber(  "Displacement_Y",       ahrs->GetDisplacementY() );

		}




		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		LiveWindow::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(Robot)

