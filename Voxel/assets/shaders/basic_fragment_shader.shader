#SHADER FRAGMENT FRAGMENT
#version 330 core

in vec2 texCoords;
in flat float textureId;

out vec4 color;

uniform vec4 u_color;
uniform sampler2D u_texture_1;
uniform sampler2D u_texture_2;
uniform sampler2D u_texture_3;
uniform sampler2D u_texture_4;

void main()
{
	color = vec4(0.0, 0.0, 0.0, 0.0);
	if (textureId == 0)
	{
		color += texture(u_texture_1, texCoords);
	}
	else if (textureId == 1.0/4.0)
	{
		color += texture(u_texture_2, texCoords);
	}
	else if (textureId == 2.0/4.0)
	{
		color += texture(u_texture_3, texCoords);
	}
	else if (textureId == 3.0/4.0)
	{
		color += texture(u_texture_4, texCoords);
	}
}
