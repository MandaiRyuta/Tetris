#pragma once
#include "UI.h"

namespace TetrisUI
{
	constexpr int Minute = 3600;
	constexpr int Second = 60;
	class Time : public UI
	{
	public:
		Time():
			endtime_(0),
			Min_(0),
			Sec_(0),
			MinSec_(0)
		{

		}
		~Time() {}
	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void Draw() override;
		virtual void Release() override;
		static int GetNowTime();
	private:
		int TimeFontTexture_;
		static int nowtime_;
		int endtime_;
		int Min_;
		int Sec_;
		int MinSec_;
		
		std::array<int, 3> Positionx_;
		std::array<int, 3> Positiony_;
		std::array<int, 3> Color_;
	};
}