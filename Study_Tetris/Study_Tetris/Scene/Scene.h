#pragma once
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
	void Init();
	void Update();
	void Draw();
	void Release();
	void PauseDraw();
	void PauseSelect();
	template<class T>
	void AddUIObject(int scenetype);
	template<class T>
	void AddBlockObject();
	template<class T>
	void ObjectReleaseMemory(std::vector<T*>& vector);
private:
	int EnterKeyMaxTime_;
	int EnterKeyNowTime_;
	int UpArrowKeyNowTime_;
	int UpArrowKeyMaxTime_;
	int DownArrowKeyMaxTime_;
	int DownArrowKeyNowTime_;
	int MenuSelectNumber_;
	int PauseKeyMaxTime_;
	int PauseKeyNowTime_;
	int Pause_;
	int Scenenumber_;
	int TitleDrawTime_;

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

template<class T>
inline void Scene::ObjectReleaseMemory(std::vector<T*>& vector)
{
	for (int i = 0; i < vector.size(); ++i)
	{
		delete vector[i];
	}
}
