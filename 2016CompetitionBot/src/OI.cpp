#include "OI.h"
#include "RobotMap.h"
#include "Commands/DriveTurnCmd.h"
#include "Commands/SpinupCmd.h"
#include "Commands/BallToIntakeCmd.h"
#include "Commands/BallToShooterCmd.h"
#include "Commands/ToggleDriveLiftCmd.h"
#include "Commands/PrepareShotCmd.h"
#include "Commands/LowBarTransformCmd.h"
#include "Commands/IntakeUntilLimitHitCmd.h"
#include "Commands/EmergencyStopCmd.h"

OI::OI()
{
	dController = new Joystick(DControllerDriverPort);
	oController = new Joystick(OControllerOperatorPort);

	oFlywheelSpinBtn = new JoystickButton(oController, OFlywheelSpinBtn);
	oFlywheelSpinBtn->WhileHeld(new SpinupCmd);

	oLowGoalBtn = new JoystickButton(oController, OLowGoalBtn);
	oLowGoalBtn->WhenPressed(new BallToIntakeCmd);

	oHighGoalBtn = new JoystickButton(oController, OHighGoalBtn);
	oHighGoalBtn->WhenPressed(new BallToShooterCmd);

	dLiftShifterBtn = new JoystickButton(dController, DLiftShifterBtn);
	dLiftShifterBtn->WhenPressed(new ToggleDriveLiftCmd);

	oPrepareShotBtn = new JoystickButton (oController, OPrepareShotBtn);
	oPrepareShotBtn->WhenPressed(new PrepareShotCmd);

	oLowBarTransformBtn = new JoystickButton(oController, OLowBarTransformBtn);
	oLowBarTransformBtn->WhenPressed(new LowBarTransformCmd);

	oIntakeUntilLimitBtn = new JoystickButton(oController, OIntakeUntilLimitBtn);
	oIntakeUntilLimitBtn->WhenPressed(new IntakeUntilLimitHitCmd);

	//Emergency Stop commands.
	oEmergencyStopBtn1 = new JoystickButton(oController, OEmergencyStopBtn1);
	oEmergencyStopBtn1->WhenPressed(new EmergencyStopCmd);

	dEmergencyStopBtn1 = new JoystickButton(oController, DEmergencyStopBtn1);
	dEmergencyStopBtn1->WhenPressed(new EmergencyStopCmd);

	oEmergencyStopBtn2 = new JoystickButton(oController, OEmergencyStopBtn2);
	oEmergencyStopBtn2->WhenPressed(new EmergencyStopCmd);

	dEmergencyStopBtn2 = new JoystickButton(oController, DEmergencyStopBtn2);
	dEmergencyStopBtn2->WhenPressed(new EmergencyStopCmd);
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
