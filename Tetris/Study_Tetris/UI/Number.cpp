#include "Number.h"
#include "../Scene/SceneManager/SceneManager.h"
#include "../Scene/Scene.h"
int TetrisUI::Number::Number_[] = {};
int TetrisUI::Number::PositionX_[] = {};
int TetrisUI::Number::PositionY_[] = {};

int TetrisUI::Number::ResizeNumber_[] = {};
int TetrisUI::Number::ReSizePositionX_[] = {};
int TetrisUI::Number::ReSizePositionY_[] = {};
int TetrisUI::Number::ReSize_ = ReSizeDrawSize;
signed short int TetrisUI::Number::ResizeCheck_ = 0x000;
TetrisUI::Number::Number()
{
}

TetrisUI::Number::~Number()
{

}

void TetrisUI::Number::Init()
{
}

void TetrisUI::Number::Update()
{
}

void TetrisUI::Number::Draw()
{
    TetrisGameType::SCENETYPE s = SceneManager::GetNowScene();
    if (SceneManager::GetNowScene() == TetrisGameType::SCENETYPE::GAME)
    {
        for (int i = 0; i < NumberDrawSize; i++)
        {
            DrawNumber(PositionX_[i], PositionY_[i], Number_[i]);
        }

        if (ResizeCheck_ == 0x001)
        {
            for (int t = 0; t < ReSizeDrawSize; t++)
            {
                NumDraw(ReSizePositionX_[t], ReSizePositionY_[t], ResizeNumber_[t]);
            }
        }
    }
    if (SceneManager::GetNowScene() == TetrisGameType::SCENETYPE::RESULT)
    {
        if (ResizeCheck_ == 0x001)
        {
            for (int t = 0; t < ReSizeDrawSize; t++)
            {
                NumDraw(ReSizePositionX_[t], ReSizePositionY_[t], ResizeNumber_[t]);
            }
        }
    }
}

void TetrisUI::Number::Release()
{
    for (int i = 0; i < 10; i++)
    {
        DeleteGraph(DrawNumberTexture_[i]);
    }
}

void TetrisUI::Number::LoadTexture(int handle, int texturenumber)
{
    switch (texturenumber)
    {
    case 0:
        DrawNumberTexture_[0] = handle;
        break;
    case 1:
        DrawNumberTexture_[1] = handle;
        break;
    case 2:
        DrawNumberTexture_[2] = handle;
        break;
    case 3:
        DrawNumberTexture_[3] = handle;
        break;
    case 4:
        DrawNumberTexture_[4] = handle;
        break;
    case 5:
        DrawNumberTexture_[5] = handle;
        break;
    case 6:
        DrawNumberTexture_[6] = handle;
        break;
    case 7:
        DrawNumberTexture_[7] = handle;
        break;
    case 8:
        DrawNumberTexture_[8] = handle;
        break;
    case 9:
        DrawNumberTexture_[9] = handle;
        break;
    }
}

