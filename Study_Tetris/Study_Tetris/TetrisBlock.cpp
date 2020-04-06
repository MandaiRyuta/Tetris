#include "TetrisBlock.h"
#include <random>

constexpr int LEFTPADDING = 3;
constexpr int UPPADDING = 3;
constexpr int RIGHTPADDING = 17;
constexpr int DOWNPADDING = 17;

void TetrisBlocks::TetrisBlock::SetBlock(TetrisGameType::BlockType type)
{

}

void TetrisBlocks::TetrisBlock::DrawBlock(int type, int vertical, int side, int positionX, int positionY)
{

	DrawBox(positionX + LEFTPADDING, positionY + UPPADDING, positionX + RIGHTPADDING, positionY + DOWNPADDING, GetColor(Blocktype_[type][vertical][side].r, Blocktype_[type][vertical][side].g, Blocktype_[type][vertical][side].b), true);
}

void TetrisBlocks::TetrisBlock::ChangeRotate()
{
}

void TetrisBlocks::TetrisBlock::Init()
{
	//Input_ = new Input(1);
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rndblocktype(0, 6);

	Blocknumber_ = rndblocktype(rnd);
	BlockMaxMoveTime_ = 2500;
	BlockNowMoveTime_ = 0;
	InputMaxMoveTime_ = 1500;
	InputNowMoveTime_ = 0;
	OneMoveCheck_ = 0x000;
	Position_.x = 4;
	Position_.y = 0;
	YblockCount_ = 0;
	Collision_ = 0;
	MakeBlock_ = 0x000;

	for (int y = 0; y < TetrisGameType::STAGEHEIGHT; y++)
	{
		for (int x = 0 ; x < TetrisGameType::STAGEWIDTH; x++)
		{
			Board_[y][x] = 0;

			if (x == 0 || x == 12)
			{
				Board_[y][x] = 9;
			}
			else if (y == 22)
			{
				Board_[y][x] = 9;
			}
		}
	}

	for (int y = 0; y < TetrisGameType::BLOCKHEIGHT; y++)
	{
		for (int x = 0; x < TetrisGameType::BLOCKWIDTH; x++)
		{
			CopyBlock_[y][x] = 0;
		}
	}
	//I
	Blocktype_[TetrisGameType::TYPEI][0][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEI][0][1] = {
		0,165,255,255,1
	};
	Blocktype_[TetrisGameType::TYPEI][0][2] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEI][0][3] = {
		255,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEI][1][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEI][1][1] = {
		0,165,255,255,1
	};
	Blocktype_[TetrisGameType::TYPEI][1][2] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEI][1][3] = {
		255,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEI][2][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEI][2][1] = {
		0,165,255,255,1
	};
	Blocktype_[TetrisGameType::TYPEI][2][2] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEI][2][3] = {
		255,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEI][3][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEI][3][1] = {
		0,165,255,255,1
	};
	Blocktype_[TetrisGameType::TYPEI][3][2] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEI][3][3] = {
		255,255,255,255,0
	};

	//J
	Blocktype_[TetrisGameType::TYPEJ][0][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEJ][0][1] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEJ][0][2] = {
		0,0,255,255,2
	};
	Blocktype_[TetrisGameType::TYPEJ][0][3] = {
		255,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEJ][1][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEJ][1][1] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEJ][1][2] = {
		0,0,255,255,2
	};
	Blocktype_[TetrisGameType::TYPEJ][1][3] = {
		255,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEJ][2][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEJ][2][1] = {
		0,0,255,255,2
	};
	Blocktype_[TetrisGameType::TYPEJ][2][2] = {
		0,0,255,255,2
	};
	Blocktype_[TetrisGameType::TYPEJ][2][3] = {
		255,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEJ][3][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEJ][3][1] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEJ][3][2] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEJ][3][3] = {
		255,255,255,255,0
	};

	//L
	Blocktype_[TetrisGameType::TYPEL][0][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEL][0][1] = {
		255,140,0,255,3
	};
	Blocktype_[TetrisGameType::TYPEL][0][2] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEL][0][3] = {
		255,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEL][1][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEL][1][1] = {
		255,140,0,255,3
	};
	Blocktype_[TetrisGameType::TYPEL][1][2] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEL][1][3] = {
		255,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEL][2][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEL][2][1] = {
		255,140,0,255,3
	};
	Blocktype_[TetrisGameType::TYPEL][2][2] = {
		255,140,0,255,3
	};
	Blocktype_[TetrisGameType::TYPEL][2][3] = {
		255,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEL][3][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEL][3][1] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEL][3][2] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEL][3][3] = {
		255,255,255,255,0
	};

	//O
	Blocktype_[TetrisGameType::TYPEO][0][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEO][0][1] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEO][0][2] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEO][0][3] = {
		255,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEO][1][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEO][1][1] = {
		255,255,0,255,4
	};
	Blocktype_[TetrisGameType::TYPEO][1][2] = {
		255,255,0,255,4
	};
	Blocktype_[TetrisGameType::TYPEO][1][3] = {
		255,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEO][2][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEO][2][1] = {
		255,255,0,255,4
	};
	Blocktype_[TetrisGameType::TYPEO][2][2] = {
		255,255,0,255,4
	};
	Blocktype_[TetrisGameType::TYPEO][2][3] = {
		255,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEO][3][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEO][3][1] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEO][3][2] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEO][3][3] = {
		255,255,255,255,0
	};

	//S
	Blocktype_[TetrisGameType::TYPES][0][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPES][0][1] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPES][0][2] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPES][0][3] = {
		255,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPES][1][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPES][1][1] = {
		124,252,0,255,5
	};
	Blocktype_[TetrisGameType::TYPES][1][2] = {
		124,252,0,255,5
	};
	Blocktype_[TetrisGameType::TYPES][1][3] = {
		255,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPES][2][0] = {
		124,252,0,255,5
	};
	Blocktype_[TetrisGameType::TYPES][2][1] = {
		124,252,0,255,5
	};
	Blocktype_[TetrisGameType::TYPES][2][2] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPES][2][3] = {
		255,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPES][3][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPES][3][1] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPES][3][2] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPES][3][3] = {
		255,255,255,255,0
	};

	//T
	Blocktype_[TetrisGameType::TYPET][0][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPET][0][1] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPET][0][2] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPET][0][3] = {
		255,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPET][1][0] = {
		255,0,255,255,6
	};
	Blocktype_[TetrisGameType::TYPET][1][1] = {
		255,0,255,255,6
	};
	Blocktype_[TetrisGameType::TYPET][1][2] = {
		255,0,255,255,6
	};
	Blocktype_[TetrisGameType::TYPET][1][3] = {
		255,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPET][2][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPET][2][1] = {
		255,0,255,255,6
	};
	Blocktype_[TetrisGameType::TYPET][2][2] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPET][2][3] = {
		255,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPET][3][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPET][3][1] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPET][3][2] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPET][3][3] = {
		255,255,255,255,0
	};

	//Z
	Blocktype_[TetrisGameType::TYPEZ][0][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEZ][0][1] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEZ][0][2] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEZ][0][3] = {
		255,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEZ][1][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEZ][1][1] = {
		255,0,0,255,7
	};
	Blocktype_[TetrisGameType::TYPEZ][1][2] = {
		255,0,0,255,7
	};
	Blocktype_[TetrisGameType::TYPEZ][1][3] = {
		255,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEZ][2][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEZ][2][1] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEZ][2][2] = {
		255,0,0,255,7
	};
	Blocktype_[TetrisGameType::TYPEZ][2][3] = {
		255,0,0,255,7
	};

	Blocktype_[TetrisGameType::TYPEZ][3][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEZ][3][1] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEZ][3][2] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEZ][3][3] = {
		255,255,255,255,0
	};
}

