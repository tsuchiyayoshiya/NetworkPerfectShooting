#include "Timer.h"

const int FPS = 60;

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
	countTime_ += 100.0f / FPS;
	currentTime_ = countTime_ / 100;
}
