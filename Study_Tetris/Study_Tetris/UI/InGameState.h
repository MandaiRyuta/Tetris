#pragma once
#include "UI.h"

namespace TetrisUI
{
	class InGameState : public UI
	{
	public:
		InGameState() {}
		~InGameState() {}
	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void Draw() override;
		virtual void Release() override;
	private:
		signed short int state_;
		std::vector<char> texture_name_;
		std::vector<Vector2> position_;
		std::vector<Vector2> rotate_;
		std::vector<Vector2> scale_;
		std::vector<Color> color_;
	};
}