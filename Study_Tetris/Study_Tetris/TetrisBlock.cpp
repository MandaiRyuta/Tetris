#include "TetrisBlock.h"
#include "Input.h"
#include "BlockCollection.h"
constexpr int LEFTPADDING = 3;
constexpr int UPPADDING = 3;
constexpr int RIGHTPADDING = 17;
constexpr int DOWNPADDING = 17;

void TetrisBlocks::TetrisBlock::SetBlock(TetrisGameType::BlockType type)
{

}

void TetrisBlocks::TetrisBlock::DrawBlock(int type, int vertical, int side, int positionX, int positionY)
{
	if (Blocktype_[type][vertical][side].type == 1)
	{
		DrawBox(positionX + LEFTPADDING, positionY + UPPADDING, positionX + RIGHTPADDING, positionY + DOWNPADDING, GetColor(Blocktype_[type][vertical][side].r, Blocktype_[type][vertical][side].g, Blocktype_[type][vertical][side].b), true);
	}
}

void TetrisBlocks::TetrisBlock::ChangeRotate()
{
}

void TetrisBlocks::TetrisBlock::Init()
{
	//Input_ = new Input(1);

	Blocknumber_ = 0;
	BlockMaxMoveTime_ = 3500;
	BlockNowMoveTime_ = 0;
	InputMaxMoveTime_ = 1500;
	InputNowMoveTime_ = 0;
	Blockmovex_ = 5;
	OneMoveCheck = 0x000;
	Position_.x = 20;
	Position_.y = 0;

	//I
	Blocktype_[TetrisGameType::TYPEI][0][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEI][0][1] = {
		0,165,255,255,1
	};
	Blocktype_[TetrisGameType::TYPEI][0][2] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEI][0][3] = {
		255,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEI][1][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEI][1][1] = {
		0,165,255,255,1
	};
	Blocktype_[TetrisGameType::TYPEI][1][2] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEI][1][3] = {
		255,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEI][2][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEI][2][1] = {
		0,165,255,255,1
	};
	Blocktype_[TetrisGameType::TYPEI][2][2] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEI][2][3] = {
		255,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEI][3][0] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEI][3][1] = {
		0,165,255,255,1
	};
	Blocktype_[TetrisGameType::TYPEI][3][2] = {
		255,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEI][3][3] = {
		255,255,255,255,0
	};

	//J
	Blocktype_[TetrisGameType::TYPEJ][0][0] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEJ][0][1] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEJ][0][2] = {
		0,0,255,255,2
	};
	Blocktype_[TetrisGameType::TYPEJ][0][3] = {
		0,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEJ][1][0] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEJ][1][1] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEJ][1][2] = {
		0,0,255,255,2
	};
	Blocktype_[TetrisGameType::TYPEJ][1][3] = {
		0,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEJ][2][0] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEJ][2][1] = {
		0,0,255,255,2
	};
	Blocktype_[TetrisGameType::TYPEJ][2][2] = {
		0,0,255,255,2
	};
	Blocktype_[TetrisGameType::TYPEJ][2][3] = {
		0,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEJ][3][0] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEJ][3][1] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEJ][3][2] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEJ][3][3] = {
		0,255,255,255,0
	};

	//L
	Blocktype_[TetrisGameType::TYPEL][0][0] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEL][0][1] = {
		255,140,0,255,3
	};
	Blocktype_[TetrisGameType::TYPEL][0][2] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEL][0][3] = {
		0,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEL][1][0] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEL][1][1] = {
		255,140,0,255,3
	};
	Blocktype_[TetrisGameType::TYPEL][1][2] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEL][1][3] = {
		0,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEL][2][0] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEL][2][1] = {
		255,140,0,255,3
	};
	Blocktype_[TetrisGameType::TYPEL][2][2] = {
		255,140,0,255,3
	};
	Blocktype_[TetrisGameType::TYPEL][2][3] = {
		0,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEL][3][0] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEL][3][1] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEL][3][2] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEL][3][3] = {
		0,255,255,255,0
	};

	//O
	Blocktype_[TetrisGameType::TYPEO][0][0] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEO][0][1] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEO][0][2] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEO][0][3] = {
		0,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEO][1][0] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEO][1][1] = {
		255,255,0,255,4
	};
	Blocktype_[TetrisGameType::TYPEO][1][2] = {
		255,255,0,255,4
	};
	Blocktype_[TetrisGameType::TYPEO][1][3] = {
		0,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEO][2][0] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEO][2][1] = {
		255,255,0,255,4
	};
	Blocktype_[TetrisGameType::TYPEO][2][2] = {
		255,255,0,255,4
	};
	Blocktype_[TetrisGameType::TYPEO][2][3] = {
		0,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEO][3][0] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEO][3][1] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEO][3][2] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEO][3][3] = {
		0,255,255,255,0
	};

	//S
	Blocktype_[TetrisGameType::TYPES][0][0] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPES][0][1] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPES][0][2] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPES][0][3] = {
		0,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPES][1][0] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPES][1][1] = {
		124,252,0,255,5
	};
	Blocktype_[TetrisGameType::TYPES][1][2] = {
		124,252,0,255,5
	};
	Blocktype_[TetrisGameType::TYPES][1][3] = {
		0,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPES][2][0] = {
		124,252,0,255,5
	};
	Blocktype_[TetrisGameType::TYPES][2][1] = {
		124,252,0,255,5
	};
	Blocktype_[TetrisGameType::TYPES][2][2] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPES][2][3] = {
		0,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPES][3][0] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPES][3][1] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPES][3][2] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPES][3][3] = {
		0,255,255,255,0
	};

	//T
	Blocktype_[TetrisGameType::TYPET][0][0] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPET][0][1] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPET][0][2] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPET][0][3] = {
		0,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPET][1][0] = {
		255,0,255,255,6
	};
	Blocktype_[TetrisGameType::TYPET][1][1] = {
		255,0,255,255,6
	};
	Blocktype_[TetrisGameType::TYPET][1][2] = {
		255,0,255,255,6
	};
	Blocktype_[TetrisGameType::TYPET][1][3] = {
		0,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPET][2][0] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPET][2][1] = {
		255,0,255,255,6
	};
	Blocktype_[TetrisGameType::TYPET][2][2] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPET][2][3] = {
		0,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPET][3][0] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPET][3][1] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPET][3][2] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPET][3][3] = {
		0,255,255,255,0
	};

	//Z
	Blocktype_[TetrisGameType::TYPEZ][0][0] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEZ][0][1] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEZ][0][2] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEZ][0][3] = {
		0,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEZ][1][0] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEZ][1][1] = {
		255,0,0,255,7
	};
	Blocktype_[TetrisGameType::TYPEZ][1][2] = {
		255,0,0,255,7
	};
	Blocktype_[TetrisGameType::TYPEZ][1][3] = {
		0,255,255,255,0
	};

	Blocktype_[TetrisGameType::TYPEZ][2][0] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEZ][2][1] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEZ][2][2] = {
		255,0,0,255,7
	};
	Blocktype_[TetrisGameType::TYPEZ][2][3] = {
		255,0,0,255,7
	};

	Blocktype_[TetrisGameType::TYPEZ][3][0] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEZ][3][1] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEZ][3][2] = {
		0,255,255,255,0
	};
	Blocktype_[TetrisGameType::TYPEZ][3][3] = {
		0,255,255,255,0
	};
}

