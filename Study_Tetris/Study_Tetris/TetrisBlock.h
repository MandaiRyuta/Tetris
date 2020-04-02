#pragma once
#include "BlockCollection.h"

enum class BlockType
{
	I,
	J,
	L,
	O,
	S,
	T,
	Z,
	W,
};

struct Vector2
{
	int x;
	int y;
};

struct Color
{
	int r;
	int g;
	int b;
	int a;
};

namespace TetrisBlocks
{
	class TetrisBlock
	{
	public:
		TetrisBlock(){}
		~TetrisBlock(){}
	public:
		void SetBlock(BlockType type);
		void SetBlockTransform(int positionX, int positionY);
		void ChangeRotate();
		void ValidArea();
		void Init();
		void Update();
		void Draw();
		void Release();
		void Hold();
		void Stack();
		void NowBlockReset();
		void StackBlockClear();
	private:
		Vector2 position_;
		Vector2 rotate_;
		Vector2 scale_;
		Color color_;
		BlockType type_;
		BlockCollection collection_;
	};
}