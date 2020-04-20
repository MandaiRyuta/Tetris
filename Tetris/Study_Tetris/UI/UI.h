#pragma once
//UI.h
//UIの仮想クラス
#include <DxLib.h>
#include "../TetrisGameType/TetrisGameType.h"

namespace TetrisUI
{
	class UI
	{
	public:
		UI(){}
		virtual ~UI() {}
	public:
		/// <summary>
		/// 初期化メソッドの抽象化
		/// </summary>
		virtual void Init() =0;
		/// <summary>
		/// 更新メソッド抽象化
		/// </summary>
		virtual void Update() =0;
		/// <summary>
		/// 描画メソッド抽象化
		/// </summary>
		virtual void Draw() =0;
		/// <summary>
		/// 解放メソッド抽象化
		/// </summary>
		virtual void Release() =0;
		/// <summary>
		/// ロードテクスチャーメソッドの抽象化
		/// </summary>
		/// <param name="handle">登録したテクスチャー番号</param>
		/// <param name="texturenumber">数字テクスチャー用の番号 0 から 9</param>
		virtual void LoadTexture(int handle, int texturenumber = 0) = 0;
	};
}