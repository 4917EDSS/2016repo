#include "OI.h"
#include "RobotMap.h"
#include "Commands/DriveTurnCmd.h"
#include "Commands/FireCmd.h"
#include "Commands/BallToIntakeCmd.h"
#include "Commands/BallToShooterCmd.h"
#include "Commands/ToggleDriveLiftCmd.h"
#include "Commands/PrepareShotCmd.h"
#include "Commands/LowBarTransformCmd.h"
#include "Commands/IntakeUntilLimitHitCmd.h"

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

	oIntakeUntilLimitBtn = new JoystickButton(oController, OIntakeUntilLimitBtn);
	oIntakeUntilLimitBtn->WhenPressed(new IntakeUntilLimitHitCmd);


	//oIntakeBtn = new JoystickButton(oController, OIntakeBtn);
	//oIntakeBtn->WhenPressed(new IntakeUntilLimitHitCmd());


	// Process operator interface input here.
}

float OI::getStick(Joystick* controller, int axis, float sensitivity){
	float rawInput = controller->GetRawAxis(axis);
	float adjustedInput = pow(fabs(rawInput), sensitivity);
	if (rawInput > CONTROLLER_DEADZONE_VALUE)
	{
		return adjustedInput;
	}
	else if(rawInput < -CONTROLLER_DEADZONE_VALUE)
	{
		return -adjustedInput;
	}
	else
	{
		return 0.0;
	}
}

float OI::DGetRightVer(float sensitivity){
	return -getStick(dController, DRightVerticalAxis, sensitivity);
}

float OI::DGetLeftVer(float sensitivity){
	return -getStick(dController, DLeftVerticalAxis, sensitivity);
}

float OI::DGetLeftHor(float sensitivity){
	return getStick(dController, DLeftHorizontalAxis, sensitivity);
}

float OI::DGetRightHor(float sensitivity){
	return getStick(dController, DRightHorizontalAxis, sensitivity);
}

float OI::OGetRightVer(float sensitivity){
	return -getStick(oController, ORightVerticalAxis, sensitivity);
}

float OI::OGetLeftVer(float sensitivity){
	return -getStick(oController, OLeftVerticalAxis, sensitivity);
}

float OI::OGetLeftHor(float sensitivity){
	return getStick(oController, OLeftHorizontalAxis, sensitivity);
}

float OI::OGetRightHor(float sensitivity){
	return getStick(oController, ORightHorizontalAxis, sensitivity);
}

int OI::OGetPov() {
	return oController->GetPOV();
}
