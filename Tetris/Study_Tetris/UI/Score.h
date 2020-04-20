#pragma once
//Score.h
//スコアを表示するクラス
#include "UI.h"

namespace TetrisUI
{
	class Score : public UI
	{
	public:
		Score()
		{
			Position_.x = 600;
			Position_.y = 100;
		}
		~Score() {}
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
		/// スコアをセットするメソッド
		/// </summary>
		/// <param name="score">スコア</param>
		static void SetScore(int score);
		/// <summary>
		/// スコアの情報を受け取るメソッド
		/// </summary>
		/// <returns>現在のスコア</returns>
		static unsigned int GetScore();
		/// <summary>
		/// スコアを加算するメソッド
		/// </summary>
		/// <param name="addscore">加算するスコア</param>
		static void AddScore(int addscore);
	private:
		/// <value>リザルト時のスコアテクスチャーです</value>
		int ScoreTexture_;
		/// <value>描画時間です</value>
		int DrawTime_;
		/// <value>ゲームプレイ中の文字のスコアテクスチャーです</value>
		int FontScoreTexture_;
		/// <value>スコアです</value>
		static unsigned int Score_;
		/// <value>描画位置です</value>
		TetrisGameType::Vector2 Position_;
	};
}