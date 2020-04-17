#pragma once
// ApplicationManager.h
// アプリケーション環境を管理するクラス

#include "../TetrisGameType/TetrisGameType.h"
#include "../Scene\SceneManager/SceneManager.h"

class ApplicationManager
{
public:
	ApplicationManager();
	~ApplicationManager();
public:
	/// <summary>
	/// 初期化メソッド
	/// </summary>
	void Init();
	/// <summary>
	/// 更新メソッド
	/// <param name="loop">loopのフラグを参照です</param>
	/// </summary>
	void Update(bool &loop);
	/// <summary> 
	/// 描画メソッド
	/// </summary>
	void Draw();
	/// <summary>　
	/// 解放メソッド
	/// </summary>
	void Release();
	/// <summary>　
	/// ループのフラグ参照メソッド
	/// <returns>ループのフラグを返します</returns>
	/// </summary>
	const bool& GetLoop();
	/// <summary>
	/// ループのフラグ設定メソッド
	/// </summary>
	static void SetLoop(signed short int loopselect);
private:
	/// <value> 全てのシーンを管理しているマネージャーです </value>
	SceneManager* SceneManager_;
	/// <value> 参照したループを受け取るフラグ　0x000 = false 0x001 = true </value>
	static signed short int Loop_;
};