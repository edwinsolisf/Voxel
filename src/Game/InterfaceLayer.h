#pragma once

#include "../Renderer/Layer.h"
#include "../Renderer/RendererCore.h"

#include "../Widgets/Widget.h"

class InterfaceLayer : public Layer
{
public:
	InterfaceLayer(Renderer& renderer, Window& window);
	~InterfaceLayer();

	void OnUpdate() override;
	void OnEvent(std::shared_ptr<Event> event) override;
	void OnAttach() override;
	void OnDettach() override;

private:
	Window& _window;
	Renderer& _renderer;
	Widget _widget;
};