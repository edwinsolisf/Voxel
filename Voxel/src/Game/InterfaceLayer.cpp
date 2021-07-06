#include "InterfaceLayer.h"

InterfaceLayer::InterfaceLayer(Renderer& renderer, Window& window)
	:_renderer(renderer), _window(window)
{
	_widget.Init();
}

void InterfaceLayer::OnAttach()
{

}

void InterfaceLayer::OnDettach()
{

}

void InterfaceLayer::OnUpdate()
{
	_widget.OnRender(_renderer, _window);
}

void InterfaceLayer::OnEvent(std::shared_ptr<Event> event)
{
	//EventDispatcher dispatcher(*event);

	//dispatcher.Dispatch<MouseMovedEvent>(std::bind(&InterfaceLayer::OnMousedHover, this, std::placeholders::_1));
}

InterfaceLayer::~InterfaceLayer()
{

}