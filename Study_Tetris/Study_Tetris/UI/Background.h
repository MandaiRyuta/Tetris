#pragma once
//Background.h
//背景UIクラスです。
#include "UI.h"

namespace TetrisUI
{
	class Background : public UI
	{
	public:
		Background(){}
		~Background() {}
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
	private:
		/// <value>背景テクスチャー</value>
		int BackGroundTexture_;
	};
}