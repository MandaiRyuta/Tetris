#include "Score.h"
#include "Number.h"
#include "../Scene/SceneManager/SceneManager.h"
#include "Fade.h"
#include "../Scene/Scene.h"

unsigned int TetrisUI::Score::Score_ = 0;

void TetrisUI::Score::Init()
{
	Score_ = 0;

}

void TetrisUI::Score::Update()
{
	if (SceneManager::GetNowScene() == TetrisGameType::SCENETYPE::GAME)
	{
		Number::SetDrawNumber(Position_.x, Position_.y, Score_, 0, 0x001);
	}

	if (SceneManager::GetNowScene() == TetrisGameType::SCENETYPE::RESULT)
	{
		Number::SetDrawNumber(350, 240, SceneManager::GetTotalScore(), 0, 0x001);
	}

	DrawTime_ += 5;
}

void TetrisUI::Score::Draw()
{
	if (SceneManager::GetNowScene() == TetrisGameType::SCENETYPE::GAME)
	{
		DrawGraph(400, 100, FontScoreTexture_, true);
	}
	if (SceneManager::GetNowScene() == TetrisGameType::SCENETYPE::RESULT)
	{
		DrawGraph(220, 240 - 32, ScoreTexture_, true);

		if (DrawTime_ > 255)
		{
			DrawTime_ = 0;
		}

		if (DrawTime_ > 120)
		{
			DrawString(210, 300, "Enter ：タイトルへ戻る", GetColor(0,0,0));
		}
	}
}

void TetrisUI::Score::Release()
{
	DeleteGraph(ScoreTexture_);
	DeleteGraph(FontScoreTexture_);
}

void TetrisUI::Score::LoadTexture(int handle, int texturenumber)
{
	if (texturenumber == 0)
	{
		ScoreTexture_ = handle;
	}
	else if (texturenumber == 1)
	{
		FontScoreTexture_ = handle;
	}
}

void TetrisUI::Score::SetScore(int score)
{
	Score_ = score;
}

unsigned int TetrisUI::Score::GetScore()
{
	return Score_;
}

void TetrisUI::Score::AddScore(int addscore)
{
	Score_ += addscore;
}
