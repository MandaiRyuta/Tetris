#pragma once
//Fade.h
//フェードを管理しているクラス
#include "UI.h"

namespace TetrisUI
{
	class Fade : public UI
	{
	public:
		Fade() {}
		~Fade() {}
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
		/// <param name="handle">テクスチャーハンドル</param>
		/// <param name="texturenumber">数字テクスチャーを</param>
		virtual void LoadTexture(int handle, int texturenumber = 0) override;
		/// <summary>
		/// フェードインメソッド
		/// </summary>
		/// <returns></returns>
		signed short int FadeIn();
		/// <summary>
		/// フェードアウト
		/// </summary>
		/// <returns></returns>
		signed short int FadeOut();
		/// <summary>
		/// フェードのタイプを指定するメソッドです
		/// </summary>
		/// <param name="type"></param>
		static void SetStartFade(int type);
		/// <summary>
		/// フェードが終わったか
		/// </summary>
		/// <returns>フェードの状態を取得</returns>
		static signed short int GetFadeCheck();
	private:
		/// <value>フェードチェックフラグです</value>
		static signed short int FadeCheck_;
		/// <value>フェードをしないか、フェードインするか、フェードアウトするかを指定するステートです</value>
		static int State_;
		/// <value>色情報</value>
		TetrisGameType::Color Color_;
	};
}