void TetrisBlocks::TetrisBlock::Update()
{
	//Input_->Update();
	if (BlockNowMoveTime_ > BlockMaxMoveTime_)
	{
		YblockCount_ += 100;
		Position_.y = YblockCount_ / TetrisGameType::DRAWBLOCKWIDTH;
		BlockNowMoveTime_ = 0;
	}
	if (InputNowMoveTime_ > InputMaxMoveTime_)
	{
		InputNowMoveTime_ = 0x000;
		OneMoveCheck = 0x000;
	}

	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		if (OneMoveCheck == 0x000 && Blockmovex_ > 1)
		{
			Blockmovex_ -= 1;
			Position_.x -= 5;
			OneMoveCheck = 0x001;
		}
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		if (OneMoveCheck == 0x000 && Blockmovex_ < 10)
		{
			Blockmovex_ += 1;
			Position_.x += 5;
			OneMoveCheck = 0x001;
		}
	}
	
	if (YblockCount_ > TetrisGameType::DRAWBLOCKWIDTH * 75) {
		YblockCount_ = 0;
		Position_.y = 0;
	}
	
	BlockNowMoveTime_++;
	InputNowMoveTime_++;
}

void TetrisBlocks::TetrisBlock::Draw()
{
	switch (Blocknumber_)
	{
	case TetrisGameType::TYPEI:
		for (int i = 0; i < TetrisGameType::BLOCKHEIGHT; i++)
		{
			for (int j = 0; j < TetrisGameType::BLOCKWIDTH; j++)
			{   
				DrawBlock(TetrisGameType::TYPEI, i, j, Position_.x * TetrisGameType::BLOCKWIDTH + j * TetrisGameType::DRAWBLOCKWIDTH, 
					Position_.y * TetrisGameType::BLOCKHEIGHT + i * TetrisGameType::DRAWBLOCKWIDTH);
			}
		}
		break;
	case TetrisGameType::TYPEJ:
		for (int i = 0; i < TetrisGameType::BLOCKHEIGHT; i++)
		{
			for (int j = 0; j < TetrisGameType::BLOCKWIDTH; j++)
			{
				DrawBlock(TetrisGameType::TYPEJ, i, j, Position_.x * TetrisGameType::BLOCKWIDTH + j * TetrisGameType::DRAWBLOCKWIDTH,
					Position_.y * TetrisGameType::BLOCKHEIGHT + i * TetrisGameType::DRAWBLOCKWIDTH);
			}
		}
		break;
	case TetrisGameType::TYPEL:
		for (int i = 0; i < TetrisGameType::BLOCKHEIGHT; i++)
		{
			for (int j = 0; j < TetrisGameType::BLOCKWIDTH; j++)
			{
				DrawBlock(TetrisGameType::TYPEL, i, j, Position_.x * TetrisGameType::BLOCKWIDTH + j * TetrisGameType::DRAWBLOCKWIDTH,
					Position_.y * TetrisGameType::BLOCKHEIGHT + i * TetrisGameType::DRAWBLOCKWIDTH);
			}
		}
		break;
	case TetrisGameType::TYPEO:
		for (int i = 0; i < TetrisGameType::BLOCKHEIGHT; i++)
		{
			for (int j = 0; j < TetrisGameType::BLOCKWIDTH; j++)
			{
				DrawBlock(TetrisGameType::TYPEO, i, j, Position_.x * TetrisGameType::BLOCKWIDTH + j * TetrisGameType::DRAWBLOCKWIDTH,
					Position_.y * TetrisGameType::BLOCKHEIGHT + i * TetrisGameType::DRAWBLOCKWIDTH);
			}
		}
		break;
	case TetrisGameType::TYPES:
		for (int i = 0; i < TetrisGameType::BLOCKHEIGHT; i++)
		{
			for (int j = 0; j < TetrisGameType::BLOCKWIDTH; j++)
			{
				DrawBlock(TetrisGameType::TYPES, i, j, Position_.x * TetrisGameType::BLOCKWIDTH + j * TetrisGameType::DRAWBLOCKWIDTH,
					Position_.y * TetrisGameType::BLOCKHEIGHT + i * TetrisGameType::DRAWBLOCKWIDTH);
			}
		}
		break;
	case TetrisGameType::TYPET:
		for (int i = 0; i < TetrisGameType::BLOCKHEIGHT; i++)
		{
			for (int j = 0; j < TetrisGameType::BLOCKWIDTH; j++)
			{
				DrawBlock(TetrisGameType::TYPET, i, j, Position_.x * TetrisGameType::BLOCKWIDTH + j * TetrisGameType::DRAWBLOCKWIDTH,
					Position_.y * TetrisGameType::BLOCKHEIGHT + i * TetrisGameType::DRAWBLOCKWIDTH);
			}
		}
		break;
	case TetrisGameType::TYPEZ:
		for (int i = 0; i < TetrisGameType::BLOCKHEIGHT; i++)
		{
			for (int j = 0; j < TetrisGameType::BLOCKWIDTH; j++)
			{
				DrawBlock(TetrisGameType::TYPEZ, i, j, Position_.x * TetrisGameType::BLOCKWIDTH + j * TetrisGameType::DRAWBLOCKWIDTH,
					Position_.y * TetrisGameType::BLOCKHEIGHT + i * TetrisGameType::DRAWBLOCKWIDTH);
			}
		}
		break;
	}
}

void TetrisBlocks::TetrisBlock::Release()
{
}

int TetrisBlocks::TetrisBlock::GetBlockXCount()
{
	return Blockmovex_;
}

int TetrisBlocks::TetrisBlock::GetYblockCount()
{
	return YblockCount_;
}

void TetrisBlocks::TetrisBlock::SetTetrisBlockStage(BlockCollection* blockcollection)
{
	Blockcollection_ = blockcollection;
}
