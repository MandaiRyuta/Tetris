#include "Fade.h"
#include "../Scene/Scene.h"
int TetrisUI::Fade::State_ = 0;
signed short int TetrisUI::Fade::FadeCheck_ = 0x000;
void TetrisUI::Fade::Init()
{
	Color_.r = 0;
	Color_.g = 0;
	Color_.b = 0;
	Color_.a = 0;
	State_ = 0;
	FadeCheck_ = 0x000;
}

void TetrisUI::Fade::Update()
{
	if (Scene::GetTextureData(0, 0) || Scene::GetTextureData(1, 5) || Scene::GetTextureData(2, 2))
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
}

void TetrisUI::Fade::Draw()
{
	switch (State_)
	{
	case 0:
		SetDrawBright(255,255,255);
		//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		break;
	case 1:
		SetDrawBright(Color_.r, Color_.g, Color_.b);
		//SetDrawBlendMode(DX_BLENDMODE_ADD, Color_.a);
		//SetDrawBright(Color_.r, Color_.g, Color_.b);
		//DrawBox(0, 0, 640, 480, GetColor(Color_.r, Color_.g, Color_.b), true);
		break;
	case 2:
		SetDrawBright(Color_.r, Color_.g, Color_.b);
		//SetDrawBlendMode(DX_BLENDMODE_ADD, Color_.a);
		//SetDrawBright(Color_.r, Color_.g, Color_.b);
		//DrawBox(0, 0, 640, 480, GetColor(Color_.r, Color_.g, Color_.b), true);
		break;
	}
}

void TetrisUI::Fade::Release()
{
}

signed short int TetrisUI::Fade::FadeIn()
{
	if (Color_.a < 255)
	{
		Color_.r += 1;
		Color_.g += 1;
		Color_.b += 1;
		Color_.a += 1;
	}
	if (Color_.a >= 255)
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
	if (Color_.a > 0)
	{
		Color_.a -= 1;
		Color_.r = (255 * Color_.a) / 255;
		Color_.g = (255 * Color_.a) / 255;
		Color_.b = (255 * Color_.a) / 255;
	}
	if (Color_.a <= 0)
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
