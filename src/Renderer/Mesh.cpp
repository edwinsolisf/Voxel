#include "Mesh.h"

std::shared_ptr<VertexArray> Mesh::_vao;
bool Mesh::_init = false;

Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<Index>& indices, const std::vector<std::string>& textures)
	://_vao(std::make_shared<VertexArray>(Vertex::GetLayout())),
	 _vbo(std::make_shared<VertexBuffer>(vertices.data(), vertices.size() * sizeof(Vertex))),
	 _ibo(std::make_shared<IndexBuffer>(indices.data(), indices.size()))
{
	if (!_init)
	{
		_vao = std::make_shared<VertexArray>(Vertex::GetLayout());
		_init = true;
	}


	for (const auto& textureFile : textures)
		_texture.emplace_back(std::make_shared<Texture>(textureFile));
}

void Mesh::SetUpMesh() const
{
	_vao->Bind();
	_vbo->Bind();
	_ibo->Bind();

	for (uint32_t i = 0; i < _texture.size(); ++i)
		_texture[i]->Bind(i);
}