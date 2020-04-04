#include "BlockCollection.h"

void TetrisBlocks::BlockCollection::Init()
{
	Block_ = new TetrisBlocks::TetrisBlock();
	Block_->Init();

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			Board_[i][j] = 0;

			if (j == 0 || j == 11)
			{
				Board_[i][j] = 9;
			}
			else if (i == 19)
			{
				Board_[i][j] = 9;
			}

		}
	}
}

void TetrisBlocks::BlockCollection::Update()
{
	Block_->Update();
}

void TetrisBlocks::BlockCollection::Draw()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			SetFontSize(25);
			if (Board_[i][j] == 0)
			{
				DrawBox(j * 20 + 2, i * 20 + 2, j * 20 + 20 - 2, i * 20 + 20 -2, GetColor(255, 255, 255), true);
			}
			else if (Board_[i][j] == 9)
			{
				DrawBox(j * 20 + 2, i * 20 + 2, j * 20 + 20 - 2, i * 20 + 20 -2, GetColor(0, 255, 255), true);
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
