#pragma once
class Application;

class Time
{
	friend Application;
private:
	static float _dt;
	static float _timeScale;
	static float _time;

public:
	inline static const float GetDT() { return _dt * _timeScale; }
	inline static const float GetTimeScale() { return _timeScale; }
	inline static const float GetTime() { return _time; }

	inline static void SetTimeScale(float ts) { _timeScale = ts; }

protected:
	inline static void SetDT(float dt) { _dt = dt; }
	inline static void SetTime(float time) { _time = time; }
};