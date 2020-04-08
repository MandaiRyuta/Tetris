#include "TetrisBlock.h"
#include <random>

constexpr int LEFTPADDING = 3;
constexpr int UPPADDING = 3;
constexpr int RIGHTPADDING = 17;
constexpr int DOWNPADDING = 17;

void TetrisBlocks::TetrisBlock::BlockSwapHold()
{


}

int TetrisBlocks::TetrisBlock::GetHoldBlockType()
{
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rndblocktype(0, 6);

	SwapHoldBlockType_ = Blocknumber_;

	for (int i = 0; i < TetrisGameType::StockBlockSize; i++)
	{
		if (i < 3)
		{
			StockBlocks_[i] = StockBlocks_[i + 1];
		}
		else if (i == 3)
		{
			StockBlocks_[i] = rndblocktype(rnd);
		}
	}

	Blocknumber_ = StockBlocks_[1];

	return SwapHoldBlockType_;
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

	for (int y = 0; y < TetrisGameType::BlockHeight; y++)
	{
		for (int x = 0; x < TetrisGameType::BlockWidth; x++)
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
		for (int y = 0; y < TetrisGameType::BlockHeight; y++)
		{
			for (int x = 0; x < TetrisGameType::BlockWidth; x++)
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
			StageBlockCollisionLeft();
			if (Collision_ == 1)
			{
				if (Blocknumber_ != 3)
				{
					Position_.x = 1;
				}
			}
			StageBlockCollisionCenter();
			if (Collision_ == 1)
			{
				Position_.x += 1;
			}

			LeftCollision_ = false;
		}
		if (RightCollision_)
		{
			StageBlockCollisionRight();
			if (Collision_ == 1)
			{
				if (Blocknumber_ != 3)
				{
					Position_.x = 8;
				}
			}
			StageBlockCollisionCenter();
			if (Collision_)
			{
				if (Blocknumber_ != 3)
				{
					Position_.x -= 1;
				}
			}

			RightCollision_ = false;
		}

		TurnPoint_--;
	}
}

