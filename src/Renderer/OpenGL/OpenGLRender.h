#pragma once

#include "OpenGLCore.h"

static void OpenGLDraw(uint32_t vertexCount)
{
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	GLCALL(glDrawElements(GL_TRIANGLES, vertexCount, GL_UNSIGNED_INT, (const void*)0));
}