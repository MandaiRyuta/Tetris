#include "Background.h"
#include "../Window/main.h"
void TetrisUI::Background::Init()
{
	BackGroundTexture_ = SceneTextureData.GetBackgroundData();
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
