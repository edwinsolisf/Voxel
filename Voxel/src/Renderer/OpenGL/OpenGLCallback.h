#pragma once

#include "OpenGLCore.h"
#include "../../Game/Player.h"
#include "stm/matrix_transform.h"

void SetPlayer(Player*);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

void mouse_callback(GLFWwindow* window, double xpos, double ypos);

void movement(GLFWwindow* window);