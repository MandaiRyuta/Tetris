#include "TetrisBlock.h"
#include "Input.h"
constexpr int LEFTPADDING = 3;
constexpr int UPPADDING = 3;
constexpr int RIGHTPADDING = 17;
constexpr int DOWNPADDING = 17;

void TetrisBlocks::TetrisBlock::SetBlock(Utils::BlockType type)
{
	switch (type)
	{
	case Utils::BlockType::I:
		//DrawRotaGraph3
		break;
	case Utils::BlockType::J:
		break;
	case Utils::BlockType::L:
		break;
	case Utils::BlockType::O:
		break;
	case Utils::BlockType::S:
		break;
	case Utils::BlockType::T:
		break;
	case Utils::BlockType::Z:
		break;
	}
}

void TetrisBlocks::TetrisBlock::DrawBlock(int type, int vertical, int side, int positionX, int positionY)
{
	if (Blocktype_[type][vertical][side].type == 1)
	{
		DrawBox(positionX + LEFTPADDING, positionY + UPPADDING, positionX + RIGHTPADDING, positionY + DOWNPADDING, GetColor(Blocktype_[type][vertical][side].r, Blocktype_[type][vertical][side].g, Blocktype_[type][vertical][side].b), true);
	}
}

void TetrisBlocks::TetrisBlock::ChangeRotate()
{
}

