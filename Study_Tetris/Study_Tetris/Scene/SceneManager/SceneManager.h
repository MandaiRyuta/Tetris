#pragma once
#include "../Scene.h"
#include "../../TetrisGameType\TetrisGameType.h"

constexpr int ArrowInputMaxTime = 30;
constexpr int EnterInputMaxTime = 30;
class SceneManager
{
public:
	SceneManager() 
	{
		CurrentScene_ = new Scene(0);
		CurrentScene_->Init();
		Arrow_Up_Down_ = 0x000;
		ArrowInputNowTime_ = 30;
		EnterInputNowTime_ = 30;
	}
	~SceneManager() {}
	void Init();
	void Update();
	void Draw();
	void Release();
	void ChangeScene(TetrisGameType::SCENETYPE Type);
private:
	TetrisGameType::SCENETYPE type_;
	Scene* CurrentScene_;
	unsigned int EnterInputNowTime_;
	unsigned int ArrowInputNowTime_;
	signed short int Arrow_Up_Down_;
};