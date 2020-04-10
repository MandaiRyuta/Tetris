#include "Background.h"

void TetrisUI::Background::Init()
{
	BackGroundTexture_ = LoadGraph("Background.png");
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
