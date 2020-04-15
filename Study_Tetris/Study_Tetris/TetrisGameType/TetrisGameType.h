#pragma once
#include <DxLib.h>
#include <array>

namespace SceneNumber
{
	constexpr int TitleSceneNumber = 0;
	constexpr int GameSceneNumber = 1;
	constexpr int ResultSceneNumber = 2;
	constexpr int TitleLoadingScene = 3;
	constexpr int GameLoadingScene = 4;
	constexpr int ResultLoadingScene = 5;
}
namespace ResourceTexture
{
	static int BackgroundTexture = 0;
}
namespace TetrisGameType
{
	namespace TetrisBlockTypeNum
	{
		constexpr int MaxNumber = 7;
	}
	namespace TetrisBlockType
	{
		constexpr int TYPEI = 0;
		constexpr int TYPEJ = 1;
		constexpr int TYPEL = 2;
		constexpr int TYPEO = 3;
		constexpr int TYPES = 4;
		constexpr int TYPET = 5;
		constexpr int TYPEZ = 6;
	}

	constexpr int StockBlockSize = 4;
	constexpr int BlockHeight = 5;
	constexpr int BlockWidth = 5;
	constexpr int StageHeight = 23;
	constexpr int StageWidth = 13;
	constexpr int DrawBlockWidth = 20;
	constexpr int BlockSpeed = 5;
	constexpr int KeyFrame = 1;

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