#include "VoxelRenderer.h"

void VoxelRenderer::RenderWorld(const World& world)
{
	static bool preloaded = false;
	if (!preloaded)
	{
		for (const auto& chunk : world.GetChunks())
		{
			Push(chunk.GenMesh());
		}
		preloaded = true;
	}
	Draw();
	//Clear();
}