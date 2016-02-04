#include "WPILib.h"
#include "NetworkTables/NetworkTable.h"
#include <iostream>
#include <exception>

class Robot: public IterativeRobot
{
private:
	LiveWindow *lw = LiveWindow::GetInstance();
	SendableChooser *chooser;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";
	std::string autoSelected;
	NetworkTable* table;

	void RobotInit()
	{
		chooser = new SendableChooser();
		chooser->AddDefault(autoNameDefault, (void*)&autoNameDefault);
		chooser->AddObject(autoNameCustom, (void*)&autoNameCustom);
		SmartDashboard::PutData("Auto Modes", chooser);
		table = NetworkTable::GetTable("datatable").get();
	}



	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString line to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional comparisons to the if-else structure below with additional strings.
	 * If using the SendableChooser make sure to add them to the chooser code above as well.
	 */
	void AutonomousInit()
	{
		autoSelected = *((std::string*)chooser->GetSelected());
		//std::string autoSelected = SmartDashboard::GetString("Auto Selector", autoNameDefault);
		std::cout << "Auto selected: " << autoSelected << std::endl;

		if(autoSelected == autoNameCustom){
			//Custom Auto goes here
		} else {
			//Default Auto goes here
		}
	}

	void AutonomousPeriodic()
	{
		if(autoSelected == autoNameCustom){
			//Custom Auto goes here
		} else {
			//Default Auto goes here
		}
	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		double x = 0;
		double y = 0;
		while(true) {
			std::cerr << "AJGNSGBJAVAD JVADV JAJ VAOJVD AKJDV AKJVD KDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD" << std::endl;
			Wait(1.0);
			if (table != NULL){
				std::cerr << "I am not NULL!!" << std::endl;
			}
			table->Flush();

			std::cerr << "!!!!!!!!!!!!!!!111111111111!!!!!!!!" << std::endl;

			try {
				table->PutNumber("X", x);
			} catch (std::exception& e) {
				std::cerr << "exception" << std::endl;
			} catch (...) {
				std::cerr << "Something else" << std::endl;
			}
			std::cerr << "22222222222222222" << std::endl;

			table->PutNumber("Y", y);
			std::cerr << "33333333333333333333333" << std::endl;
			x += 0.25;
			y += 0.25;
		}

	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
