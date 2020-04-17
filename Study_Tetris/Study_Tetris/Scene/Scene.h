#pragma once
//Scene.h
//シーンを管理しているクラスです。
#include <algorithm>
#include <vector>
#include <iterator>
#include <deque>
#include <list>
#include "../TetrisGameType\TetrisGameType.h"
#include "../TetrisBlock\BlockCollection\BlockCollection.h"
#include "../UI/UIManager/UIManager.h"
#include "../Actor/Actor.h"

class Scene
{
public:
	Scene(int type);
	~Scene();
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
	/// ポーズ時の画面描画をしているメソッド
	/// </summary>
	void PauseDraw();
	/// <summary>
	/// ポーズ字の選択を管理しているメソッド
	/// </summary>
	void PauseSelect();
	/// <summary>
	/// 外部で生成されたSceneでUiを追加するメソッド
	/// </summary>
	template<class T>
	void AddUIObject(int scenetype);
	/// <summary>
	/// 外部で生成されたSceneでゲームのブロックを追加するメソッド
	/// </summary>
	template<class T>
	void AddBlockObject();
private:
	/// <summary>
	/// メモリーを解放するメソッド
	/// <param name="vector">T型で作られたstd::vectorを参照します。</param>
	/// </summary>
	void ObjectReleaseMemory();
private:
	/// <value>Enterキーの入力ができるまでの待機時間です</value>
	int EnterKeyMaxTime_;
	/// <value>現在のフレーム時間</value>
	int EnterKeyNowTime_;
	/// <value>[↑]キーの入力ができるまでの待機時間です</value>
	int UpArrowKeyMaxTime_;
	/// <value>現在のフレーム時間</value>
	int UpArrowKeyNowTime_;
	/// <value>[↓]キーの入力ができるまでの待機時間です</value>
	int DownArrowKeyMaxTime_;
	/// <value>現在のフレーム時間</value>
	int DownArrowKeyNowTime_;
	/// <value>メニューの選択番号です。</value>
	int MenuSelectNumber_;
	/// <value>[P]キーの入力ができるまでの待機時間です</value>
	int PauseKeyMaxTime_;
	/// <value>現在のフレーム時間です</value>
	int PauseKeyNowTime_;
	/// <value>ポーズのフラグです　　　 1 : ポーズ解除　-1 : ポーズ開始</value>
	int Pause_;
	/// <value>シーンの番号です。</value>
	int Scenenumber_;
	/// <value>タイトルで特定の文字を点滅させるために作られてます。</value>
	int TitleDrawTime_;
	/// <value>UiManagerクラスやBlockCollectionクラスを含める為に作られた配列です</value>
	std::vector<Actor*> Actor_;
};

template<class T>
inline void Scene::AddUIObject(int scenetype)
{
	TetrisUI::UIManager* obj = new T;
	obj->SetType(scenetype);
	Actor_.push_back(obj);
}

template<class T>
inline void Scene::AddBlockObject()
{
	TetrisBlocks::BlockCollection* obj = new T;
	Actor_.push_back(obj);
}

inline void Scene::ObjectReleaseMemory()
{
	for (int i = 0; i < Actor_.size(); ++i)
	{
		delete Actor_[i];
	}
	Actor_.clear();
}
