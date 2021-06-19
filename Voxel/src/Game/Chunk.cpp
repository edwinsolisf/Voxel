#include "Chunk.h"

void Chunk::FillChunk(const Block& block)
{
	std::fill(_data.begin(), _data.end(), block);
}

void GenFaceMesh(std::vector<Vertex>& vertices, std::vector<Index>& indices, const std::array<Vertex, 4>& meshVertices, const std::array<Index, 6>& meshIndices, const stm::vec3i& offset)
{
	uint32_t meshVertexCount = meshVertices.size();
	uint32_t lastVertex = vertices.size();

	vertices.insert(vertices.cend(), meshVertices.begin(), meshVertices.end());
	for (uint32_t j = lastVertex; j < (lastVertex + meshVertexCount); ++j)
		vertices[j].position += offset.Cast<float>();

	uint32_t meshIndexCount = meshIndices.size();
	uint32_t lastIndex = indices.size();

	indices.insert(indices.cend(), meshIndices.begin(), meshIndices.end());
	for (uint32_t j = lastIndex; j < (lastIndex + meshIndexCount); ++j)
		indices[j] += lastVertex;
}

Mesh Chunk::GenMesh() const
{
	static std::vector<Vertex> vertices(size * size * size * 24);
	static std::vector<Index> indices(size * size * size * 36);
	vertices.clear();
	indices.clear();

	std::vector<std::string> textures = {
		//"assets/textures/stone.png",
		"assets/textures/dirt.png",
		//"assets/textures/grass.png",
		//"assets/textures/sand.png"
	};

	for (uint32_t i = 0; i < _data.size(); ++i)
	{
		const auto& thisBlock = _data[i];
		if (thisBlock.isBlock(BlockId::AIR))	continue;

		int32_t index = (int32_t)i;
		int32_t len = (int32_t)size;
		stm::vec3i offset = { (index % len),
							 ((index / (len * len))),
							 ((index / (len)) % len)};

		if (offset.x != 0 && offset.x != 15 &&
			offset.y != 0 && offset.y != 15 &&
			offset.z != 0 && offset.z != 15)
		{
			offset += _position * 16;
			//FRONT
			if ((offset.z != 15) && _data[i + 1].isBlock(BlockId::AIR))
			{
				GenFaceMesh(vertices, indices, CubeMesh::FrontVertices, CubeMesh::IndicesLayout, offset);
			}
			//RIGHT
			if ((offset.x != 15) && _data[i + (size * size)].isBlock(BlockId::AIR))
			{
				GenFaceMesh(vertices, indices, CubeMesh::RightVertices, CubeMesh::IndicesLayout, offset);
			}
			//BACK
			if ((offset.z != 0) && _data[i - 1].isBlock(BlockId::AIR))
			{
				GenFaceMesh(vertices, indices, CubeMesh::BackVertices, CubeMesh::IndicesLayout, offset);
			}
			//LEFT
			if ((offset.x != 0) && _data[i - (size * size)].isBlock(BlockId::AIR))
			{
				GenFaceMesh(vertices, indices, CubeMesh::LeftVertices, CubeMesh::IndicesLayout, offset);
			}
			//TOP
			if ((offset.y != 15) && _data[i + size].isBlock(BlockId::AIR))
			{
				GenFaceMesh(vertices, indices, CubeMesh::TopVertices, CubeMesh::IndicesLayout, offset);
			}
			//BOTTOM
			if ((offset.y != 0) && _data[i - size].isBlock(BlockId::AIR))
			{
				GenFaceMesh(vertices, indices, CubeMesh::BottomVertices, CubeMesh::IndicesLayout, offset);
			}
		}
		else
		{
			offset += _position * 16;

			const auto& meshVertices = CubeMesh::GenVertices();
			uint32_t meshVertexCount = meshVertices.size();
			uint32_t lastVertex = vertices.size();

			vertices.insert(vertices.cend(), meshVertices.begin(), meshVertices.end());
			for (uint32_t j = lastVertex; j < (lastVertex + meshVertexCount); ++j)
				vertices[j].position += offset.Cast<float>();

			const auto& meshIndices = CubeMesh::GenIndices();
			uint32_t meshIndexCount = meshIndices.size();
			uint32_t lastIndex = indices.size();

			indices.insert(indices.cend(), meshIndices.begin(), meshIndices.end());
			for (uint32_t j = lastIndex; j < (lastIndex + meshIndexCount); ++j)
				indices[j] += lastVertex;
			
		}
	}

	return Mesh(vertices, indices, textures);
}