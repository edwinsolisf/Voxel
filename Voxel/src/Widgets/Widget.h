#pragma once

#include "stm/vector2.h"
#include "../Renderer/Renderer.h"

class Widget
{
public:
	Widget();
	void Init();
	void Begin();
	void End();
	void OnRender(Renderer& renderer, Window& window);

	~Widget();

private:
	std::shared_ptr<Shader> _shader;
	std::shared_ptr<Texture> _texture;
	std::shared_ptr<VertexArray> _vao;
	
	stm::vec2i _pos;
	uint32_t _width, _height;
};