void TetrisBlocks::TetrisBlock::Init()
{
	//Input_ = new Input(1);
	
	Blocknumber_ = 0;
	BlockMaxMoveTime_ = 3400;
	BlockNowMoveTime_ = 0;
	const auto TypeI = static_cast<int>(Utils::BlockType::I);
	const auto TypeJ = static_cast<int>(Utils::BlockType::J);
	const auto TypeL = static_cast<int>(Utils::BlockType::L);
	const auto TypeO = static_cast<int>(Utils::BlockType::O);
	const auto TypeS = static_cast<int>(Utils::BlockType::S);
	const auto TypeT = static_cast<int>(Utils::BlockType::T);
	const auto TypeZ = static_cast<int>(Utils::BlockType::Z);

	//I
	Blocktype_[static_cast<int>(TypeI)][0][0] = {
		255,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeI)][0][1] = {
		0,165,255,255,1
	};
	Blocktype_[static_cast<int>(TypeI)][0][2] = {
		255,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeI)][0][3] = {
		255,255,255,255,0
	};

	Blocktype_[static_cast<int>(TypeI)][1][0] = {
		255,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeI)][1][1] = {
		0,165,255,255,1
	};
	Blocktype_[static_cast<int>(TypeI)][1][2] = {
		255,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeI)][1][3] = {
		255,255,255,255,0
	};

	Blocktype_[static_cast<int>(TypeI)][2][0] = {
		255,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeI)][2][1] = {
		0,165,255,255,1
	};
	Blocktype_[static_cast<int>(TypeI)][2][2] = {
		255,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeI)][2][3] = {
		255,255,255,255,0
	};

	Blocktype_[static_cast<int>(TypeI)][3][0] = {
		255,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeI)][3][1] = {
		0,165,255,255,1
	};
	Blocktype_[static_cast<int>(TypeI)][3][2] = {
		255,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeI)][3][3] = {
		255,255,255,255,0
	};

	//J
	Blocktype_[static_cast<int>(TypeJ)][0][0] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeJ)][0][1] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeJ)][0][2] = {
		0,0,255,255,2
	};
	Blocktype_[static_cast<int>(TypeJ)][0][3] = {
		0,255,255,255,0
	};

	Blocktype_[static_cast<int>(TypeJ)][1][0] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeJ)][1][1] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeJ)][1][2] = {
		0,0,255,255,2
	};
	Blocktype_[static_cast<int>(TypeJ)][1][3] = {
		0,255,255,255,0
	};

	Blocktype_[static_cast<int>(TypeJ)][2][0] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeJ)][2][1] = {
		0,0,255,255,2
	};
	Blocktype_[static_cast<int>(TypeJ)][2][2] = {
		0,0,255,255,2
	};
	Blocktype_[static_cast<int>(TypeJ)][2][3] = {
		0,255,255,255,0
	};

	Blocktype_[static_cast<int>(TypeJ)][3][0] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeJ)][3][1] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeJ)][3][2] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeJ)][3][3] = {
		0,255,255,255,0
	};

	//L
	Blocktype_[static_cast<int>(TypeL)][0][0] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeL)][0][1] = {
		255,140,0,255,3
	};
	Blocktype_[static_cast<int>(TypeL)][0][2] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeL)][0][3] = {
		0,255,255,255,0
	};

	Blocktype_[static_cast<int>(TypeL)][1][0] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeL)][1][1] = {
		255,140,0,255,3
	};
	Blocktype_[static_cast<int>(TypeL)][1][2] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeL)][1][3] = {
		0,255,255,255,0
	};

	Blocktype_[static_cast<int>(TypeL)][2][0] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeL)][2][1] = {
		255,140,0,255,3
	};
	Blocktype_[static_cast<int>(TypeL)][2][2] = {
		255,140,0,255,3
	};
	Blocktype_[static_cast<int>(TypeL)][2][3] = {
		0,255,255,255,0
	};

	Blocktype_[static_cast<int>(TypeL)][3][0] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeL)][3][1] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeL)][3][2] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeL)][3][3] = {
		0,255,255,255,0
	};

	//O
	Blocktype_[static_cast<int>(TypeO)][0][0] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeO)][0][1] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeO)][0][2] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeO)][0][3] = {
		0,255,255,255,0
	};

	Blocktype_[static_cast<int>(TypeO)][1][0] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeO)][1][1] = {
		255,255,0,255,4
	};
	Blocktype_[static_cast<int>(TypeO)][1][2] = {
		255,255,0,255,4
	};
	Blocktype_[static_cast<int>(TypeO)][1][3] = {
		0,255,255,255,0
	};

	Blocktype_[static_cast<int>(TypeO)][2][0] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeO)][2][1] = {
		255,255,0,255,4
	};
	Blocktype_[static_cast<int>(TypeO)][2][2] = {
		255,255,0,255,4
	};
	Blocktype_[static_cast<int>(TypeO)][2][3] = {
		0,255,255,255,0
	};

	Blocktype_[static_cast<int>(TypeO)][3][0] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeO)][3][1] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeO)][3][2] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeO)][3][3] = {
		0,255,255,255,0
	};

	//S
	Blocktype_[static_cast<int>(TypeS)][0][0] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeS)][0][1] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeS)][0][2] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeS)][0][3] = {
		0,255,255,255,0
	};

	Blocktype_[static_cast<int>(TypeS)][1][0] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeS)][1][1] = {
		124,252,0,255,5
	};
	Blocktype_[static_cast<int>(TypeS)][1][2] = {
		124,252,0,255,5
	};
	Blocktype_[static_cast<int>(TypeS)][1][3] = {
		0,255,255,255,0
	};

	Blocktype_[static_cast<int>(TypeS)][2][0] = {
		124,252,0,255,5
	};
	Blocktype_[static_cast<int>(TypeS)][2][1] = {
		124,252,0,255,5
	};
	Blocktype_[static_cast<int>(TypeS)][2][2] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeS)][2][3] = {
		0,255,255,255,0
	};

	Blocktype_[static_cast<int>(TypeS)][3][0] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeS)][3][1] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeS)][3][2] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeS)][3][3] = {
		0,255,255,255,0
	};

	//T
	Blocktype_[static_cast<int>(TypeT)][0][0] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeT)][0][1] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeT)][0][2] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeT)][0][3] = {
		0,255,255,255,0
	};

	Blocktype_[static_cast<int>(TypeT)][1][0] = {
		255,0,255,255,6
	};
	Blocktype_[static_cast<int>(TypeT)][1][1] = {
		255,0,255,255,6
	};
	Blocktype_[static_cast<int>(TypeT)][1][2] = {
		255,0,255,255,6
	};
	Blocktype_[static_cast<int>(TypeT)][1][3] = {
		0,255,255,255,0
	};

	Blocktype_[static_cast<int>(TypeT)][2][0] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeT)][2][1] = {
		255,0,255,255,6
	};
	Blocktype_[static_cast<int>(TypeT)][2][2] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeT)][2][3] = {
		0,255,255,255,0
	};

	Blocktype_[static_cast<int>(TypeT)][3][0] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeT)][3][1] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeT)][3][2] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeT)][3][3] = {
		0,255,255,255,0
	};

	//Z
	Blocktype_[static_cast<int>(TypeZ)][0][0] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeZ)][0][1] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeZ)][0][2] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeZ)][0][3] = {
		0,255,255,255,0
	};

	Blocktype_[static_cast<int>(TypeZ)][1][0] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeZ)][1][1] = {
		255,0,0,255,7
	};
	Blocktype_[static_cast<int>(TypeZ)][1][2] = {
		255,0,0,255,7
	};
	Blocktype_[static_cast<int>(TypeZ)][1][3] = {
		0,255,255,255,0
	};

	Blocktype_[static_cast<int>(TypeZ)][2][0] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeZ)][2][1] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeZ)][2][2] = {
		255,0,0,255,7
	};
	Blocktype_[static_cast<int>(TypeZ)][2][3] = {
		255,0,0,255,7
	};

	Blocktype_[static_cast<int>(TypeZ)][3][0] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeZ)][3][1] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeZ)][3][2] = {
		0,255,255,255,0
	};
	Blocktype_[static_cast<int>(TypeZ)][3][3] = {
		0,255,255,255,0
	};
}

