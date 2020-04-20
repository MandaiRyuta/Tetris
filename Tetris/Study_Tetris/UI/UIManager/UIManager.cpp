#include "UIManager.h"

TextureDataBase::TextureData TetrisUI::UIManager::texture_ = {};

TetrisUI::UIManager::UIManager()
{

}

TetrisUI::UIManager::~UIManager()
{
}

void TetrisUI::UIManager::Init()
{
	texture_.Init();
	texture_.Loading(SceneType_);
    
	switch (SceneType_)
	{
	case 0:
		TitleObj_[0] = Create<TetrisUI::Fade>();
		TitleObj_[1] = Create<TetrisUI::Background>();

		TitleObj_[1]->LoadTexture(texture_.GetTitleTextureData(0));
		break;
	case 1:
		GameObj_[0] = Create<TetrisUI::Background>();
		GameObj_[0]->LoadTexture(texture_.GetGameTextureData(4));
		GameObj_[1] = Create<TetrisUI::Score>();
		GameObj_[1]->LoadTexture(texture_.GetGameTextureData(1));
		GameObj_[1]->LoadTexture(texture_.GetGameTextureData(0),1);
		GameObj_[2] = Create<TetrisUI::Number>();
		GameObj_[2]->LoadTexture(texture_.GetNumberTexture(0), 0);
		GameObj_[2]->LoadTexture(texture_.GetNumberTexture(1), 1);
		GameObj_[2]->LoadTexture(texture_.GetNumberTexture(2), 2);
		GameObj_[2]->LoadTexture(texture_.GetNumberTexture(3), 3);
		GameObj_[2]->LoadTexture(texture_.GetNumberTexture(4), 4);
		GameObj_[2]->LoadTexture(texture_.GetNumberTexture(5), 5);
		GameObj_[2]->LoadTexture(texture_.GetNumberTexture(6), 6);
		GameObj_[2]->LoadTexture(texture_.GetNumberTexture(7), 7);
		GameObj_[2]->LoadTexture(texture_.GetNumberTexture(8), 8);
		GameObj_[2]->LoadTexture(texture_.GetNumberTexture(9), 9);
		GameObj_[2]->LoadTexture(texture_.GetNumberTexture(10),10);
		GameObj_[3] = Create<TetrisUI::NextBlock>();
		GameObj_[4] = Create<TetrisUI::Hold>();
		GameObj_[5] = Create<TetrisUI::InGameState>();
		GameObj_[5]->LoadTexture(texture_.GetGameTextureData(2), 0);
		GameObj_[5]->LoadTexture(texture_.GetGameTextureData(3), 1);
		GameObj_[6] = Create<TetrisUI::Fade>();
		GameObj_[7] = Create<TetrisUI::Time>();
		GameObj_[7]->LoadTexture(texture_.GetGameTextureData(1));
		break;
	case 2:
		ResultObj_[0] = Create<TetrisUI::Background>();
		ResultObj_[0]->LoadTexture(texture_.GetResultTextureData(1));
		ResultObj_[1] = Create<TetrisUI::Score>();
		ResultObj_[1]->LoadTexture(texture_.GetResultTextureData(0));
		ResultObj_[2] = Create<TetrisUI::Number>();
		ResultObj_[2]->LoadTexture(texture_.GetNumberTexture(0), 0);
		ResultObj_[2]->LoadTexture(texture_.GetNumberTexture(1), 1);
		ResultObj_[2]->LoadTexture(texture_.GetNumberTexture(2), 2);
		ResultObj_[2]->LoadTexture(texture_.GetNumberTexture(3), 3);
		ResultObj_[2]->LoadTexture(texture_.GetNumberTexture(4), 4);
		ResultObj_[2]->LoadTexture(texture_.GetNumberTexture(5), 5);
		ResultObj_[2]->LoadTexture(texture_.GetNumberTexture(6), 6);
		ResultObj_[2]->LoadTexture(texture_.GetNumberTexture(7), 7);
		ResultObj_[2]->LoadTexture(texture_.GetNumberTexture(8), 8);
		ResultObj_[2]->LoadTexture(texture_.GetNumberTexture(9), 9);
		ResultObj_[2]->LoadTexture(texture_.GetNumberTexture(10), 10);
		ResultObj_[3] = Create<TetrisUI::Fade>();
		break;
	default:
		break;
	}

	InitAll();
}

