#pragma once
#include "Utils.h"

constexpr int BLOCKTYPE = 7;
constexpr int BLOCKSIZE = 4;

namespace TetrisBlocks
{
	class TetrisBlock
	{
	public:
		TetrisBlock():
			Blocknumber_(0),
			//Input_(nullptr),
			Type_(Utils::BlockType::I),
			Blocktype_()
		{
			OneMoveCheck = 0x000;
			Position_.x = 0;
			Position_.y = -1;
		}
		~TetrisBlock(){}
	public:
		void SetBlock(Utils::BlockType type);
		void DrawBlock(int type, int vertical, int side, int positionX, int positionY);
		void ChangeRotate();
		void Init();
		void Update();
		void Draw();
		void Release();
	
	private:
		//Input* Input_;
		signed short int OneMoveCheck;
		Utils::Vector2 Position_;
		int Blocknumber_;
		Utils::BlockType Type_;
		Utils::Block Blocktype_[BLOCKTYPE][BLOCKSIZE][BLOCKSIZE];
		int BlockMaxMoveTime_;
		int BlockNowMoveTime_;
	};
}