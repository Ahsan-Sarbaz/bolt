#include "Shader.h"
#include "Utils.h"

Shader::Shader()
{

}

Shader::Shader(const char* path, SHADER_TYPE type)
{
	_id = glCreateShader(type);
	std::string source = ReadFileFromPath(path);

	const char* bytes = source.c_str();

	glShaderSource(_id, 1, &bytes, 0);
	glCompileShader(_id);
	int result;
	glGetShaderiv(_id, GL_COMPILE_STATUS, &result);
	if (result != GL_TRUE)
	{
		int loglen = 0;
		glGetShaderiv(_id, GL_INFO_LOG_LENGTH, &loglen);
		char* logmessage = (char*)malloc(loglen);
		glGetShaderInfoLog(_id, loglen, 0, logmessage);
		printf("%s Shader Error : %s ", type == SHADER_TYPE_VERTEX ? "Vertex" : "Fragment", logmessage);
		free(logmessage);
		return;
	}
}