void TetrisBlocks::TetrisBlock::Update()
{
	//Input_->Update();
	if (BlockNowMoveTime_ > BlockMaxMoveTime_)
	{
		YblockCount_ += TetrisGameType::BLOCKSPEED;
		Position_.y = YblockCount_ / TetrisGameType::DRAWBLOCKWIDTH;
		BlockNowMoveTime_ = 0;
	}
	if (InputNowMoveTime_ > InputMaxMoveTime_)
	{
		InputNowMoveTime_ = 0x000;
		OneMoveCheck_ = 0x000;
	}

	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		StageBlockCollisionLeft();
		if (OneMoveCheck_ == 0x000 && Collision_ == 0)
		{
			Position_.x -= 1;
			OneMoveCheck_ = 0x001;
		}
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		StageBlockCollisionRight();
		if (OneMoveCheck_ == 0x000 && Collision_ == 0)
		{
			Position_.x += 1;
			OneMoveCheck_ = 0x001;
		}
	}

	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		if (OneMoveCheck_ == 0x000 && Position_.y < 22)
		{
			Position_.y = 18;
			OneMoveCheck_ = 0x001;
		}
	}
	
	if (Position_.y >= 18) {
		CopyBlock(Blocknumber_);
		Position_.y = 0;
		YblockCount_ = 0;
	}
	
	BlockNowMoveTime_++;
	InputNowMoveTime_++;
}

