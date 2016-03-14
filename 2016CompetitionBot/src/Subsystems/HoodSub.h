#ifndef HoodSub_H
#define HoodSub_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class HoodSub: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Encoder* tiltEncoder;
	DigitalInput* tiltDown;
	Talon* tiltTurretMotor;
	int targetHeight;
public:
	HoodSub();
	void SetTurretTilt(float speed);
	int GetVisionHeight();
	void SetTiltHeight(int height);
	void Update(bool VisionActive);
	bool IsOnTarget();
	float GetTiltEnc();
	float GetRawTiltEnc();
	void ResetTiltEnc();
	bool GetTiltDown();
	void InitDefaultCommand();
};

#endif
