#pragma once
#include "../TetrisGameType/TetrisGameType.h"

class BlockData
{
public:
	BlockData();
	~BlockData();
public:
	void Init();
	const TetrisGameType::Block& GetBlockPosition(int type, int x, int y);
private:
	TetrisGameType::Block Block_[TetrisGameType::TetrisBlockTypeNum::MaxNumber][TetrisGameType::BlockHeight][TetrisGameType::BlockHeight];
};