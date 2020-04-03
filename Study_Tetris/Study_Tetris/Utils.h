#pragma once
#include <DxLib.h>
#include <vector>
#include <array>

namespace Utils
{
	template<typename T>
	struct ObjectPool
	{
		std::vector<T> obj_;
	};

	enum class ObjectType
	{
		BACKGROUND,
		TETRIS,
	};
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

	enum class SCENETYPE
	{
		TITLE,
		GAME,
		RESULT,
		NONE,
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
	
	typedef struct Block
	{
		int Handle_;
		int positionx;
		int positiony;
		int rotatex;
		int rotatey;
		int saclex;
		int scaley;
		int r;
		int g;
		int b;
		int a;
	};
}