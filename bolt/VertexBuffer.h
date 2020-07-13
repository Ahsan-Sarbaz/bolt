#pragma once
#include <GL/glew.h>

struct VertexAttrib
{
	int index;
	int size;
	int type;
	int normalized;
	int stride;
	void* pointer;

	VertexAttrib(int index, int size, int type, int normalized, int stride, void* pointer)
	{
		this->index = index;
		this->size = size;
		this->type = type;
		this->normalized = normalized;
		this->stride = stride;
		this->pointer = pointer;
	}
};

class VertexBuffer
{
private:
	unsigned int _id;
	VertexAttrib* _layout;
	int _attribsCount;

public:
	VertexBuffer();
	VertexBuffer(float* data, int size, VertexAttrib* layout, int count);
	
	void BufferSubData(float* data, int size);

	inline int GetID() { return _id; }
	inline VertexAttrib* GetVertexAttribLayout() { return _layout; }
	inline int GetAttribsCount() { return _attribsCount; }

	inline void Bind() { glBindBuffer(GL_ARRAY_BUFFER, _id); }
	inline void Unbind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }
};

