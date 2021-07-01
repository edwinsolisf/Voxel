#pragma once

#include "../Application/Application.h"
#include "VoxelRenderer.h"

class VoxelGame : public Application
{
public:
	VoxelGame();
	~VoxelGame();

	void Init() override;
	void Process() override;

	bool OnMouseMoved(MouseMovedEvent& event) override;
	bool OnKeyPressed(KeyPressedEvent& event) override;
	bool OnKeyRepeat(KeyRepeatEvent& event) override;
	bool OnKeyReleased(KeyReleasedEvent& event) override;

private:
	static const uint32_t default_width = 1600;
	static const uint32_t default_height = 900;

	VoxelRenderer& renderer;
};