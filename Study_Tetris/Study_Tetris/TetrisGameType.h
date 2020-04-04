#pragma once
#include <DxLib.h>
#include <vector>
#include <array>

namespace TetrisGameType
{
	constexpr int TITLESCENENUMBER = 0;
	constexpr int GAMESCENENUMBER = 1;
	constexpr int RESULTSCENENUMBER = 2;

	constexpr int TYPEI = 0;
	constexpr int TYPEJ = 1;
	constexpr int TYPEL = 2;
	constexpr int TYPEO = 3;
	constexpr int TYPES = 4;
	constexpr int TYPET = 5;
	constexpr int TYPEZ = 6;

	constexpr int BLOCKTYPE = 7;
	constexpr int BLOCKHEIGHT = 4;
	constexpr int BLOCKWIDTH = 4;
	constexpr int STAGEHEIGHT = 23;
	constexpr int STAGEWIDTH = 18;
	constexpr int DRAWBLOCKWIDTH = 20;

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