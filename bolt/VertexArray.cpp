#include "VertexArray.h"

VertexArray::VertexArray()
{
}

void VertexArray::Init()
{
	glGenVertexArrays(1, &_id);
}

void VertexArray::PushVertexBuffer(VertexBuffer buffer)
{
	glBindVertexArray(_id);
	buffer.Bind();
	for (int i = 0; i < buffer.GetAttribsCount(); ++i)
	{
		VertexAttrib attrib = (buffer.GetVertexAttribLayout())[i];
		glVertexAttribPointer(attrib.index, attrib.size, attrib.type, attrib.normalized, attrib.stride, attrib.pointer);
		glEnableVertexAttribArray(attrib.index);
	}
	glBindVertexArray(0);
	buffer.Unbind();
}

void VertexArray::PushIndexBuffer(IndexBuffer buffer)
{
	_count = buffer.GetCount();
	glBindVertexArray(_id);
	buffer.Bind();
	glBindVertexArray(0);
	buffer.Unbind();
}

void VertexArray::Draw()
{
	glBindVertexArray(_id);
	glDrawElements(GL_TRIANGLES, _count, GL_UNSIGNED_INT, 0);
}
