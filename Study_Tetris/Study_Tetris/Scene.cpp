#include "Scene.h"
#include "SceneManager.h"
#include "Utils.h"

void Scene::Init()
{
	if(this->GetSceneNumber() == static_cast<int>(Utils::SCENETYPE::TITLE))
	{
	}
	if(this->GetSceneNumber() == static_cast<int>(Utils::SCENETYPE::GAME))
	{
	}
	if(this->GetSceneNumber() == static_cast<int>(Utils::SCENETYPE::RESULT))
	{
	}
}

void Scene::Update()
{
	if (this->GetSceneNumber() == static_cast<int>(Utils::SCENETYPE::TITLE))
	{
		title_start_end_ = 1;

		if (this->title_start_end_ == 1)
		{
			SceneManager::GetInstance().GetScene(Utils::SCENETYPE::GAME).Create(1);
		}
	}

	if (this->GetSceneNumber() == static_cast<int>(Utils::SCENETYPE::GAME))
	{
		this->GetSceneNumber();
	}

	if (this->GetSceneNumber() == static_cast<int>(Utils::SCENETYPE::RESULT))
	{
		this->GetSceneNumber();
	}
}

void Scene::Draw()
{
	if(this->GetSceneNumber() == static_cast<int>(Utils::SCENETYPE::TITLE))
	{
	}
	if(this->GetSceneNumber() == static_cast<int>(Utils::SCENETYPE::GAME))
	{
	}
	if(this->GetSceneNumber() == static_cast<int>(Utils::SCENETYPE::RESULT))
	{
	}
}

void Scene::Release()
{
}

void Scene::Create(int obj)
{
	obj_.push_back(obj);
}

void Scene::Delete()
{
}

void Scene::SetSceneNumber(int scenenum)
{
	scenenumber_ = scenenum;
}

int Scene::GetSceneNumber()
{
	return scenenumber_;
}
