#include "Score.h"
#include "Number.h"
#include "../Scene/SceneManager/SceneManager.h"
#include "Fade.h"
unsigned int TetrisUI::Score::Score_ = 0;

void TetrisUI::Score::Init()
{
	Score_ = 0;
	ScoreTexture_ = LoadGraph("Resource/TotalScore.png");
	DrawTime_ = 0;
	FontScoreTexture_ = LoadGraph("Resource/Game_Score.png");
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
		if (TetrisUI::Fade::GetFadeCheck() == 0x001)
		{
			if (DrawTime_ > 255)
			{
				DrawTime_ = 0;
			}
			else if (DrawTime_ < 120)
			{
				DrawGraph(400, 100, FontScoreTexture_, true);
			}
		}
	}
	if (SceneManager::GetNowScene() == TetrisGameType::SCENETYPE::RESULT)
	{
		if (TetrisUI::Fade::GetFadeCheck() == 0x001)
		{
			if (DrawTime_ > 255)
			{
				DrawTime_ = 0;
			}

			if (DrawTime_ > 120)
			{
				DrawGraph(220, 240 - 32, ScoreTexture_, true);
			}
		}
	}
}

void TetrisUI::Score::Release()
{

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
