#pragma once
#include <vector>
#include "../TetrisGameType\TetrisGameType.h"
#include "../TetrisBlock\BlockCollection\BlockCollection.h"
#include "../UI/UIManager/UIManager.h"
#include "../Resource/TextureData.h"
#include "../Resource/Block.h"
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
	static const TetrisGameType::Block& GetBlockTypeColor(int type, int x, int y);
	template<class T>
	void AddObject(int type);
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
	static BlockData* BlocksData;
	TetrisUI::UIManager* Ui_;
	TetrisBlocks::BlockCollection* Collection_;
};

template<class T>
inline void Scene::AddObject(int type)
{
	TetrisUI::UIManager* obj = new T;
	obj->SetType(type);
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
