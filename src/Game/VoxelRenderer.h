#pragma once

#include "../Renderer/Renderer.h"
#include "World.h"

class VoxelRenderer : public Renderer
{
public:
	VoxelRenderer() {}
	void RenderWorld(const World& world);

};