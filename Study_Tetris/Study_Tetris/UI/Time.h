#pragma once
#include "UI.h"

namespace TetrisUI
{
	constexpr int Minute = 3600;
	class Time : public UI
	{
	public:
		Time() {}
		~Time() {}
	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void Draw() override;
		virtual void Release() override;
	private:
		int nowtime_;
		int endtime_;

		std::vector<TetrisGameType::Vector2> position_;
		std::vector<TetrisGameType::Color> color_;
	};
}