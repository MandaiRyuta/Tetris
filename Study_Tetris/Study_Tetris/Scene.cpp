#include "Scene.h"
#include "Input.h"



Scene::Scene() :
	Scenenumber_(0),
	Title_start_end_(0x000),
	Game_start_end_(0x000),
	Result_start_end_(0x000)
{

}

Scene::~Scene()
{
}

void Scene::Init()
{
	Loop_ = 0x000;

	Collection_ = new TetrisBlocks::BlockCollection();
	Collection_->Init();

	switch (Scenenumber_)
	{
	case TetrisGameType::TITLESCENENUMBER:
		Title_start_end_ = 0x000;
		Scenenumber_ = TetrisGameType::TITLESCENENUMBER;
		break;
	case TetrisGameType::GAMESCENENUMBER:
		Game_start_end_ = 0x000;
		Scenenumber_ = TetrisGameType::GAMESCENENUMBER;
		break;
	case TetrisGameType::RESULTSCENENUMBER:
		Result_start_end_ = 0x000;
		Scenenumber_ = TetrisGameType::RESULTSCENENUMBER;
		break;
	}
}

void Scene::Update()
{
	if (CheckHitKey(KEY_INPUT_ESCAPE) == 0x001)
	{
		Loop_ = 0x001;
	}

	switch (Scenenumber_)
	{
	case TetrisGameType::TITLESCENENUMBER:
		if (CheckHitKey(KEY_INPUT_UP) == 0x001)
		{
			Title_start_end_ = 0x001;
		}
		if (CheckHitKey(KEY_INPUT_DOWN) == 0x001)
		{
			Title_start_end_ = 0x000;
		}

		if (this->Title_start_end_ == 0x001 && CheckHitKey(KEY_INPUT_RETURN))
		{
			this->SetSceneNumber(1);
		}
		break;
	case TetrisGameType::GAMESCENENUMBER:
		Collection_->Update();

		if (CheckHitKey(KEY_INPUT_UP) == 0x001)
		{
			Game_start_end_ = 0x001;
		}
		if (CheckHitKey(KEY_INPUT_DOWN) == 0x001)
		{
			Game_start_end_ = 0x000;
		}

		if (this->Game_start_end_ == 0x001 && CheckHitKey(KEY_INPUT_RETURN))
		{
			this->SetSceneNumber(2);
		}
		break;
	case TetrisGameType::RESULTSCENENUMBER:
		if (CheckHitKey(KEY_INPUT_UP) == 0x001)
		{
			Result_start_end_ = 0x001;
		}
		if (CheckHitKey(KEY_INPUT_DOWN) == 0x001)
		{
			Result_start_end_ = 0x000;
		}

		if (this->Result_start_end_ == 0x001 && CheckHitKey(KEY_INPUT_RETURN))
		{
			this->SetSceneNumber(0);
		}
		break;
	}
}

void Scene::Draw()
{
	switch (Scenenumber_)
	{
	case TetrisGameType::TITLESCENENUMBER:
		DrawString(250, 240 - 32, "Title Scene", GetColor(255, 255, 255));
		break;
	case TetrisGameType::GAMESCENENUMBER:
		Collection_->Draw();
		DrawString(450, 32, "Game Scene", GetColor(255, 255, 255));
		break;
	case TetrisGameType::RESULTSCENENUMBER:
		DrawString(250, 240 - 32, "Result Scene", GetColor(255, 255, 255));
		break;
	}
}

void Scene::Release()
{
	delete Collection_;
}

void Scene::Create(int obj)
{
	Obj_.push_back(obj);
}

void Scene::Delete()
{
}

void Scene::SetSceneNumber(int scenenum)
{
	Scenenumber_ = scenenum;
}

int Scene::GetSceneNumber()
{
	return Scenenumber_;
}

bool Scene::GetLoop()
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

void Scene::SetLoop(signed short int loop)
{
	loop;
}
