#pragma once
#include "TetrisGameType.h"
//constexpr int BLOCKTYPE = 7;
//constexpr int BLOCKSIZE = 4;

namespace TetrisBlocks
{
	class BlockCollection;
	class TetrisBlock
	{
	public:
		TetrisBlock():
			Blocknumber_(0),
			//Input_(nullptr),
			Type_(TetrisGameType::BlockType::I),
			Blocktype_()
		{

		}
		~TetrisBlock(){}
	public:
		void SetBlock(TetrisGameType::BlockType type);
		void DrawBlock(int type, int vertical, int side, int positionX, int positionY);
		void ChangeRotate();
		void Init();
		void Update();
		void Draw();
		void Release();
		int GetXBlockPosition();
		int GetYblockPosition();
		TetrisGameType::Block GetBlockInfo(int x, int y);
		void CopyBlock(int blocktype);
		void SetBoardInfo(BlockCollection boardinfo);
	private:
		BlockCollection Blockcollection_;
		unsigned int YblockCount_;
		signed short int OneMoveCheck;
		TetrisGameType::Vector2 Position_;
		int Blocknumber_;
		TetrisGameType::BlockType Type_;
		TetrisGameType::Block Blocktype_[TetrisGameType::BLOCKTYPE][TetrisGameType::BLOCKHEIGHT][TetrisGameType::BLOCKWIDTH];
		TetrisGameType::Block CopyBlock_[TetrisGameType::BLOCKHEIGHT][TetrisGameType::BLOCKWIDTH];
		int BlockMaxMoveTime_;
		int BlockNowMoveTime_;
		int InputMaxMoveTime_;
		int InputNowMoveTime_;
	};
}