#pragma once

#include <iostream>
#include <queue>

#include "../EventSystem/Event.h"
#include "../EventSystem/WindowEvent.h"
#include "../EventSystem/MouseEvent.h"
#include "../EventSystem/KeyEvent.h"

#include "../Renderer/Renderer.h"
#include "../Renderer/Layer.h"

struct ApplicationCommandArgs
{
	int argc;
	char** argv;
};

class Application
{
public:
	Application(uint32_t width, uint32_t height, const char* title, ApplicationCommandArgs cmdArgs,
		std::unique_ptr<Renderer> renderer = nullptr);
	virtual ~Application();

	virtual void Init();
	virtual void OnUpdate(float timeStep);

	void Run();
	void Close();
	bool ShouldClose() const;

	void HandleEvents();
	void OnEvent(std::shared_ptr<Event> event);

protected:
	LayerStack _layerStack;
	std::unique_ptr<Window>	_window;
	std::unique_ptr<Renderer> _renderer;
	std::string _workingDirectory;

	virtual bool OnWindowClose(WindowCloseEvent& event);
	virtual bool OnWindowResize(WindowResizeEvent& event);
	virtual bool OnMouseMoved(MouseMovedEvent& event);
	virtual bool OnKeyPressed(KeyPressedEvent& event);
	virtual bool OnKeyReleased(KeyReleasedEvent& event);
	virtual bool OnKeyRepeat(KeyRepeatEvent& event);
	virtual void ParseCommandLineArgs(ApplicationCommandArgs cmdArgs);

	void EnableEventRecycling() { _eventRecycling = true; }

private:
	bool _running;
	bool _eventRecycling;
	std::queue<std::shared_ptr<Event>> _unhandledEvents;
};