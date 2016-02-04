#include "WPILib.h"
#include <unistd.h>
#include <iostream>

/**
 * This is a demo program showing the use of the RobotDrive class.
 * The SampleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 *
 * WARNING: While it may look like a good choice to use for your code if you're inexperienced,
 * don't. Unless you know what you are doing, complex code will be much more difficult under
 * this system. Use IterativeRobot or Command-Based instead if you're new.
 */
class Robot: public SampleRobot
{
public:
	const char *JAVA = "/home/lvuser/frc/JRE/bin/java";
	char *GRIP_ARGS[5] = { "java", "-jar", "/home/lvuser/grip.jar",
	            "/home/lvuser/project.grip", NULL };

	void RobotInit()
	{
		/* Run GRIP in a new process */
		if (fork() == 0) {
			if (execv(JAVA, GRIP_ARGS) == -1) {
				perror("Error running GRIP");
			}
		}
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
	void Autonomous()
	{

	}

	/**
	 * Runs the motors with arcade steering.
	 */
	void OperatorControl()
	{

	}

	/**
	 * Runs during test mode
	 */
	void Test()
	{
		//table = NetworkTable::GetTable("testtable");
		//std::cerr << "Putting numbers into table" << std::endl;
		//table->PutNumber("X", 1.1);
		//std::cerr << "numbers into table" << std::endl;
		//double a = table->GetNumber("X", 0);
		//a = a*2;
		//std::cerr << a << " = number out of table x2" << std::endl;
		std::shared_ptr<NetworkTable> table2 = NetworkTable::GetTable("GRIP/myContoursReport");

		std::cerr << "getting number array" << std::endl;
		std::vector<double> arr = table2->GetNumberArray("area", llvm::ArrayRef<double>());
		std::cerr << "done getting number array" << std::endl;
		for (unsigned int i = 0; i < arr.size(); i++) {
			std::cout << arr[i] << std::endl;
		}


	}
};

START_ROBOT_CLASS(Robot)
