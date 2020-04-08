#pragma once
#include <vector>
#include "../TetrisGameType\TetrisGameType.h"
#include "../TetrisBlock\BlockCollection\BlockCollection.h"

class Input;

class Scene
{
public:
	Scene();
	~Scene();
	void Init();
	void Update();
	void Draw();
	void Release();
	void Create(int obj);
	void Delete();
	void SetSceneNumber(int scenenum);
	int GetSceneNumber();
	bool GetLoop();
	void SetLoop(signed short int loop);
private:
	std::vector<int> Obj_;
	int Scenenumber_;
	TetrisBlocks::BlockCollection* Collection_;
	signed short int Title_start_end_;
	signed short int Game_start_end_;
	signed short int Result_start_end_;
	signed short int Loop_;
};