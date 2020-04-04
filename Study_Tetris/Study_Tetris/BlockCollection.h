#pragma once
#include <array>
#include "TetrisGameType.h"
#include "TetrisBlock.h"

namespace TetrisBlocks
{
	class BlockCollection
	{
	public:
		BlockCollection()
		{
			Board_ = {};
		}
		~BlockCollection(){}
	public:
		void Init();
		void Update();
		void Draw();
		void Release();
		void StackBlockClear();
		void StackBlock(TetrisBlock* block);
		void NowBlock();
		void SetHold(TetrisBlock* block);
		void CopyBlock(TetrisGameType::Block src, TetrisGameType::Block dst);
		void Clear(TetrisGameType::Block block);
		void Hold() {}
		void Stack() {}
		void NowBlockReset() {}
		void ValidArea() {}

	private:
		TetrisBlock* Block_;
		std::array<std::array<int, TetrisGameType::STAGEWIDTH>, TetrisGameType::STAGEHEIGHT> Board_;
	};
}