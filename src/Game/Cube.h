#pragma once

#include "../Renderer/Mesh.h"

#include <array>
namespace CubeMesh
{
	std::vector<Vertex> GenVertices();
	std::vector<Index> GenIndices();
	Mesh GenMesh();

	//std::array<Vertex, 4> FrontVertices;
	const std::array<Index, 6> IndicesLayout = {
		0, 1, 2, 0, 2, 3
	};

	const std::array<Vertex, 4> FrontVertices = {
		Vertex({ -0.5f, -0.5f,  0.5f }, { 0.0f, 0.0f }, 1),
		Vertex({ -0.5f,  0.5f,  0.5f }, { 0.0f, 1.0f }, 1),
		Vertex({  0.5f,  0.5f,  0.5f }, { 1.0f, 1.0f }, 1),
		Vertex({  0.5f, -0.5f,  0.5f }, { 1.0f, 0.0f }, 1)
	};

	const std::array<Vertex, 4> BackVertices = {
		Vertex({  0.5f, -0.5f, -0.5f }, { 0.0f, 0.0f }, 0),
		Vertex({  0.5f,  0.5f, -0.5f }, { 0.0f, 1.0f }, 0),
		Vertex({ -0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f }, 0),
		Vertex({ -0.5f, -0.5f, -0.5f }, { 1.0f, 0.0f }, 0)
	};

	const std::array<Vertex, 4> TopVertices = {
		Vertex({ -0.5f,  0.5f,  0.5f }, { 0.0f, 0.0f }, 0),
		Vertex({ -0.5f,  0.5f, -0.5f }, { 0.0f, 1.0f }, 0),
		Vertex({  0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f }, 0),
		Vertex({  0.5f,  0.5f,  0.5f }, { 1.0f, 0.0f }, 0)
	};

	const std::array<Vertex, 4> BottomVertices = {
		Vertex({ -0.5f, -0.5f, -0.5f }, { 0.0f, 0.0f }, 0),
		Vertex({ -0.5f, -0.5f,  0.5f }, { 0.0f, 1.0f }, 0),
		Vertex({  0.5f, -0.5f,  0.5f }, { 1.0f, 1.0f }, 0),
		Vertex({  0.5f, -0.5f, -0.5f }, { 1.0f, 0.0f }, 0)
	};

	const std::array<Vertex, 4> RightVertices = {
		Vertex({  0.5f, -0.5f,  0.5f }, { 0.0f, 0.0f }, 0),
		Vertex({  0.5f,  0.5f,  0.5f }, { 0.0f, 1.0f }, 0),
		Vertex({  0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f }, 0),
		Vertex({  0.5f, -0.5f, -0.5f }, { 1.0f, 0.0f }, 0)
	};

	const std::array<Vertex, 4> LeftVertices = {
		Vertex({ -0.5f, -0.5f, -0.5f }, { 0.0f, 0.0f }, 0),
		Vertex({ -0.5f,  0.5f, -0.5f }, { 0.0f, 1.0f }, 0),
		Vertex({ -0.5f,  0.5f,  0.5f }, { 1.0f, 1.0f }, 0),
		Vertex({ -0.5f, -0.5f,  0.5f }, { 1.0f, 0.0f }, 0)
	};
}