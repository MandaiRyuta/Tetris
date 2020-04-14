#include "Time.h"
#include "Number.h"
#include "InGameState.h"
#include "Fade.h"
#include "../TetrisBlock/TetrisBlock.h"

int TetrisUI::Time::nowtime_ = 0;

void TetrisUI::Time::Init()
{
}

void TetrisUI::Time::Update()
{
	if (TetrisUI::Fade::GetFadeCheck() == 0x001)
	{
		Min_ = nowtime_ / 3600;
		Sec_ = nowtime_ % 3600 / 60;
		MinSec_ = nowtime_ % 60;
		nowtime_--;

		int a, b, c, d, e;

		a = Min_;
		b = Sec_ / 60;
		c = Sec_ % 10;
		d = MinSec_ / 60;
		e = MinSec_ % 10;

		Number::SetDrawNumber(Positionx_[0], Positiony_[0], Min_, 0, 0x000);
		Number::SetDrawNumber(Positionx_[1], Positiony_[1], Sec_ / 10, 1, 0x000);
		Number::SetDrawNumber(Positionx_[1] + 25, Positiony_[1], Sec_ % 10, 2, 0x000);
		Number::SetDrawNumber(Positionx_[2] + 25, Positiony_[2], MinSec_ / 10, 3, 0x000);
		Number::SetDrawNumber(Positionx_[2] + 50, Positiony_[2], MinSec_ % 10, 4, 0x000);
	}
}

void TetrisUI::Time::Draw()
{
	if (TetrisUI::Fade::GetFadeCheck() == 0x001)
	{
		DrawGraph(400, 20, TimeFontTexture_, true);
	}
	//DrawFormatString(Positionx_[0], Positiony_[0], GetColor(Color_[0], Color_[1], Color_[2]),"%2d",Min_);
	//DrawFormatString(Positionx_[1], Positiony_[1], GetColor(Color_[0], Color_[1], Color_[2]),"%2d",Sec_);
	//DrawFormatString(Positionx_[2], Positiony_[2], GetColor(Color_[0], Color_[1], Color_[2]),"%2d",MinSec_);
}

void TetrisUI::Time::Release()
{
}

int TetrisUI::Time::GetNowTime()
{
	return nowtime_;
}
