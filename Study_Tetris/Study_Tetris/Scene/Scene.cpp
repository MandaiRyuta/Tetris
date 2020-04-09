#include "Scene.h"
#include "SceneManager/SceneManager.h"
Scene::Scene(int type):
	Scenenumber_(type)
{
	switch (Scenenumber_)
	{
	case SceneNumber::TitleSceneNumber:
		Scenenumber_ = SceneNumber::TitleSceneNumber;
		break;
	case SceneNumber::GameSceneNumber:
		Ui_ = new TetrisUI::UIManager();
		Collection_ = new TetrisBlocks::BlockCollection();
		Collection_->Init();
		Scenenumber_ = SceneNumber::GameSceneNumber;
		break;
	case SceneNumber::ResultSceneNumber:
		Scenenumber_ = SceneNumber::ResultSceneNumber;
		break;
	}
}

Scene::~Scene()
{
}

void Scene::Init()
{
}

void Scene::Update()
{
	switch (Scenenumber_)
	{
	case SceneNumber::TitleSceneNumber:

		break;
	case SceneNumber::GameSceneNumber:
		Collection_->Update();
		Ui_->UpdateAll();

		break;
	case SceneNumber::ResultSceneNumber:

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