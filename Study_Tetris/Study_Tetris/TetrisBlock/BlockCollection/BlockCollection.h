#pragma once
// BlockCollection.h
// ゲームのステージを管理しているクラスです。
#include <array>
#include "../../TetrisGameType\TetrisGameType.h"
#include "../TetrisBlock.h"
#include "../../Actor/Actor.h"

namespace TetrisBlocks
{
	class BlockCollection : public Actor
	{
	public:
		BlockCollection()
		{

		}
		~BlockCollection()
		{

		}
	public:
		/// <summary>
		/// 初期化メソッド
		/// </summary>
		virtual void Init() override;
		/// <summary>
		/// 更新メソッド
		/// </summary>
		virtual void Update() override;
		/// <summary>
		/// 描画メソッド
		/// </summary>
		virtual void Draw() override;
		/// <summary>
		/// 解放メソッド
		/// </summary>
		virtual void Release() override;

		/// <summary>
		/// ステージに配置されたブロックを横一列で確認するメソッド
		/// </summary>
		void StackBlockClearLineCheck();
		/// <summary>
		/// 横一列で並んでいるブロックを消すメソッド
		/// </summary>
		void StageBlockLineClear();
		/// <summary>
		/// ステージに配置されているブロックを確認するためのメソッド
		/// </summary>
		/// <param name="x">確認したいステージ内のX座標</param>
		/// <param name="y">確認したいステージ内のY座標</param>
		/// <returns>ブロックの有無　有: 1 から 7 無: 0  ステージの外 : 9 位置によって参照されます。</returns>
		const int& GetBoardInfo(int x, int y);
	private:
		/// <value>ステージにブロックが置ける行です</value>
		int ClearLine_[23];
		/// <value>テトリスブロックが１行並んでいたら"0x001:(true)"に設定し消した際に"0x000:(false)"に変わります</value>
		signed short int ClearCheck_;
		/// <value>プレイヤーが操作できるブロッククラスです</value>
		TetrisBlock Block_;
		/// <value>ブロックが並んでおり、消した行の数</value>
		int ClearCount_;
		/// <value>ステージの幅、高さを管理している配列です。</value>
		std::array<std::array<int, TetrisGameType::StageWidth>, TetrisGameType::StageHeight> Board_;
	};
}