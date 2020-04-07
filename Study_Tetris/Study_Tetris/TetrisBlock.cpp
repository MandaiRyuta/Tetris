#include "TetrisBlock.h"
#include <random>

constexpr int LEFTPADDING = 3;
constexpr int UPPADDING = 3;
constexpr int RIGHTPADDING = 17;
constexpr int DOWNPADDING = 17;

/*
	明日、ブロックの種類ごとに回転指定＋色の表示バグ修正。
*/
void TetrisBlocks::TetrisBlock::SetBlock(TetrisGameType::BlockType type)
{

}

void TetrisBlocks::TetrisBlock::DrawBlock(int type, int vertical, int side, int positionX, int positionY)
{
	if (DrawBlock_[vertical][side] != 9)
	{
		DrawBox(positionX + LEFTPADDING, positionY + UPPADDING, positionX + RIGHTPADDING, positionY + DOWNPADDING,
			GetColor(DrawBlockColor_[vertical][side].r, DrawBlockColor_[vertical][side].g, DrawBlockColor_[vertical][side].b), true);
	}
}

void TetrisBlocks::TetrisBlock::ChangeRotate()
{
	TurnPoint_++;

	for (int y = 0; y < TetrisGameType::BLOCKHEIGHT; y++)
	{
		for (int x = 0; x < TetrisGameType::BLOCKWIDTH; x++)
		{
			TurnBlock_[y][x] = DrawBlock_[3 - x][y];

			DrawBlockColor_[y][x].r = TurnColor_[3 - x][y].r;
			DrawBlockColor_[y][x].g = TurnColor_[3 - x][y].g;
			DrawBlockColor_[y][x].b = TurnColor_[3 - x][y].b;
		}
	}

	BlockCollisionTurn();

	if (Collision_ == 0)
	{
		for (int y = 0; y < TetrisGameType::BLOCKHEIGHT; y++)
		{
			for (int x = 0; x < TetrisGameType::BLOCKWIDTH; x++)
			{
				DrawBlock_[y][x] = TurnBlock_[y][x];
			}
		}
	}
	else
	{
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				DrawBlock_[y][x] = TurnBlock_[y][x];
			}
		}

		if (LeftCollision_)
		{
			switch (Blocknumber_)
			{
			case 0: 
				Position_.x += 2;
				break;
			case 1:
				Position_.x += 1;
				break;
			case 2:
				Position_.x += 1;
				break;
			case 3:
				break;
			case 4:
				Position_.x += 1;
				break;
			case 5:
				Position_.x += 1;
				break;
			case 6:
				Position_.x += 1;
				break;
			}
			LeftCollision_ = false;
		}
		else if (RightCollision_)
		{
			switch (Blocknumber_)
			{
			case 0:
				Position_.x -= 4;
				break;
			case 1:
				//
				Position_.x -= 4;
				break;
			case 2:
				Position_.x -= 4;
				break;
			case 3:
				
				break;
			case 4:
				Position_.x -= 2;
				break;
			case 5:
				Position_.x -= 3;
				break;
			case 6:
				Position_.x -= 3;
				break;
			}
			RightCollision_ = false;
		}


		TurnPoint_--;
	}
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
	InputMaxMoveTime_ = 1200;
	InputNowMoveTime_ = 0;
	LeftMoveAcceleration_ = 0;
	LeftMoveMaxTime_ = 1200;
	LeftMoveNowTime_ = 0;
	LeftMoveCheck_ = 0x000;
	RightMoveAcceleration_ = 0;
	RightMoveMaxTime_ = 1200;
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
	RotateMaxTime_ = 1200;
	BlockDownCheck_ = 0x000;
	OneMoveCheck_ = 0x000;
	Position_.x = 4;
	Position_.y = 0;
	YblockCount_ = 0;
	Collision_ = 0;
	MakeBlock_ = 0x000;
	TurnPoint_ = 0;

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
	//I
	Blocktype_[TetrisGameType::TYPEI][0][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEI][0][1] = {
		0,165,255,255,1
	};
	Blocktype_[TetrisGameType::TYPEI][0][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEI][0][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TYPEI][1][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEI][1][1] = {
		0,165,255,255,1
	};
	Blocktype_[TetrisGameType::TYPEI][1][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEI][1][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TYPEI][2][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEI][2][1] = {
		0,165,255,255,1
	};
	Blocktype_[TetrisGameType::TYPEI][2][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEI][2][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TYPEI][3][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEI][3][1] = {
		0,165,255,255,1
	};
	Blocktype_[TetrisGameType::TYPEI][3][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEI][3][3] = {
		0,255,255,255,9
	};

	//J
	Blocktype_[TetrisGameType::TYPEJ][0][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEJ][0][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEJ][0][2] = {
		0,0,255,255,2
	};
	Blocktype_[TetrisGameType::TYPEJ][0][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TYPEJ][1][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEJ][1][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEJ][1][2] = {
		0,0,255,255,2
	};
	Blocktype_[TetrisGameType::TYPEJ][1][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TYPEJ][2][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEJ][2][1] = {
		0,0,255,255,2
	};
	Blocktype_[TetrisGameType::TYPEJ][2][2] = {
		0,0,255,255,2
	};
	Blocktype_[TetrisGameType::TYPEJ][2][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TYPEJ][3][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEJ][3][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEJ][3][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEJ][3][3] = {
		0,255,255,255,9
	};

	//L
	Blocktype_[TetrisGameType::TYPEL][0][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEL][0][1] = {
		255,140,0,255,3
	};
	Blocktype_[TetrisGameType::TYPEL][0][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEL][0][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TYPEL][1][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEL][1][1] = {
		255,140,0,255,3
	};
	Blocktype_[TetrisGameType::TYPEL][1][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEL][1][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TYPEL][2][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEL][2][1] = {
		255,140,0,255,3
	};
	Blocktype_[TetrisGameType::TYPEL][2][2] = {
		255,140,0,255,3
	};
	Blocktype_[TetrisGameType::TYPEL][2][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TYPEL][3][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEL][3][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEL][3][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEL][3][3] = {
		0,255,255,255,9
	};

	//O
	Blocktype_[TetrisGameType::TYPEO][0][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEO][0][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEO][0][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEO][0][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TYPEO][1][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEO][1][1] = {
		255,255,0,255,4
	};
	Blocktype_[TetrisGameType::TYPEO][1][2] = {
		255,255,0,255,4
	};
	Blocktype_[TetrisGameType::TYPEO][1][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TYPEO][2][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEO][2][1] = {
		255,255,0,255,4
	};
	Blocktype_[TetrisGameType::TYPEO][2][2] = {
		255,255,0,255,4
	};
	Blocktype_[TetrisGameType::TYPEO][2][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TYPEO][3][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEO][3][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEO][3][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEO][3][3] = {
		0,255,255,255,9
	};

	//S
	Blocktype_[TetrisGameType::TYPES][0][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPES][0][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPES][0][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPES][0][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TYPES][1][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPES][1][1] = {
		124,252,0,255,5
	};
	Blocktype_[TetrisGameType::TYPES][1][2] = {
		124,252,0,255,5
	};
	Blocktype_[TetrisGameType::TYPES][1][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TYPES][2][0] = {
		124,252,0,255,5
	};
	Blocktype_[TetrisGameType::TYPES][2][1] = {
		124,252,0,255,5
	};
	Blocktype_[TetrisGameType::TYPES][2][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPES][2][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TYPES][3][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPES][3][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPES][3][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPES][3][3] = {
		0,255,255,255,9
	};

	//T
	Blocktype_[TetrisGameType::TYPET][0][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPET][0][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPET][0][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPET][0][3] = {
		0,255,255,255,9
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
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TYPET][2][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPET][2][1] = {
		255,0,255,255,6
	};
	Blocktype_[TetrisGameType::TYPET][2][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPET][2][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TYPET][3][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPET][3][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPET][3][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPET][3][3] = {
		0,255,255,255,9
	};

	//Z
	Blocktype_[TetrisGameType::TYPEZ][0][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEZ][0][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEZ][0][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEZ][0][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TYPEZ][1][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEZ][1][1] = {
		255,0,0,255,7
	};
	Blocktype_[TetrisGameType::TYPEZ][1][2] = {
		255,0,0,255,7
	};
	Blocktype_[TetrisGameType::TYPEZ][1][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TYPEZ][2][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEZ][2][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEZ][2][2] = {
		255,0,0,255,7
	};
	Blocktype_[TetrisGameType::TYPEZ][2][3] = {
		255,0,0,255,7
	};

	Blocktype_[TetrisGameType::TYPEZ][3][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEZ][3][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEZ][3][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TYPEZ][3][3] = {
		0,255,255,255,9
	};

	for (int y = 0; y < TetrisGameType::BLOCKHEIGHT; y++)
	{
		for (int x = 0; x < TetrisGameType::BLOCKWIDTH; x++)
		{
			TurnBlock_[y][x] = 0;
			CopyBlock_[y][x] = 0;
			CopyBlock_[y][x] = Blocktype_[Blocknumber_][y][x].type;
			TurnColor_[y][x].r = 0;
			TurnColor_[y][x].g = 0;
			TurnColor_[y][x].b = 0;
			DrawBlock_[y][x] = Blocktype_[Blocknumber_][y][x].type;
			DrawBlockColor_[y][x].r = Blocktype_[Blocknumber_][y][x].r;
			DrawBlockColor_[y][x].g = Blocktype_[Blocknumber_][y][x].g;
			DrawBlockColor_[y][x].b = Blocktype_[Blocknumber_][y][x].b;
		}
	}
	CheckBlock_ = 0x000;
	Blockdown_ = 0x000;
	LeftCollision_ = false;
	RightCollision_ = false;
	BlockDoneCheck_ = 0x000;
	SpaceBarRefreshNowTime_ = 0;
	SpaceBarRefreshCheck_ = 0x000;
	SpaceBarRefreshMaxTime_ = 1000;
}

