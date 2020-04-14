#include "UIManager.h"

TetrisUI::UIManager::UIManager(int scenetype)
{
	switch (scenetype)
	{
	case 0:
		Obj_.push_back(Create<TetrisUI::Fade>());
		break;
	case 1:		
		//Obj_.push_back(Create<TetrisUI::Fade>());
		//Obj_.push_back(Create<TetrisUI::Menu>());
		Obj_.push_back(Create<TetrisUI::Score>());
		Obj_.push_back(Create<TetrisUI::Number>());
		Obj_.push_back(Create<TetrisUI::NextBlock>());
		Obj_.push_back(Create<TetrisUI::Hold>());
		Obj_.push_back(Create<TetrisUI::Time>());
		//Obj_.push_back(Create<TetrisUI::Particle>());

		Obj_.push_back(Create<TetrisUI::InGameState>());
		//Obj_.push_back(Create<TetrisUI::Time>());
		//Obj_.push_back(Create<TetrisUI::UI>());
		Obj_.push_back(Create<TetrisUI::Fade>());
		break;
	case 2:
		Obj_.push_back(Create<TetrisUI::Score>());
		Obj_.push_back(Create<TetrisUI::Number>());
		Obj_.push_back(Create<TetrisUI::Fade>());
		break;
	default:
		break;
	}
}

TetrisUI::UIManager::~UIManager()
{
	for (auto itr = Obj_.begin(); itr != Obj_.end(); itr++)
	{
		delete *itr;
	}
}

void TetrisUI::UIManager::InitAll()
{
	for (auto itr = Obj_.begin(); itr != Obj_.end(); ++itr)
	{
		(*itr)->Init();
	}
}

void TetrisUI::UIManager::UpdateAll()
{
	for (auto itr = Obj_.begin(); itr != Obj_.end(); ++itr)
	{
		(*itr)->Update();
	}
}

void TetrisUI::UIManager::DrawAll()
{
	for (auto itr = Obj_.begin(); itr != Obj_.end(); ++itr)
	{
		(*itr)->Draw();
	}
}

void TetrisUI::UIManager::ReleaseAll()
{
	for (auto itr = Obj_.begin(); itr != Obj_.end(); itr++)
	{
		(*itr)->Release();
	}
}
