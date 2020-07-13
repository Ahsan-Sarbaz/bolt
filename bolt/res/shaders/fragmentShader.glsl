#version 440
out vec4 outColor;

in vec4 v_col;

uniform vec2 u_mouse;

void main()
{
	outColor = v_col;
}