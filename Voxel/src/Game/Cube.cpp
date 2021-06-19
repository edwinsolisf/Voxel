#include "Cube.h"

using namespace CubeMesh;

std::vector<Vertex> CubeMesh::GenVertices()
{
	static std::vector<Vertex> vertices =
	{
		//Vertices arranged from bottom-left clockwise

		//FRONT
		Vertex({ -0.5f, -0.5f,  0.5f }, { 0.0f, 0.0f }),
		Vertex({ -0.5f,  0.5f,  0.5f }, { 0.0f, 1.0f }),
		Vertex({  0.5f,  0.5f,  0.5f }, { 1.0f, 1.0f }),
		Vertex({  0.5f, -0.5f,  0.5f }, { 1.0f, 0.0f }),

		//RIGHT
		Vertex({  0.5f, -0.5f,  0.5f }, { 0.0f, 0.0f }),
		Vertex({  0.5f,  0.5f,  0.5f }, { 0.0f, 1.0f }),
		Vertex({  0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f }),
		Vertex({  0.5f, -0.5f, -0.5f }, { 1.0f, 0.0f }),

		//BACK
		Vertex({  0.5f, -0.5f, -0.5f }, { 0.0f, 0.0f }),
		Vertex({  0.5f,  0.5f, -0.5f }, { 0.0f, 1.0f }),
		Vertex({ -0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f }),
		Vertex({ -0.5f, -0.5f, -0.5f }, { 1.0f, 0.0f }),

		//LEFT
		Vertex({ -0.5f, -0.5f, -0.5f }, { 0.0f, 0.0f }),
		Vertex({ -0.5f,  0.5f, -0.5f }, { 0.0f, 1.0f }),
		Vertex({ -0.5f,  0.5f,  0.5f }, { 1.0f, 1.0f }),
		Vertex({ -0.5f, -0.5f,  0.5f }, { 1.0f, 0.0f }),

		//TOP
		Vertex({ -0.5f,  0.5f,  0.5f }, { 0.0f, 0.0f }),
		Vertex({ -0.5f,  0.5f, -0.5f }, { 0.0f, 1.0f }),
		Vertex({  0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f }),
		Vertex({  0.5f,  0.5f,  0.5f }, { 1.0f, 0.0f }),

		//BOTTOM
		Vertex({ -0.5f, -0.5f, -0.5f }, { 0.0f, 0.0f }),
		Vertex({ -0.5f, -0.5f,  0.5f }, { 0.0f, 1.0f }),
		Vertex({  0.5f, -0.5f,  0.5f }, { 1.0f, 1.0f }),
		Vertex({  0.5f, -0.5f, -0.5f }, { 1.0f, 0.0f }),
	};
	return vertices;
}

std::vector<Index> CubeMesh::GenIndices()
{
	static std::vector<Index> indices =
	{
		0, 1, 2,	0, 2, 3,
		4, 5, 6,	4, 6, 7,
		8, 9, 10,	8, 10, 11,
		12, 13, 14,	12, 14, 15,
		16, 17, 18, 16, 18, 19,
		20, 21, 22, 20, 22, 23
	};
	return indices;
}

Mesh CubeMesh::GenMesh()
{
	static std::vector<std::string> textures;
	static bool init = false;
	if (!init)
	{
		textures.push_back("assets/textures/stone.png");
		init = true;
	}

	return Mesh(GenVertices(), GenIndices(), textures);
}