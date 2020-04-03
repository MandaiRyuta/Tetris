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
	loop_ = 0x000;
	if(this->GetSceneNumber() == static_cast<int>(Utils::SCENETYPE::TITLE))
	{
		title_start_end_ = 0x000;
		scenenumber_ = static_cast<int>(Utils::SCENETYPE::TITLE);
	}
	if(this->GetSceneNumber() == static_cast<int>(Utils::SCENETYPE::GAME))
	{
		game_start_end_ = 0x000;
		scenenumber_ = static_cast<int>(Utils::SCENETYPE::GAME);
	}
	if(this->GetSceneNumber() == static_cast<int>(Utils::SCENETYPE::RESULT))
	{
		result_start_end = 0x000;
		scenenumber_ = static_cast<int>(Utils::SCENETYPE::RESULT);
	}
}

void Scene::Update()
{
	input_->Update();

	if (input_->GetKeyDown(KEY_INPUT_ESCAPE) == 0x001)
	{
		loop_ = 0x001;
	}

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
		DrawString(250, 240 - 32, "Game Scene", GetColor(0, 0, 0));
		DrawString(250, 240 - 32, "Result Scene", GetColor(0, 0, 0));
		DrawString(250, 240 - 32, "Title Scene", GetColor(255, 255, 255));
	}
	if(this->GetSceneNumber() == static_cast<int>(Utils::SCENETYPE::GAME))
	{
		DrawString(250, 240 - 32, "Title Scene", GetColor(0, 0, 0));
		DrawString(250, 240 - 32, "Result Scene", GetColor(0, 0, 0));
		DrawString(250, 240 - 32, "Game Scene", GetColor(255, 255, 255));
	}
	if(this->GetSceneNumber() == static_cast<int>(Utils::SCENETYPE::RESULT))
	{
		DrawString(250, 240 - 32, "Title Scene", GetColor(0, 0, 0));
		DrawString(250, 240 - 32, "Game Scene", GetColor(0, 0, 0));
		DrawString(250, 240 - 32, "Result Scene", GetColor(255, 255, 255));
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

bool Scene::GetLoop()
{
	if (loop_ == 0x001)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Scene::SetLoop(signed short int loop)
{
	loop;
}
