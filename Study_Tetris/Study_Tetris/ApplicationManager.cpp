#include "ApplicationManager.h"

ApplicationManager::ApplicationManager()
{
	Scene_ = SceneManager::GetInstance().GetScene(TetrisGameType::SCENETYPE::TITLE);
}

ApplicationManager::~ApplicationManager()
{
}

void ApplicationManager::Init()
{
	Scene_.Init();
}

void ApplicationManager::Update(bool* loop, int* scenenum, bool* changescene)
{
	(*loop) = Scene_.GetLoop();
	switch (*scenenum)
	{
	case TetrisGameType::TITLESCENENUMBER:
		if ((*changescene) == true)
		{
			(*changescene) = false;
		}

		Scene_.Update();
		if (Scene_.GetSceneNumber() == TetrisGameType::GAMESCENENUMBER && (*changescene) == false)
		{
			Scene_.Release();
			Scene_ = SceneManager::GetInstance().GetScene(TetrisGameType::SCENETYPE::GAME);
			Scene_.Init();
			(*scenenum) = TetrisGameType::GAMESCENENUMBER;
			(*changescene) = true;
		}
		break;
	case TetrisGameType::GAMESCENENUMBER:
		if ((*changescene) == true)
		{
			(*changescene) = false;
		}

		Scene_.Update();

		if (Scene_.GetSceneNumber() == TetrisGameType::RESULTSCENENUMBER && (*changescene) == false)
		{
			Scene_.Release();
			Scene_ = SceneManager::GetInstance().GetScene(TetrisGameType::SCENETYPE::RESULT);
			Scene_.Init();
			(*scenenum) = TetrisGameType::RESULTSCENENUMBER;
			(*changescene) = true;
		}
		break;
	case TetrisGameType::RESULTSCENENUMBER:
		if ((*changescene) == true)
		{
			(*changescene) = false;
		}

		Scene_.Update();

		if (Scene_.GetSceneNumber() == TetrisGameType::TITLESCENENUMBER && (*changescene) == false)
		{
			Scene_.Release();
			Scene_ = SceneManager::GetInstance().GetScene(TetrisGameType::SCENETYPE::TITLE);
			Scene_.Init();
			(*scenenum) = TetrisGameType::TITLESCENENUMBER;
			(*changescene) = true;
		}
		break;
	}

}

void ApplicationManager::Draw()
{
	Scene_.Draw();
}

void ApplicationManager::Release()
{
	Scene_.Release();
}