void TetrisBlocks::TetrisBlock::Update()
{
	//Input_->Update();
	if (BlockNowMoveTime_ > BlockMaxMoveTime_)
	{
		Position_.y += 20;
		OneMoveCheck = 0x000;
		BlockNowMoveTime_ = 0;
	}
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		if (OneMoveCheck == 0x000)
		{
			Position_.x -= 20;
			OneMoveCheck = 0x001;
		}
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		if (OneMoveCheck == 0x000)
		{
			Position_.x += 20;
			OneMoveCheck = 0x001;
		}
	}

	BlockNowMoveTime_++;
}

void TetrisBlocks::TetrisBlock::Draw()
{
	switch (Blocknumber_)
	{
	case 0:
		for (int i = 0; i < BLOCKSIZE; i++)
		{
			for (int j = 0; j < BLOCKSIZE; j++)
			{   
				DrawBlock(0, i, j, Position_.x + (j * 20), Position_.y + (i * 20));
			}
		}
		break;
	//case 1:
	//	for (int i = 0; i < BLOCKSIZE; i++)
	//	{
	//		for (int j = 0; j < BLOCKSIZE; j++)
	//		{
	//			DrawBlock(1, Position_.x, Position_.y);
	//		}
	//	}
	//	break;
	//case 2:
	//	for (int i = 0; i < BLOCKSIZE; i++)
	//	{
	//		for (int j = 0; j < BLOCKSIZE; j++)
	//		{
	//			DrawBlock(2, Position_.x, Position_.y);
	//		}
	//	}
	//	break;
	//case 3:
	//	for (int i = 0; i < BLOCKSIZE; i++)
	//	{
	//		for (int j = 0; j < BLOCKSIZE; j++)
	//		{
	//			DrawBlock(3, Position_.x, Position_.y);
	//		}
	//	}
	//	break;
	//case 4:
	//	for (int i = 0; i < BLOCKSIZE; i++)
	//	{
	//		for (int j = 0; j < BLOCKSIZE; j++)
	//		{
	//			DrawBlock(4, Position_.x, Position_.y);
	//		}
	//	}
	//	break;
	//case 5:
	//	for (int i = 0; i < BLOCKSIZE; i++)
	//	{
	//		for (int j = 0; j < BLOCKSIZE; j++)
	//		{
	//			DrawBlock(5, Position_.x, Position_.y);
	//		}
	//	}
	//	break;
	//case 6:
	//	for (int i = 0; i < BLOCKSIZE; i++)
	//	{
	//		for (int j = 0; j < BLOCKSIZE; j++)
	//		{
	//			DrawBlock(6, Position_.x, Position_.y);
	//		}
	//	}
	//	break;
	}
}

void TetrisBlocks::TetrisBlock::Release()
{
}
