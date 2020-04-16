#include "Background.h"
#include "../Scene/SceneManager/SceneManager.h"

void TetrisUI::Background::Init()
{
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

void TetrisUI::Background::LoadTexture(int handle, int texturenumber)
{
	BackGroundTexture_ = handle;
}
