#pragma once
#include <array>

class TetrisBlock {};

namespace TetrisBlocks
{
	class BlockCollection
	{
	public:
		BlockCollection(){}
		~BlockCollection(){}
	public:
		void StackBlock(TetrisBlock* block);
		void NowBlock();
		void SetHold(TetrisBlock* block);
	private:
		TetrisBlock block_;
		std::array<std::array<TetrisBlock, 6>, 20> Board_;
	};
}