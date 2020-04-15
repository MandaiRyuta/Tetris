#pragma once
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
	void PauseDraw();
	void PauseSelect();
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
	TetrisUI::UIManager* Ui_;
	TetrisBlocks::BlockCollection* Collection_;
};