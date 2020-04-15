#include "Time.h"
#include "Number.h"
#include "InGameState.h"
#include "Fade.h"
#include "../TetrisBlock/TetrisBlock.h"
#include "../Window/main.h"
int TetrisUI::Time::nowtime_ = 0;

void TetrisUI::Time::Init()
{
	TimeFontTexture_ = SceneTextureData.GetGameTextureData(2);
}

void TetrisUI::Time::Update()
{
	if (TetrisUI::Fade::GetFadeCheck() == 0x001)
	{
		Min_ = nowtime_ / 3600;
		Sec_ = nowtime_ % 3600 / 60;
		MinSec_ = nowtime_ % 60;
		nowtime_--;
	}

	Number::SetDrawNumber(Positionx_[0], Positiony_[0], Min_, 0, 0x000);
	Number::SetDrawNumber(Positionx_[1], Positiony_[1], Sec_ / 10, 1, 0x000);
	Number::SetDrawNumber(Positionx_[1] + 25, Positiony_[1], Sec_ % 10, 2, 0x000);
	Number::SetDrawNumber(Positionx_[2] + 25, Positiony_[2], MinSec_ / 10, 3, 0x000);
	Number::SetDrawNumber(Positionx_[2] + 50, Positiony_[2], MinSec_ % 10, 4, 0x000);
}

void TetrisUI::Time::Draw()
{
	DrawGraph(400, 20, TimeFontTexture_, true);
}

void TetrisUI::Time::Release()
{
}

int TetrisUI::Time::GetNowTime()
{
	return nowtime_;
}
