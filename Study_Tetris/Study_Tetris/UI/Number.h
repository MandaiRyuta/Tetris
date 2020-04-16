#pragma once
#include "UI.h"

namespace TetrisUI
{
	constexpr int NumberDrawSize = 5;
	constexpr int ReSizeDrawSize = 1;
	class Number : public UI
	{
	public:
		Number();
		~Number();
	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void Draw() override;
		virtual void Release() override;
		virtual void LoadTexture(int handle, int texturenumber = 0) override;
		void DrawNumber(int x, int y, int num);
		void NumDraw(int x, int y, int Num);
		static void SetDrawNumber(int x, int y, int num, int size, signed short int resizecheck);
	private:
		static int PositionX_[NumberDrawSize];
		static int PositionY_[NumberDrawSize];
		static int Number_[NumberDrawSize];
		static int Size_;
		static int ReSizePositionX_[ReSizeDrawSize];
		static int ReSizePositionY_[ReSizeDrawSize];
		static int ResizeNumber_[ReSizeDrawSize];
		static int ReSize_;
		static signed short int ResizeCheck_;
		int DrawNumberTexture_[10];
	};
}
