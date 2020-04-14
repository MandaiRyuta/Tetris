#include "NextBlock.h"
#include <string>
#include "Fade.h"

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
	if (TetrisUI::Fade::GetFadeCheck() == 0x001)
	{
		NextBlockPlaceDraw();
	}
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

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (Blocktype_[BlockNumber_[0]][y][x].type != 9)
			{
				DrawBox(15 * 20 + x * TetrisGameType::DrawBlockWidth + 3,
					1 * 20 + y * TetrisGameType::DrawBlockWidth + 3,
					15 * 20 + x * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 3,
					1 * 20 + y * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 3,
					GetColor(Blocktype_[BlockNumber_[0]][y][x].r, Blocktype_[BlockNumber_[0]][y][x].g, Blocktype_[BlockNumber_[0]][y][x].b), true);
			}
			if (Blocktype_[BlockNumber_[1]][y][x].type != 9)
			{
				DrawBox(15 * 20 + x * TetrisGameType::DrawBlockWidth + 3,
					6 * 20 + y * TetrisGameType::DrawBlockWidth + 3,
					15 * 20 + x * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 3,
					6 * 20 + y * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 3,
					GetColor(Blocktype_[BlockNumber_[1]][y][x].r, Blocktype_[BlockNumber_[1]][y][x].g, Blocktype_[BlockNumber_[1]][y][x].b), true);
			}
			if (Blocktype_[BlockNumber_[2]][y][x].type != 9)
			{
				DrawBox(15 * 20 + x * TetrisGameType::DrawBlockWidth + 3,
					11 * 20 + y * TetrisGameType::DrawBlockWidth + 3,
					15 * 20 + x * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 3,
					11 * 20 + y * TetrisGameType::DrawBlockWidth + TetrisGameType::DrawBlockWidth - 3,
					GetColor(Blocktype_[BlockNumber_[2]][y][x].r, Blocktype_[BlockNumber_[2]][y][x].g, Blocktype_[BlockNumber_[2]][y][x].b), true);
			}
		}
	}
}

void TetrisUI::NextBlock::BlockInit()
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
		255,215,0,255,4
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEO][1][2] = {
		255,215,0,255,4
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEO][1][3] = {
		0,255,255,255,9
	};

	Blocktype_[TetrisGameType::TetrisBlockType::TYPEO][2][0] = {
		0,255,255,255,9
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEO][2][1] = {
		255,215,0,255,4
	};
	Blocktype_[TetrisGameType::TetrisBlockType::TYPEO][2][2] = {
		255,215,0,255,4
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

