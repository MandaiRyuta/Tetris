#pragma once
#include "UI.h"

namespace TetrisUI
{
	//リソースの画像が大きく、読み込むのに時間がかかるため継承外しました。
	class Background
	{
	public:
		Background()
		{

		}
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