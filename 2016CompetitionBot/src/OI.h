#ifndef OI_H
#define OI_H

#include "WPILib.h"

/*
 * ON LOGITECH CONTROLLER:
 * X = 1
 * A = 2
 * B = 3
 * Y = 4
 * LB = 5
 * RB = 6
 * LT = 7
 * RT = 8
 * Select = 9
 * Start = 10
 * L3 = 11
 * R3 = 12
 * Left Vertical = 1
 * Left Horizontal = 0
 * Right Vertical = 3
 * Right Horizontal = 2
 *
 */

// D = driver controller
// O = operator controller

//Controllers
#define DControllerDriverPort 0
#define OControllerOperatorPort 1

//Buttons
#define OIntakeBtn 1
#define OFlywheelSpinBtn 5
#define OLowGoalBtn 6
#define OHighGoalBtn 8
#define DLiftShifterBtn 5
#define OPrepareShotBtn 2
#define OLowBarTransformBtn 7
#define OIntakeUntilLimitBtn 3
#define OEmergencyStopBtn1 11
#define DEmergencyStopBtn1 11
#define OEmergencyStopBtn2 12
#define DEmergencyStopBtn2 12

//Axis
#define DRightVerticalAxis 3
#define DLeftVerticalAxis 1
#define DRightHorizontalAxis 2
#define DLeftHorizontalAxis 0

#define ORightVerticalAxis 3
#define OLeftVerticalAxis 1
#define ORightHorizontalAxis 2
#define OLeftHorizontalAxis 0


#define CONTROLLER_DEADZONE_VALUE 0.001


class OI
{
private:


	Joystick* dController;
	Joystick* oController;
	JoystickButton* oFlywheelSpinBtn;
	JoystickButton* oLowGoalBtn;
	JoystickButton* oHighGoalBtn;
	JoystickButton* dLiftShifterBtn;
	JoystickButton* oPrepareShotBtn;
	JoystickButton* oLowBarTransformBtn;
	JoystickButton* oIntakeUntilLimitBtn;
	JoystickButton* oEmergencyStopBtn1;
	JoystickButton* dEmergencyStopBtn1;
	JoystickButton* oEmergencyStopBtn2;
	JoystickButton* dEmergencyStopBtn2;
	float getStick(Joystick* stick, int axis, float sensitivity);


public:
	OI();
	float DGetRightVer(float sensitivity);
	float DGetLeftVer(float sensitivity);
	float DGetLeftHor(float sensitivity);
	float DGetRightHor(float sensitivity);
	float OGetRightVer(float sensitivity);
	float OGetLeftVer(float sensitivity);
	float OGetLeftHor(float sensitivity);
	float OGetRightHor(float sensitivity);
	int OGetPov();
};

#endif
