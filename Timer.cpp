#include "Timer.h"



Timer::Timer()
{
	countTime_ = 0;
	currentTime_ = 0;
	limitTime_ = 0;
}

Timer::Timer(float limTime_)
{
	countTime_ = 0;
	currentTime_ = 0;
	limitTime_ = limTime_;
}

void Timer::UpData()
{
	if (timeStop_)
	{
		countTime_ += 100.0f / FPS;
		currentTime_ = countTime_ / 100;
	}
}
