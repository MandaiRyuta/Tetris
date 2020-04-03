#pragma once
#include "BlockCollection.h"
#include "Utils.h"

constexpr int BlockType = 7;
constexpr int BlockSize = 4;

namespace TetrisBlocks
{
	class TetrisBlock
	{
	public:
		TetrisBlock(){}
		~TetrisBlock(){}
	public:
		void SetBlock(Utils::BlockType type);
		void SetBlockTransform(int positionX, int positionY);
		void ChangeRotate();
		void ValidArea();
		void Init();
		void Update();
		void Draw();
		void Release();
		void Hold();
		void Stack();
		void NowBlockReset();
		void StackBlockClear();
		
	private:
		Utils::BlockType type_;
		BlockCollection collection_;
		Utils::Block blocktype_[BlockType][BlockSize][BlockSize];
	};
}