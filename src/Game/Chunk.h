#pragma once

#include <array>
#include "Block.h"

class Chunk
{
public:
	Chunk(const stm::vec3i& position) :_position(position), _data(size * size * size) {}
	void SetBlock(const Block& block, const stm::vec3i& pos);
	void FillChunk(const Block& block);
	void RandomFill();
	Mesh GenMesh() const;
	static const uint32_t size = 16;

private:

	stm::vec3i _position;
	std::vector<Block> _data;
};