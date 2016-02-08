#include "OI.h"
#include "RobotMap.h"
#include "Commands/DriveTurnCmd.h"
#include "Commands/FireCmd.h"
#include "Commands/BallToIntakeCmd.h"
#include "Commands/BallToShooterCmd.h"
#include "Commands/ToggleDriveLiftCmd.h"
#include "Commands/PrepareShotCmd.h"
#include "Commands/LowBarTransformCmd.h"

OI::OI()
{
	dController = new Joystick(DControllerDriverPort);
	oController = new Joystick(OControllerOperatorPort);

	oFlywheelSpinBtn = new JoystickButton(oController, OFlywheelSpinBtn);
	oFlywheelSpinBtn->WhileHeld(new FireCmd);

	oLowGoalBtn = new JoystickButton(oController, OLowGoalBtn);
	oLowGoalBtn->WhenPressed(new BallToIntakeCmd);

	oHighGoalBtn = new JoystickButton(oController, OHighGoalBtn);
	oHighGoalBtn->WhenPressed(new BallToShooterCmd);

	dLiftShifterBtn = new JoystickButton(dController, DLiftShifterBtn);
	dLiftShifterBtn->WhenPressed(new ToggleDriveLiftCmd);

	oPrepareShotBtn = new JoystickButton (oController, OPrepareShotBtn);
	oPrepareShotBtn->WhileHeld(new PrepareShotCmd);

	oLowBarTransformBtn = new JoystickButton(oController, OLowBarTransformBtn);
	oLowBarTransformBtn->WhenPressed(new LowBarTransformCmd);

	//oIntakeBtn = new JoystickButton(oController, OIntakeBtn);
	//oIntakeBtn->WhenPressed(new IntakeUntilLimitHitCmd());


	// Process operator interface input here.
}

float OI::getStick(Joystick* controller, int axis){
	float rawInput = controller->GetRawAxis(axis);
	if (rawInput > CONTROLLER_DEADZONE_VALUE)
	{
		return (rawInput*fabs(rawInput));
	}
	else if(rawInput < -CONTROLLER_DEADZONE_VALUE)
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

float OI::OGetRightVer(){
	return -getStick(oController, ORightVerticalAxis);
}

float OI::OGetLeftVer(){
	return -getStick(oController, OLeftVerticalAxis);
}

float OI::OGetLeftHor(){
	return getStick(oController, OLeftHorizontalAxis);
}

float OI::OGetRightHor(){
	return getStick(oController, ORightHorizontalAxis);
}
