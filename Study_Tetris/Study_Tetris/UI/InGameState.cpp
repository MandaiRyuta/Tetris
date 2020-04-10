#include "InGameState.h"
#include "../Scene/SceneManager/SceneManager.h"
int TetrisUI::InGameState::GameState_ = 0;

void TetrisUI::InGameState::Init()
{
	GameClearTexture_ = LoadGraph("GameClear.png");
	GameOverTexture_ = LoadGraph("GameOver.png");
	GameState_ = 0;
}

void TetrisUI::InGameState::Update()
{
	if (GameState_ != 0)
	{
		NextSceneCount_++;

		if (NextSceneCount_ > 30)
		{
			SceneManager::ChangeScene(TetrisGameType::SCENETYPE::RESULT);
		}
	}
}

void TetrisUI::InGameState::Draw()
{
	switch (GameState_)
	{
	case 0:
		break;
	case GameState::GameClear:
		DrawGraph(213, 240, GameClearTexture_, true);
		break;
	case GameState::GameOver:
		DrawGraph(213, 240, GameOverTexture_, true);
		break;
	}
}

void TetrisUI::InGameState::Release()
{
}

int TetrisUI::InGameState::GetGameState()
{
	return GameState_;
}

void TetrisUI::InGameState::SetGameState(int state)
{
	GameState_ = state;
}
