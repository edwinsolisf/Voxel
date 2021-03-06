#include "Vertex.h"

VertexBufferLayout Vertex::GetLayout()
{
	static VertexBufferLayout layout;
	static bool init = false;

	if (!init)
	{
		layout.Push<GLfloat>(3);
		layout.Push<GLfloat>(2);
		layout.Push<GLfloat>(1);
		init = true;
	}

	return layout;
}