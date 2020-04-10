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
		static void SetStartFade(int type);
		static signed short int GetFadeCheck();
	private:
		static signed short int FadeCheck_;
		int Texture_;
		static int State_;
		TetrisGameType::Color Color_;
	};
}