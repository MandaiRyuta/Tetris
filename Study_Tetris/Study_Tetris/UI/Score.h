#pragma once
#include "UI.h"

namespace TetrisUI
{
	class Score : public UI
	{
	public:
		Score() {}
		~Score() {}
	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void Draw() override;
		virtual void Release() override;
		void SetScore(int score);
	private:
		unsigned int score_;
		std::vector<char> texture_name_;
		std::vector<Vector2> position_;
		std::vector<Vector2> scale_;
		std::vector<Color> color_;
	};
}