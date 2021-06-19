#pragma once

#include "RendererCore.h"
#include "Vertex.h"
#include "Mesh.h"

class Renderer
{
public:
	Renderer();

	void Push(const Mesh& mesh) { _queue.push_back(mesh); }
	void Clear() { _queue.clear(); }
	void Draw() const;

private:
	std::vector<Mesh> _queue;
};
