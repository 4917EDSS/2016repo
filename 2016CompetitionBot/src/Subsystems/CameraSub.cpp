#include "CameraSub.h"
#include "../RobotMap.h"
#include "../Commands/CameraUpdateCmd.h"

CameraSub::CameraSub() :
		Subsystem("ExampleSubsystem")
{
	 // create an image
		frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
		//the camera name (ex "cam0") can be found through the roborio web interface
		imaqError = IMAQdxOpenCamera(CAMERA_NAME, IMAQdxCameraControlModeController, &session);
		if(imaqError != IMAQdxErrorSuccess) {
			DriverStation::ReportError("IMAQdxOpenCamera error: " + std::to_string((long)imaqError) + "\n");
		}
		imaqError = IMAQdxConfigureGrab(session);
		if(imaqError != IMAQdxErrorSuccess) {
			DriverStation::ReportError("IMAQdxConfigureGrab error: " + std::to_string((long)imaqError) + "\n");
		}
}

void CameraSub::InitDefaultCommand()
{
	SetDefaultCommand(new CameraUpdateCmd());// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void CameraSub::RunFeed()
{
	IMAQdxGrab(session, frame, true, NULL);
	if(imaqError != IMAQdxErrorSuccess) {
		DriverStation::ReportError("IMAQdxGrab error: " + std::to_string((long)imaqError) + "\n");
	} else {
		imaqDrawShapeOnImage(frame, frame, { 10, 10, 100, 100 }, DrawMode::IMAQ_DRAW_VALUE, ShapeMode::IMAQ_SHAPE_OVAL, 0.0f);
		CameraServer::GetInstance()->SetImage(frame);
	}
}

void CameraSub::StartFeed()
{
	IMAQdxStartAcquisition(session);
}

void CameraSub::EndFeed()
{
	IMAQdxStopAcquisition(session);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
