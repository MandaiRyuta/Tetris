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
			if (Board_[i][j] == 0)
			{
				DrawBox(j * TetrisGameType::DRAWBLOCKWIDTH + 2, i * TetrisGameType::DRAWBLOCKWIDTH + 2, j * TetrisGameType::DRAWBLOCKWIDTH + TetrisGameType::DRAWBLOCKWIDTH - 2, 
					i * TetrisGameType::DRAWBLOCKWIDTH + TetrisGameType::DRAWBLOCKWIDTH -2, GetColor(255, 255, 255), true);
			}
			else if (Board_[i][j] == 9)
			{
				DrawBox(j * TetrisGameType::DRAWBLOCKWIDTH + 2, i * TetrisGameType::DRAWBLOCKWIDTH + 2,
					j * TetrisGameType::DRAWBLOCKWIDTH + TetrisGameType::DRAWBLOCKWIDTH - 2, i * TetrisGameType::DRAWBLOCKWIDTH + TetrisGameType::DRAWBLOCKWIDTH -2, GetColor(0, 255, 255), true);
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

void TetrisBlocks::BlockCollection::stage_collision_left()
{

	for (int y = 0; y < TetrisGameType::BLOCKHEIGHT; y++)
	{
		for (int x = 0; x < TetrisGameType::BLOCKWIDTH; x++)
		{
			if (Board_[Block_->GetYblockCount() + y][Block_->GetBlockXCount() + (x - 1)] != 0)
			{

			}
			else if (Block_->GetYblockCount() - (Block_->GetYblockCount() * TetrisGameType::DRAWBLOCKWIDTH) > 0) {
				if (Board_[ Block_->GetYblockCount() + (y + 1)][Block_->GetBlockXCount() + (x - 1)] != 0)
				{

				}
			}
		}
	}
}

void TetrisBlocks::BlockCollection::stage_collision_right()
{
}

void TetrisBlocks::BlockCollection::stage_collision_bottom()
{
}
