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
	virtual void DrawQuad(std::shared_ptr<VertexBuffer>, std::shared_ptr<IndexBuffer>, std::shared_ptr<Texture>, const stm::mat4f& transform) const;
	void BindShader(std::shared_ptr<Shader> shader) { _boundShader = shader; _boundShader->Bind(); }
	auto GetBoundShader() const { return _boundShader; }

private:
	std::vector<Mesh> _queue;
	std::shared_ptr<Shader> _boundShader;
};
