#version 450 core

layout (location = 0) in vec3 position;

uniform mat4 u_translation;

void main()
{
	gl_Position = u_translation * vec4(position, 1.0);
}
