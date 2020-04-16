#include "ApplicationManager.h"

signed short int ApplicationManager::Loop_ = 0x000;

ApplicationManager::ApplicationManager()
{
	SceneManager_ = new SceneManager;
	Loop_ = 0x000;
}

ApplicationManager::~ApplicationManager()
{

}

void ApplicationManager::Init()
{
	SceneManager_->Init();
}

void ApplicationManager::Update(bool& loop)
{
	if (CheckHitKey(KEY_INPUT_ESCAPE) == 0x001)
	{
		Loop_ = 0x001;
	}

	loop = this->GetLoop();
	
	SceneManager_->Update();
}

void ApplicationManager::Draw()
{
	SceneManager_->Draw();
}

void ApplicationManager::Release()
{
	if (SceneManager_ != nullptr)
	{
		SceneManager_->Release();
		delete SceneManager_;
	}
}

const bool& ApplicationManager::GetLoop()
{
	if (Loop_ == 0x001)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void ApplicationManager::SetLoop(signed short int loopselect)
{
	Loop_ = loopselect;
}