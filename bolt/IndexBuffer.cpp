#include "IndexBuffer.h"

IndexBuffer::IndexBuffer()
{
}

IndexBuffer::IndexBuffer(unsigned int* data, int count)
	:_count(count)
{
	glGenBuffers(1, &_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * count, data, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
