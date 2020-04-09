#include "Score.h"

unsigned int TetrisUI::Score::Score_ = 0;

void TetrisUI::Score::Init()
{
}

void TetrisUI::Score::Update()
{
}

void TetrisUI::Score::Draw()
{
	DrawFormatString(Position_.x, Position_.y, GetColor(Color_.r, Color_.g, Color_.b)," Score : %d", Score_);
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
