#pragma once

class GameLoop
{
private:
	bool _isLooping = true;

public:
	virtual void Update() = 0;
	
	bool IsLooping() { return _isLooping; }
protected:
	inline void ExitLoop() { _isLooping = false; }
};