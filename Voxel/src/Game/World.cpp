#include "World.h"

#include "stm/simplex_noise.h"

const uint32_t smallWorldSize = 8;

World::World()
{
	//for (uint32_t i = 0; i < smallWorldSize; ++i)
	//{
	//	for (uint32_t j = 0; j < smallWorldSize; ++j)
	//		GenChunkAt(stm::vec3i(i, 0, j));
	//}
	for (uint32_t i = 0; i < smallWorldSize; ++i)
	{
		for (uint32_t j = 0; j < smallWorldSize; ++j)
			WorldGenerator(stm::vec3i(i, 0, j));
	}
}

void World::GenChunkAt(const stm::vec3i& pos)
{
	Chunk chunk(pos);
	//chunk.FillChunk(Block(BlockId::STONE));
	chunk.RandomFill();

	_worldData.push_back(chunk);
}

void World::WorldGenerator(const stm::vec3i& pos)
{
	stm::simplex_noise<3> generator;
	Chunk chunk(pos);
	for (uint32_t i = 0; i < Chunk::size; ++i)
	{
		for (uint32_t j = 0; j < Chunk::size; ++j)
		{
			for (uint32_t k = 0; k < Chunk::size; ++k)
			{
				BlockId type = BlockId::AIR;
				int seed = rand();
				if (generator.Noise({ (float)(i + pos.x * Chunk::size)/10.f, (float)(k + pos.y * Chunk::size)/10.f, (float)(j + pos.z * Chunk::size)/10.f }) > 0.0f)
				{
					switch (seed % 4)
					{
					case 0: type = BlockId::DIRT; break;
					case 1: type = BlockId::GRASS; break;
					case 2: type = BlockId::SAND; break;
					case 3: type = BlockId::STONE; break;
					}
				}
				chunk.SetBlock(Block(type), stm::vec3i(i, j, k));
			}
		}
	}
	_worldData.push_back(chunk);
}