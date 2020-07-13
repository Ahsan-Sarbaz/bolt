#include "ShaderProgram.h"
#include <stdio.h>
#include <stdlib.h>

ShaderProgram::ShaderProgram()
{
}

ShaderProgram::ShaderProgram(Shader* shaders, int count)
{
	_id = glCreateProgram();
	for (int i = 0; i < count; ++i)
		glAttachShader(_id, shaders[i].GetID());

	glLinkProgram(_id);

	int result = 0;
	glGetProgramiv(_id, GL_LINK_STATUS, &result);
	if (result != GL_TRUE)
	{
		int loglen = 0;
		glGetProgramiv(_id, GL_INFO_LOG_LENGTH, &loglen);
		char* logmessage = (char*)malloc(loglen);
		glGetProgramInfoLog(_id, loglen, 0, logmessage);
		printf("Program Error: %s", logmessage);
		free(logmessage);
		return;
	}

	for (int i = 0; i < count; ++i)
		glDeleteShader(shaders[i].GetID());
}
