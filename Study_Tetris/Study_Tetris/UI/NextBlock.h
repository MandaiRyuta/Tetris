#pragma once
#include "UI.h"

namespace TetrisUI
{
	class NextBlock : public UI
	{	
	public:
		NextBlock(){
		}
		~NextBlock() {}
	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void Draw() override;
		virtual void Release() override;
		virtual void LoadTexture(int handle, int texturenumber = 0) override;
		void NextBlockPlaceDraw();
		void BlockInit();
		static void GetNextBlockType(int num, int type)
		{
			BlockNumber_[num] = type;
		}
	private:	
		static std::array<int, 3> BlockNumber_;
		TetrisGameType::Block Blocktype_[TetrisGameType::TetrisBlockTypeNum::MaxNumber][TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
	};
}