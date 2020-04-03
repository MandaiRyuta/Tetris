#pragma once
#include <DxLib.h>
#include <vector>
#include <array>

namespace Utils
{
	constexpr int KEYFRAME = 1;

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
	
	struct Block
	{
		int r;
		int g;
		int b;
		int a;
		int type;
	};
}