#pragma once
//InGameState.h
//テトリスの勝敗を表示するクラス
#include "UI.h"

namespace TetrisUI
{
	namespace GameState
	{
		constexpr int GameClear = 1;
		constexpr int GameOver = 2;
	}
	class InGameState : public UI
	{
	public:
		InGameState() : GameClearTexture_(0), GameOverTexture_(0), NextSceneCount_(0){}
		~InGameState() {}
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
		/// ゲームをクリアしたか失敗したかを知らせるメソッド
		/// </summary>
		/// <returns>ゲームをクリアしたか失敗したかが返ってきます</returns>
		static int GetGameState();
		/// <summary>
		/// ゲームをクリアしたか失敗したかを指定するメソッド
		/// </summary>
		/// <param name="state">クリアもしくは失敗を設定する</param>
		static void SetGameState(int state);
	private:
		/// <value>ゲームクリアテクスチャーです</value>
		int GameClearTexture_;
		/// <value>ゲームオーバーテクスチャーです</value>
		int GameOverTexture_;
		/// <value>ゲームのクリア、失敗を管理します</value>
		static int GameState_;
		/// <value>次のシーンに移るまでのカウントです</value>
		int NextSceneCount_;
	};
}