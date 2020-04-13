#include "Scene.h"
#include "../App/ApplicationManager.h"
#include "SceneManager/SceneManager.h"
#include "../UI/Fade.h"

Scene::Scene(int type):
	Scenenumber_(type)
{
	Pause_ = 1;
	PauseKeyMaxTime_ = 60;
	PauseKeyNowTime_ = 0;
	DownArrowKeyNowTime_ = 0;
	UpArrowKeyNowTime_ = 0;
	DownArrowKeyMaxTime_ = 60;
	UpArrowKeyMaxTime_ = 60;
	MenuSelectNumber_ = 0;
	EnterKeyMaxTime_ = 60;
	EnterKeyNowTime_ = 0;
}

Scene::~Scene()
{
}

void Scene::Init()
{
	switch (Scenenumber_)
	{
	case SceneNumber::TitleSceneNumber:
		TitleDrawTime_ = 0;
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
		TitleDrawTime_ += 5;
		Ui_->UpdateAll();
		break;
	case SceneNumber::GameSceneNumber:
		if (CheckHitKey(KEY_INPUT_P) == 0x001)
		{
			if (PauseKeyNowTime_ > PauseKeyMaxTime_)
			{
				Pause_ *= -1;
				PauseKeyNowTime_ = 0;
			}
		}
		if (Pause_ == 1)
		{
			Ui_->UpdateAll();
			Collection_->Update();
		}
		else
		{
			if (CheckHitKey(KEY_INPUT_UP) == 0x001)
			{
				if (UpArrowKeyNowTime_ > UpArrowKeyMaxTime_)
				{
					if (MenuSelectNumber_ > 0)
					{
						MenuSelectNumber_--;
					}
					UpArrowKeyNowTime_ = 0;
				}
			}
			if (CheckHitKey(KEY_INPUT_DOWN) == 0x001)
			{
				if (DownArrowKeyNowTime_ > DownArrowKeyMaxTime_)
				{
					if (MenuSelectNumber_ < 3)
					{
						MenuSelectNumber_ ++;
					}
					DownArrowKeyNowTime_ = 0;
				}
			}
		}
		PauseSelect();
		UpArrowKeyNowTime_++;
		DownArrowKeyNowTime_++;
		PauseKeyNowTime_++;
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
		if (TetrisUI::Fade::GetFadeCheck() == 0x001)
		{
			if (TitleDrawTime_ > 255)
			{
				TitleDrawTime_ = 0;
			}
			else if (TitleDrawTime_ < 120)
			{
				DrawString(235, 300, "E n t e r 押してね", GetColor(0, 0, 0));
			}
			DrawString(250, 240 - 32, "て　と　り　す", GetColor(0, 0, 0));
		}
		break;
	case SceneNumber::GameSceneNumber:
		Ui_->DrawAll();
		if (TetrisUI::Fade::GetFadeCheck() == 0x001)
		{
			Collection_->Draw();
		}
		if (Pause_ == -1)
		{
			PauseDraw();
		}
		//DrawString(450, 32, "Game Scene", GetColor(255, 255, 255));
		break;
	case SceneNumber::ResultSceneNumber:
		Ui_->DrawAll();
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

void Scene::PauseDraw()
{
	switch (MenuSelectNumber_)
	{
	case 0:
		DrawBox(220, 150, 420, 340, GetColor(128, 128, 128), true);
		DrawString(290, 200 - 32, "ポーズ", GetColor(255, 255, 255));
		DrawString(260, 240 - 32, "やり直す", GetColor(255, 255, 0));
		DrawString(260, 280 - 32, "タイトルに戻る", GetColor(255, 255, 255));
		DrawString(260, 320 - 32, "ゲームをやめる", GetColor(255, 255, 255));
		break;
	case 1:
		DrawBox(220, 150, 420, 340, GetColor(128, 128, 128), true);
		DrawString(290, 200 - 32, "ポーズ", GetColor(255, 255, 255));
		DrawString(260, 240 - 32, "やり直す", GetColor(255, 255, 255));
		DrawString(260, 280 - 32, "タイトルに戻る", GetColor(255, 255, 0));
		DrawString(260, 320 - 32, "ゲームをやめる", GetColor(255, 255, 255));
		break;
	case 2:
		DrawBox(220, 150, 420, 340, GetColor(128, 128, 128), true);
		DrawString(290, 200 - 32, "ポーズ", GetColor(255, 255, 255));
		DrawString(260, 240 - 32, "やり直す", GetColor(255, 255, 255));
		DrawString(260, 280 - 32, "タイトルに戻る", GetColor(255, 255, 255));
		DrawString(260, 320 - 32, "ゲームをやめる", GetColor(255, 255, 0));
		break;
	}
}

void Scene::PauseSelect()
{
	switch (MenuSelectNumber_)
	{
	case 0:
		if (CheckHitKey(KEY_INPUT_RETURN) == 0x001)
		{
			if (EnterKeyNowTime_ > EnterKeyMaxTime_)
			{
				SceneManager::ChangeScene(TetrisGameType::SCENETYPE::GAME);
				EnterKeyNowTime_ = 0;
			}
		}
		break;
	case 1:
		if (CheckHitKey(KEY_INPUT_RETURN) == 0x001)
		{
			if (EnterKeyNowTime_ > EnterKeyMaxTime_)
			{
				SceneManager::ChangeScene(TetrisGameType::SCENETYPE::TITLE);
				EnterKeyNowTime_ = 0;
			}
		}
		break;
	case 2:
		if (CheckHitKey(KEY_INPUT_RETURN) == 0x001)
		{
			if (EnterKeyNowTime_ > EnterKeyMaxTime_)
			{
				ApplicationManager::SetLoop(0x001);
				EnterKeyNowTime_ = 0;
			}
		}
		break;
	}

	EnterKeyNowTime_++;
}
