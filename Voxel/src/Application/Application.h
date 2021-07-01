#pragma once

#include <iostream>
#include <queue>

#include "../EventSystem/Event.h"
#include "../EventSystem/WindowEvent.h"
#include "../EventSystem/MouseEvent.h"
#include "../EventSystem/KeyEvent.h"

#include "../Renderer/Renderer.h"

class Application
{
public:
	Application(uint32_t width, uint32_t height, const char* title, std::unique_ptr<Renderer> renderer = nullptr);
	virtual ~Application();

	virtual void Init();
	virtual void Process();
	void Run();
	void Close();
	bool ShouldClose() const;

	void HandleEvents();
	void OnEvent(std::shared_ptr<Event> event);

protected:
	std::unique_ptr<Window>	_window;
	std::unique_ptr<Renderer> _renderer;

	virtual bool OnWindowClose(WindowCloseEvent& event);
	virtual bool OnWindowResize(WindowResizeEvent& event);
	virtual bool OnMouseMoved(MouseMovedEvent& event);
	virtual bool OnKeyPressed(KeyPressedEvent& event);
	virtual bool OnKeyReleased(KeyReleasedEvent& event);
	virtual bool OnKeyRepeat(KeyRepeatEvent& event);

private:
	bool _running;
	std::queue<std::shared_ptr<Event>> _unhandledEvents;
};