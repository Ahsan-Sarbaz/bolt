#pragma once
#include "Application.h"

class Input
{
public:
	static inline bool GetKeyDown(int key)
	{
		return (glfwGetKey(Application::GetWindow(), key) == GLFW_PRESS);
	}

	static inline float GetMouseX()
	{
		double x, y;
		glfwGetCursorPos(Application::GetWindow(), &x, &y);
		return x;
	}

	static inline float GetMouseY()
	{
		double x, y;
		glfwGetCursorPos(Application::GetWindow(), &x, &y);
		return y;
	}
};
