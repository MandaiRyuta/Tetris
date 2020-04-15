#include "UIManager.h"

TetrisUI::UIManager::UIManager(int scenetype)
{
	switch (scenetype)
	{
	case 0:
		Obj_[0] = (Create<TetrisUI::Fade>());
		for (int i = 1; i < 7; i++)
		{
			Obj_[i] = nullptr;
		}
		break;
	case 1:
		Obj_[0] = (Create<TetrisUI::Score>());
		Obj_[1] = (Create<TetrisUI::Number>());
		Obj_[2] = (Create<TetrisUI::NextBlock>());
		Obj_[3] = (Create<TetrisUI::Hold>());
		Obj_[4] = (Create<TetrisUI::Time>());
		Obj_[5] = (Create<TetrisUI::InGameState>());
		Obj_[6] = (Create<TetrisUI::Fade>());
		break;
	case 2:
		Obj_[0] = (Create<TetrisUI::Score>());
		Obj_[1] = (Create<TetrisUI::Number>());
		Obj_[2] = (Create<TetrisUI::Fade>());
		for (int i = 3; i < 7; i++)
		{
			Obj_[i] = nullptr;
		}
		break;
	default:
		break;
	}
}

TetrisUI::UIManager::~UIManager()
{
	for (int i = 0; i < 7; i++)
	{
		if (Obj_[i] != nullptr)
		{
			delete Obj_[i];
		}
	}
}

void TetrisUI::UIManager::InitAll()
{
	for (int i = 0; i < 7; i++)
	{
		if(Obj_[i] != nullptr)
		Obj_[i]->Init();
	}
}

void TetrisUI::UIManager::UpdateAll()
{
	for (int i = 0; i < 7; i++)
	{
		if (Obj_[i] != nullptr)
		{
			Obj_[i]->Update();
		}
	}
}

void TetrisUI::UIManager::DrawAll()
{
	for (int i = 0; i < 7; i++)
	{
		if (Obj_[i] != nullptr)
		{
			Obj_[i]->Draw();
		}
	}
}

void TetrisUI::UIManager::ReleaseAll()
{
	for (int i = 0; i < 7; i++)
	{
		if (Obj_[i] != nullptr)
		{
			Obj_[i]->Release();
		}
	}
}
