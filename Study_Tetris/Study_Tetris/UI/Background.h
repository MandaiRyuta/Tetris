#pragma once
#include "UI.h"

namespace TetrisUI
{
	//���\�[�X�̉摜���傫���A�ǂݍ��ނ̂Ɏ��Ԃ������邽�ߌp���O���܂����B
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