#pragma once
#include <array>
#include "../../TetrisGameType\TetrisGameType.h"
#include "../TetrisBlock.h"
#include "../../Actor/Actor.h"

namespace TetrisBlocks
{
	class BlockCollection : public Actor
	{
	public:
		BlockCollection()
		{

		}
		~BlockCollection()
		{

		}
	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void Draw() override;
		virtual void Release() override;

		void StackBlockClearLineCheck();
		void StageBlockLineClear();
		void CopyBlock(TetrisGameType::Block src, TetrisGameType::Block dst);
		void Clear(TetrisGameType::Block block);

		const int& GetBoardInfo(int x, int y);
	private:
		int ClearLine_[23];
		signed short int ClearCheck_;
		TetrisBlock Block_;
		int ClearCount_;
		std::array<std::array<int, TetrisGameType::StageWidth>, TetrisGameType::StageHeight> Board_;
	};
}