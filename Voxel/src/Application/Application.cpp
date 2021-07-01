#include "Application.h"

#include <thread>
#include <chrono>

Application::Application(uint32_t width, uint32_t height, const char* title, std::unique_ptr<Renderer> renderer)
	:_window(std::make_unique<Window>(width, height, title)), _running(true), _renderer(std::move(renderer))
{
	_window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
}

void Application::Init()
{
}

void Application::Run()
{
	while (!ShouldClose())
	{
		Process();
		HandleEvents();
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(10ms);
	}
}

void Application::Process()
{ 
}

void Application::Close()
{
	_window->WindowClose();
	_running = false;
}

bool Application::ShouldClose() const
{
	return _window->ShouldClose() || !_running;
}

void Application::OnEvent(std::shared_ptr<Event> event)
{
	if (!event->_handled)
		_unhandledEvents.push(event);
}

void Application::HandleEvents()
{
	std::queue<std::shared_ptr<Event>> missingEvents;

	for (uint32_t i = 0; i < _unhandledEvents.size(); ++i)
	{
		auto event = _unhandledEvents.front();
		_unhandledEvents.pop();

		EventDispatcher dispatcher(*event.get());

		dispatcher.Dispatch<WindowCloseEvent >(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));
		dispatcher.Dispatch<WindowResizeEvent>(std::bind(&Application::OnWindowResize, this, std::placeholders::_1));
		dispatcher.Dispatch<MouseMovedEvent  >(std::bind(&Application::OnMouseMoved, this, std::placeholders::_1));
		dispatcher.Dispatch<KeyPressedEvent  >(std::bind(&Application::OnKeyPressed, this, std::placeholders::_1));
		dispatcher.Dispatch<KeyReleasedEvent >(std::bind(&Application::OnKeyReleased, this, std::placeholders::_1));
		dispatcher.Dispatch<KeyRepeatEvent   >(std::bind(&Application::OnKeyRepeat, this, std::placeholders::_1));

		if (!event->_handled)
		{
			missingEvents.push(event);
			//LOG_WARN("Not Handled: " + event->ToString());
		}
		else
		{
			//LOG_INFO("Handled: " + event->ToString());
		}
	}

	for (uint32_t i = 0; i < _unhandledEvents.size(); ++i)
	{
		missingEvents.push(_unhandledEvents.front());
		_unhandledEvents.pop();
	}

	_unhandledEvents.swap(missingEvents);
}

bool Application::OnWindowClose(WindowCloseEvent& event)
{
	Close();
	return true;
}

bool Application::OnWindowResize(WindowResizeEvent& event)
{
	_window->WindowResize(event.GetWidth(), event.GetHeight());
	return true;
}

bool Application::OnMouseMoved(MouseMovedEvent& event)
{
	return true;
}

bool Application::OnKeyPressed(KeyPressedEvent& event)
{
	return true;
}

bool Application::OnKeyReleased(KeyReleasedEvent& event)
{
	return true;
}

bool Application::OnKeyRepeat(KeyRepeatEvent& event)
{
	return true;
}

Application::~Application()
{
}