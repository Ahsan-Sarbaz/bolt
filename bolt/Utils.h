#pragma once
#include <fstream>
#include <sstream>
#include <string>

static inline std::string ReadFileFromPath(const char* path)
{
	std::fstream file(path, std::ios::in);
	if (!file.is_open())
	{
		return nullptr;
	}

	std::stringstream ss;
	ss << file.rdbuf();
	std::string s = ss.str();
	return s;
}
