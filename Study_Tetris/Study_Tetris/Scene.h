#pragma once
#include <vector>
#include "Utils.h"

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
	std::vector<int> obj_;
	int scenenumber_;
	signed short int title_start_end_;
	signed short int game_start_end_;
	signed short int result_start_end;
	Input* input_;
	signed short int loop_;
};