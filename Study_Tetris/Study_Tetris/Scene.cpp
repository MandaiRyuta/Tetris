#include "Scene.h"
#include "SceneManager.h"
#include "Utils.h"
#include "Input.h"


Scene::Scene() :
	scenenumber_(0),
	title_start_end_(0x000),
	game_start_end_(0x000),
	result_start_end(0x000)
{
	input_ = new Input(0);
}

Scene::~Scene()
{
}

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
	input_->Update();

	if (this->GetSceneNumber() == static_cast<int>(Utils::SCENETYPE::TITLE))
	{
		if (input_->GetKeyDown(KEY_INPUT_UP) == 0x001)
		{
			title_start_end_ = 0x001;
		}
		if (input_->GetKeyDown(KEY_INPUT_DOWN) == 0x001)
		{
			title_start_end_ = 0x000;
		}

		if (this->title_start_end_ == 0x001 && input_->GetKeyDown(KEY_INPUT_RETURN))
		{
			this->SetSceneNumber(static_cast<int>(Utils::SCENETYPE::GAME));
		}
	}

	if (this->GetSceneNumber() == static_cast<int>(Utils::SCENETYPE::GAME))
	{
		if (input_->GetKeyDown(KEY_INPUT_UP) == 0x001)
		{
			game_start_end_ = 0x001;
		}
		if (input_->GetKeyDown(KEY_INPUT_DOWN) == 0x001)
		{
			game_start_end_ = 0x000;
		}

		if (this->game_start_end_ == 0x001 && input_->GetKeyDown(KEY_INPUT_RETURN))
		{
			this->SetSceneNumber(static_cast<int>(Utils::SCENETYPE::RESULT));
		}
	}

	if (this->GetSceneNumber() == static_cast<int>(Utils::SCENETYPE::RESULT))
	{
		if (input_->GetKeyDown(KEY_INPUT_UP) == 0x001)
		{
			result_start_end = 0x001;
		}
		if (input_->GetKeyDown(KEY_INPUT_DOWN) == 0x001)
		{
			result_start_end = 0x000;
		}

		if (this->result_start_end == 0x001 && input_->GetKeyDown(KEY_INPUT_RETURN))
		{
			this->SetSceneNumber(static_cast<int>(Utils::SCENETYPE::TITLE));
		}
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
