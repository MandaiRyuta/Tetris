#pragma once
#include "../TetrisGameType/TetrisGameType.h"
#include "../Scene\SceneManager/SceneManager.h"

class ApplicationManager
{
public:
	ApplicationManager();
	~ApplicationManager();
public:
	void Init();
	void Update(bool *loop);
	void Draw();
	void Release();
	bool GetLoop();
private:
	SceneManager* SceneManager_;
	signed short int Loop_;
};