#version 450 core

layout (location = 0) in vec3 position;
/*layout (location = 1) in vec3 vertexColor;
layout (location = 2) in vec2 in_texture;

out vec3 fragmentColor;
out vec2 frag_texture;*/

void main()
{
	gl_Position = vec4(position, 1.0);
	/*fragmentColor = vertexColor;
	frag_texture = vec2(in_texture.x, in_texture.y);*/
}

