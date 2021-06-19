#pragma once

#include "Cube.h"

enum class BlockId : uint8_t
{
	AIR = 0,
	STONE, GRASS, DIRT, SAND
};

class Block
{
public:
	Block() :_id(BlockId::AIR), _data(nullptr) {}
	Block(BlockId id) :_id(id), _data(nullptr) {}

	bool isBlock(BlockId id) const { return id == _id; }
private:
	BlockId _id;
	void* _data;
};