#pragma once

#include "Chunk.h"

class World
{
public:
	World();

	//bool SaveToFile();
	//bool LoadFromFile();
	//void OnUpdate();
	void GenChunkAt(const stm::vec3i& pos);
	const auto& GetChunks() const { return _worldData; }
	void WorldGenerator(const stm::vec3i& pos);
private:
	std::vector<Chunk> _worldData;
	//std::vector<Entity> _entityData;
	//std::vector<Event> _eventData;
};