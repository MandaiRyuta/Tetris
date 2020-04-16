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
			BlockDoneCheck_(0x000),
			DownMoveAcceleration_(0),
			DownMoveCheck_(0x000),
			DownMoveMaxTime_(10),
			DownMoveNowTime_(0),
			SpaceDownCheck_(0x000),
			SpaceDownMaxTime_(15),
			SpaceDownNowTime_(0),
			RotateNowTime_(0),
			RotateMaxTime_(10),
			BlockDownCheck_(0x000),
			YblockCount_(0),
			Collision_(0),
			MakeBlock_(0x000),
			TurnPoint_(0),
			CheckBlock_(0x000),
			Blockdown_(0x000),
			LeftCollision_(false),
			RightCollision_(false),
			BottomCollision_(false),
			SpaceBarRefreshNowTime_(0),
			SpaceBarRefreshMaxTime_(15),
			SpaceBarRefreshCheck_(0x000),
			SideSpeed_(1),
			InputDownMoveCheck_(0x000),
			InputDownMoveMaxTime_(1),
			InputDownMoveNowTime_(0),
			SwapHoldBlockType_(9),
			HoldCheck_(0x000),
			HoldStockCheck_(1),
			BreakStockCheck_(0x000),
			GameBlockLevelFrame_(0),
			ChangeKeyStateCount_(0),
			WaitMakeBlcokTime_(0)
		{
			Position_.y = 0;
			Position_.x = 4;
			GameBlockState_ = 0;
		}
		~TetrisBlock(){}
	public:
		const int& GetHoldBlockType();
		void DrawBlock(int type, int vertical, int side, int positionX, int positionY);
		void ChangeRotate();
		void Init();
		void Update();
		void Draw();
		void Release();
		void StockBlock();
		void SwapBlock();
		const int& GetXBlockPosition();
		const int& GetYblockPosition();
		const int& GetBlockType();
		void SetBlockData(int data, int x, int y);
		const int& GetBlockData(int x, int y);
		void StageBlockCollisionLeft();
		void StageBlockCollisionRight();
		void StageBlockCollisionBottom();
		void StageBlockCollisionCenter();
		void BlockCollisionTurn();
		void MakeBlock();
		const int& GetStockBlock(int num);
		const signed short int& GetBlockDone();
		void SetBlockDone(signed short int blockdonecheck);
		//void InitBlocks();
		void GameInputState();
		void InputStateFirst(int& keyframe);
		void InputStateSecond(int& keyframe);
		void GameInputRight();
		void GameInputLeft();
		void GameBlockDownState();
		void GameBlockDownFirst(int& frame);
		void GameBlockDownSecond(int& frame);
		void GameBlockDownThird(int& frame);
	private:
		int SwapHoldBlockType_;
		signed short int HoldCheck_;
		signed short int HoldStockCheck_;
		signed short int BreakStockCheck_;
		std::array<int, 4> StockBlocks_;
		int YblockCount_;
		signed short int SpaceDownCheck_;
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
		bool BottomCollision_;

		int SpaceBarRefreshNowTime_;
		int SpaceBarRefreshMaxTime_;
		int RotateNowTime_;
		int RotateMaxTime_;

		int DownMoveNowTime_;
		int InputDownMoveNowTime_;
		int LeftMoveMaxTime_;
		int RightMoveMaxTime_;
		int DownMoveMaxTime_;
		int InputDownMoveMaxTime_;
		int DownMoveAcceleration_;
		int Blocknumber_;

		TetrisGameType::Vector2 Position_;
		TetrisGameType::BlockType Type_;
		TetrisGameType::Block Blocktype_[TetrisGameType::TetrisBlockTypeNum::MaxNumber][TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		int CopyBlock_[TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		int Board_[TetrisGameType::StageHeight][TetrisGameType::StageWidth];

		int SpaceDownMaxTime_;
		int SpaceDownNowTime_;
		int Collision_;
		int TurnPoint_;
		TetrisGameType::Color TurnColor_[TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		int DrawBlock_[TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		TetrisGameType::Color DrawBlockColor_[TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		int TurnBlock_[TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		int SideSpeed_;

		int InputSideCheck_;
		int ChangeKeyStateCount_;
		int KeyFrame_;
		int InputState_;
		int BlockMoveSpeed_;
		int GameBlockLevelFrame_;
		int GameBlockState_;
		int WaitMakeBlcokTime_;
	};
}