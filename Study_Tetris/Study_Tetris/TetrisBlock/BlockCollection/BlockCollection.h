#pragma once
#include <array>
#include "../../TetrisGameType\TetrisGameType.h"
#include "../TetrisBlock.h"

namespace TetrisBlocks
{
	class BlockCollection
	{
	public:
		BlockCollection()
		{
			Block_ = new TetrisBlocks::TetrisBlock();
			Block_->Init();
			Board_ = {};
			*ClearLine_ = {};
			ClearCheck_ = 0x000;
			ClearCount_ = 1;
		}
		~BlockCollection(){}
	public:
		void Init();
		void Update();
		void Draw();
		void Release();
		void StackBlockClearLineCheck();
		void StageBlockLineClear();
		void StackBlock(TetrisBlock* block);
		void NowBlock();
		void SetHold(TetrisBlock* block);
		void CopyBlock(TetrisGameType::Block src, TetrisGameType::Block dst);
		void Clear(TetrisGameType::Block block);
		void Hold() {}
		void Stack() {}
		void NowBlockReset() {}
		void ValidArea() {}
		int GetBoardInfo(int x, int y);
		TetrisBlock* GetBlock();
	private:
		int ClearLine_[23];
		signed short int ClearCheck_;
		TetrisBlock* Block_;
		int ClearCount_;
		std::array<std::array<int, TetrisGameType::StageWidth>, TetrisGameType::StageHeight> Board_;
	};
}