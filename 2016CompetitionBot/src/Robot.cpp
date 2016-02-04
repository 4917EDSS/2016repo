#include "WPILib.h"
#include <unistd.h>
#include <iostream>
#include "Commands/AutoGenericDuoGrp.h"
#include "Commands/AutoLowBarGrp.h"
#include "Commands/AutoPortcullisGrp.h"
#include "Commands/AutoChevalGrp.h"
#include "Commands/AutoRampartsGrp.h"
#include "Commands/AutoMoatGrp.h"
#include "Commands/AutoDrawbridgeGrp.h"
#include "Commands/AutoSallyPortGrp.h"
#include "Commands/AutoRockWallGrp.h"
#include "Commands/AutoRoughTerrainGrp.h"
#include "Commands/AutoPosition1ShootGrp.h"
#include "Commands/AutoPosition2ShootGrp.h"
#include "Commands/AutoPosition3ShootGrp.h"
#include "Commands/AutoPosition4ShootGrp.h"
#include "Commands/AutoPosition5ShootGrp.h"
#include "Commands/DriveStraightCmd.h"
#include "Commands/IntakeUntilLimitHitCmd.h"
#include "Commands/BallToIntakeCmd.h"
#include "Commands/BallToShooterCmd.h"
#include "CommandBase.h"
#include "RobotMap.h"
#include "AHRS.h"


class Robot: public IterativeRobot
{
private:
	Command* autonomousCommand;
	Command* autonomousDefenceCommand;
	Command* autonomousLocationCommand;
	SendableChooser* autoDefenceOptions;
	SendableChooser* autoLocationOptions;
	AHRS *ahrs;

	// Constants to run the GRIP process
	const char *JAVA = "/home/lvuser/frc/JRE/bin/java";
	char *GRIP_ARGS[5] = { "java", "-jar", "/home/lvuser/grip.jar",
				"/home/lvuser/project.grip", NULL };


	void RobotInit()
	{
		// Running GRIP in a new process
		// TODO:
		// THIS PROGRAM HAS YET TO WORK AS IS. Commenting out the rest of this function
		// from CommandBase::init() down to the bottom makes it work.
		if (fork() == 0) {
			if (execv(JAVA, GRIP_ARGS) == -1) {
				perror("Error running GRIP");
			}
		}

		CommandBase::init();
		//CameraServer::GetInstance()->SetQuality(50);
		//the camera name (ex "cam0") can be found through the roborio web interface
		//CameraServer::GetInstance()->StartAutomaticCapture(CAMERA_NAME);
		autoDefenceOptions = new SendableChooser();
		autoDefenceOptions->AddDefault("Low Bar Defence", new AutoLowBarGrp());
		autoDefenceOptions->AddObject("Portcullis Defence", new AutoPortcullisGrp());
		autoDefenceOptions->AddObject("Cheval De Fris", new AutoChevalGrp());
		autoDefenceOptions->AddObject("Ramparts Defence", new AutoRampartsGrp());
		autoDefenceOptions->AddObject("Moat Defence", new AutoMoatGrp());
		autoDefenceOptions->AddObject("Drawbridge Defence", new AutoDrawbridgeGrp());
		autoDefenceOptions->AddObject("Sally Port Defence", new AutoSallyPortGrp());
		autoDefenceOptions->AddObject("Rock Wall Defence", new AutoRockWallGrp());
		autoDefenceOptions->AddObject("Rough Terrain Defence", new AutoRoughTerrainGrp());
		autoDefenceOptions->AddObject("put to shooter", new BallToShooterCmd());
		autoDefenceOptions->AddObject("expel", new BallToIntakeCmd());

		autoLocationOptions = new SendableChooser();
		autoLocationOptions->AddDefault("Position 1 (Low Bar)", new AutoPosition1ShootGrp());
		autoLocationOptions->AddObject("Position 2", new AutoPosition2ShootGrp());
		autoLocationOptions->AddObject("Position 3", new AutoPosition3ShootGrp());
		autoLocationOptions->AddObject("Position 4", new AutoPosition4ShootGrp());
		autoLocationOptions->AddObject("Position 5", new AutoPosition5ShootGrp());
		autoLocationOptions->AddObject("Test Position", new IntakeUntilLimitHitCmd());


		//chooser->AddObject("My Auto", new MyAutoCommand());
		SmartDashboard::PutData("Auto Modes", autoDefenceOptions);
		SmartDashboard::PutData("Auto Modes 2", autoLocationOptions);

		// Initialize the navX-mxp IMU (accelerometer, gyro, compass)
#if ENABLE_IMU
		ahrs = new AHRS(SerialPort::kUSB); // Options are:  SerialPort::kMXP, SPI::kMXP, I2C::kMXP or SerialPort::kUSB
#endif

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
			autonomousCommand = new MyAutoCommand();
		} else {
			autonomousCommand = new ExampleCommand();
		} */

		autonomousDefenceCommand = (Command *)autoDefenceOptions->GetSelected();
		autonomousLocationCommand = (Command *)autoLocationOptions->GetSelected();
		autonomousCommand = new AutoGenericDuoGrp(autonomousDefenceCommand, autonomousLocationCommand);


		autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
		SmartDashboard::PutNumber("Left Wheel dis Encoder", CommandBase::rDrivetrainSub->GetLeftEnc());
		SmartDashboard::PutNumber("Right Wheel dis Encoder", CommandBase::rDrivetrainSub->GetRightEnc());
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
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		// The following NetworkTable code does not need to live in Robot.cpp. This is just to prove it works.
		// Network table looking up the contours report
		std::shared_ptr<NetworkTable> gripTable = NetworkTable::GetTable("GRIP/myContoursReport");
		std::cerr << "Getting contours area array." << std::endl;
		std::vector<double> arr = gripTable->GetNumberArray("area", llvm::ArrayRef<double>());
		std::cerr << "Done getting number array. Array values are as follows: " << std::endl;
		for (unsigned int i = 0; i < arr.size(); i++) {
			std::cout << arr[i] << std::endl;
		}

		LiveWindow::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(Robot)

