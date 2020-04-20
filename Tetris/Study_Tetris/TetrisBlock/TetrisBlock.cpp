#include "TetrisBlock.h"
#include "../UI/InGameState.h"
#include "../UI/Time.h"
#include <random>
#include "../Scene/Scene.h"
constexpr int LEFTPADDING = 3;
constexpr int UPPADDING = 3;
constexpr int RIGHTPADDING = 17;
constexpr int DOWNPADDING = 17;

const int& TetrisBlocks::TetrisBlock::GetHoldBlockType()
{
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rndblocktype(0, 6);
	

	if (HoldStockCheck_ == 1 && BreakStockCheck_ == 0x000)
	{
		HoldStockCheck_ = -1;
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

		for (int y = 0; y < TetrisGameType::BlockHeight; y++)
		{
			for (int x = 0; x < TetrisGameType::BlockWidth; x++)
			{
				CopyBlock_[y][x] = Blocktype_[Blocknumber_][y][x].type;
				DrawBlock_[y][x] = Blocktype_[Blocknumber_][y][x].type;
				DrawBlockColor_[y][x].r = Blocktype_[Blocknumber_][y][x].r;
				DrawBlockColor_[y][x].g = Blocktype_[Blocknumber_][y][x].g;
				DrawBlockColor_[y][x].b = Blocktype_[Blocknumber_][y][x].b;
			}
		}
		Position_.x = 4;
		Position_.y = 0;
	}
	else if(HoldStockCheck_ == -1 && BreakStockCheck_ == 0x001)
	{
		HoldStockCheck_ = 1;
		int stock = Blocknumber_;
		Blocknumber_ = SwapHoldBlockType_;
		SwapHoldBlockType_ = stock;
		for (int y = 0; y < TetrisGameType::BlockHeight; y++)
		{
			for (int x = 0; x < TetrisGameType::BlockWidth; x++)
			{
				CopyBlock_[y][x] = Blocktype_[Blocknumber_][y][x].type;
				DrawBlock_[y][x] = Blocktype_[Blocknumber_][y][x].type;
				DrawBlockColor_[y][x].r = Blocktype_[Blocknumber_][y][x].r;
				DrawBlockColor_[y][x].g = Blocktype_[Blocknumber_][y][x].g;
				DrawBlockColor_[y][x].b = Blocktype_[Blocknumber_][y][x].b;
			}
		}

		Position_.x = 4;
		Position_.y = 0;
	}

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
	RightCollision_ = false;
	LeftCollision_ = false;
	TetrisGameType::Color CopyColor[5][5] = {};
	for (int y = 0; y < TetrisGameType::BlockHeight; y++)
	{
		for (int x = 0; x < TetrisGameType::BlockWidth; x++)
		{
			if (Blocknumber_ != 3)
			{
				TurnBlock_[y][x] = DrawBlock_[4 - x][y];
				CopyColor[y][x] = TurnColor_[4 - x][y];
			}
		}
	}

	BlockCollisionTurn();

	if (Collision_ == 0)
	{
		StageBlockCollisionLeft();
		if (LeftCollision_)
		{
			if (Blocknumber_ != 3)
			{
				if (Blocknumber_ == 0)
				{
					Position_.x += 1;
				}
				else
				{
					Position_.x += 1;
				}
			}
			else
			{
				Position_.x -= 1;
			}
			LeftCollision_ = false;
		}

		StageBlockCollisionRight();
		if (RightCollision_)
		{
			if (Blocknumber_ != 3)
			{
				if (Blocknumber_ == 0)
				{
					Position_.x -= 1;
				}
				else
				{
					Position_.x -= 1;
				}
			}
			else
			{
				Position_.x += 1;
			}
			RightCollision_ = false;
		}
		StageBlockCollisionBottom();
		if (BottomCollision_)
		{
			if (Blocknumber_ != 3)
			{
				if (Blocknumber_ == 0)
				{
					YblockCount_ -= 5;
				}
				else
				{
					YblockCount_ -= 5;
				}
			}
			BottomCollision_ = false;
		}
		for (int y = 0; y < TetrisGameType::BlockHeight; y++)
		{
			for (int x = 0; x < TetrisGameType::BlockWidth; x++)
			{

				if (Blocknumber_ != 3)
				{
					DrawBlock_[y][x] = TurnBlock_[y][x];
					TurnColor_[y][x] = CopyColor[y][x];
					DrawBlockColor_[y][x] = TurnColor_[y][x];
				}
			}
		}
	}
	else
	{
		StageBlockCollisionCenter();
		if (Collision_ == 0)
		{
			StageBlockCollisionBottom();
			if (BottomCollision_ == 0)
			{
				//���m�F�@������ƉE�m�F
				StageBlockCollisionLeft();
				if (!LeftCollision_)
				{
					StageBlockCollisionRight();
					if (RightCollision_)
					{
						if (Blocknumber_ != 3)
						{
							if (Blocknumber_ == 0)
							{
								Position_.x += -1;
							}
							else
							{
								Position_.x += -1;
							}
						}
						for (int y = 0; y < TetrisGameType::BlockHeight; y++)
						{
							for (int x = 0; x < TetrisGameType::BlockWidth; x++)
							{

								if (Blocknumber_ != 3)
								{
									DrawBlock_[y][x] = TurnBlock_[y][x];
									TurnColor_[y][x] = CopyColor[y][x];
									DrawBlockColor_[y][x] = TurnColor_[y][x];
								}
							}
						}
						Collision_ = 0;
						LeftCollision_ = false;
						RightCollision_ = false;
					}
					else
					{
						for (int y = 0; y < TetrisGameType::BlockHeight; y++)
						{
							for (int x = 0; x < TetrisGameType::BlockWidth; x++)
							{

								if (Blocknumber_ != 3)
								{
									DrawBlock_[y][x] = TurnBlock_[y][x];
									TurnColor_[y][x] = CopyColor[y][x];
									DrawBlockColor_[y][x] = TurnColor_[y][x];
								}
							}
						}
						Collision_ = 0;
						LeftCollision_ = false;
						RightCollision_ = false;
					}
				}
				else
				{
					StageBlockCollisionRight();
					if (!RightCollision_)
					{
						if (Blocknumber_ != 3)
						{
							if (Blocknumber_ == 0)
							{
								Position_.x += 1;
							}
							else
							{
								Position_.x += 1;
							}
						}
						for (int y = 0; y < TetrisGameType::BlockHeight; y++)
						{
							for (int x = 0; x < TetrisGameType::BlockWidth; x++)
							{

								if (Blocknumber_ != 3)
								{
									DrawBlock_[y][x] = TurnBlock_[y][x];
									TurnColor_[y][x] = CopyColor[y][x];
									DrawBlockColor_[y][x] = TurnColor_[y][x];
								}
							}
						}
						Collision_ = 0;
						LeftCollision_ = false;
						RightCollision_ = false;
					}
				}

				//�E���̊m�F�A���肪����΍����m�F�B
				StageBlockCollisionRight();
				if (!RightCollision_)
				{
					StageBlockCollisionLeft();
					if (LeftCollision_)
					{
						if (Blocknumber_ != 3)
						{
							if (Blocknumber_ == 0)
							{
								Position_.x += 1;
							}
							else
							{
								Position_.x += 1;
							}
						}
						for (int y = 0; y < TetrisGameType::BlockHeight; y++)
						{
							for (int x = 0; x < TetrisGameType::BlockWidth; x++)
							{

								if (Blocknumber_ != 3)
								{
									DrawBlock_[y][x] = TurnBlock_[y][x];
									TurnColor_[y][x] = CopyColor[y][x];
									DrawBlockColor_[y][x] = TurnColor_[y][x];
								}
							}
						}
						Collision_ = 0;
						LeftCollision_ = false;
						RightCollision_ = false;
					}
					else
					{
						for (int y = 0; y < TetrisGameType::BlockHeight; y++)
						{
							for (int x = 0; x < TetrisGameType::BlockWidth; x++)
							{

								if (Blocknumber_ != 3)
								{
									DrawBlock_[y][x] = TurnBlock_[y][x];
									TurnColor_[y][x] = CopyColor[y][x];
									DrawBlockColor_[y][x] = TurnColor_[y][x];
								}
							}
						}
						Collision_ = 0;
						LeftCollision_ = false;
						RightCollision_ = false;
					}
				}
				else
				{
					StageBlockCollisionLeft();
					if (!LeftCollision_)
					{
						if (Blocknumber_ != 3)
						{
							if (Blocknumber_ == 0)
							{
								Position_.x += -1;
							}
							else
							{
								Position_.x += -1;
							}
						}

						for (int y = 0; y < TetrisGameType::BlockHeight; y++)
						{
							for (int x = 0; x < TetrisGameType::BlockWidth; x++)
							{

								if (Blocknumber_ != 3)
								{
									DrawBlock_[y][x] = TurnBlock_[y][x];
									DrawBlockColor_[y][x] = TurnColor_[y][x];
								}
							}
						}
					}

					Collision_ = 0;
					LeftCollision_ = false;
					RightCollision_ = false;
				}
			}
			else
			{				
				if (Blocknumber_ != 3)
				{
					if (Blocknumber_ == 0)
					{
						YblockCount_ -= 5;
					}
					else
					{
						YblockCount_ -= 5;
					}
				}
				BottomCollision_ = false;
			}
		}
	}
}

