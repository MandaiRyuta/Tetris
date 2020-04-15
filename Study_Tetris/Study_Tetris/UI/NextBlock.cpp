#include "NextBlock.h"
#include <string>
#include "Fade.h"
#include "../Window/main.h"

std::array<int, 3> TetrisUI::NextBlock::BlockNumber_;
void TetrisUI::NextBlock::Init()
{
	BlockInit();
}

void TetrisUI::NextBlock::Update()
{
}

void TetrisUI::NextBlock::Draw()
{
	NextBlockPlaceDraw();
}

void TetrisUI::NextBlock::Release()
{
}

void TetrisUI::NextBlock::NextBlockPlaceDraw()
{
	for (int y = 0; y < 16; y++)
	{
		for (int x = TetrisGameType::StageWidth; x < TetrisGameType::StageWidth + 7; x++)
		{
			DrawBox(x * TetrisGameType::DrawBlockWidth + 2, y * TetrisGameType::DrawBlockWidth + 2, x * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
				y * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
				GetColor(255, 255, 255), true);

			if (y % 5 == 0 || x == TetrisGameType::StageWidth || x == TetrisGameType::StageWidth + 6 || y == 0)
			{
				DrawBox(x * TetrisGameType::DrawBlockWidth + 2, y * TetrisGameType::DrawBlockWidth + 2, x * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
					y * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
					GetColor(155, 155, 255), true);
			}
		}
	}

	for (int y = 0; y < TetrisGameType::BlockHeight - 1; y++)
	{
		for (int x = 0; x < TetrisGameType::BlockWidth - 1; x++)
		{
			if (Blocktype_[BlockNumber_[0]][y][x].type != 9)
			{
				DrawBox(14 * 20 + x * TetrisGameType::DrawBlockWidth + 3,
					1 * 20 + y * TetrisGameType::DrawBlockWidth + 3,
					14 * 20 + x * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 3,
					1 * 20 + y * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 3,
					GetColor(Blocktype_[BlockNumber_[0]][y][x].r, Blocktype_[BlockNumber_[0]][y][x].g, Blocktype_[BlockNumber_[0]][y][x].b), true);
			}
			if (Blocktype_[BlockNumber_[1]][y][x].type != 9)
			{
				DrawBox(14 * 20 + x * TetrisGameType::DrawBlockWidth + 3,
					6 * 20 + y * TetrisGameType::DrawBlockWidth + 3,
					14 * 20 + x * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 3,
					6 * 20 + y * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 3,
					GetColor(Blocktype_[BlockNumber_[1]][y][x].r, Blocktype_[BlockNumber_[1]][y][x].g, Blocktype_[BlockNumber_[1]][y][x].b), true);
			}
			if (Blocktype_[BlockNumber_[2]][y][x].type != 9)
			{
				DrawBox(14 * 20 + x * TetrisGameType::DrawBlockWidth + 3,
					11 * 20 + y * TetrisGameType::DrawBlockWidth + 3,
					14 * 20 + x * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 3,
					11 * 20 + y * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 3,
					GetColor(Blocktype_[BlockNumber_[2]][y][x].r, Blocktype_[BlockNumber_[2]][y][x].g, Blocktype_[BlockNumber_[2]][y][x].b), true);
			}
		}
	}
}

void TetrisUI::NextBlock::BlockInit()
{
	for (int type = 0; type < 7; type++)
	{
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				Blocktype_[type][y][x] = BlcoksData.GetBlockPosition(type, x, y);
			}
		}
	}
}

