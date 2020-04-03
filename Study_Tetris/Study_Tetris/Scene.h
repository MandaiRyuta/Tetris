#pragma once
#include <vector>
#include "Utils.h"
class UI;

class Scene
{
public:
	Scene() :
		title_start_end_(0)
	{}
	void Init();
	void Update();
	void Draw();
	void Release();
	void Create(int obj);
	void Delete();
	void SetSceneNumber(int scenenum);
	int GetSceneNumber();
private:
	std::vector<int> obj_;
	int scenenumber_;
	int title_start_end_;

};