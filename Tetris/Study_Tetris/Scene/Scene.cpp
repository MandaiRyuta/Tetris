#include "Scene.h"
#include "../App/ApplicationManager.h"
#include "SceneManager/SceneManager.h"
#include "../UI/Fade.h"

Scene::Scene(int type) :
	Scenenumber_(type)
{
	Pause_ = 0x001;
	PauseKeyMaxTime_ = 60;
	PauseKeyNowTime_ = 0;
	DownArrowKeyNowTime_ = 0;
	UpArrowKeyNowTime_ = 0;
	DownArrowKeyMaxTime_ = 60;
	UpArrowKeyMaxTime_ = 60;
	MenuSelectNumber_ = 0;
	EnterKeyMaxTime_ = 120;
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

		for (const auto Obj : Actor_)
		{
			Obj->Init();
		}

		TitleDrawTime_ = 0;

		TetrisUI::Fade::SetStartFade(1);
		Scenenumber_ = SceneNumber::TitleSceneNumber;

		break;
	case SceneNumber::GameSceneNumber:

		for (const auto Obj : Actor_)
		{
			Obj->Init();
		}

		TetrisUI::Fade::SetStartFade(1);
		Scenenumber_ = SceneNumber::GameSceneNumber;
		break;
	case SceneNumber::ResultSceneNumber:
		
		for (const auto Obj : Actor_)
		{
			Obj->Init();
		}

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
		for (const auto Obj : Actor_)
		{
			Obj->Update();
		}
		TitleDrawTime_ += 5;
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
			if (TetrisUI::Fade::GetFadeCheck() == 0x001)
			{
				for (const auto Obj : Actor_)
				{
					Obj->Update();
				}
			}
			else
			{
				Actor_.front()->Update();
			}
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
						MenuSelectNumber_++;
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
		for (const auto Obj : Actor_)
		{
			Obj->Update();
		}
		break;
	}
}

void Scene::Draw()
{
	switch (Scenenumber_)
	{
	case SceneNumber::TitleSceneNumber:
		for (const auto Obj : Actor_)
		{
			Obj->Draw();
		}
		if (TitleDrawTime_ > 255)
		{
			TitleDrawTime_ = 0;
		}
		else if (TitleDrawTime_ < 120)
		{
			DrawString(235, 300, "E n t e r 押してね", GetColor(0, 0, 0));
		}
		DrawString(250, 240 - 32, "て　と　り　す", GetColor(0, 0, 0));
		break;
	case SceneNumber::GameSceneNumber:
		for (const auto Obj : Actor_)
		{
			Obj->Draw();
		}
		DrawString(410, 225, "[H] : ゲームプレイ中（ホールド）", GetColor(0, 0, 0));
		DrawString(410, 250, "[↑] : ゲームプレイ中（回転）", GetColor(0, 0, 0));
		DrawString(410, 275, "[←] : ゲームプレイ中（左移動）", GetColor(0, 0, 0));
		DrawString(410, 300, "[→] : ゲームプレイ中（右移動）", GetColor(0, 0, 0));
		DrawString(410, 325, "[↓] : ゲームプレイ中（下移動）", GetColor(0, 0, 0));
		DrawString(410, 350, "[SPACE] : 落下", GetColor(0, 0, 0));
		DrawString(410, 375, "[P] : ポーズ画面", GetColor(0, 0, 0));
		DrawString(410, 400, "[↑] : ポーズ時（上移動）", GetColor(0, 0, 0));
		DrawString(410, 425, "[↓] : ポーズ時（下移動）", GetColor(0, 0, 0));
		DrawString(410, 450, "[Enter] : ポーズ時（決定）", GetColor(0, 0, 0));

		if (Pause_ == -1)
		{
			PauseDraw();
		}
		break;
	case SceneNumber::ResultSceneNumber:
		for (const auto Obj : Actor_)
		{
			Obj->Draw();
		}
		break;
	}
}

void Scene::Release()
{
	for (auto obj : Actor_)
	{
		obj->Release();
	}
	ObjectReleaseMemory();
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
		if (Pause_ == -1 && CheckHitKey(KEY_INPUT_RETURN) == 0x001)
		{
			if (EnterKeyNowTime_ > EnterKeyMaxTime_)
			{
				Scenenumber_ = 1;
				SceneManager::ChangeScene(TetrisGameType::SCENETYPE::GAME);
				EnterKeyNowTime_ = 0;
			}
		}
		break;
	case 1:
		if (Pause_ == -1 && CheckHitKey(KEY_INPUT_RETURN) == 0x001)
		{
			if (EnterKeyNowTime_ > EnterKeyMaxTime_)
			{
				EnterKeyNowTime_ = 0;
				Scenenumber_ = 0;
				SceneManager::ChangeScene(TetrisGameType::SCENETYPE::TITLE);
			}
		}
		break;
	case 2:
		if (Pause_ == -1 && CheckHitKey(KEY_INPUT_RETURN) == 0x001)
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
