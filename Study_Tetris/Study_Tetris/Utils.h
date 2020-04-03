#pragma once
#include <DxLib.h>
#include <vector>
#include <array>

namespace Utils
{
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
}