#include "Time.h"

void TetrisUI::Time::Init()
{
}

void TetrisUI::Time::Update()
{
	if (nowtime_ < 0)
	{
		//ゲームオーバー
	}
	Min_ = nowtime_ / 3600;
	Sec_ = nowtime_ % 3600 / 60;
	MinSec_ = nowtime_ % 60;
	nowtime_--;
}

void TetrisUI::Time::Draw()
{
	DrawFormatString(Positionx_[0], Positiony_[0], GetColor(Color_[0], Color_[1], Color_[2]),"%2d",Min_);
	DrawFormatString(Positionx_[1], Positiony_[1], GetColor(Color_[0], Color_[1], Color_[2]),"%2d",Sec_);
	DrawFormatString(Positionx_[2], Positiony_[2], GetColor(Color_[0], Color_[1], Color_[2]),"%2d",MinSec_);
}

void TetrisUI::Time::Release()
{
}
