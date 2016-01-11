#include "OI.h"
#include "RobotMap.h"


OI::OI()
{
	dController = new Joystick(DControllerDriverPort);

	// Process operator interface input here.
}

float OI::getStick(Joystick* controller, int axis){
	float rawInput = controller->GetRawAxis(axis);
	if (axis > CONTROLLER_DEADZONE_VALUE)
	{
		return (rawInput*fabs(rawInput));
	}
	else
	{
		return 0.0;
	}
}

float OI::DGetRightVer(){
	return -getStick(dController, DRightVerticalAxis);
}

float OI::DGetLeftVer(){
	return -getStick(dController, DLeftVerticalAxis);
}

float OI::DGetLeftHor(){
	return getStick(dController, DLeftHorizontalAxis);
}

float OI::DGetRightHor(){
	return getStick(dController, DRightHorizontalAxis);
}

