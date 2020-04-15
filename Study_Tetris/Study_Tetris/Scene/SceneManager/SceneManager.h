#pragma once
#include "../Scene.h"
#include "../../TetrisGameType\TetrisGameType.h"

constexpr int ArrowInputMaxTime = 30;
constexpr int EnterInputMaxTime = 120;
class SceneManager
{
public:
	SceneManager() 
	{
		CurrentScene_ = new Scene(0);
		CurrentScene_->Init();
		EnterInputNowTime_[0] = 0;
		EnterInputNowTime_[1] = 0;
		EnterInputNowTime_[2] = 0;
		Type_ = TetrisGameType::SCENETYPE::TITLE;
		NowType_ = TetrisGameType::SCENETYPE::TITLE;

	}
	~SceneManager() {}
	void Init();
	void Update();
	void Draw();
	void Release();
	static void ChangeScene(TetrisGameType::SCENETYPE Type);
	static void SetTotalScore(int score);
	static int GetTotalScore();
	static TetrisGameType::SCENETYPE GetNowScene();
private:
	static int TotalScore_;
	static TetrisGameType::SCENETYPE NowType_;
	static TetrisGameType::SCENETYPE Type_;
	static Scene* CurrentScene_;
	unsigned int EnterInputNowTime_[3];
};