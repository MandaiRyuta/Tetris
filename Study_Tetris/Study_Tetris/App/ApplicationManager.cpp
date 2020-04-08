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
	case SceneNumber::TitleSceneNumber:
		if ((*changescene) == true)
		{
			(*changescene) = false;
		}

		Scene_.Update();
		if (Scene_.GetSceneNumber() == SceneNumber::GameSceneNumber && (*changescene) == false)
		{
			Scene_.Release();
			Scene_ = SceneManager::GetInstance().GetScene(TetrisGameType::SCENETYPE::GAME);
			Scene_.Init();
			(*scenenum) = SceneNumber::GameSceneNumber;
			(*changescene) = true;
		}
		break;
	case SceneNumber::GameSceneNumber:
		if ((*changescene) == true)
		{
			(*changescene) = false;
		}

		Scene_.Update();

		if (Scene_.GetSceneNumber() == SceneNumber::ResultSceneNumber && (*changescene) == false)
		{
			Scene_.Release();
			Scene_ = SceneManager::GetInstance().GetScene(TetrisGameType::SCENETYPE::RESULT);
			Scene_.Init();
			(*scenenum) = SceneNumber::ResultSceneNumber;
			(*changescene) = true;
		}
		break;
	case SceneNumber::ResultSceneNumber:
		if ((*changescene) == true)
		{
			(*changescene) = false;
		}

		Scene_.Update();

		if (Scene_.GetSceneNumber() == SceneNumber::TitleSceneNumber && (*changescene) == false)
		{
			Scene_.Release();
			Scene_ = SceneManager::GetInstance().GetScene(TetrisGameType::SCENETYPE::TITLE);
			Scene_.Init();
			(*scenenum) = SceneNumber::TitleSceneNumber;
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
