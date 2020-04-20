#pragma once
//SceneManager.h
//各シーンを管理しています。
#include "../Scene.h"
#include "../../TetrisGameType\TetrisGameType.h"

///<value> シーンを連続で切り替えない為に作られたEnterの入力を制限する数値です </value>
constexpr int EnterInputMaxTime = 120;
class SceneManager
{
public:
	SceneManager() 
	{

	}
	~SceneManager() {}
	/// <summary>
	/// 初期化メソッド
	/// </summary>
	void Init();
	/// <summary> 
	/// 更新メソッド
	/// </summary>
	void Update();
	/// <summary>
	/// 描画メソッド
	/// </summary>
	void Draw();
	/// <summary>
	/// 解放メソッド
	/// </summary>
	void Release();
	/// <summary>
	/// シーンを切り替えるメソッド
	/// </summary>
	static void ChangeScene(TetrisGameType::SCENETYPE Type);
	/// <summary>
	/// ゲームのスコアを設定するメソッド
	/// </summary>
	static void SetTotalScore(int score);
	/// <summary>
	/// リザルトシーンでトータルスコアを参照するメソッド
	/// <returns>トータルスコアを返します。</returns>
	///</summary>
	static const int& GetTotalScore();
	/// <summary> 
	/// 現在描画しているシーンの番号を参照するメソッド
	/// </summary>
	static const TetrisGameType::SCENETYPE& GetNowScene();
private:
	///<value>トータルスコアを管理しています</value>
	static int TotalScore_;
	///<value>現在のシーンのタイプです</value>
	static TetrisGameType::SCENETYPE NowType_;
	///<value>シーン切り替え時に現在のシーンを受け取る用に作られてます。</value>
	static TetrisGameType::SCENETYPE Type_;
	///<value>シーンを管理しています。</value>
	static Scene* CurrentScene_;
	///<value>シーン切り替え時に必要なEnterの入力を管理しています。</value>
	unsigned int EnterInputNowTime_[3];
};