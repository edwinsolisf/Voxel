#pragma once

#include <stm/math.h>
#include "RendererCore.h"

struct Vertex
{
public:
	static VertexBufferLayout GetLayout();
	Vertex() {}

	Vertex(const stm::vec3f& pos, const stm::vec2f& coords, uint8_t tex)
		:position(pos), texcoords(coords), texture(tex) {}

	stm::vec3f position;
	stm::vec2f texcoords;
	float texture = 0.0f;
};

using Index = uint32_t;