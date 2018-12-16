#version 450 core

out vec4 fragColor;

/*in vec3 fragmentColor;
in vec2 frag_texture;

uniform sampler2D u_texture1;
uniform sampler2D u_texture2;*/

void main()
{
	//fragColor = mix(texture(u_texture1, frag_texture), texture(u_texture2, frag_texture), 0.2);
	fragColor = vec4(1.0, 0.0, 0.0, 1.0);
}
