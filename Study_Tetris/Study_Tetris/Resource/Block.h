#pragma once
#include "../TetrisGameType/TetrisGameType.h"

class Block
{
public:
	Block();
	~Block();
public:
	void Init();
	TetrisGameType::TetrisBlockType GetBlockPosition(int type, int x, int y);
private:

};