void TetrisBlocks::TetrisBlock::Init()
{
	StockBlock();
	BlocksData_.Init();
	LeftKeyFrame_ = 0;
	RightKeyFrame_ = 0;
	InputState_ = 0;
	InputSideCheck_ = 0;

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

	for (int type = 0; type < 7; type++)
	{
		for (int y = 0; y < TetrisGameType::BlockHeight; y++)
		{
			for (int x = 0; x < TetrisGameType::BlockWidth; x++)
			{
				Blocktype_[type][y][x] = BlocksData_.GetBlockPosition(type, x, y);
			}
		}
	}

	for (int y = 0; y < TetrisGameType::BlockHeight; y++)
	{
		for (int x = 0; x < TetrisGameType::BlockWidth; x++)
		{
			TurnBlock_[y][x] = 0;
			CopyBlock_[y][x] = 0;
			CopyBlock_[y][x] = Blocktype_[Blocknumber_][y][x].type;
			DrawBlock_[y][x] = Blocktype_[Blocknumber_][y][x].type;
			DrawBlockColor_[y][x].r = Blocktype_[Blocknumber_][y][x].r;
			DrawBlockColor_[y][x].g = Blocktype_[Blocknumber_][y][x].g;
			DrawBlockColor_[y][x].b = Blocktype_[Blocknumber_][y][x].b;
			TurnColor_[y][x].r = DrawBlockColor_[y][x].r;
			TurnColor_[y][x].g = DrawBlockColor_[y][x].g;
			TurnColor_[y][x].b = DrawBlockColor_[y][x].b;
		}
	}

}

