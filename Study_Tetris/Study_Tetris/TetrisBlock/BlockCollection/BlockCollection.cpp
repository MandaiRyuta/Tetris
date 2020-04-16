#include "BlockCollection.h"
#include "../../UI/NextBlock.h"
#include "../../UI/Hold.h"
#include "../../UI/Score.h"

void TetrisBlocks::BlockCollection::Init()
{
	Block_ = new TetrisBlocks::TetrisBlock();
	Block_->Init();
	Board_ = {};

	for (int i = 0; i < 23; i++)
	{
		ClearLine_[i] = {};
	}
	ClearCheck_ = 0x000;
	ClearCount_ = 1;

	for (int i = 0; i < TetrisGameType::StageHeight; i++)
	{
		for (int j = 0; j < TetrisGameType::StageWidth; j++)
		{
			Board_[i][j] = 0;
			if (j == 0 || j == 12)
			{
				Board_[i][j] = 9;
			}
			else if (i == 22)
			{
				Board_[i][j] = 9;
			}
		}
	}

	//for (int y = 0; y < TetrisGameType::kStageHeight; y++)
	//{
	//	for (int x = 0; x < TetrisGameType::kStageWidth; x++)
	//	{
	//		Block_->SetBoardInfo(Board_[y][x], x, y);
	//	}
	//}
}

void TetrisBlocks::BlockCollection::Update()
{
	Block_->Update();

	for (int i = 0; i < 3; i++)
	{
		TetrisUI::NextBlock::GetNextBlockType(i, Block_->GetStockBlock(i));
	}

	if (CheckHitKey(KEY_INPUT_H) == 1)
	{
		TetrisUI::Hold::GetHoldBlockType(Block_->GetHoldBlockType());
	}

	if (Block_->GetBlockDone() == 0x001)
	{
		for (int y = 0; y < TetrisGameType::StageHeight; y++)
		{
			for (int x = 0; x < TetrisGameType::StageWidth; x++)
			{
				Board_[y][x] = Block_->GetBlockData(x, y);
			}
		}
		Block_->SetBlockDone(0x000);
	}

	StackBlockClearLineCheck();
	StageBlockLineClear();
}

void TetrisBlocks::BlockCollection::Draw()
{
	for (int i = 0; i < TetrisGameType::StageHeight; i++)
	{
		for (int j = 0; j < TetrisGameType::StageWidth; j++)
		{
			switch (Board_[i][j])
			{
			case 0:
				DrawBox(j * TetrisGameType::DrawBlockWidth + 2, i * TetrisGameType::DrawBlockWidth + 2, j * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
					i * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
					GetColor(255, 255, 255), true);
				break;
			case 1:
				DrawBox(j * TetrisGameType::DrawBlockWidth + 2, i * TetrisGameType::DrawBlockWidth + 2,
					j * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
					i * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
					GetColor(0, 165, 255), true);
				break;
			case 2:
				DrawBox(j * TetrisGameType::DrawBlockWidth + 2, i * TetrisGameType::DrawBlockWidth + 2,
					j * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
					i * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
					GetColor(0, 0, 255), true);
				break;
			case 3:
				DrawBox(j * TetrisGameType::DrawBlockWidth + 2, i * TetrisGameType::DrawBlockWidth + 2,
					j * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
					i * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
					GetColor(255, 140, 0), true);
				break;
			case 4:
				DrawBox(j * TetrisGameType::DrawBlockWidth + 2, i * TetrisGameType::DrawBlockWidth + 2,
					j * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
					i * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
					GetColor(255, 255, 0), true);
				break;
			case 5:
				DrawBox(j * TetrisGameType::DrawBlockWidth + 2, i * TetrisGameType::DrawBlockWidth + 2,
					j * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
					i * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
					GetColor(124, 252, 0), true);
				break;
			case 6:
				DrawBox(j * TetrisGameType::DrawBlockWidth + 2, i * TetrisGameType::DrawBlockWidth + 2,
					j * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
					i * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
					GetColor(255, 0, 255), true);
				break;
			case 7:
				DrawBox(j * TetrisGameType::DrawBlockWidth + 2, i * TetrisGameType::DrawBlockWidth + 2,
					j * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
					i * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
					GetColor(255, 0, 0), true);
				break;
			case 9:
				DrawBox(j * TetrisGameType::DrawBlockWidth + 2, i * TetrisGameType::DrawBlockWidth + 2,
					j * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
					i * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
					GetColor(0, 255, 255), true);
				break;
			}
		}
	}

	Block_->Draw();
}

