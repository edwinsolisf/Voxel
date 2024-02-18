#pragma once

#include <vector>
#include <memory>

#include "../EventSystem/Event.h"

class Layer
{
public:
	Layer() {}
	virtual ~Layer() {}

	virtual void OnEvent(std::shared_ptr<Event> event) {}
	virtual void OnUpdate() {}
	virtual void OnAttach() {}
	virtual void OnDettach() {}
};

class LayerStack
{
public:
	LayerStack();
	~LayerStack();

	void PushLayer(std::shared_ptr<Layer> layer);
	void PopLayer(std::shared_ptr<Layer> layer);
	void PushOverlay(std::shared_ptr<Layer> layer);
	void PopOverlay(std::shared_ptr<Layer> layer);

	std::vector<std::shared_ptr<Layer>>::iterator begin() { return _layers.begin(); }
	std::vector<std::shared_ptr<Layer>>::iterator end() { return _layers.end(); }

private:
	std::vector<std::shared_ptr<Layer>> _layers;
	uint32_t _layerOffset = 0;
};