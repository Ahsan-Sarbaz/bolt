#pragma once
#include "VertexBuffer.h"
#include "IndexBuffer.h"

class VertexArray
{
private:
	unsigned int _id;
	int _count;
public:
	VertexArray();

	void Init();
	void PushVertexBuffer(VertexBuffer buffer);
	void PushIndexBuffer(IndexBuffer buffer);
	void Draw();

	inline unsigned int GetID() { return _id; }
	inline int GetCount() { return _count; }

	inline void Bind() { glBindVertexArray(_id); }
	inline void Unbind() { glBindVertexArray(0); }
};