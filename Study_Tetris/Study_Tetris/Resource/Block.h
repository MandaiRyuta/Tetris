#pragma once
//Block.h
//ブロックの色、配置を管理しているクラス
#include "../TetrisGameType/TetrisGameType.h"

class BlockData
{
public:
	BlockData();
	~BlockData();
public:
	/// <summary> 
	/// 初期化メソッド
	/// </summary>
	void Init();
	/// <summary>
	/// ブロックの配置座標を受け取るメソッド
	/// <para>各ブロックの表示を行う際、初期化のタイミングで呼び出して使います</para>
	/// </summary>
	const TetrisGameType::Block& GetBlockPosition(int type, int x, int y);
private:
	///<value>テトリスの各ブロックを管理しています</value>
	TetrisGameType::Block Block_[TetrisGameType::TetrisBlockTypeNum::MaxNumber][TetrisGameType::BlockHeight][TetrisGameType::BlockHeight];
};