
#pragma once
class Timer
{
	float countTime_;
	float currentTime_;
	float limitTime_;
public:
	Timer();
	Timer(float limTime_);
	void UpData();
	float GetRestTime() { return limitTime_ - currentTime_; }
	float GetTime() { return currentTime_; }
	bool isTimeUpped()
	{
		if (limitTime_ <= currentTime_)
		{
			return true;
		}
		return false;
	}
};

