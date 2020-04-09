#include "UIManager.h"

TetrisUI::UIManager::UIManager()
{
	//obj_.push_back(Create<TetrisUI::Background>());
	//obj_.push_back(Create<TetrisUI::Fade>());
	//obj_.push_back(Create<TetrisUI::InGameState>());
	//obj_.push_back(Create<TetrisUI::Menu>());
	obj_.push_back(Create<TetrisUI::NextBlock>());
	obj_.push_back(Create<TetrisUI::Hold>());
	obj_.push_back(Create<TetrisUI::Time>());
	//obj_.push_back(Create<TetrisUI::Particle>());
	obj_.push_back(Create<TetrisUI::Score>());
	//obj_.push_back(Create<TetrisUI::Time>());
	//obj_.push_back(Create<TetrisUI::UI>());

	for (auto itr = obj_.begin(); itr != obj_.end(); ++itr)
	{
		(*itr)->Init();
	}
}

TetrisUI::UIManager::~UIManager()
{
}

void TetrisUI::UIManager::UpdateAll()
{
	for (auto itr = obj_.begin(); itr != obj_.end(); ++itr)
	{
		(*itr)->Update();
	}
}

void TetrisUI::UIManager::DrawAll()
{
	for (auto itr = obj_.begin(); itr != obj_.end(); ++itr)
	{
		(*itr)->Draw();
	}
}

void TetrisUI::UIManager::ReleaseAll()
{
	//for (auto itr = obj_.begin(); itr != obj_.end(); ++itr)
	//{
	//	(*itr)->Release();
	//}
}
