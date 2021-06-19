#include "World.h"

const uint32_t smallWorldSize = 4;

World::World()
{
	for (uint32_t i = 0; i < smallWorldSize; ++i)
	{
		for (uint32_t j = 0; j < smallWorldSize; ++j)
			GenChunkAt(stm::vec3i(i, 0, j));
	}
}

void World::GenChunkAt(const stm::vec3i& pos)
{
	Chunk chunk(pos);
	chunk.FillChunk(Block(BlockId::STONE));
	_worldData.push_back(chunk);
}
