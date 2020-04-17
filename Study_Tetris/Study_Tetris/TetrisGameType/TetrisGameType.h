#pragma once
// TetrisGameType.h
// テトリスゲームに関係する情報をまとめてます
#include <DxLib.h>
#include <array>

//デバッグ用のdefineです。
#define DEBUGCHECK 
/// <summary>
/// シーンの番号です
/// </summary>
namespace SceneNumber
{
	constexpr int TitleSceneNumber = 0;
	constexpr int GameSceneNumber = 1;
	constexpr int ResultSceneNumber = 2;
}
/// <summary>
/// テトリスのゲームにかかわる情報です
/// </summary>
namespace TetrisGameType
{
	//ブロックの種類
	namespace TetrisBlockTypeNum
	{
		constexpr int MaxNumber = 7;
	}
	//ブロックの形状を示す番号
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

	//ストックするブロックの数
	constexpr int StockBlockSize = 4;
	//ブロックの高さ
	constexpr int BlockHeight = 5;
	//ブロックの幅
	constexpr int BlockWidth = 5;
	//ステージの高さ
	constexpr int StageHeight = 23;
	//ステージの幅
	constexpr int StageWidth = 13;
	//描画しているブロックの幅
	constexpr int DrawBlockWidth = 20;
	//ブロックの速度
	constexpr int BlockSpeed = 5;
	//１フレーム
	constexpr int KeyFrame = 1;

	//オブジェクトのタイプ
	enum class ObjectType
	{
		BACKGROUND,
		TETRIS,
	};

	//オブジェクトの形状
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
	//シーンの種類
	enum class SCENETYPE
	{
		TITLE,
		GAME,
		RESULT,
		NONE,
	};
	//２次元座標
	struct Vector2
	{
		int x;
		int y;
	};
	//色情報
	struct Color
	{
		int r;
		int g;
		int b;
		int a;
	};
	//ブロックの形状と色情報
	struct Block
	{
		int r;
		int g;
		int b;
		int a;
		int type;
	};
}