#include "UIManager.h"

TetrisUI::UIManager::UIManager(int scenetype)
{
	SceneType_ = scenetype;
	switch (scenetype)
	{
	case 0:
		TitleObj_[0] = new TetrisUI::Fade;
		TitleObj_[1] = new TetrisUI::Background;

		break;
	case 1:
		GameObj_[0] = new TetrisUI::Background;
		GameObj_[1] = new TetrisUI::Score;
		GameObj_[2] = new TetrisUI::Number;
		GameObj_[3] = new TetrisUI::NextBlock;
		GameObj_[4] = new TetrisUI::Hold;
		GameObj_[5] = new TetrisUI::InGameState;
		GameObj_[6] = new TetrisUI::Fade;
		GameObj_[7] = new TetrisUI::Time;
		break;
	case 2:
		ResultObj_[0] = new TetrisUI::Background;
		ResultObj_[1] = new TetrisUI::Score;
		ResultObj_[2] = new TetrisUI::Number;
		ResultObj_[3] = new TetrisUI::Fade;
		break;
	default:
		break;
	}
}

TetrisUI::UIManager::~UIManager()
{
}

void TetrisUI::UIManager::InitAll()
{
	switch (SceneType_)
	{
	case 0:
		for (int i = 0; i < 2; i++)
		{
			if (TitleObj_[i] != nullptr)
			{
				TitleObj_[i]->Init();
			}
		}
		break;
	case 1:
		for (int i = 0; i < 8; i++)
		{
			if (GameObj_[i] != nullptr)
			{
				GameObj_[i]->Init();
			}
		}
		break;
	case 2:
		for (int i = 0; i < 4; i++)
		{
			if (ResultObj_[i] != nullptr)
			{
				ResultObj_[i]->Init();
			}
		}
		break;
	}
}

void TetrisUI::UIManager::UpdateAll()
{
	switch (SceneType_)
	{
	case 0:
		for (int i = 0; i < 2; i++)
		{
			if (TitleObj_[i] != nullptr)
			{
				TitleObj_[i]->Update();
			}
		}
		break;
	case 1:
		for (int i = 0; i < 8; i++)
		{
			if (GameObj_[i] != nullptr)
			{
				GameObj_[i]->Update();
			}
		}
		break;
	case 2:
		for (int i = 0; i < 4; i++)
		{
			if (ResultObj_[i] != nullptr)
			{
				ResultObj_[i]->Update();
			}
		}
		break;
	}
}

void TetrisUI::UIManager::DrawAll()
{
	switch (SceneType_)
	{
	case 0:
		for (int i = 0; i < 2; i++)
		{
			if (TitleObj_[i] != nullptr)
			{
				TitleObj_[i]->Draw();
			}
		}
		break;
	case 1:
		for (int i = 0; i < 8; i++)
		{
			if (GameObj_[i] != nullptr)
			{
				GameObj_[i]->Draw();
			}
		}
		break;
	case 2:
		for (int i = 0; i < 4; i++)
		{
			if (ResultObj_[i] != nullptr)
			{
				ResultObj_[i]->Draw();
			}
		}
		break;
	}
}

void TetrisUI::UIManager::ReleaseAll()
{
	switch (SceneType_)
	{
	case 0:
		for (int i = 0; i < 2; i++)
		{
			if (TitleObj_[i] != nullptr)
			{
				TitleObj_[i]->Release();
				delete TitleObj_[i];
			}
		}
		break;
	case 1:
		for (int i = 0; i < 8; i++)
		{
			if (GameObj_[i] != nullptr)
			{
				GameObj_[i]->Release();
				delete GameObj_[i];
			}
		}
		break;
	case 2:
		for (int i = 0; i < 4; i++)
		{
			if (ResultObj_[i] != nullptr)
			{
				ResultObj_[i]->Release();
				delete ResultObj_[i];
			}
		}
		break;
	}
}