void  TetrisUI::Number::NumDraw(int x, int y, int Num)
{
    int i, NumberWidth, xx;

    NumberWidth = 0;
    for (i = 10; Num >= i; i *= 10) NumberWidth++;

    switch (NumberWidth)
    {
    case 0:
        DrawGraph(x - 15, y, DrawNumberTexture_[0], TRUE);
        DrawGraph(x - (15 * 2), y, DrawNumberTexture_[0], TRUE);
        DrawGraph(x - (15 * 3), y, DrawNumberTexture_[0], TRUE);
        DrawGraph(x - (15 * 4), y, DrawNumberTexture_[0], TRUE);
        DrawGraph(x - (15 * 5), y, DrawNumberTexture_[0], TRUE);
        DrawGraph(x - (15 * 6), y, DrawNumberTexture_[0], TRUE);
        DrawGraph(x - (15 * 7), y, DrawNumberTexture_[0], TRUE);
        break;
    case 1:
        DrawGraph(x - (15 * 2), y, DrawNumberTexture_[0], TRUE);
        DrawGraph(x - (15 * 3), y, DrawNumberTexture_[0], TRUE);
        DrawGraph(x - (15 * 4), y, DrawNumberTexture_[0], TRUE);
        DrawGraph(x - (15 * 5), y, DrawNumberTexture_[0], TRUE);
        DrawGraph(x - (15 * 6), y, DrawNumberTexture_[0], TRUE);
        DrawGraph(x - (15 * 7), y, DrawNumberTexture_[0], TRUE);
        break;
    case 2:
        DrawGraph(x - (15 * 3), y, DrawNumberTexture_[0], TRUE);
        DrawGraph(x - (15 * 4), y, DrawNumberTexture_[0], TRUE);
        DrawGraph(x - (15 * 5), y, DrawNumberTexture_[0], TRUE);
        DrawGraph(x - (15 * 6), y, DrawNumberTexture_[0], TRUE);
        DrawGraph(x - (15 * 7), y, DrawNumberTexture_[0], TRUE);
        break;
    case 3:
        DrawGraph(x - (15 * 4), y, DrawNumberTexture_[0], TRUE);
        DrawGraph(x - (15 * 5), y, DrawNumberTexture_[0], TRUE);
        DrawGraph(x - (15 * 6), y, DrawNumberTexture_[0], TRUE);
        DrawGraph(x - (15 * 7), y, DrawNumberTexture_[0], TRUE);
        break;
    case 4:
        DrawGraph(x - (15 * 5), y, DrawNumberTexture_[0], TRUE);
        DrawGraph(x - (15 * 6), y, DrawNumberTexture_[0], TRUE);
        DrawGraph(x - (15 * 7), y, DrawNumberTexture_[0], TRUE);
        break;
    case 5:
        DrawGraph(x - (15 * 6), y, DrawNumberTexture_[0], TRUE);
        DrawGraph(x - (15 * 7), y, DrawNumberTexture_[0], TRUE);
        break;
    case 6:
        DrawGraph(x - (15 * 7), y, DrawNumberTexture_[0], TRUE);
        break;
    }

    xx = (NumberWidth * -(15 / 1000)) * 15;
    for (i = 0; i <= NumberWidth; i++)
    {
        DrawGraph(x + xx, y, DrawNumberTexture_[Num % 10], TRUE);
        xx -= 15;
        Num /= 10;
    }
}
void TetrisUI::Number::SetDrawNumber(int x, int y, int num, int size, signed short int resizecheck = 0x000)
{
    if (resizecheck == 0x001)
    {
        ReSizePositionX_[size] = x;
        ReSizePositionY_[size] = y;
        ResizeNumber_[size] = num;
        ResizeCheck_ = resizecheck;
    }
    else
    {
        PositionX_[size] = x;
        PositionY_[size] = y;
        Number_[size] = num;
    }
}
void TetrisUI::Number::DrawNumber(int x, int y, int num)
{
	switch (num)
	{
	case 0:
		DrawGraph(x, y, DrawNumberTexture_[0], true);
		break;
	case 1:
		DrawGraph(x, y, DrawNumberTexture_[1], true);
		break;
	case 2:
		DrawGraph(x, y, DrawNumberTexture_[2], true);
		break;
	case 3:
		DrawGraph(x, y, DrawNumberTexture_[3], true);
		break;
	case 4:
		DrawGraph(x, y, DrawNumberTexture_[4], true);
		break;
	case 5:
		DrawGraph(x, y, DrawNumberTexture_[5], true);
		break;
	case 6:
		DrawGraph(x, y, DrawNumberTexture_[6], true);
		break;
	case 7:
		DrawGraph(x, y, DrawNumberTexture_[7], true);
		break;
	case 8:
		DrawGraph(x, y, DrawNumberTexture_[8], true);
		break;
	case 9:
		DrawGraph(x, y, DrawNumberTexture_[9], true);
		break;
	default:
		DrawGraph(x, y, DrawNumberTexture_[0], true);
		break;
	}
}
