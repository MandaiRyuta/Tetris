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

	}
	~SceneManager() {}
	void Init();
	void Update();
	void Draw();
	void Release();
	static void ChangeScene(TetrisGameType::SCENETYPE Type);
	static void SetTotalScore(int score);
	static const int& GetTotalScore();
	static const TetrisGameType::SCENETYPE& GetNowScene();
private:
	static int TotalScore_;
	static TetrisGameType::SCENETYPE NowType_;
	static TetrisGameType::SCENETYPE Type_;
	static Scene* CurrentScene_;
	unsigned int EnterInputNowTime_[3];
};