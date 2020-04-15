#pragma once
#include "UI.h"

namespace TetrisUI
{
	class Background
	{
	public:
		Background(){}
		~Background() {}
	public:
		void Init();
		void Update();
		void Draw();
		void Release();

	private:
		int BackGroundTexture_;
	};
}