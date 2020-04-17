#pragma once
// Hold.h
// ブロックを保持させるためのクラスです。
#include "UI.h"
#include "../Resource/Block.h"

namespace TetrisUI
{
	class Hold : public UI
	{
	public:
		Hold();
		~Hold();
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
		/// ブロック情報の初期化メソッド
		/// </summary>
		void BlockInit();
		/// <summary>
		/// 保持しているブロックの形状を管理するメソッド
		/// </summary>
		/// <param name="type">保持しているブロックの形状</param>
		static void GetHoldBlockType(int type)
		{
			HoldBlockType_ = type;
		}
	private:
		/// <value>ブロックのデータです</value>
		BlockData BlocksData_;
		/// <value>保持しているブロックの形状を描画するための配列です</value>
		TetrisGameType::Block Blocktype_[TetrisGameType::TetrisBlockTypeNum::MaxNumber][TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		/// <value>ホールドしているブロックの形状です</value>
		static int HoldBlockType_;
	};
}