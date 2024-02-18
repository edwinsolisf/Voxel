#include "Renderer.h"

Renderer::Renderer()
	:_boundShader(nullptr)
{
}

void Renderer::Draw() const
{
	for (const auto& mesh : _queue)
	{
		mesh.SetUpMesh();
		for (uint32_t i = 0; i < mesh.GetTextureCount(); ++i)
		{
			const auto& texture = mesh.GetTextures()[i];
			texture->Bind(i);
			_boundShader->SetUniform1i("u_texture_" + std::to_string(i + 1), i);
		}
		OpenGLDraw(mesh.GetVertexCount());
	}
}

void Renderer::DrawQuad(std::shared_ptr<VertexBuffer> vbo, std::shared_ptr<IndexBuffer> ibo, std::shared_ptr<Texture> texture,
	const stm::mat4f& transform) const
{
	vbo->Bind();
	ibo->Bind();
	texture->Bind(0);
	_boundShader->SetUniform1i("u_texture", 0);
	_boundShader->SetUniformMat4f("u_view", transform);
	OpenGLDraw(ibo->GetIndexCount());
}
