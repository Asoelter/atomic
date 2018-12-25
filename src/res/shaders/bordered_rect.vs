#version 450 core

layout (location = 0) in vec3 position;

out vec4 fragPosition;

uniform mat4 u_translation;

void main()
{
	gl_Position  = u_translation * vec4(position, 1.0);
	fragPosition = u_translation * vec4(position, 1.0);
}
