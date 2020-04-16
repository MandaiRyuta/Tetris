#include "Background.h"
#include "../Scene/SceneManager/SceneManager.h"
#include "../Window/main.h"
void TetrisUI::Background::Init()
{
	if (SceneManager::GetNowScene() == TetrisGameType::SCENETYPE::TITLE)
	{
		BackGroundTexture_ = Scene::GetTextureData(0, 0);
	}
	if (SceneManager::GetNowScene() == TetrisGameType::SCENETYPE::GAME)
	{
		BackGroundTexture_ = Scene::GetTextureData(1, 4);
	}
	if (SceneManager::GetNowScene() == TetrisGameType::SCENETYPE::RESULT)
	{
		BackGroundTexture_ = Scene::GetTextureData(2, 2);
	}
	//BackGroundTexture_ = LoadGraph("Resource/Background.png");
}

void TetrisUI::Background::Update()
{
}

void TetrisUI::Background::Draw()
{
	DrawGraph(0, 0, BackGroundTexture_, true);
}

void TetrisUI::Background::Release()
{
	DeleteGraph(BackGroundTexture_);
}
