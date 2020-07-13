#pragma once
#include <GL/glew.h>

class IndexBuffer
{
private:
	unsigned int _id;
	int _count;

public:
	IndexBuffer();
	IndexBuffer(unsigned int* data, int count);

	inline unsigned int GetID() { return _id; }
	inline int GetCount() { return _count; }

	inline void Bind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id); }
	inline void Unbind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
};