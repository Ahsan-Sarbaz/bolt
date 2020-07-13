#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "GameLoop.h"

class Application
{
private:
	static Application* _this;
	bool _isRunning;
	GLFWwindow* _window;
	GameLoop* _loop;
public:
	Application();

	void Run(GameLoop* loop);

	static inline GLFWwindow* GetWindow() { return _this->_window; }

private:

};