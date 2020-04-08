#pragma once
#include "UI.h"

namespace TetrisUI
{
	class Fade : public UI
	{
	public:
		Fade() {}
		~Fade() {}
	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void Draw() override;
		virtual void Release() override;
		signed short int FadeIn();
		signed short int FadeOut();
	private:
		int texture_;
		Vector2 position_;
		Vector2 scale_;
		Color color_;
	};
}