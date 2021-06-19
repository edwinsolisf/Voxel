#include "OpenGLCallback.h"

static bool keys[1024];
static bool firstMouse = true;
static double lastX, lastY;
static float sensitivity = 0.005f;
static float step = 0.1f;

static Player* player;
void SetPlayer(Player* g_Player)
{
    player = g_Player;
}

void movement(GLFWwindow* window)
{
    if (keys[GLFW_KEY_ESCAPE])
        glfwSetWindowShouldClose(window, GL_TRUE);
    if (keys[GLFW_KEY_W])
        player->MoveForward(step);
    if (keys[GLFW_KEY_S])
        player->MoveForward(-step);
    if (keys[GLFW_KEY_A])
        player->MoveRight(-step);
    if (keys[GLFW_KEY_D])
        player->MoveRight(step);
    if (keys[GLFW_KEY_SPACE])
        player->MoveUp(step);
    if (keys[GLFW_KEY_LEFT_SHIFT])
        player->MoveUp(-step);
    if (keys[GLFW_KEY_UP])
        player->RotatePitch(step);
    if (keys[GLFW_KEY_DOWN])
        player->RotatePitch(-step);
    if (keys[GLFW_KEY_LEFT])
        player->RotateYaw(step);
    if (keys[GLFW_KEY_RIGHT])
        player->RotateYaw(-step);
    if (keys[GLFW_KEY_Q])
        player->RotateRoll(-step);
    if (keys[GLFW_KEY_E])
        player->RotateRoll(step);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = lastX - xpos, yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;

    player->RotatePitch(yoffset * sensitivity);
    player->RotateYaw(xoffset * sensitivity);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (action == GLFW_PRESS)
        keys[key] = true;
    else if (action == GLFW_RELEASE)
        keys[key] = false;
}