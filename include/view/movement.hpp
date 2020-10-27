#ifndef PROC_GEN_OPENGL_MOVEMENT_HPP
#define PROC_GEN_OPENGL_MOVEMENT_HPP


#include <SDL_events.h>
#include "camera_controller.hpp"

class Movement
{
protected:
public:
	virtual void processInput(SDL_Event& e, CameraController* cameraController) = 0;
};


#endif //PROC_GEN_OPENGL_MOVEMENT_HPP
