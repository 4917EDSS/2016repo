#include "CommandBase.h"
#include "Commands/Scheduler.h"
#include "RobotMap.h"

// Initialize a single static instance of all of your subsystems to NULL
OI* CommandBase::oi = NULL;
DrivetrainSub* CommandBase::rDrivetrainSub = NULL;
IntakeSub* CommandBase::rIntakeSub = NULL;
HoodSub* CommandBase::rHoodSub = NULL;
ShooterSub* CommandBase::rShooterSub = NULL;
CameraSub* CommandBase::rCameraSub = NULL;
HopperSub* CommandBase::rHopperSub = NULL;
ClimberSub* CommandBase::rClimberSub = NULL;

CommandBase::CommandBase(const std::string &name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	rDrivetrainSub = new DrivetrainSub();
	rIntakeSub = new IntakeSub();
	rHoodSub = new HoodSub();
	rShooterSub = new ShooterSub();
	//rCameraSub = new CameraSub(); commented out to allow for better console outputs
	rHopperSub = new HopperSub();
	rClimberSub = new ClimberSub();

	//OI must be at the bottom!!
	oi = new OI();
}
float CommandBase::GetTargetDistance(){
	float centerY = GetGripValue("centerY");

	float quadraticDistance = DISTANCE_EQUATION_QA*centerY*centerY + DISTANCE_EQUATION_QB*centerY + DISTANCE_EQUATION_QC;
	//std::cout << "centerY " << centerY << std::endl;
	//std::cout << "Quadratic Distance " << quadraticDistance << " m" << std::endl;
	return quadraticDistance;
}

float CommandBase::GetGripValue(std::string gripValue)
{
	int TargetIndex = 0, widestTarget = 0;

	std::shared_ptr<NetworkTable> gripTable = NetworkTable::GetTable("GRIP/myContoursReport");

	std::vector<double> WidthArray = gripTable->GetNumberArray("width", llvm::ArrayRef<double>());

	if (WidthArray.size() < 1)
	{
		return 0.0;
	}

	for (unsigned int i = 0; i < WidthArray.size(); i++) {
		if (WidthArray[i] > widestTarget)
		{
			TargetIndex = i;
			widestTarget = WidthArray[i];
		}
	}

	std::vector<double> ValuesArray = gripTable->GetNumberArray(gripValue, llvm::ArrayRef<double>());

	return ValuesArray[TargetIndex];
}
