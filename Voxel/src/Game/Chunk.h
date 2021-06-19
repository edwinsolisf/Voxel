#pragma once

#include <array>
#include "Block.h"

class Chunk
{
public:
	Chunk(const stm::vec3i& position) :_position(position), _data(size * size * size) {}

	void FillChunk(const Block& block);
	Mesh GenMesh() const;

private:
	static const uint32_t size = 16;

	stm::vec3i _position;
	std::vector<Block> _data;
};