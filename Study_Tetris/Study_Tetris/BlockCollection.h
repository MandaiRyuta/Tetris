#pragma once
#include <array>
#include "Utils.h"
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
		void CopyBlock(Utils::Block src, Utils::Block dst);
		void Clear(Utils::Block block);
		void Hold() {}
		void Stack() {}
		void NowBlockReset() {}
		void ValidArea() {}

	private:
		TetrisBlock* block_;
		std::array<std::array<int, 12>, 20> Board_;
	};
}