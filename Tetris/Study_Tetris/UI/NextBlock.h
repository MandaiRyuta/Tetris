#pragma once
// NextBlock.h
// ストックさせたブロックを表示するクラス
#include "UI.h"
#include "../Resource/Block.h"

namespace TetrisUI
{
	class NextBlock : public UI
	{	
	public:
		NextBlock(){
		}
		~NextBlock() {}
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
		/// ロードテクスチャーメソッド
		/// </summary>
		/// <param name="handle">登録したテクスチャー番号</param>
		/// <param name="texturenumber">数字テクスチャー用の番号 0 から 9</param>
		virtual void LoadTexture(int handle, int texturenumber = 0) override;
		/// <summary>
		/// スタックしているブロックを描画するメソッド
		/// </summary>
		void NextBlockPlaceDraw();
		/// <summary>
		/// ブロックの初期化メソッド
		/// </summary>
		void BlockInit();
		/// <summary>
		/// ストックしているブロックを取得するメソッド
		/// </summary>
		/// <param name="num">ストックさせる番号</param>
		/// <param name="type">ストックさせるブロックの形状</param>
		static void GetNextBlockType(int num, int type)
		{
			BlockNumber_[num] = type;
		}
	private:	
		/// <value>ブロックのデータです</value>
		BlockData BlocksData_;
		/// <value>ストックさせているブロックの番号です</value>
		static std::array<int, 3> BlockNumber_;
		/// <value>描画させるブロックの配列です</value>
		TetrisGameType::Block Blocktype_[TetrisGameType::TetrisBlockTypeNum::MaxNumber][TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
	};
}