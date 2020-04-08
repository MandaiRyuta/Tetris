#pragma once
#include "../TetrisGameType/TetrisGameType.h"
//constexpr int BLOCKTYPE = 7;
//constexpr int BLOCKSIZE = 4;

namespace TetrisBlocks
{
	class TetrisBlock
	{
	public:
		TetrisBlock() :
			Blocknumber_(0),
			//Input_(nullptr),
			Type_(TetrisGameType::BlockType::I),
			BlockMaxMoveTime_(2500),
			BlockNowMoveTime_(0),
			BlockDoneCheck_(0x000),
			LeftMoveAcceleration_(0),
			LeftMoveMaxTime_(2100),
			LeftMoveNowTime_(0),
			LeftMoveCheck_(0x000),
			RightMoveAcceleration_(0),
			RightMoveMaxTime_(2100),
			RightMoveNowTime_(0),
			RightMoveCheck_(0x000),
			DownMoveAcceleration_(0),
			DownMoveCheck_(0x000),
			DownMoveMaxTime_(2000),
			DownMoveNowTime_(0),
			SpaceDownCheck_(0x000),
			SpaceDownMaxTime_(1800),
			SpaceDownNowTime_(0),
			RotateNowTime_(0),
			RotateMaxTime_(720),
			BlockDownCheck_(0x000),
			YblockCount_(0),
			Collision_(0),
			MakeBlock_(0x000),
			TurnPoint_(0),
			CheckBlock_(0x000),
			Blockdown_(0x000),
			LeftCollision_(false),
			RightCollision_(false),
			SpaceBarRefreshNowTime_(0),
			SpaceBarRefreshMaxTime_(1000),
			SpaceBarRefreshCheck_(0x000),
			SideSpeed_(1),
			InputDownMoveCheck_(0x000),
			InputDownMoveMaxTime_(100),
			InputDownMoveNowTime_(0)
		{
			Position_.y = 0;
			Position_.x = 4;
			
			/*BlockMaxMoveTime_ = 2500;
			BlockNowMoveTime_ = 0;
			LeftMoveAcceleration_ = 0;
			LeftMoveMaxTime_ = 1500;
			LeftMoveNowTime_ = 0;
			LeftMoveCheck_ = 0x000;
			RightMoveAcceleration_ = 0;
			RightMoveMaxTime_ = 1500;
			RightMoveNowTime_ = 0;
			RightMoveCheck_ = 0x000;
			DownMoveAcceleration_ = 0;
			DownMoveMaxTime_ = 2000;
			DownMoveNowTime_ = 0;
			DownMoveCheck_ = 0x000;
			SpaceDownCheck_ = 0x000;
			SpaceDownMaxTime_ = 1800;
			SpaceDownNowTime_ = 0;
			RotateNowTime_ = 0;
			RotateMaxTime_ = 900;
			BlockDownCheck_ = 0x000;
			Position_.x = 4;
			Position_.y = 0;
			YblockCount_ = 0;
			Collision_ = 0;
			MakeBlock_ = 0x000;
			TurnPoint_ = 0;

			CheckBlock_ = 0x000;
			Blockdown_ = 0x000;
			LeftCollision_ = false;
			RightCollision_ = false;
			BlockDoneCheck_ = 0x000;
			SpaceBarRefreshNowTime_ = 0;
			SpaceBarRefreshCheck_ = 0x000;
			SpaceBarRefreshMaxTime_ = 1000;*/
		}
		~TetrisBlock(){}
	public:
		void FrameCount();
		void SetBlock(TetrisGameType::BlockType type);
		void DrawBlock(int type, int vertical, int side, int positionX, int positionY);
		void ChangeRotate();
		void Init();
		void Update();
		void Draw();
		void Release();
		void StockBlock();
		void SwapBlock();
		int GetXBlockPosition();
		int GetYblockPosition();
		int GetBlockType();
		int GetBlockData(int x, int y);
		void StageBlockCollisionLeft();
		void StageBlockCollisionRight();
		void StageBlockCollisionBottom();
		void StageBlockCollisionCenter();
		void BlockCollisionTurn();
		void MakeBlock();
		int GetStockBlock(int num);
		signed short int GetBlockDone();
		void SetBlockDone(signed short int blockdonecheck);
		void InitBlocks();
	private:
		std::array<int, TetrisGameType::TetrisBlockTypeNum::MaxNumber> StockBlocks_;
		int YblockCount_;
		signed short int SpaceDownCheck_;
		signed short int LeftMoveCheck_;
		signed short int RightMoveCheck_;
		signed short int InputDownMoveCheck_;
		signed short int DownMoveCheck_;
		signed short int BlockDownCheck_;
		signed short int BlockRotateCheck_;
		signed short int BlockDoneCheck_;
		signed short int SpaceBarRefreshCheck_;
		signed short int MakeBlock_;
		signed short int BottomBlockCheck_;
		signed short int CheckBlock_;
		signed short int Blockdown_;
		bool LeftCollision_;
		bool RightCollision_;

		int SpaceBarRefreshNowTime_;
		int SpaceBarRefreshMaxTime_;
		int RotateNowTime_;
		int RotateMaxTime_;
		int LeftMoveNowTime_;
		int RightMoveNowTime_;
		int DownMoveNowTime_;
		int InputDownMoveNowTime_;
		int LeftMoveMaxTime_;
		int RightMoveMaxTime_;
		int DownMoveMaxTime_;
		int InputDownMoveMaxTime_;
		int LeftMoveAcceleration_;
		int RightMoveAcceleration_;
		int DownMoveAcceleration_;
		int Blocknumber_;

		TetrisGameType::Vector2 Position_;
		TetrisGameType::BlockType Type_;
		TetrisGameType::Block Blocktype_[TetrisGameType::TetrisBlockTypeNum::MaxNumber][TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		int CopyBlock_[TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		int Board_[TetrisGameType::StageHeight][TetrisGameType::StageWidth];
		int BlockMaxMoveTime_;
		int BlockNowMoveTime_;
		int SpaceDownMaxTime_;
		int SpaceDownNowTime_;
		int Collision_;
		int TurnPoint_;
		TetrisGameType::Color TurnColor_[TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		int DrawBlock_[TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		TetrisGameType::Color DrawBlockColor_[TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		int TurnBlock_[TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		int SideSpeed_;
	};
}