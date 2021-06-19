#pragma once

#include <iostream>

#include "../Renderer/Renderer.h"
#include "../Game/VoxelRenderer.h"

class Application
{
public:
	Application(uint32_t width, uint32_t height, const char* title);
	~Application();

	bool ShouldClose() const;
	void Init();
	void Close() const;
	void Run();

private:
	Window*		_window;
	//static Renderer renderer;
	VoxelRenderer renderer;
};