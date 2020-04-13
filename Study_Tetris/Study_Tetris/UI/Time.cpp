#include "Time.h"
#include "Number.h"
#include "InGameState.h"
#include "Fade.h"
#include "../TetrisBlock/TetrisBlock.h"

void TetrisUI::Time::Init()
{
}

void TetrisUI::Time::Update()
{
	if (TetrisUI::Fade::GetFadeCheck() == 0x001)
	{
		if (nowtime_ < 8000 && TetrisBlocks::TetrisBlock::GetGameBlockLevel() == 0)
		{
			TetrisBlocks::TetrisBlock::SetGameBlockLevel(1);
		}
		else if (nowtime_ < 7000 && TetrisBlocks::TetrisBlock::GetGameBlockLevel() == 1)
		{
			TetrisBlocks::TetrisBlock::SetGameBlockLevel(2);
		}
		else if (nowtime_ < 0 && TetrisBlocks::TetrisBlock::GetGameBlockLevel() == 2)
		{
			TetrisUI::InGameState::SetGameState(1);
		}
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

		TimeFontDrawTime_ += 5;
	}
}

void TetrisUI::Time::Draw()
{
	if (TetrisUI::Fade::GetFadeCheck() == 0x001)
	{
		if (TimeFontDrawTime_ > 255)
		{
			TimeFontDrawTime_ = 0;
		}
		else if (TimeFontDrawTime_ < 120)
		{
			DrawGraph(400, 20, TimeFontTexture_, true);
		}
	}
	//DrawFormatString(Positionx_[0], Positiony_[0], GetColor(Color_[0], Color_[1], Color_[2]),"%2d",Min_);
	//DrawFormatString(Positionx_[1], Positiony_[1], GetColor(Color_[0], Color_[1], Color_[2]),"%2d",Sec_);
	//DrawFormatString(Positionx_[2], Positiony_[2], GetColor(Color_[0], Color_[1], Color_[2]),"%2d",MinSec_);
}

void TetrisUI::Time::Release()
{
}
