#include <iostream>
#include "Application.h"
#include "Time.h"
#include "ShaderProgram.h"
#include "VertexArray.h"
#include "Input.h"

#pragma comment(lib, "opengl32.lib")


class MainGameLoop : public GameLoop
{
private:
	ShaderProgram p;
	VertexArray vao;

public:
	MainGameLoop()
	{
		Shader shaders[2] = {
			Shader("res/shaders/vertexShader.glsl", SHADER_TYPE_VERTEX),
			Shader("res/shaders/fragmentShader.glsl", SHADER_TYPE_FRAGMENT)
		};
		p = ShaderProgram(shaders, 2);
	
		
		float verts[] = {
			-0.5f, 0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			0.5f, 0.5f, 0.0f,
			0.5f, -0.5f, 0.0f
		};

		VertexAttrib layout[] = {
			VertexAttrib(0, 3, GL_FLOAT, 0, 0, 0)
		};

		VertexBuffer vbo(verts, sizeof(verts), layout, 1);

		unsigned int inds[] = {0,1,2,2,1,3};

		IndexBuffer ibo(inds, 6);

		vao.Init();
		vao.PushVertexBuffer(vbo);
		vao.PushIndexBuffer(ibo);
	}

	void Update() override
	{
		glClear(GL_COLOR_BUFFER_BIT);
		
		p.Bind();
		vao.Draw();
	}
};

int main()
{
	Application app;
	app.Run(new MainGameLoop());
}