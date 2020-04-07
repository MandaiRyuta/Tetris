#pragma once
#include "TetrisGameType.h"
#include "SceneManager.h"

class ApplicationManager
{
public:
	ApplicationManager();
	~ApplicationManager();
public:
	void Init();
	void Update(bool *loop, int* scenenum, bool *changescene);
	void Draw();
	void Release();
private:
	Scene Scene_;
};