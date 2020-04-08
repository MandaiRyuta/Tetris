#include "Scene.h"

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

	switch (Scenenumber_)
	{
	case SceneNumber::TitleSceneNumber:
		Title_start_end_ = 0x000;
		Scenenumber_ = SceneNumber::TitleSceneNumber;
		break;
	case SceneNumber::GameSceneNumber:
		Ui_ = new TetrisUI::UIManager();
		Collection_ = new TetrisBlocks::BlockCollection();
		Collection_->Init();
		Game_start_end_ = 0x000;
		Scenenumber_ = SceneNumber::GameSceneNumber;
		break;
	case SceneNumber::ResultSceneNumber:
		Result_start_end_ = 0x000;
		Scenenumber_ = SceneNumber::ResultSceneNumber;
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
	case SceneNumber::TitleSceneNumber:
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
	case SceneNumber::GameSceneNumber:
		Collection_->Update();
		Ui_->UpdateAll();
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
	case SceneNumber::ResultSceneNumber:
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
	case SceneNumber::TitleSceneNumber:
		DrawString(250, 240 - 32, "Title Scene", GetColor(255, 255, 255));
		break;
	case SceneNumber::GameSceneNumber:
		Collection_->Draw();
		Ui_->DrawAll();
		DrawString(450, 32, "Game Scene", GetColor(255, 255, 255));
		break;
	case SceneNumber::ResultSceneNumber:
		DrawString(250, 240 - 32, "Result Scene", GetColor(255, 255, 255));
		break;
	}
}

void Scene::Release()
{
	Ui_->ReleaseAll();
	delete Ui_;
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
