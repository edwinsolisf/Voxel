#pragma once

#include <stm/math.h>
#include "RendererCore.h"

struct Vertex
{
public:
	static VertexBufferLayout GetLayout();
	Vertex() {}

	Vertex(const stm::vec3f& pos, const stm::vec2f& tex)
		:position(pos), texcoords(tex) {}

	stm::vec3f position;
	stm::vec2f texcoords;
};

using Index = uint32_t;