#include "Score.h"
#include "Number.h"
#include "../Scene/SceneManager/SceneManager.h"
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
		Number::SetDrawNumber(320, 240, SceneManager::GetTotalScore(), 0, 0x001);
	}
}

void TetrisUI::Score::Draw()
{
	//DrawFormatString(Position_.x, Position_.y, GetColor(Color_.r, Color_.g, Color_.b)," Score : %d", Score_);
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
