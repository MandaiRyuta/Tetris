#pragma once
#include "../TetrisGameType/TetrisGameType.h"

class Block
{
public:
	Block();
	~Block();
public:
	void Init();
	TetrisGameType::Block GetBlockPosition(int type, int x, int y);
private:
	TetrisGameType::Block Block_[TetrisGameType::TetrisBlockTypeNum::MaxNumber][TetrisGameType::BlockHeight][TetrisGameType::BlockHeight];
};