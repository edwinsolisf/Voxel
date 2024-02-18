#pragma once

#include "RendererCore.h"
#include "Vertex.h"

class Mesh
{
public:
	Mesh(const std::vector<Vertex>&, const std::vector<Index>&, const std::vector<std::string>&);

	uint32_t GetVertexCount() const { return _ibo->GetIndexCount(); }
	uint32_t GetTextureCount() const { return _texture.size(); }

	const std::vector<std::shared_ptr<Texture>>& GetTextures() const { return _texture; }

	void SetUpMesh() const;
private:
	static std::shared_ptr<VertexArray>	_vao;
	static bool _init;
	std::shared_ptr<VertexBuffer>	_vbo;
	std::shared_ptr<IndexBuffer>	_ibo;
	std::vector<std::shared_ptr<Texture>>		_texture;
};