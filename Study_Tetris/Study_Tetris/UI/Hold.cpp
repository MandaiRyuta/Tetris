#include "Hold.h"
#include "Fade.h"
#include "../Scene/Scene.h"
int TetrisUI::Hold::HoldBlockType_ = 0;

TetrisUI::Hold::Hold()
{
}

TetrisUI::Hold::~Hold()
{
}

void TetrisUI::Hold::Init()
{
	HoldBlockType_ = 9;
	BlockInit();
}

void TetrisUI::Hold::Update()
{
}

void TetrisUI::Hold::Draw()
{
	for (int y = 17; y < 23; y++)
	{
		for (int x = TetrisGameType::StageWidth; x < TetrisGameType::StageWidth + 7; x++)
		{
			DrawBox(x * TetrisGameType::DrawBlockWidth + 2, y * TetrisGameType::DrawBlockWidth + 2, x * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
				y * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
				GetColor(255, 255, 255), true);

			if (y == 22 || x == TetrisGameType::StageWidth || x == TetrisGameType::StageWidth + 6 || y == 17)
			{
				DrawBox(x * TetrisGameType::DrawBlockWidth + 2, y * TetrisGameType::DrawBlockWidth + 2, x * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
					y * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 2,
					GetColor(155, 155, 255), true);
			}
		}
	}

	for (int y = 0; y < TetrisGameType::BlockHeight; y++)
	{
		for (int x = 0; x < TetrisGameType::BlockWidth; x++)
		{
			if (HoldBlockType_ != 9 && Blocktype_[HoldBlockType_][y][x].type != 9)
			{
				DrawBox(14 * 20 + x * TetrisGameType::DrawBlockWidth + 3,
					18 * 20 + y * TetrisGameType::DrawBlockWidth + 3,
					14 * 20 + x * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 3,
					18 * 20 + y * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 3,
					GetColor(Blocktype_[HoldBlockType_][y][x].r, Blocktype_[HoldBlockType_][y][x].g, Blocktype_[HoldBlockType_][y][x].b), true);
			}
		}
	}
}

void TetrisUI::Hold::Release()
{
}

void TetrisUI::Hold::LoadTexture(int handle, int texturenumber)
{
}

void TetrisUI::Hold::BlockInit()
{
	for (int type = 0; type < 7; type++)
	{
		for (int y = 0; y < TetrisGameType::BlockHeight; y++)
		{
			for (int x = 0; x < TetrisGameType::BlockWidth; x++)
			{
				Blocktype_[type][y][x] = Scene::GetBlockTypeColor(type, x, y);
			}
		}
	}
}