void TetrisBlocks::TetrisBlock::Draw()
{
	for (int i = 0; i < TetrisGameType::BLOCKHEIGHT; i++)
	{
		for (int j = 0; j < TetrisGameType::BLOCKWIDTH; j++)
		{
			DrawBlock(Blocknumber_, i, j, (Position_.x * TetrisGameType::BLOCKSPEED) * TetrisGameType::BLOCKWIDTH + j * TetrisGameType::DRAWBLOCKWIDTH,
				(Position_.y * TetrisGameType::BLOCKSPEED) * TetrisGameType::BLOCKHEIGHT + i * TetrisGameType::DRAWBLOCKWIDTH);
		}
	}
}

void TetrisBlocks::TetrisBlock::Release()
{
}

int TetrisBlocks::TetrisBlock::GetXBlockPosition()
{
	return Position_.x;
}

int TetrisBlocks::TetrisBlock::GetYblockPosition()
{
	return Position_.y;
}

int TetrisBlocks::TetrisBlock::GetBlockInfo(int x, int y)
{
	return CopyBlock_[x][y];
}

void TetrisBlocks::TetrisBlock::CopyBlock(int blocktype)
{
	for (int i = 0; i < TetrisGameType::BLOCKHEIGHT; i++)
	{
		for (int j = 0; j < TetrisGameType::BLOCKWIDTH; j++)
		{
			CopyBlock_[i][j] = Blocktype_[blocktype][i][j].type;
			Board_[Position_.x][Position_.y] = Blocktype_[blocktype][i][j].type;
		}
	}
	
}

void TetrisBlocks::TetrisBlock::SetBoardInfo(int boardinfo, int x, int y)
{
	Board_[x][y] = boardinfo;
}

void TetrisBlocks::TetrisBlock::StageBlockCollisionLeft()
{
	Collision_ = 0;

	for (int y = 0; y < TetrisGameType::BLOCKHEIGHT; y++)
	{
		for (int x = 0; x < TetrisGameType::BLOCKWIDTH; x++)
		{
			if (Blocktype_[Blocknumber_][y][x].type != 0)
			{
				if (Board_[Position_.y + y][Position_.x + (x - 1)] != 0)
				{
					Collision_ = 1;
				}
				else if (YblockCount_ - (Position_.y * TetrisGameType::BLOCKHEIGHT * TetrisGameType::DRAWBLOCKWIDTH) > 0)
				{
					if (Board_[Position_.y + (y + 1)][Position_.x + (x - 1)] != 0)
					{
						Collision_ = 1;
					}
				}
			}
		}
	}
}

void TetrisBlocks::TetrisBlock::StageBlockCollisionRight()
{
	Collision_ = 0;

	for (int y = 0; y < TetrisGameType::BLOCKHEIGHT; y++)
	{
		for (int x = 0; x < TetrisGameType::BLOCKWIDTH; x++)
		{
			if (Blocktype_[Blocknumber_][y][x].type != 0)
			{
				if (Board_[Position_.y + y][Position_.x + (x + 1)] != 0)
				{
					Collision_ = 1;
				}
				else if (YblockCount_ - (Position_.y * TetrisGameType::BLOCKHEIGHT * TetrisGameType::DRAWBLOCKWIDTH) > 0)
				{
					if (Board_[Position_.y + (y + 1)][Position_.x + (x + 1)] != 0)
					{
						Collision_ = 1;
					}
				}
			}
		}
	}
}

void TetrisBlocks::TetrisBlock::StageBlockCollisionBottom()
{
	Collision_ = 0;

	for (int y = 0; y < TetrisGameType::BLOCKHEIGHT; y++)
	{
		for (int x = 0; x < TetrisGameType::BLOCKWIDTH; x++)
		{
			if (Blocktype_[Blocknumber_][y][x].type != 0)
			{
				if (Board_[Position_.y + y][Position_.x + x] != 0)
				{
					Collision_ = 1;
				}
			}
		}
	}
}

void TetrisBlocks::TetrisBlock::MakeBlock()
{
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rndblocktype(0, 6);

	if(MakeBlock_ == 0x001)
	{
		Blocknumber_ = rndblocktype(rnd);

		MakeBlock_ = 0x000;
	}
}
