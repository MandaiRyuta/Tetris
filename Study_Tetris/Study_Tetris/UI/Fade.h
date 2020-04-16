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
		virtual void LoadTexture(int handle, int texturenumber = 0) override;
		signed short int FadeIn();
		signed short int FadeOut();
		static void SetStartFade(int type);
		static signed short int GetFadeCheck();
	private:
		static signed short int FadeCheck_;
		static int State_;
		TetrisGameType::Color Color_;
	};
}