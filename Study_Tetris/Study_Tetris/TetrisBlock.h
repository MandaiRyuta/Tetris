#pragma once
#include "TetrisGameType.h"
//constexpr int BLOCKTYPE = 7;
//constexpr int BLOCKSIZE = 4;

namespace TetrisBlocks
{
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
		int GetBlockType();
		int GetBlockData(int x, int y);
		void CopyBlock(int blocktype);
		void SetBoardData(int boardinfo, int x, int y);
		void StageBlockCollisionLeft();
		void StageBlockCollisionRight();
		void StageBlockCollisionBottom();
		void StageBlockCollisionCenter();
		void BlockCollisionTurn();
		void MakeBlock();
		
	private:
		int YblockCount_;
		signed short int SpaceDownCheck_;
		signed short int OneMoveCheck_;
		signed short int MakeBlock_;
		signed short int BottomBlockCheck_;
		signed short int CheckBlock_;
		signed short int Blockdown_;
		TetrisGameType::Vector2 Position_;
		int Blocknumber_;
		TetrisGameType::BlockType Type_;
		TetrisGameType::Block Blocktype_[TetrisGameType::BLOCKTYPE][TetrisGameType::BLOCKHEIGHT][TetrisGameType::BLOCKWIDTH];
		int CopyBlock_[TetrisGameType::BLOCKHEIGHT][TetrisGameType::BLOCKWIDTH];
		int Board_[TetrisGameType::STAGEHEIGHT][TetrisGameType::STAGEWIDTH];
		int BlockMaxMoveTime_;
		int BlockNowMoveTime_;
		int InputMaxMoveTime_;
		int InputNowMoveTime_;
		int SpaceDownMaxTime_;
		int SpaceDownNowTime_;
		int Collision_;
		bool LeftCollision_;
		bool RightCollision_;
		int TurnPoint_;
		TetrisGameType::Color TurnColor_[TetrisGameType::BLOCKHEIGHT][TetrisGameType::BLOCKWIDTH];
		int DrawBlock_[TetrisGameType::BLOCKHEIGHT][TetrisGameType::BLOCKWIDTH];
		TetrisGameType::Color DrawBlockColor_[TetrisGameType::BLOCKHEIGHT][TetrisGameType::BLOCKWIDTH];
		int TurnBlock_[TetrisGameType::BLOCKHEIGHT][TetrisGameType::BLOCKWIDTH];
	};
}