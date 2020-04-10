#include "Scene.h"
#include "SceneManager/SceneManager.h"
#include "../UI/Fade.h"

Scene::Scene(int type):
	Scenenumber_(type)
{
}

Scene::~Scene()
{
}

void Scene::Init()
{
	switch (Scenenumber_)
	{
	case SceneNumber::TitleSceneNumber:
		Ui_ = new TetrisUI::UIManager(0);
		Ui_->InitAll();
		TetrisUI::Fade::SetStartFade(1);
		Scenenumber_ = SceneNumber::TitleSceneNumber;
		break;
	case SceneNumber::GameSceneNumber:
		Ui_ = new TetrisUI::UIManager(1);
		Ui_->InitAll();
		TetrisUI::Fade::SetStartFade(1);
		Collection_ = new TetrisBlocks::BlockCollection();
		Collection_->Init();
		Scenenumber_ = SceneNumber::GameSceneNumber;
		break;
	case SceneNumber::ResultSceneNumber:
		Ui_ = new TetrisUI::UIManager(2);
		Ui_->InitAll();
		TetrisUI::Fade::SetStartFade(1);
		Scenenumber_ = SceneNumber::ResultSceneNumber;
		break;
	}
}

void Scene::Update()
{
	switch (Scenenumber_)
	{
	case SceneNumber::TitleSceneNumber:

		Ui_->UpdateAll();
		break;
	case SceneNumber::GameSceneNumber:
		Ui_->UpdateAll();
		Collection_->Update();
		break;
	case SceneNumber::ResultSceneNumber:
		Ui_->UpdateAll();
		break;
	}
}

void Scene::Draw()
{
	switch (Scenenumber_)
	{
	case SceneNumber::TitleSceneNumber:
		Ui_->DrawAll();
		DrawString(250, 240 - 32, "Title Scene", GetColor(255, 255, 255));
		break;
	case SceneNumber::GameSceneNumber:
		Ui_->DrawAll();
		if (TetrisUI::Fade::GetFadeCheck() == 0x001)
		{
			Collection_->Draw();
		}
		DrawString(450, 32, "Game Scene", GetColor(255, 255, 255));
		break;
	case SceneNumber::ResultSceneNumber:
		Ui_->DrawAll();
		DrawString(250, 240 - 32, "Result Scene", GetColor(255, 255, 255));
		break;
	}
}

void Scene::Release()
{
	if (Ui_ != nullptr)
	{
		Ui_->ReleaseAll();
		delete Ui_;
	}
	if (Collection_ != nullptr)
	{
		Collection_->Release();
		delete Collection_;
	}
}
