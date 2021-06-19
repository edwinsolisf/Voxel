#SHADER FRAGMENT FRAGMENT
#version 330 core

in vec2 texCoords;

out vec4 color;

uniform vec4 u_color;
uniform sampler2D u_texture;

void main()
{
	color = texture(u_texture, texCoords);
	//color = u_color;
}
