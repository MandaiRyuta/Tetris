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
	static void SetLoop(signed short int loopselect);
private:
	SceneManager* SceneManager_;
	static signed short int Loop_;
};