void TetrisBlocks::TetrisBlock::Update()
{	
	if (SpaceBarRefreshNowTime_ > SpaceBarRefreshMaxTime_)
	{
		SpaceDownCheck_ = 0x000;
		SpaceBarRefreshNowTime_ = 0;
	}
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			TurnColor_[y][x].r = DrawBlockColor_[y][x].r;
			TurnColor_[y][x].g = DrawBlockColor_[y][x].g;
			TurnColor_[y][x].b = DrawBlockColor_[y][x].b;
		}
	}

	if (MakeBlock_ == 0x001)
	{
		BlockDownCheck_ = 0x000;
		MakeBlock();
		MakeBlock_ = 0x000;
	}

	if (Blockdown_ != 0x000)
	{
		YblockCount_ += TetrisGameType::BLOCKSPEED;
		Position_.y = YblockCount_ / TetrisGameType::DRAWBLOCKWIDTH;
		DownMoveNowTime_ = 0;
		BlockDownCheck_ = 0x001;
	}
	else if (Blockdown_ == 0x000 && BlockDownCheck_ == 0x000)
	{
		if (BlockNowMoveTime_ > BlockMaxMoveTime_)
		{
			YblockCount_ += TetrisGameType::BLOCKSPEED;
			Position_.y = YblockCount_ / TetrisGameType::DRAWBLOCKWIDTH;
			BlockNowMoveTime_ = 0;
		}
		if (RotateNowTime_ > RotateMaxTime_)
		{
			RotateNowTime_ = 0;
			BlockRotateCheck_ = 0x000;
		}
		if (InputNowMoveTime_ > InputMaxMoveTime_)
		{
			InputNowMoveTime_ = 0x000;
			OneMoveCheck_ = 0x000;
		}
		if(SpaceDownNowTime_ > SpaceDownMaxTime_)
		{
			SpaceDownNowTime_ = 0;
			SpaceDownCheck_ = 0x000;
		}
		if (RightMoveAcceleration_ > 400)
		{
			RightMoveNowTime_ += 3;
		}
		if (LeftMoveAcceleration_ > 400)
		{
			LeftMoveNowTime_ += 3;
		}
		if (DownMoveAcceleration_ > 200)
		{
			DownMoveNowTime_ += 2;
		}
		if (RightMoveNowTime_ > RightMoveMaxTime_)
		{
			RightMoveNowTime_ = 0;
			RightMoveCheck_ = 0x000;
		}
		if (LeftMoveNowTime_ > LeftMoveMaxTime_)
		{
			LeftMoveNowTime_ = 0;
			LeftMoveCheck_ = 0x000;
		}
		if (DownMoveNowTime_ > DownMoveMaxTime_)
		{
			DownMoveNowTime_ = 0;
			DownMoveCheck_ = 0x000;
		}
	}

	if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		if (BlockRotateCheck_ == 0x000 && Collision_ == 0)
		{
			ChangeRotate();
			BlockRotateCheck_ = 0x001;
		}
	}

	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		if (CheckHitKey(KEY_INPUT_SPACE) == 1 && SpaceDownCheck_ == 0x000)
		{
			if (Collision_ == 0)
			{
				Blockdown_ = 0x001;
				SpaceDownCheck_ = 0x001;
				SpaceBarRefreshCheck_ = 0x001;
			}
		}
		LeftMoveAcceleration_++;
		StageBlockCollisionLeft();
		if (LeftMoveCheck_ == 0x000 && Collision_ == 0)
		{
			Position_.x -= 1;
			LeftMoveCheck_ = 0x001;
		}
	}
	else
	{
		LeftMoveAcceleration_ = 0;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		if (CheckHitKey(KEY_INPUT_SPACE) == 1 && SpaceDownCheck_ == 0x000)
		{
			if (Collision_ == 0)
			{
				Blockdown_ = 0x001;
				SpaceDownCheck_ = 0x001;
				SpaceBarRefreshCheck_ = 0x001;
			}
		}

		RightMoveAcceleration_++;
		StageBlockCollisionRight();
		if (RightMoveCheck_ == 0x000 && Collision_ == 0)
		{
			Position_.x += 1;
			RightMoveCheck_ = 0x001;
		}
	}
	else
	{
		RightMoveAcceleration_ = 0;
	}

	if (CheckHitKey(KEY_INPUT_SPACE) == 1 && SpaceDownCheck_ == 0x000)
	{
		if (Collision_ == 0)
		{
			Blockdown_ = 0x001;
			SpaceDownCheck_ = 0x001;
			SpaceBarRefreshCheck_ = 0x001;
		}
	}

	StageBlockCollisionBottom();

	if (Collision_ == 1) {
		Blockdown_ = 0x000;
		MakeBlock_ = 0x001;
		CheckBlock_ = 0x001;
	}

	if (CheckBlock_ == 0x001)
	{
		for (int i = 0; i < TetrisGameType::BLOCKHEIGHT; i++)
		{
			for (int j = 0; j < TetrisGameType::BLOCKWIDTH; j++)
			{
				if (DrawBlock_[i][j] != 9)
				{
					CopyBlock_[i][j] = DrawBlock_[i][j];
					Board_[Position_.y + i][Position_.x + j] = CopyBlock_[i][j];
				}

			}
		}
		BlockDoneCheck_ = 0x001;

		CheckBlock_ = 0x000;
	}
	RotateNowTime_++;

	RightMoveNowTime_++;
	LeftMoveNowTime_++;
	DownMoveNowTime_++;

	if (SpaceDownCheck_ == 0x000)
	{
		SpaceDownNowTime_++;
	}
	else
	{
		SpaceBarRefreshNowTime_++;
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

int TetrisBlocks::TetrisBlock::GetBlockType()
{
	return Blocknumber_;
}

int TetrisBlocks::TetrisBlock::GetBlockData(int x, int y)
{
	return Board_[y][x];
}

//void TetrisBlocks::TetrisBlock::CopyBlock(int blocktype)
//{
//
//}

//void TetrisBlocks::TetrisBlock::SetBoardData(int boardinfo, int x, int y)
//{
//	Board_[x][y] = boardinfo;
//}

void TetrisBlocks::TetrisBlock::StageBlockCollisionLeft()
{
	Collision_ = 0;

	for (int y = 0; y < TetrisGameType::BLOCKHEIGHT; y++)
	{
		for (int x = 0; x < TetrisGameType::BLOCKWIDTH; x++)
		{
			if (DrawBlock_[y][x] != 9)
			{
				if (Board_[Position_.y + y][Position_.x + (x - 1)] != 0)
				{
					Collision_ = 1;
					LeftCollision_ = true;
				}
				else if (YblockCount_ - (Position_.y * TetrisGameType::BLOCKHEIGHT * TetrisGameType::DRAWBLOCKWIDTH) > 0)
				{
					if (Board_[Position_.y + (y + 1)][Position_.x + (x - 1)] != 0)
					{
						Collision_ = 1;
						LeftCollision_ = true;
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
			if (DrawBlock_[y][x] != 9)
			{
				if (Board_[Position_.y + y][Position_.x + (x + 1)] != 0)
				{
					Collision_ = 1;
					RightCollision_ = true;
				}
				else if (YblockCount_ - (Position_.y * TetrisGameType::BLOCKHEIGHT * TetrisGameType::DRAWBLOCKWIDTH) > 0)
				{
					if (Board_[Position_.y + (y + 1)][Position_.x + (x + 1)] != 0)
					{
						Collision_ = 1;
						RightCollision_ = true;
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
			if (DrawBlock_[y][x] != 9)
			{
				if (Board_[Position_.y + (y + 1)][Position_.x + x] != 0)
				{
					MakeBlock_ = 0x001;
					Collision_ = 1;
				}
			}
		}
	}
}

void TetrisBlocks::TetrisBlock::StageBlockCollisionCenter()
{
	Collision_ = 0;
	for (int y = 0; y < TetrisGameType::BLOCKHEIGHT; y++)
	{
		for (int x = 0; x < TetrisGameType::BLOCKWIDTH; x++)
		{
			if (Blocktype_[Blocknumber_][y][x].type != 9)
			{
				if (Board_[Position_.y + y][Position_.x + x] != 0)
				{
					Collision_ = 1;
				}
			}
		}
	}
}

void TetrisBlocks::TetrisBlock::BlockCollisionTurn()
{
	for (int y = 0; y < TetrisGameType::BLOCKHEIGHT; y++)
	{
		for (int x = 0; x < TetrisGameType::BLOCKWIDTH; x++)
		{
			if (TurnBlock_[y][x] != 9)
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

	for (int y = 0; y < TetrisGameType::BLOCKHEIGHT; y++)
	{
		for (int x = 0; x < TetrisGameType::BLOCKWIDTH; x++)
		{
			DrawBlock_[y][x] = Blocktype_[Blocknumber_][y][x].type;
			DrawBlockColor_[y][x].r = Blocktype_[Blocknumber_][y][x].r;
			DrawBlockColor_[y][x].g = Blocktype_[Blocknumber_][y][x].g;
			DrawBlockColor_[y][x].b = Blocktype_[Blocknumber_][y][x].b;
		}
	}
	Position_.x = 4;
	Position_.y = 0;
	YblockCount_ = 0;
}

signed short int TetrisBlocks::TetrisBlock::GetBlockDone()
{
	return BlockDoneCheck_;
}

void TetrisBlocks::TetrisBlock::SetBlockDone(signed short int blockdonecheck)
{
	BlockDoneCheck_ = blockdonecheck;
}