void TetrisUI::UIManager::Update()
{
	UpdateAll();
}

void TetrisUI::UIManager::Draw()
{
	DrawAll();
}

void TetrisUI::UIManager::Release()
{
	texture_.Release();

	ReleaseAll();
}

const int& TetrisUI::UIManager::GetTextureHandle(int type, int number)
{
	switch (type)
	{
	case 0:
		return texture_.GetTitleTextureData(number);
		break;
	case 1:
		return texture_.GetGameTextureData(number);
		break;
	case 2:
		return texture_.GetResultTextureData(number);
		break;
	default:
		return texture_.GetTitleTextureData(0);
		break;
	}
}

void TetrisUI::UIManager::SetType(int type)
{
	SceneType_ = type;
}

void TetrisUI::UIManager::InitAll()
{

	switch (SceneType_)
	{
	case 0:
		for (int i = 0; i < 2; i++)
		{
			if (TitleObj_[i] != nullptr)
			{
				TitleObj_[i]->Init();
			}
		}
		break;
	case 1:
		for (int i = 0; i < 8; i++)
		{
			if (GameObj_[i] != nullptr)
			{
				GameObj_[i]->Init();
			}
		}
		break;
	case 2:
		for (int i = 0; i < 4; i++)
		{
			if (ResultObj_[i] != nullptr)
			{
				ResultObj_[i]->Init();
			}
		}
		break;
	}
}

void TetrisUI::UIManager::UpdateAll()
{
	switch (SceneType_)
	{
	case 0:
		for (int i = 0; i < 2; i++)
		{
			if (TitleObj_[i] != nullptr)
			{
				TitleObj_[i]->Update();
			}
		}
		break;
	case 1:
		for (int i = 0; i < 8; i++)
		{
			if (GameObj_[i] != nullptr)
			{
				GameObj_[i]->Update();
			}
		}
		break;
	case 2:
		for (int i = 0; i < 4; i++)
		{
			if (ResultObj_[i] != nullptr)
			{
				ResultObj_[i]->Update();
			}
		}
		break;
	}
}

void TetrisUI::UIManager::DrawAll()
{
	switch (SceneType_)
	{
	case 0:
		for (int i = 0; i < 2; i++)
		{
			if (TitleObj_[i] != nullptr)
			{
				TitleObj_[i]->Draw();
			}
		}
		break;
	case 1:
		for (int i = 0; i < 8; i++)
		{
			if (GameObj_[i] != nullptr)
			{
				GameObj_[i]->Draw();
			}
		}
		break;
	case 2:
		for (int i = 0; i < 4; i++)
		{
			if (ResultObj_[i] != nullptr)
			{
				ResultObj_[i]->Draw();
			}
		}
		break;
	}
}

void TetrisUI::UIManager::ReleaseAll()
{
	switch (SceneType_)
	{
	case 0:
		for (int i = 0; i < 2; i++)
		{
			if (TitleObj_[i] != nullptr)
			{
				TitleObj_[i]->Release();
				delete TitleObj_[i];
			}
		}
		break;
	case 1:
		for (int i = 0; i < 8; i++)
		{
			if (GameObj_[i] != nullptr)
			{
				GameObj_[i]->Release();
				delete GameObj_[i];
			}
		}
		break;
	case 2:
		for (int i = 0; i < 4; i++)
		{
			if (ResultObj_[i] != nullptr)
			{
				ResultObj_[i]->Release();
				delete ResultObj_[i];
			}
		}
		break;
	}
}
