#pragma once

#include "Cube.h"

enum class BlockId : uint8_t
{
	AIR = 0,
	STONE = 1, GRASS = 2, DIRT = 3, SAND = 4
};

class Block
{
public:
	Block() :_id(BlockId::AIR), _data(nullptr) {}
	Block(BlockId id) :_id(id), _data(nullptr) {}

	BlockId GetId() const { return _id; }
	bool isBlock(BlockId id) const { return id == _id; }
private:
	BlockId _id;
	void* _data;
};