void TetrisBlocks::TetrisBlock::Update()
{	
	if (SpaceBarRefreshNowTime_ > SpaceBarRefreshMaxTime_)
	{
		SpaceDownCheck_ = 0x000;
		SpaceBarRefreshNowTime_ = 0;
	}

	StageBlockCollisionCenter();

	if (MakeBlock_ == 0x001)
	{
		StageBlockCollisionCenter();
		if (Collision_ == 1)
		{
			Position_.y = Position_.y - 1;
			if (Position_.y < 0)
			{
				//�Q�[���I�[�o�[
				TetrisUI::InGameState::SetGameState(2);
			}
		}
		if (HoldStockCheck_ == 1)
		{
			BreakStockCheck_ = 0x000;
		}
		if (HoldStockCheck_ == -1)
		{
			BreakStockCheck_ = 0x001;
		}
		InputState_ = 0;
		MakeBlock();
		MakeBlock_ = 0x000;
		BlockDownCheck_ = 0x000;
		Blockdown_ = 0x000;

	}

	if (Blockdown_ != 0x000)
	{
		StageBlockCollisionBottom();

		if (Collision_ == 0)
		{
			Position_.y += 1;
			DownMoveNowTime_ = 0;
			BlockDownCheck_ = 0x001;
		}
		else
		{
			WaitMakeBlcokTime_ = 61;
		}
	}
	else if (Blockdown_ == 0x000 && BlockDownCheck_ == 0x000)
	{
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

		if (DownMoveAcceleration_ > 5)
		{
			DownMoveNowTime_ += 2;
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
	if (BlockDownCheck_ == 0x000)
	{
		if (CheckHitKey(KEY_INPUT_DOWN) == 1 && InputDownMoveCheck_ == 0x000)
		{
			StageBlockCollisionBottom();
			if (Collision_ == 0)
			{
				YblockCount_ += TetrisGameType::BlockSpeed;
				Position_.y = YblockCount_ / TetrisGameType::DrawBlockWidth;
				InputDownMoveCheck_ = 0x001;
			}
		}
		else
		{
			InputDownMoveCheck_ = 0x000;
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

		if (CheckHitKey(KEY_INPUT_UP) == 1 && BlockRotateCheck_ == 0x000)
		{
			SideSpeed_ = 0;

			StageBlockCollisionCenter();
			if (Collision_ == 0)
			{
				ChangeRotate();
				RotateNowTime_ = 0;

				BlockRotateCheck_ = 0x001;
			}
		}

		GameInputState();
		GameInputLeft();
		GameInputRight();
		GameBlockDownState();
	}


	StageBlockCollisionBottom();

	if (Collision_ == 1)
	{
		if (WaitMakeBlcokTime_ > 60)
		{
			Blockdown_ = 0x000;
			MakeBlock_ = 0x001;
			CheckBlock_ = 0x001;
			WaitMakeBlcokTime_ = 0;
		}
		WaitMakeBlcokTime_++;
	}

	if (CheckBlock_ == 0x001)
	{
		for (int i = 0; i < TetrisGameType::BlockHeight; i++)
		{
			for (int j = 0; j < TetrisGameType::BlockWidth; j++)
			{
				if (DrawBlock_[i][j] == 9) continue;
				CopyBlock_[i][j] = DrawBlock_[i][j];
				Board_[i + Position_.y][j + Position_.x] = CopyBlock_[i][j];
			}
		}
		BlockDoneCheck_ = 0x001;
		CheckBlock_ = 0x000;
	}
	RotateNowTime_++;

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

	GameBlockLevelFrame_++;
}

void TetrisBlocks::TetrisBlock::Draw()
{
	for (int i = 0; i < TetrisGameType::BlockHeight; i++)
	{
		for (int j = 0; j < TetrisGameType::BlockWidth; j++)
		{
			DrawBlock(Blocknumber_, i, j, (Position_.x * TetrisGameType::BlockSpeed) * (TetrisGameType::BlockWidth - 1) + j * TetrisGameType::DrawBlockWidth,
				(Position_.y * TetrisGameType::BlockSpeed) * (TetrisGameType::BlockHeight - 1) + i * TetrisGameType::DrawBlockWidth);
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

const int& TetrisBlocks::TetrisBlock::GetXBlockPosition()
{
	return Position_.x;
}

const int& TetrisBlocks::TetrisBlock::GetYblockPosition()
{
	return Position_.y;
}

const int& TetrisBlocks::TetrisBlock::GetBlockType()
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

void TetrisBlocks::TetrisBlock::SetBlockData(int data, int x, int y)
{
	Board_[y][x] = data;
}

const int& TetrisBlocks::TetrisBlock::GetBlockData(int x, int y)
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
			BottomCollision_ = true;
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
			if (TurnBlock_[y][x] != 0) 
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
	if(MakeBlock_ == 0x001)
	{
		SwapBlock();
		RightCollision_ = false;
		LeftCollision_ = false;
		BottomCollision_ = false;
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
			TurnColor_[y][x].r = Blocktype_[Blocknumber_][y][x].r;
			TurnColor_[y][x].g = Blocktype_[Blocknumber_][y][x].g;
			TurnColor_[y][x].b = Blocktype_[Blocknumber_][y][x].b;
		}
	}
	Position_.x = 4;
	Position_.y = 0;
	YblockCount_ = 0;
}

const int& TetrisBlocks::TetrisBlock::GetStockBlock(int num)
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

const signed short int& TetrisBlocks::TetrisBlock::GetBlockDone()
{
	return BlockDoneCheck_;
}

void TetrisBlocks::TetrisBlock::SetBlockDone(signed short int blockdonecheck)
{
	BlockDoneCheck_ = blockdonecheck;
}

void TetrisBlocks::TetrisBlock::GameInputState()
{
	switch (InputState_)
	{
	case 0:
		InputStateFirst(LeftKeyFrame_,RightKeyFrame_);
		break;
	case 1:
		InputStateSecond(LeftKeyFrame_,RightKeyFrame_);
		break;
	}
}

void TetrisBlocks::TetrisBlock::InputStateFirst(int& leftkeyframe, int& rightkeyframe)
{
	if (rightkeyframe > 5)
	{
		if (ChangeKeyStateCount_ > 1)
		{
			InputState_ = 1;
			ChangeKeyStateCount_ = 0;
		}
		if (InputSideCheck_ == 0)
		{
			StageBlockCollisionRight();
			if (Collision_ == 0)
			{
				Position_.x += 1;
			}
			else
			{
				InputState_ = 0;
			}
		}
		rightkeyframe = 0;
	}
	if(leftkeyframe > 5)
	{
		if (InputSideCheck_ == 1)
		{
			StageBlockCollisionLeft();
			if (Collision_ == 0)
			{
				Position_.x -= 1;
			}
			else
			{
				InputState_ = 0;
			}
		}
		if (InputState_ != 1)
		{
			ChangeKeyStateCount_++;
		}
		leftkeyframe = 0;
	}
}

void TetrisBlocks::TetrisBlock::InputStateSecond(int& leftkeyframe, int& rightkeyframe)
{

	if (leftkeyframe > 3)
	{
		if (InputSideCheck_ == 1)
		{
			StageBlockCollisionLeft();
			if (Collision_ == 0)
			{
				Position_.x -= 1;
			}
			else
			{
				InputState_ = 0;
			}
		}
		leftkeyframe = 0;
	}
	if (rightkeyframe > 3)
	{
		if (InputSideCheck_ == 0)
		{
			StageBlockCollisionRight();
			if (Collision_ == 0)
			{
				Position_.x += 1;
			}
			else
			{
				InputState_ = 0;
			}
		}
		rightkeyframe = 0;
	}
}

void TetrisBlocks::TetrisBlock::GameInputRight()
{
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		RightKeyFrame_++;
		StageBlockCollisionCenter();
		InputSideCheck_ = 0;
	}
}

void TetrisBlocks::TetrisBlock::GameInputLeft()
{
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		LeftKeyFrame_++;
		StageBlockCollisionCenter();
	
		InputSideCheck_ = 1;
	}
}

void TetrisBlocks::TetrisBlock::GameBlockDownState()
{
	if (TetrisUI::Time::GetNowTime() < 8000 && GameBlockState_ == 0)
	{
		GameBlockState_ = 1;
	}
	else if (TetrisUI::Time::GetNowTime() < 7000 && GameBlockState_ == 1)
	{
		GameBlockState_ = 2;
	}
	else if (TetrisUI::Time::GetNowTime() < 0 && GameBlockState_ == 2)
	{
		GameBlockState_ = 1;
		TetrisUI::InGameState::SetGameState(1);
	}
	switch (GameBlockState_)
	{
	case 0:
		GameBlockDownFirst(GameBlockLevelFrame_);
		break;
	case 1:
		GameBlockDownSecond(GameBlockLevelFrame_);
		break;
	case 2:
		GameBlockDownThird(GameBlockLevelFrame_);
		break;
	}
}

void TetrisBlocks::TetrisBlock::GameBlockDownFirst(int& frame)
{
	StageBlockCollisionBottom();
	if(frame > 20 && Collision_  == 0)
	{
		YblockCount_ += TetrisGameType::BlockSpeed;
		Position_.y = YblockCount_ / TetrisGameType::DrawBlockWidth;
		frame = 0;
	}
}

void TetrisBlocks::TetrisBlock::GameBlockDownSecond(int& frame)
{
	StageBlockCollisionBottom();
	if (frame > 10 && Collision_ == 0)
	{
		YblockCount_ += TetrisGameType::BlockSpeed;
		Position_.y = YblockCount_ / TetrisGameType::DrawBlockWidth;
		frame = 0;
	}
}

void TetrisBlocks::TetrisBlock::GameBlockDownThird(int& frame)
{
	StageBlockCollisionBottom();
	if (frame > 5 && Collision_ == 0)
	{
		YblockCount_ += TetrisGameType::BlockSpeed;
		Position_.y = YblockCount_ / TetrisGameType::DrawBlockWidth;
		frame = 0;
	}
}