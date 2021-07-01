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
	virtual void Draw() const;
	void BindShader(std::shared_ptr<Shader> shader) { _boundShader = shader; }
	auto GetBoundShader() const { return _boundShader; }

private:
	std::vector<Mesh> _queue;
	std::shared_ptr<Shader> _boundShader;
};
