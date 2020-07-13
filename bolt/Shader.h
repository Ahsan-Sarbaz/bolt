#pragma once
#include <GL/glew.h>

enum SHADER_TYPE
{
	SHADER_TYPE_VERTEX = GL_VERTEX_SHADER,
	SHADER_TYPE_FRAGMENT = GL_FRAGMENT_SHADER
};

class Shader
{
private:
	int _id;
public:
	Shader();
	Shader(const char* path, SHADER_TYPE type);

	inline int GetID() { return _id; }
};