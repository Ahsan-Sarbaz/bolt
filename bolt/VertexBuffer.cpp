#include "VertexBuffer.h"

VertexBuffer::VertexBuffer()
{
}

VertexBuffer::VertexBuffer(float* data, int size, VertexAttrib* layout, int count)
	:_layout(layout), _attribsCount(count)
{
	glGenBuffers(1, &_id);
	glBindBuffer(GL_ARRAY_BUFFER, _id);
	glBufferData(GL_ARRAY_BUFFER, size, data, data == nullptr ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::BufferSubData(float* data, int size)
{
	glBindBuffer(GL_ARRAY_BUFFER, _id);
	glBufferSubData(GL_ARRAY_BUFFER, 0, size, (void*)data);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
