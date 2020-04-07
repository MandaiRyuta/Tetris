#include "BlockCollection.h"

void TetrisBlocks::BlockCollection::Init()
{
	Block_ = new TetrisBlocks::TetrisBlock();
	Block_->Init();
	for (int i = 0; i < TetrisGameType::STAGEHEIGHT; i++)
	{
		for (int j = 0; j < TetrisGameType::STAGEWIDTH; j++)
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

	//for (int y = 0; y < TetrisGameType::STAGEHEIGHT; y++)
	//{
	//	for (int x = 0; x < TetrisGameType::STAGEWIDTH; x++)
	//	{
	//		Block_->SetBoardInfo(Board_[y][x], x, y);
	//	}
	//}
}

void TetrisBlocks::BlockCollection::Update()
{
	Block_->Update();

	if (Block_->GetBlockDone() == 0x001)
	{
		for (int y = 0; y < TetrisGameType::STAGEHEIGHT; y++)
		{
			for (int x = 0; x < TetrisGameType::STAGEWIDTH; x++)
			{
				Board_[y][x] = Block_->GetBlockData(x, y);
			}
		}
		Block_->SetBlockDone(0x000);
	}
}

void TetrisBlocks::BlockCollection::Draw()
{
	for (int i = 0; i < TetrisGameType::STAGEHEIGHT; i++)
	{
		for (int j = 0; j < TetrisGameType::STAGEWIDTH; j++)
		{
			switch (Board_[i][j])
			{
			case 0:
				DrawBox(j * TetrisGameType::DRAWBLOCKWIDTH + 2, i * TetrisGameType::DRAWBLOCKWIDTH + 2, j * TetrisGameType::DRAWBLOCKWIDTH + TetrisGameType::DRAWBLOCKWIDTH - 2,
					i * TetrisGameType::DRAWBLOCKWIDTH + TetrisGameType::DRAWBLOCKWIDTH - 2,
					GetColor(255, 255, 255), true);
				break;
			case 1:
				DrawBox(j * TetrisGameType::DRAWBLOCKWIDTH + 2, i * TetrisGameType::DRAWBLOCKWIDTH + 2,
					j * TetrisGameType::DRAWBLOCKWIDTH + TetrisGameType::DRAWBLOCKWIDTH - 2,
					i * TetrisGameType::DRAWBLOCKWIDTH + TetrisGameType::DRAWBLOCKWIDTH - 2,
					GetColor(0, 165, 255), true);
				break;
			case 2:
				DrawBox(j * TetrisGameType::DRAWBLOCKWIDTH + 2, i * TetrisGameType::DRAWBLOCKWIDTH + 2,
					j * TetrisGameType::DRAWBLOCKWIDTH + TetrisGameType::DRAWBLOCKWIDTH - 2,
					i * TetrisGameType::DRAWBLOCKWIDTH + TetrisGameType::DRAWBLOCKWIDTH - 2,
					GetColor(0, 0, 255), true);
				break;
			case 3:
				DrawBox(j * TetrisGameType::DRAWBLOCKWIDTH + 2, i * TetrisGameType::DRAWBLOCKWIDTH + 2,
					j * TetrisGameType::DRAWBLOCKWIDTH + TetrisGameType::DRAWBLOCKWIDTH - 2,
					i * TetrisGameType::DRAWBLOCKWIDTH + TetrisGameType::DRAWBLOCKWIDTH - 2,
					GetColor(255, 140, 0), true);
				break;
			case 4:
				DrawBox(j * TetrisGameType::DRAWBLOCKWIDTH + 2, i * TetrisGameType::DRAWBLOCKWIDTH + 2,
					j * TetrisGameType::DRAWBLOCKWIDTH + TetrisGameType::DRAWBLOCKWIDTH - 2,
					i * TetrisGameType::DRAWBLOCKWIDTH + TetrisGameType::DRAWBLOCKWIDTH - 2,
					GetColor(255, 255, 0), true);
				break;
			case 5:
				DrawBox(j * TetrisGameType::DRAWBLOCKWIDTH + 2, i * TetrisGameType::DRAWBLOCKWIDTH + 2,
					j * TetrisGameType::DRAWBLOCKWIDTH + TetrisGameType::DRAWBLOCKWIDTH - 2,
					i * TetrisGameType::DRAWBLOCKWIDTH + TetrisGameType::DRAWBLOCKWIDTH - 2,
					GetColor(124, 252, 0), true);
				break;
			case 6:
				DrawBox(j * TetrisGameType::DRAWBLOCKWIDTH + 2, i * TetrisGameType::DRAWBLOCKWIDTH + 2,
					j * TetrisGameType::DRAWBLOCKWIDTH + TetrisGameType::DRAWBLOCKWIDTH - 2,
					i * TetrisGameType::DRAWBLOCKWIDTH + TetrisGameType::DRAWBLOCKWIDTH - 2,
					GetColor(255, 0, 255), true);
				break;
			case 7:
				DrawBox(j * TetrisGameType::DRAWBLOCKWIDTH + 2, i * TetrisGameType::DRAWBLOCKWIDTH + 2,
					j * TetrisGameType::DRAWBLOCKWIDTH + TetrisGameType::DRAWBLOCKWIDTH - 2,
					i * TetrisGameType::DRAWBLOCKWIDTH + TetrisGameType::DRAWBLOCKWIDTH - 2,
					GetColor(255, 0, 0), true);
				break;
			case 9:
				DrawBox(j * TetrisGameType::DRAWBLOCKWIDTH + 2, i * TetrisGameType::DRAWBLOCKWIDTH + 2,
					j * TetrisGameType::DRAWBLOCKWIDTH + TetrisGameType::DRAWBLOCKWIDTH - 2,
					i * TetrisGameType::DRAWBLOCKWIDTH + TetrisGameType::DRAWBLOCKWIDTH - 2,
					GetColor(0, 255, 255), true);
				break;
			}
		}
	}

	Block_->Draw();
}

void TetrisBlocks::BlockCollection::Release()
{
}

void TetrisBlocks::BlockCollection::StackBlockClear()
{
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
	for (int i = 0; i < TetrisGameType::STAGEHEIGHT; i++)
	{
		for (int j = 0; j < TetrisGameType::STAGEWIDTH; j++)
		{
			dst = src;
		}
	}
}

void TetrisBlocks::BlockCollection::Clear(TetrisGameType::Block block)
{
	for (int i = 0; i < TetrisGameType::STAGEHEIGHT; i++)
	{
		for (int j = 0; j < TetrisGameType::STAGEWIDTH; j++)
		{
			block.type = 0;
		}
	}
}

int TetrisBlocks::BlockCollection::GetBoardInfo(int x, int y)
{
	return Board_[x][y];
}
