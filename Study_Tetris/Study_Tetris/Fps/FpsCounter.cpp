#include "FpsCounter.h"
#include <DxLib.h>

void FPS::FpsCounter::Update()
{
	if (TimeCount_ == 0)
	{
		StartTime_ = GetNowCount();
	}
	else if (TimeCount_ == Fps_N)
	{
		int t = GetNowCount();
		Fps_ = 1000.f / ((t - StartTime_) / (float)Fps_N);
		TimeCount_ = 0;
		StartTime_ = t;
	}
	TimeCount_++;
}

void FPS::FpsCounter::Draw()
{
	//DrawFormatString(0, 0, GetColor(0, 0, 0), "%.1f", Fps_);
}

void FPS::FpsCounter::WaitTime()
{
	int passagetime = GetNowCount() - StartTime_;
	int waittime = TimeCount_ * 1000 / FPS::FpsFrame - passagetime;

	if (waittime > 0)
	{
		Sleep(waittime);
	}
}
