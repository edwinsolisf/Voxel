#include "Layer.h"

LayerStack::LayerStack()
{
}

void LayerStack::PushLayer(std::shared_ptr<Layer> layer)
{
	layer->OnAttach();
	_layers.emplace(_layers.begin() + _layerOffset, layer);
	++_layerOffset;
}

void LayerStack::PopLayer(std::shared_ptr<Layer> layer)
{
	auto it = std::find(_layers.cbegin(), _layers.cbegin() + _layerOffset, layer);
	if (it != (_layers.cbegin() + _layerOffset))
	{
		(*it)->OnDettach();
		_layers.erase(it);
		--_layerOffset;
	}
}

void LayerStack::PushOverlay(std::shared_ptr<Layer> layer)
{
	layer->OnAttach();
	_layers.emplace_back(layer);
}

void LayerStack::PopOverlay(std::shared_ptr<Layer> layer)
{
	auto it = std::find(_layers.cbegin(), _layers.cend(), layer);
	if (it != _layers.cend())
	{
		(*it)->OnDettach();
		_layers.erase(it);
	}
}

LayerStack::~LayerStack()
{
	for (auto& layer : _layers)
	{
		layer->OnDettach();
	}
}