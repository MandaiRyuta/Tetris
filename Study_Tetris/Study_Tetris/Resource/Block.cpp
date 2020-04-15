#include "Block.h"

BlockData::BlockData()
{
	for (int type = 0; type < TetrisGameType::TetrisBlockTypeNum::MaxNumber; type++)
	{
		for (int y = 0; y < TetrisGameType::BlockHeight; y++)
		{
			for (int x = 0; x < TetrisGameType::BlockHeight; x++)
			{
				Block_[type][y][x] = {};
			}
		}
	}
}

BlockData::~BlockData()
{
}

void BlockData::Init()
{
	//I
	Block_[TetrisGameType::TetrisBlockType::TYPEI][0][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEI][0][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEI][0][2] = {
		0,165,255,255,1
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEI][0][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEI][0][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPEI][1][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEI][1][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEI][1][2] = {
		0,165,255,255,1
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEI][1][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEI][1][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPEI][2][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEI][2][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEI][2][2] = {
		0,165,255,255,1
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEI][2][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEI][2][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPEI][3][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEI][3][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEI][3][2] = {
		0,165,255,255,1
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEI][3][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEI][3][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPEI][4][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEI][4][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEI][4][2] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEI][4][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEI][4][4] = {
		0,255,255,255,9
	};

	//J

	Block_[TetrisGameType::TetrisBlockType::TYPEJ][0][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEJ][0][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEJ][0][2] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEJ][0][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEJ][0][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPEJ][1][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEJ][1][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEJ][1][2] = {
		0,0,255,255,2
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEJ][1][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEJ][1][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPEJ][2][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEJ][2][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEJ][2][2] = {
		0,0,255,255,2
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEJ][2][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEJ][2][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPEJ][3][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEJ][3][1] = {
		0,0,255,255,2
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEJ][3][2] = {
		0,0,255,255,2
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEJ][3][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEJ][3][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPEJ][4][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEJ][4][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEJ][4][2] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEJ][4][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEJ][4][4] = {
		0,255,255,255,9
	};

	//L
	Block_[TetrisGameType::TetrisBlockType::TYPEL][0][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEL][0][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEL][0][2] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEL][0][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEL][0][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPEL][1][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEL][1][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEL][1][2] = {
		255,140,0,255,3
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEL][1][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEL][1][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPEL][2][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEL][2][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEL][2][2] = {
		255,140,0,255,3
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEL][2][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEL][2][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPEL][3][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEL][3][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEL][3][2] = {
		255,140,0,255,3
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEL][3][3] = {
		255,140,0,255,3
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEL][3][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPEL][4][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEL][4][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEL][4][2] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEL][4][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEL][4][4] = {
		0,255,255,255,9
	};

	//O
	Block_[TetrisGameType::TetrisBlockType::TYPEO][0][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEO][0][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEO][0][2] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEO][0][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEO][0][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPEO][1][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEO][1][1] = {
		255,215,0,255,4
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEO][1][2] = {
		255,215,0,255,4
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEO][1][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEO][1][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPEO][2][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEO][2][1] = {
		255,215,0,255,4
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEO][2][2] = {
		255,215,0,255,4
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEO][2][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEO][2][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPEO][3][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEO][3][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEO][3][2] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEO][3][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEO][3][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPEO][4][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEO][4][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEO][4][2] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEO][4][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEO][4][4] = {
		0,255,255,255,9
	};

	//S
	Block_[TetrisGameType::TetrisBlockType::TYPES][0][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPES][0][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPES][0][2] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPES][0][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPES][0][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPES][1][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPES][1][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPES][1][2] = {
		124,252,0,255,5
	};
	Block_[TetrisGameType::TetrisBlockType::TYPES][1][3] = {
		124,252,0,255,5
	};
	Block_[TetrisGameType::TetrisBlockType::TYPES][1][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPES][2][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPES][2][1] = {
		124,252,0,255,5
	};
	Block_[TetrisGameType::TetrisBlockType::TYPES][2][2] = {
		124,252,0,255,5
	};
	Block_[TetrisGameType::TetrisBlockType::TYPES][2][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPES][2][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPES][3][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPES][3][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPES][3][2] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPES][3][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPES][3][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPES][4][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPES][4][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPES][4][2] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPES][4][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPES][4][4] = {
		0,255,255,255,9
	};

	//T
	Block_[TetrisGameType::TetrisBlockType::TYPET][0][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPET][0][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPET][0][2] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPET][0][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPET][0][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPET][1][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPET][1][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPET][1][2] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPET][1][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPET][1][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPET][2][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPET][2][1] = {
		255,0,255,255,6
	};
	Block_[TetrisGameType::TetrisBlockType::TYPET][2][2] = {
		255,0,255,255,6
	};
	Block_[TetrisGameType::TetrisBlockType::TYPET][2][3] = {
		255,0,255,255,6
	};
	Block_[TetrisGameType::TetrisBlockType::TYPET][2][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPET][3][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPET][3][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPET][3][2] = {
		255,0,255,255,6
	};
	Block_[TetrisGameType::TetrisBlockType::TYPET][3][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPET][3][4] = {
		0,255,255,255,9
	};


	Block_[TetrisGameType::TetrisBlockType::TYPET][4][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPET][4][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPET][4][2] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPET][4][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPET][4][4] = {
		0,255,255,255,9
	};

	//Z
	Block_[TetrisGameType::TetrisBlockType::TYPEZ][0][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEZ][0][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEZ][0][2] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEZ][0][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEZ][0][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPEZ][1][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEZ][1][1] = {
		255,0,0,255,7
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEZ][1][2] = {
		255,0,0,255,7
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEZ][1][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEZ][1][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPEZ][2][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEZ][2][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEZ][2][2] = {
		255,0,0,255,7
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEZ][2][3] = {
		255,0,0,255,7
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEZ][2][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPEZ][3][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEZ][3][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEZ][3][2] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEZ][3][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEZ][3][4] = {
		0,255,255,255,9
	};

	Block_[TetrisGameType::TetrisBlockType::TYPEZ][4][0] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEZ][4][1] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEZ][4][2] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEZ][4][3] = {
		0,255,255,255,9
	};
	Block_[TetrisGameType::TetrisBlockType::TYPEZ][4][4] = {
		0,255,255,255,9
	};
}

TetrisGameType::Block& BlockData::GetBlockPosition( int type, int x, int y)
{
	return Block_[type][y][x];
}
