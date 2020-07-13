#version 440
layout(location = 0) in vec3 pos;

out vec4 v_col;

void main()
{
	gl_Position = vec4(pos, 1);
	v_col = gl_Position;
}