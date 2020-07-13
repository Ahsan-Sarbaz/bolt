#pragma once
#include <GL/glew.h>
#include "Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class ShaderProgram
{
private:
	int _id;

public:
	ShaderProgram();
	ShaderProgram(Shader* shaders, int count);
	
	inline int GetID() { return _id; }

	inline void Bind() { glUseProgram(_id); }
	inline void Unbind() { glUseProgram(0); }

	inline int GetUniformLocation(const char* name) { return glGetUniformLocation(_id, name); }
	
	inline void UniformInt(const char* name, int x) { glUniform1i(GetUniformLocation(name), x); }

	inline void UniformFloat1(const char* name, float x) { glUniform1f(GetUniformLocation(name), x); }
	inline void UniformFloat2(const char* name, float x, float y) { glUniform2f(GetUniformLocation(name), x, y); }
	inline void UniformFloat3(const char* name, float x, float y, float z) { glUniform3f(GetUniformLocation(name), x, y, z); }
	inline void UniformFloat4(const char* name, float x, float y, float z, float w) { glUniform4f(GetUniformLocation(name), x, y, z, w); }

	inline void UniformVec2(const char* name, const glm::vec2& vec) { glUniform2fv(GetUniformLocation(name), 1, glm::value_ptr(vec)); }
	inline void UniformVec3(const char* name, const glm::vec3& vec) { glUniform3fv(GetUniformLocation(name), 1, glm::value_ptr(vec)); }
	inline void UniformVec4(const char* name, const glm::vec4& vec) { glUniform4fv(GetUniformLocation(name), 1, glm::value_ptr(vec)); }

	inline void UniformMat2(const char* name, const glm::mat2& mat) { glUniformMatrix2fv(GetUniformLocation(name), 1, false, glm::value_ptr(mat)); }
	inline void UniformMat3(const char* name, const glm::mat3& mat) { glUniformMatrix3fv(GetUniformLocation(name), 1, false, glm::value_ptr(mat)); }
	inline void UniformMat4(const char* name, const glm::mat4& mat) { glUniformMatrix4fv(GetUniformLocation(name), 1, false, glm::value_ptr(mat)); }

};
