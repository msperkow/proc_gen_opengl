#ifndef PROC_GEN_OPENGL_CAMERA_CONTROL_FRAME_HPP
#define PROC_GEN_OPENGL_CAMERA_CONTROL_FRAME_HPP


#include "frame.hpp"
#include "camera_type.hpp"
#include "camera_view.hpp"
#include "rendering_mode.hpp"

class CameraControlFrame : public Frame
{
private:
	void mainDraw() override;
	CameraType cameraType;
	RenderingMode renderingMode;

	//frame buffer variables
	float mouseSensitivity;
	float fov; //degrees!!
	float drawDistance;
	float speed;
	float xpos;
	float ypos;
	float zpos;
public:
	CameraControlFrame(CameraView *view, const std::string &name);
};


#endif //PROC_GEN_OPENGL_CAMERA_CONTROL_FRAME_HPP