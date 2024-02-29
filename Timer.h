
#pragma once
class Timer
{
	float countTime_;
	float currentTime_;
	float limitTime_;

public:
	Timer(float limTime_);
	void UpData();
	float GetTime() { return limitTime_ - currentTime_; }
	bool isTimeUpped()
	{
		if (limitTime_ <= currentTime_)
		{
			return true;
		}
		return false;
	}
};