void TetrisBlocks::TetrisBlock::Init()
{
	//Input_ = new Input(1);
	
	StockBlock();

	for (int y = 0; y < TetrisGameType::StageHeight; y++)
	{
		for (int x = 0 ; x < TetrisGameType::StageWidth; x++)
		{
			if (x == 0 || x == 12)
			{
				Board_[y][x] = 9;
			}
			else if (y == 22)
			{
				Board_[y][x] = 9;
			}
			else
			{
				Board_[y][x] = 0;
			}
		}
	}

	InitBlocks();

	for (int y = 0; y < TetrisGameType::BlockHeight; y++)
	{
		for (int x = 0; x < TetrisGameType::BlockWidth; x++)
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

}

void TetrisBlocks::TetrisBlock::Update()
{	
	StageBlockCollisionCenter();
	if (Collision_ == 1)
	{
		Position_.y = Position_.y - 1;
	}

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
	
	StageBlockCollisionCenter();

	if (MakeBlock_ == 0x001)
	{
		BlockDownCheck_ = 0x000;
		MakeBlock();
		MakeBlock_ = 0x000;
	}

	if (Blockdown_ != 0x000)
	{
		YblockCount_ += TetrisGameType::BlockSpeed;
		Position_.y = YblockCount_ / TetrisGameType::DrawBlockWidth;
		DownMoveNowTime_ = 0;
		BlockDownCheck_ = 0x001;
	}
	else if (Blockdown_ == 0x000 && BlockDownCheck_ == 0x000)
	{
		if (BlockNowMoveTime_ > BlockMaxMoveTime_)
		{
			YblockCount_ += TetrisGameType::BlockSpeed;
			Position_.y = YblockCount_ / TetrisGameType::DrawBlockWidth;
			BlockNowMoveTime_ = 0;
		}
		if (RotateNowTime_ > RotateMaxTime_)
		{
			RotateNowTime_ = 0;
			BlockRotateCheck_ = 0x000;
		}

		if(SpaceDownNowTime_ > SpaceDownMaxTime_)
		{
			SpaceDownNowTime_ = 0;
			SpaceDownCheck_ = 0x000;
		}
		if (RightMoveAcceleration_ > 600)
		{
			RightMoveNowTime_ += 3;
			SideSpeed_ = 2;
			//RightMoveAcceleration_ = 0;
		}
		if (LeftMoveAcceleration_ > 600)
		{
			LeftMoveNowTime_ += 3;
			SideSpeed_ = 2;
			//LeftMoveAcceleration_ = 0;
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
		if (InputDownMoveNowTime_ > InputDownMoveMaxTime_)
		{
			InputDownMoveNowTime_ = 0;
			InputDownMoveCheck_ = 0x000;
		}
	}

	if (CheckHitKey(KEY_INPUT_DOWN) == 1 && InputDownMoveCheck_ == 0x000)
	{
		StageBlockCollisionLeft();
		StageBlockCollisionRight();
		StageBlockCollisionBottom();
		StageBlockCollisionCenter();
		if (Collision_ == 0)
		{	
			YblockCount_ += TetrisGameType::BlockSpeed;
			Position_.y = YblockCount_ / TetrisGameType::DrawBlockWidth;
			InputDownMoveCheck_ = 0x001;
		}
	}
	if (CheckHitKey(KEY_INPUT_UP) == 1 && BlockRotateCheck_ == 0x000)
	{
		SideSpeed_ = 0;
		LeftMoveAcceleration_ = 0;
		RightMoveAcceleration_ = 0;
		if (Collision_ == 0)
		{
			RotateNowTime_ = 0;
			ChangeRotate();
			BlockRotateCheck_ = 0x001;
		}
	}

	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		RightMoveAcceleration_ = 0;

		if (CheckHitKey(KEY_INPUT_SPACE) == 1 && SpaceDownCheck_ == 0x000)
		{
			SideSpeed_ = 0;
			if (Collision_ == 0)
			{
				Blockdown_ = 0x001;
				SpaceDownCheck_ = 0x001;
				SpaceBarRefreshCheck_ = 0x001;
			}
		}
		else
		{
			SideSpeed_ = 1;
		}
		LeftMoveAcceleration_++;
		StageBlockCollisionLeft();

		if (LeftMoveCheck_ == 0x000 && Collision_ == 0 )
		{
			Position_.x -= SideSpeed_;
			LeftMoveCheck_ = 0x001;
		}
	}
	else
	{
		LeftMoveAcceleration_ = 0;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		LeftMoveAcceleration_ = 0;
		if (CheckHitKey(KEY_INPUT_SPACE) == 1 && SpaceDownCheck_ == 0x000)
		{
			SideSpeed_ = 0;
			if (Collision_ == 0)
			{
				Blockdown_ = 0x001;
				SpaceDownCheck_ = 0x001;
				SpaceBarRefreshCheck_ = 0x001;
			}
		}
		else
		{
			SideSpeed_ = 1;
		}

		RightMoveAcceleration_++;
		StageBlockCollisionRight();
		if (RightMoveCheck_ == 0x000 && Collision_ == 0)
		{
			Position_.x += SideSpeed_;
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
		for (int i = 0; i < TetrisGameType::BlockHeight; i++)
		{
			for (int j = 0; j < TetrisGameType::BlockWidth; j++)
			{
				if (DrawBlock_[i][j] == 9) continue;
				CopyBlock_[i][j] = DrawBlock_[i][j];
				Board_[Position_.y + i][Position_.x + j] = CopyBlock_[i][j];
			}
		}
		BlockDoneCheck_ = 0x001;

		CheckBlock_ = 0x000;
	}
	RotateNowTime_++;

	RightMoveNowTime_++;
	LeftMoveNowTime_++;
	DownMoveNowTime_++;
	InputDownMoveNowTime_++;

	if (SpaceDownCheck_ == 0x000)
	{
		SpaceDownNowTime_++;
	}
	else
	{
		SpaceBarRefreshNowTime_++;
	}
	BlockNowMoveTime_++;
}

void TetrisBlocks::TetrisBlock::Draw()
{
	for (int i = 0; i < TetrisGameType::BlockHeight; i++)
	{
		for (int j = 0; j < TetrisGameType::BlockWidth; j++)
		{
			DrawBlock(Blocknumber_, i, j, (Position_.x * TetrisGameType::BlockSpeed) * TetrisGameType::BlockWidth + j * TetrisGameType::DrawBlockWidth,
				(Position_.y * TetrisGameType::BlockSpeed) * TetrisGameType::BlockHeight + i * TetrisGameType::DrawBlockWidth);
		}
	}
}

void TetrisBlocks::TetrisBlock::Release()
{
}

void TetrisBlocks::TetrisBlock::StockBlock()
{
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rndblocktype(0, 6);

	for (int i = 0; i < TetrisGameType::StockBlockSize; i++)
	{
		StockBlocks_[i] = rndblocktype(rnd);
	}
}

void TetrisBlocks::TetrisBlock::SwapBlock()
{
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rndblocktype(0, 6);

	Blocknumber_ = StockBlocks_.front();

	for (int i = 0; i < TetrisGameType::StockBlockSize; i++)
	{
		if (i < 3)
		{
			StockBlocks_[i] = StockBlocks_[i + 1];
		}
		else if (i == 3)
		{
			StockBlocks_[i] = rndblocktype(rnd);
		}
	}
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
	if (Blocknumber_ < TetrisGameType::TetrisBlockTypeNum::MaxNumber)
	{
		return Blocknumber_;
	}
	else
	{
		return 0;
	}
}

int TetrisBlocks::TetrisBlock::GetBlockData(int x, int y)
{
	return Board_[y][x];
}

void TetrisBlocks::TetrisBlock::StageBlockCollisionLeft()
{
	Collision_ = 0;

	for (int y = 0; y < TetrisGameType::BlockHeight; y++)
	{
		for (int x = 0; x < TetrisGameType::BlockWidth; x++)
		{
			if (DrawBlock_[y][x] == 9) continue;
			if (Board_[Position_.y + y][Position_.x + (x - 1)] == 0) continue;
			Collision_ = 1;
			LeftCollision_ = true;
			if (YblockCount_ - (Position_.y * TetrisGameType::BlockHeight * TetrisGameType::DrawBlockWidth) <= 0) continue;
			if (Board_[Position_.y + (y + 1)][Position_.x + (x - 1)] == 0) continue;
			Collision_ = 1;
			LeftCollision_ = true;
		}
	}
}

void TetrisBlocks::TetrisBlock::StageBlockCollisionRight()
{
	Collision_ = 0;

	for (int y = 0; y < TetrisGameType::BlockHeight; y++)
	{
		for (int x = 0; x < TetrisGameType::BlockWidth; x++)
		{
			if (DrawBlock_[y][x] == 9) continue;
			if (Board_[Position_.y + y][Position_.x + (x + 1)] == 0) continue;
			Collision_ = 1;
			RightCollision_ = true;
			if (YblockCount_ - (Position_.y * TetrisGameType::BlockHeight * TetrisGameType::DrawBlockWidth) <= 0) continue;
			if (Board_[Position_.y + (y + 1)][Position_.x + (x + 1)] == 0) continue;
			Collision_ = 1;
			RightCollision_ = true;
		}
	}
}

void TetrisBlocks::TetrisBlock::StageBlockCollisionBottom()
{
	Collision_ = 0;

	for (int y = 0; y < TetrisGameType::BlockHeight; y++)
	{
		for (int x = 0; x < TetrisGameType::BlockWidth; x++)
		{
			if (DrawBlock_[y][x] == 9) continue;

			if (Board_[Position_.y + (y + 1)][Position_.x + x] == 0) continue;

			MakeBlock_ = 0x001;
			Collision_ = 1;
		}
	}
}

void TetrisBlocks::TetrisBlock::StageBlockCollisionCenter()
{
	Collision_ = 0;
	for (int y = 0; y < TetrisGameType::BlockHeight; y++)
	{
		for (int x = 0; x < TetrisGameType::BlockWidth; x++)
		{
			if (DrawBlock_[y][x] == 9) continue;
			if (Board_[Position_.y + y][Position_.x + x] == 0) continue;
			Collision_ = 1;
		}
	}
}

void TetrisBlocks::TetrisBlock::BlockCollisionTurn()
{
	for (int y = 0; y < TetrisGameType::BlockHeight; y++)
	{
		for (int x = 0; x < TetrisGameType::BlockWidth; x++)
		{
			if (TurnBlock_[y][x] == 9) continue;
			if (Board_[Position_.y + y][Position_.x + x] == 0) continue;
			Collision_ = 1;
		}
	}
}

void TetrisBlocks::TetrisBlock::MakeBlock()
{
	if(MakeBlock_ == 0x001)
	{
		SwapBlock();

		MakeBlock_ = 0x000;
	}

	for (int y = 0; y < TetrisGameType::BlockHeight; y++)
	{
		for (int x = 0; x < TetrisGameType::BlockWidth; x++)
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

int TetrisBlocks::TetrisBlock::GetStockBlock(int num)
{
	if (num < TetrisGameType::StockBlockSize)
	{
		return StockBlocks_[num];
	}
	else
	{
		return 0;
	}
}

signed short int TetrisBlocks::TetrisBlock::GetBlockDone()
{
	return BlockDoneCheck_;
}

void TetrisBlocks::TetrisBlock::SetBlockDone(signed short int blockdonecheck)
{
	BlockDoneCheck_ = blockdonecheck;
}

void TetrisBlocks::TetrisBlock::InitBlocks()
{
	//I
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEI][0][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEI][0][1] = {
		0,165,255,255,1
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEI][0][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEI][0][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TetrisBlockType::TYPEI][1][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEI][1][1] = {
		0,165,255,255,1
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEI][1][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEI][1][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TetrisBlockType::TYPEI][2][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEI][2][1] = {
		0,165,255,255,1
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEI][2][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEI][2][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TetrisBlockType::TYPEI][3][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEI][3][1] = {
		0,165,255,255,1
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEI][3][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEI][3][3] = {
		0,255,255,255,9
	};

	//J
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEJ][0][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEJ][0][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEJ][0][2] = {
		0,0,255,255,2
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEJ][0][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TetrisBlockType::TYPEJ][1][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEJ][1][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEJ][1][2] = {
		0,0,255,255,2
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEJ][1][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TetrisBlockType::TYPEJ][2][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEJ][2][1] = {
		0,0,255,255,2
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEJ][2][2] = {
		0,0,255,255,2
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEJ][2][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TetrisBlockType::TYPEJ][3][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEJ][3][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEJ][3][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEJ][3][3] = {
		0,255,255,255,9
	};

	//L
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEL][0][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEL][0][1] = {
		255,140,0,255,3
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEL][0][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEL][0][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TetrisBlockType::TYPEL][1][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEL][1][1] = {
		255,140,0,255,3
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEL][1][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEL][1][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TetrisBlockType::TYPEL][2][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEL][2][1] = {
		255,140,0,255,3
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEL][2][2] = {
		255,140,0,255,3
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEL][2][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TetrisBlockType::TYPEL][3][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEL][3][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEL][3][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEL][3][3] = {
		0,255,255,255,9
	};

	//O
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEO][0][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEO][0][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEO][0][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEO][0][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TetrisBlockType::TYPEO][1][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEO][1][1] = {
		255,255,0,255,4
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEO][1][2] = {
		255,255,0,255,4
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEO][1][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TetrisBlockType::TYPEO][2][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEO][2][1] = {
		255,255,0,255,4
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEO][2][2] = {
		255,255,0,255,4
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEO][2][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TetrisBlockType::TYPEO][3][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEO][3][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEO][3][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEO][3][3] = {
		0,255,255,255,9
	};

	//S
	Blocktype_[TetrisGameType::TetrisBlockType::TYPES][0][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPES][0][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPES][0][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPES][0][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TetrisBlockType::TYPES][1][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPES][1][1] = {
		124,252,0,255,5
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPES][1][2] = {
		124,252,0,255,5
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPES][1][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TetrisBlockType::TYPES][2][0] = {
		124,252,0,255,5
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPES][2][1] = {
		124,252,0,255,5
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPES][2][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPES][2][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TetrisBlockType::TYPES][3][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPES][3][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPES][3][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPES][3][3] = {
		0,255,255,255,9
	};

	//T
	Blocktype_[TetrisGameType::TetrisBlockType::TYPET][0][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPET][0][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPET][0][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPET][0][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TetrisBlockType::TYPET][1][0] = {
		255,0,255,255,6
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPET][1][1] = {
		255,0,255,255,6
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPET][1][2] = {
		255,0,255,255,6
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPET][1][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TetrisBlockType::TYPET][2][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPET][2][1] = {
		255,0,255,255,6
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPET][2][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPET][2][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TetrisBlockType::TYPET][3][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPET][3][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPET][3][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPET][3][3] = {
		0,255,255,255,9
	};

	//Z
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEZ][0][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEZ][0][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEZ][0][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEZ][0][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TetrisBlockType::TYPEZ][1][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEZ][1][1] = {
		255,0,0,255,7
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEZ][1][2] = {
		255,0,0,255,7
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEZ][1][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TetrisBlockType::TYPEZ][2][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEZ][2][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEZ][2][2] = {
		255,0,0,255,7
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEZ][2][3] = {
		255,0,0,255,7
	};

	Blocktype_[TetrisGameType::TetrisBlockType::TYPEZ][3][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEZ][3][1] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEZ][3][2] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEZ][3][3] = {
		0,255,255,255,9
	};
}