void TetrisBlocks::BlockCollection::Release()
{
	for (int i = 0; i < 23; i++)
	{
		ClearLine_[i] = {};
	}

	if (Block_ != nullptr)
	{
		Block_->Release();
	}
	delete Block_;
}

void TetrisBlocks::BlockCollection::StackBlockClearLineCheck()
{
	for (int y = 0; y < TetrisGameType::StageHeight - 1; y++)
	{
		ClearLine_[y] = 0;
	}

	for (int y = 0; y < TetrisGameType::StageHeight - 1; y++)
	{
		for (int x = 1; x < TetrisGameType::StageWidth - 1; x++)
		{
			if (Board_[y][x] == 0)
			{
				ClearLine_[y] = 1;
				break;
			}
		}
	}

	for (int y = 0; y < TetrisGameType::StageHeight - 1; y++)
	{
		if (ClearLine_[y] == 0)
		{
			ClearCheck_ = 0x001;
		}
	}
}

void TetrisBlocks::BlockCollection::StageBlockLineClear()
{
	int clearlinepoint[22] = { 0 };
	int remainline = 0;

	if (ClearCheck_ == 0x001)
	{
		
		for (int i = 1; i < TetrisGameType::StageHeight - 1; i++) 
		{
			if (ClearLine_[i] == 0) 
			{
				if (ClearCount_ < 13) 
				{
					Board_[i][ClearCount_] = 0;
					ClearCount_++;
				}
			}
		}

		for (int i = TetrisGameType::StageHeight - 2; i >= 0; i--)
		{
			if (ClearLine_[i] != 0)
			{
				clearlinepoint[remainline] = i;
				remainline++;
			}
			else
			{
				TetrisUI::Score::AddScore(10);
			}
		}

		remainline = 0;
		for (int i = TetrisGameType::StageHeight - 2; i >= 0; i--) 
		{
			for (int j = 1; j < TetrisGameType::StageWidth ; j++) 
			{
				Board_[i][j] = Board_[clearlinepoint[remainline]][j];
			}
			remainline++;
		}

		for (int y = 0; y < TetrisGameType::StageHeight; y++)
		{
			for (int x = 0; x < TetrisGameType::StageWidth; x++)
			{
				Block_->SetBlockData(Board_[y][x], x, y);
			}
		}

		ClearCheck_ = 0x000;
		ClearCount_ = 1;
	}
}

void TetrisBlocks::BlockCollection::StackBlock(TetrisBlock* block)
{
}

void TetrisBlocks::BlockCollection::NowBlock()
{
}

void TetrisBlocks::BlockCollection::SetHold(TetrisBlock* block)
{
}

void TetrisBlocks::BlockCollection::CopyBlock(TetrisGameType::Block src, TetrisGameType::Block dst)
{
	for (int i = 0; i < TetrisGameType::StageHeight; i++)
	{
		for (int j = 0; j < TetrisGameType::StageWidth; j++)
		{
			dst = src;
		}
	}
}

void TetrisBlocks::BlockCollection::Clear(TetrisGameType::Block block)
{
	for (int i = 0; i < TetrisGameType::StageHeight; i++)
	{
		for (int j = 0; j < TetrisGameType::StageWidth; j++)
		{
			block.type = 0;
		}
	}
}

int TetrisBlocks::BlockCollection::GetBoardInfo(int x, int y)
{
	return Board_[x][y];
}
