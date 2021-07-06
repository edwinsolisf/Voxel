#SHADER VERTEX WIDGETS_VERTEX
#version 330 core

layout(location = 0) in vec2 position;
layout(location = 1) in vec2 texcoords;

out vec2 texCoords;
uniform mat4 u_view;

void main()
{
	texCoords = texcoords;
	gl_Position = u_view * vec4(position.xy, 0.0, 1.0);
}