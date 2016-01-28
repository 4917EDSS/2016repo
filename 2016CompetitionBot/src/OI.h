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

//Controllers
#define DControllerDriverPort 0
#define OControllerOperatorPort 1

//Buttons
#define OIntakeBtn 1
#define OFireBtn 5
#define OLowGoalBtn 6
#define OHighGoalBtn 8


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
	JoystickButton* oFireBtn;
	JoystickButton* oLowGoalBtn;
	JoystickButton* oHighGoalBtn;

	float getStick(Joystick* stick, int axis);


public:
	OI();
	float DGetRightVer();
	float DGetLeftVer();
	float DGetLeftHor();
	float DGetRightHor();
	float OGetRightVer();
	float OGetLeftVer();
	float OGetLeftHor();
	float OGetRightHor();
};

#endif
