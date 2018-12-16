#version 450 core

layout (location = 0) in vec3 position;

out vec3 fragPosition;

void main()
{
	gl_Position = vec4(position, 1.0);
	fragPosition = position;
}
