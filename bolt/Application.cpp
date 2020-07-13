#include "Application.h"
#include "Time.h"

Application* Application::_this;

Application::Application()
{
	_this = this;
	
	glfwInit();
	_window = glfwCreateWindow(800, 600, "bolt", 0, 0);
	glfwMakeContextCurrent(_window);
	glfwSwapInterval(1);
	glewInit();

	_isRunning = true;
}

void Application::Run(GameLoop* loop)
{
	_loop = loop;

	float time = glfwGetTime();
	float prevTime = 0.0f;
	float dt = 0.0f;

	while ((_isRunning = _loop->IsLooping()) && !glfwWindowShouldClose(_window))
	{
		time = glfwGetTime();
		dt = (time - prevTime) * 1000.0f;
		prevTime = time;

		Time::SetTime(time);
		Time::SetDT(dt);

		glfwPollEvents();
		loop->Update();
		glfwSwapBuffers(_window);
	}
}
