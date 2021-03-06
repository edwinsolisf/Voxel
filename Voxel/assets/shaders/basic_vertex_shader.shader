#SHADER VERTEX VERTEX
#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texcoords;
layout (location = 2) in float textureid;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

out vec2 texCoords;
flat out float textureId;

void main()
{
	gl_Position = u_projection * u_view * u_model * vec4(position.x, position.y, position.z, 1.0);
	texCoords = texcoords;
	textureId = textureid;
}
