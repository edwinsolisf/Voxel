#include "OpenGLWindow.h"
#include "OpenGLCallback.h"
#include "stb/stb_image.h"

OpenGLWindow::OpenGLWindow(uint32_t width, uint32_t height, const char* title)
	:CoreWindow(width, height, title), _window(nullptr)
{
	if (!(InitializedGLFW = InitializeGLFW()))
	{
		throw; 
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_RESIZABLE, false);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	_window = glfwCreateWindow(_width, _height, title, nullptr, nullptr);
	glfwMakeContextCurrent(_window);

	if (!(InitializedGLEW = InitializeGLEW()))
	{
		throw;
	}

	WindowInfo();

	GLFWimage icon;
	icon.pixels = stbi_load("assets/images/icon.png", &icon.width, &icon.height, nullptr, 4);
	glfwSetWindowIcon(_window, 1, &icon);
	stbi_image_free(icon.pixels);

	glfwSetWindowUserPointer(_window, &_windowData);

	glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwSetKeyCallback(_window, OpenGLKeyCallback);
	glfwSetCursorPosCallback(_window, OpenGLMouseMoveCallback);
	glfwSetWindowSizeCallback(_window, OpenGLWindowResizeCallback);
	glfwSetWindowCloseCallback(_window, OpenGLWindowCloseCallback);
	
	_lastFrame = glfwGetTime();
}

bool OpenGLWindow::ShouldClose() const
{
	return glfwWindowShouldClose(_window);
}

void OpenGLWindow::WindowClose()
{
	GLCALL(glfwSetWindowShouldClose(_window, true));
}

void OpenGLWindow::WindowInfo() const
{
	LOG_INFO("GLFW " + std::string(glfwGetVersionString()));
	LOG_INFO("OpenGL " + std::string((char*)glGetString(GL_VERSION)));
	LOG_INFO((char*)glGetString(GL_VENDOR));
	LOG_INFO((char*)glGetString(GL_RENDERER));

	LOG_INFO("Window: " + std::to_string(_width) + "x" + std::to_string(_height) + " " + _title);

	GLFWmonitor** monitors = nullptr;
	int32_t monitorCount = 0;

	monitors = glfwGetMonitors(&monitorCount);
	for (uint32_t i = 0; i < monitorCount; ++i)
	{
		GLFWmonitor* monitor = monitors[i];
		int32_t monitorWidth = 0, monitorHeight = 0;
		glfwGetMonitorWorkarea(monitor, nullptr, nullptr, &monitorWidth, &monitorHeight);
		LOG_INFO(std::string(glfwGetMonitorName(monitor)) + " " + std::to_string(monitorWidth) + "x" + std::to_string(monitorHeight));
	}

	LOG_INFO((glfwVulkanSupported() ? "Vulkan supported" : "Vulkan not supported"));
}

void OpenGLWindow::WindowResize(uint32_t width, uint32_t height)
{
	_width = width;
	_height = height;
	GLCALL(glViewport(0, 0, width, height));
}

void OpenGLWindow::WindowClear()
{
	//GLCALL(glEnable(GL_CULL_FACE));
	//GLCALL(glCullFace(GL_FRONT));
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	GLCALL(glEnable(GL_DEPTH_TEST));
	GLCALL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
	GLCALL(glClearColor(0.3f, 0.4f, 0.8f, 1.0f));
}

float OpenGLWindow::GetCurrentFrameTime()
{
	_lastFrame = glfwGetTime();
	return _lastFrame;
}

void OpenGLWindow::OnUpdate()
{
	GLCALL(glfwSwapBuffers(_window));
	GLCALL(glfwPollEvents());
}

OpenGLWindow::~OpenGLWindow()
{
	glfwDestroyWindow(_window);
	_window = nullptr;
	glfwTerminate();
	InitializedGLFW = false;
}