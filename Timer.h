
#pragma once
class Timer
{
	const int FPS = 60;
	float countTime_;
	float currentTime_;
	float limitTime_;
	bool timeStop_;
public:
	Timer();
	Timer(float limTime_);
	void UpData();
	float GetRestTime() { return limitTime_ - currentTime_; }
	float GetTime() { return currentTime_; }
	void SetTime(float _time) { countTime_ = _time * 100; }
	bool isTimeUpped()
	{
		if (limitTime_ <= currentTime_)
		{
			return true;
		}
		return false;
	}
	void TimeStop() { timeStop_ = true; }
};

