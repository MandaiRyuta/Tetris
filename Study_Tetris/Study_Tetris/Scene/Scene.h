#pragma once
#include <vector>
#include "../TetrisGameType\TetrisGameType.h"
#include "../TetrisBlock\BlockCollection\BlockCollection.h"
#include "../UI/UIManager/UIManager.h"

class Scene
{
public:
	Scene(int type);
	~Scene();
	void Init();
	void Update();
	void Draw();
	void Release();
private:
	std::vector<int> Obj_;
	int Scenenumber_;
	TetrisUI::UIManager* Ui_;
	TetrisBlocks::BlockCollection* Collection_;
};