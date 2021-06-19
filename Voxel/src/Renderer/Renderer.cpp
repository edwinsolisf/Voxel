#include "Renderer.h"

Renderer::Renderer()
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
		}
		OpenGLDraw(mesh.GetVertexCount());
	}
}