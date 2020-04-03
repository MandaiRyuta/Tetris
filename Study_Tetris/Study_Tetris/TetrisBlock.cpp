#include "TetrisBlock.h"

void TetrisBlocks::TetrisBlock::SetBlock(Utils::BlockType type)
{
	switch (type)
	{
	case Utils::BlockType::I:
		//DrawRotaGraph3
		break;
	case Utils::BlockType::J:
		break;
	case Utils::BlockType::L:
		break;
	case Utils::BlockType::O:
		break;
	case Utils::BlockType::S:
		break;
	case Utils::BlockType::T:
		break;
	case Utils::BlockType::Z:
		break;
	case Utils::BlockType::W:
		break;
	}
}

void TetrisBlocks::TetrisBlock::SetBlockTransform(int positionX, int positionY)
{
}

void TetrisBlocks::TetrisBlock::ChangeRotate()
{
}

void TetrisBlocks::TetrisBlock::ValidArea()
{
}

void TetrisBlocks::TetrisBlock::Init()
{
	int block;
	block = LoadGraph("/texture/TetrisBlockTexture.png");

	//I
	blocktype_[static_cast<int>(Utils::BlockType::I)][0][0] = {
		block,0,0,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::I)][0][1] = {
		block,1,0,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::I)][0][2] = {
		block,2,0,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::I)][0][3] = {
		block,3,0,0,0,1,1,0,0,0,0,
	};

	blocktype_[static_cast<int>(Utils::BlockType::I)][1][0] = {
		block,0,1,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::I)][1][1] = {
		block,1,1,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::I)][1][2] = {
		block,2,1,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::I)][1][3] = {
		block,3,1,0,0,1,1,0,0,0,0,
	};

	blocktype_[static_cast<int>(Utils::BlockType::I)][2][0] = {
		block,0,2,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::I)][2][1] = {
		block,1,2,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::I)][2][2] = {
		block,2,2,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::I)][2][3] = {
		block,3,2,0,0,1,1,0,0,0,0,
	};

	blocktype_[static_cast<int>(Utils::BlockType::I)][3][0] = {
		block,0,3,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::I)][3][1] = {
		block,1,3,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::I)][3][2] = {
		block,2,3,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::I)][3][3] = {
		block,3,3,0,0,1,1,0,0,0,0,
	};

	//J
	blocktype_[static_cast<int>(Utils::BlockType::J)][0][0] = {
		block,0,0,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::J)][0][1] = {
		block,1,0,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::J)][0][2] = {
		block,2,0,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::J)][0][3] = {
		block,3,0,0,0,1,1,0,0,0,0,
	};

	blocktype_[static_cast<int>(Utils::BlockType::J)][1][0] = {
		block,0,1,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::J)][1][1] = {
		block,1,1,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::J)][1][2] = {
		block,2,1,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::J)][1][3] = {
		block,3,1,0,0,1,1,0,0,0,0,
	};

	blocktype_[static_cast<int>(Utils::BlockType::J)][2][0] = {
		block,0,2,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::J)][2][1] = {
		block,1,2,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::J)][2][2] = {
		block,2,2,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::J)][2][3] = {
		block,3,2,0,0,1,1,0,0,0,0,
	};

	blocktype_[static_cast<int>(Utils::BlockType::J)][3][0] = {
		block,0,3,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::J)][3][1] = {
		block,1,3,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::J)][3][2] = {
		block,2,3,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::J)][3][3] = {
		block,3,3,0,0,1,1,0,0,0,0,
	};

	//L
	blocktype_[static_cast<int>(Utils::BlockType::L)][0][0] = {
		block,0,0,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::L)][0][1] = {
		block,1,0,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::L)][0][2] = {
		block,2,0,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::L)][0][3] = {
		block,3,0,0,0,1,1,0,0,0,0,
	};

	blocktype_[static_cast<int>(Utils::BlockType::L)][1][0] = {
		block,0,1,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::L)][1][1] = {
		block,1,1,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::L)][1][2] = {
		block,2,1,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::L)][1][3] = {
		block,3,1,0,0,1,1,0,0,0,0,
	};

	blocktype_[static_cast<int>(Utils::BlockType::L)][2][0] = {
		block,0,2,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::L)][2][1] = {
		block,1,2,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::L)][2][2] = {
		block,2,2,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::L)][2][3] = {
		block,3,2,0,0,1,1,0,0,0,0,
	};

	blocktype_[static_cast<int>(Utils::BlockType::L)][3][0] = {
		block,0,3,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::L)][3][1] = {
		block,1,3,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::L)][3][2] = {
		block,2,3,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::L)][3][3] = {
		block,3,3,0,0,1,1,0,0,0,0,
	};

	//O
	blocktype_[static_cast<int>(Utils::BlockType::O)][0][0] = {
		block,0,0,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::O)][0][1] = {
		block,1,0,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::O)][0][2] = {
		block,2,0,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::O)][0][3] = {
		block,3,0,0,0,1,1,0,0,0,0,
	};

	blocktype_[static_cast<int>(Utils::BlockType::O)][1][0] = {
		block,0,1,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::O)][1][1] = {
		block,1,1,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::O)][1][2] = {
		block,2,1,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::O)][1][3] = {
		block,3,1,0,0,1,1,0,0,0,0,
	};

	blocktype_[static_cast<int>(Utils::BlockType::O)][2][0] = {
		block,0,2,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::O)][2][1] = {
		block,1,2,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::O)][2][2] = {
		block,2,2,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::O)][2][3] = {
		block,3,2,0,0,1,1,0,0,0,0,
	};

	blocktype_[static_cast<int>(Utils::BlockType::O)][3][0] = {
		block,0,3,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::O)][3][1] = {
		block,1,3,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::O)][3][2] = {
		block,1,3,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::O)][3][3] = {
		block,1,3,0,0,1,1,0,0,0,0,
	};

	//S
	blocktype_[static_cast<int>(Utils::BlockType::S)][0][0] = {
		block,0,0,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::S)][0][1] = {
		block,1,0,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::S)][0][2] = {
		block,2,0,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::S)][0][3] = {
		block,3,0,0,0,1,1,0,0,0,0,
	};

	blocktype_[static_cast<int>(Utils::BlockType::S)][1][0] = {
		block,0,1,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::S)][1][1] = {
		block,1,1,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::S)][1][2] = {
		block,2,1,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::S)][1][3] = {
		block,3,1,0,0,1,1,0,0,0,0,
	};

	blocktype_[static_cast<int>(Utils::BlockType::S)][2][0] = {
		block,0,2,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::S)][2][1] = {
		block,1,2,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::S)][2][2] = {
		block,2,2,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::S)][2][3] = {
		block,3,2,0,0,1,1,0,0,0,0,
	};

	blocktype_[static_cast<int>(Utils::BlockType::S)][3][0] = {
		block,0,3,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::S)][3][1] = {
		block,1,3,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::S)][3][2] = {
		block,2,3,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::S)][3][3] = {
		block,3,3,0,0,1,1,0,0,0,0,
	};

	//T
	blocktype_[static_cast<int>(Utils::BlockType::T)][0][0] = {
		block,0,0,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::T)][0][1] = {
		block,1,0,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::T)][0][2] = {
		block,2,0,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::T)][0][3] = {
		block,3,0,0,0,1,1,0,0,0,0,
	};

	blocktype_[static_cast<int>(Utils::BlockType::T)][1][0] = {
		block,0,1,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::T)][1][1] = {
		block,1,1,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::T)][1][2] = {
		block,2,1,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::T)][1][3] = {
		block,3,1,0,0,1,1,0,0,0,0,
	};

	blocktype_[static_cast<int>(Utils::BlockType::T)][2][0] = {
		block,0,2,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::T)][2][1] = {
		block,1,2,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::T)][2][2] = {
		block,2,2,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::T)][2][3] = {
		block,3,2,0,0,1,1,0,0,0,0,
	};

	blocktype_[static_cast<int>(Utils::BlockType::T)][3][0] = {
		block,0,3,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::T)][3][1] = {
		block,1,3,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::T)][3][2] = {
		block,2,3,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::T)][3][3] = {
		block,3,3,0,0,1,1,0,0,0,0,
	};

	//Z
	blocktype_[static_cast<int>(Utils::BlockType::Z)][0][0] = {
		block,0,0,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::Z)][0][1] = {
		block,1,0,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::Z)][0][2] = {
		block,2,0,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::Z)][0][3] = {
		block,3,0,0,0,1,1,0,0,0,0,
	};

	blocktype_[static_cast<int>(Utils::BlockType::Z)][1][0] = {
		block,0,1,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::Z)][1][1] = {
		block,1,1,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::Z)][1][2] = {
		block,2,1,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::Z)][1][3] = {
		block,3,1,0,0,1,1,0,0,0,0,
	};

	blocktype_[static_cast<int>(Utils::BlockType::Z)][2][0] = {
		block,0,2,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::Z)][2][1] = {
		block,1,2,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::Z)][2][2] = {
		block,2,2,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::Z)][2][3] = {
		block,3,2,0,0,1,1,255,255,255,255,
	};

	blocktype_[static_cast<int>(Utils::BlockType::Z)][3][0] = {
		block,0,3,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::Z)][3][1] = {
		block,1,3,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::Z)][3][2] = {
		block,2,3,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::Z)][3][3] = {
		block,3,3,0,0,1,1,0,0,0,0,
	};

	//W
	blocktype_[static_cast<int>(Utils::BlockType::W)][0][0] = {
		block,0,0,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::W)][0][1] = {
		block,1,0,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::W)][0][2] = {
		block,2,0,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::W)][0][3] = {
		block,3,0,0,0,1,1,0,0,0,0,
	};

	blocktype_[static_cast<int>(Utils::BlockType::W)][1][0] = {
		block,0,1,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::W)][1][1] = {
		block,1,1,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::W)][1][2] = {
		block,2,1,0,0,1,1,255,255,255,255,
	};
	blocktype_[static_cast<int>(Utils::BlockType::W)][1][3] = {
		block,3,1,0,0,1,1,0,0,0,0,
	};

	blocktype_[static_cast<int>(Utils::BlockType::W)][2][0] = {
		block,0,2,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::W)][2][1] = {
		block,1,2,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::W)][2][2] = {
		block,2,2,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::W)][2][3] = {
		block,3,2,0,0,1,1,0,0,0,0,
	};

	blocktype_[static_cast<int>(Utils::BlockType::W)][3][0] = {
		block,0,3,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::W)][3][1] = {
		block,1,3,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::W)][3][2] = {
		block,2,3,0,0,1,1,0,0,0,0,
	};
	blocktype_[static_cast<int>(Utils::BlockType::W)][3][3] = {
		block,3,3,0,0,1,1,0,0,0,0,
	};
	DeleteGraph(block);
}

void TetrisBlocks::TetrisBlock::Update()
{
}

void TetrisBlocks::TetrisBlock::Draw()
{
}

void TetrisBlocks::TetrisBlock::Release()
{
}

void TetrisBlocks::TetrisBlock::Hold()
{
}

void TetrisBlocks::TetrisBlock::Stack()
{
}

void TetrisBlocks::TetrisBlock::NowBlockReset()
{
}

void TetrisBlocks::TetrisBlock::StackBlockClear()
{
}
