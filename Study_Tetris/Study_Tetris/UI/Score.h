#pragma once
#include "UI.h"

namespace TetrisUI
{
	class Score : public UI
	{
	public:
		Score()
		{
			Position_.x = 600;
			Position_.y = 100;
			Color_.r = 255;
			Color_.g = 255;
			Color_.b = 255;
			Color_.a = 255;
		}
		~Score() {}
	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void Draw() override;
		virtual void Release() override;
		static void SetScore(int score);
		static unsigned int GetScore();
		static void AddScore(int addscore);
	private:
		static unsigned int Score_;
		TetrisGameType::Vector2 Position_;
		TetrisGameType::Color Color_;
	};
}