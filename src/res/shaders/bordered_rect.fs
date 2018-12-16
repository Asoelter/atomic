#version 450 core

out		vec4	fragColor;
in		vec3	fragPosition;

uniform vec3	u_Color;
uniform vec3	u_BorderColor;
uniform float	xMax;
uniform float	xMin;
uniform float	yMax;
uniform float	yMin;

void main()
{
	if(fragPosition.x > xMax || fragPosition.x < xMin || fragPosition.y > yMax || fragPosition.y < yMin)
	{
		fragColor = vec4(u_BorderColor, 1.0);
	}
	else
	{
		fragColor = vec4(u_Color, 1.0);
	}
}
