#include "Fade.h"

int TetrisUI::Fade::State_ = 0;
signed short int TetrisUI::Fade::FadeCheck_ = 0x000;
void TetrisUI::Fade::Init()
{
	Color_.r = 255;
	Color_.g = 255;
	Color_.b = 255;
	Color_.a = 0;
	State_ = 0;
	FadeCheck_ = 0x000;
}

void TetrisUI::Fade::Update()
{
	switch (State_)
	{
	case 0:
		break;
	case 1:
		FadeCheck_ = FadeIn();
		if (FadeCheck_ == 0x001)
		{
			State_ = 0;
		}
		break;
	case 2:
		FadeCheck_ = FadeOut();
		if (FadeCheck_ == 0x001)
		{
			State_ = 0;
		}
		break;
	}
}

void TetrisUI::Fade::Draw()
{
	switch (State_)
	{
	case 0:
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		break;
	case 1:
		SetDrawBlendMode(DX_BLENDMODE_ADD, Color_.a);
		//SetDrawBright(Color_.r, Color_.g, Color_.b);
		DrawBox(0, 0, 640, 480, GetColor(Color_.r, Color_.g, Color_.b), true);
		break;
	case 2:
		SetDrawBlendMode(DX_BLENDMODE_ADD, Color_.a);
		//SetDrawBright(Color_.r, Color_.g, Color_.b);
		DrawBox(0, 0, 640, 480, GetColor(Color_.r, Color_.g, Color_.b), true);
		break;
	}
}

void TetrisUI::Fade::Release()
{
}

signed short int TetrisUI::Fade::FadeIn()
{
	if (Color_.a < 254)
	{
		Color_.a += 1;
		Color_.r = 0;
		Color_.g = 0;
		Color_.b = 0;
	}
	if (Color_.a >= 254)
	{
		return 0x001;
	}
	else
	{
		return 0x000;
	}
}

signed short int TetrisUI::Fade::FadeOut()
{
	if (Color_.a > 1)
	{
		Color_.a -= 1;
		Color_.r = 0;
		Color_.g = 0;
		Color_.b = 0;
	}
	if (Color_.a <= 1)
	{
		return 0x001;
	}
	else
	{
		return 0x000;
	}
}

void TetrisUI::Fade::SetStartFade(int type)
{
	FadeCheck_ = 0x000;
	State_ = type;
}

signed short int TetrisUI::Fade::GetFadeCheck()
{
	return FadeCheck_;
}
