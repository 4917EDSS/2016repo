#ifndef CameraSub_H
#define CameraSub_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class CameraSub: public Subsystem
{

private:
	IMAQdxSession session;
	Image *frame;
	IMAQdxError imaqError;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	CameraSub();
	void InitDefaultCommand();
	void RunFeed();
	void StartFeed();
	void EndFeed();
};

#endif