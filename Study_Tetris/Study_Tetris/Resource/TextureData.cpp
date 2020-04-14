#include "TextureData.h"
#include <DxLib.h>

TextureDataBase::TextureData::TextureData()
{
}

TextureDataBase::TextureData::~TextureData()
{
}

void TextureDataBase::TextureData::Init()
{
	LoadingCheck_ = false;
}

void TextureDataBase::TextureData::CreateTextureData(int& scenetype)
{
	switch (scenetype)
	{
	case 0:
		TitleTextureDataFile_.push_back("Resource/Background.png");
		break;
	case 1:
		GameTextureDataFile_.push_back("Resource/Background.png");
		GameTextureDataFile_.push_back("Resource/Game_Score.png");
		GameTextureDataFile_.push_back("Resource/Game_Timer.png");
		GameTextureDataFile_.push_back("Resource/GameClear.png");
		GameTextureDataFile_.push_back("Resource/GameOver.png");
		GameTextureDataFile_.push_back("Resource/Menu_GameEnd.png");
		GameTextureDataFile_.push_back("Resource/Menu_Restart.png");
		GameTextureDataFile_.push_back("Resource/Menu_Title.png");
		GameTextureDataFile_.push_back("Resource/Number.png");
		GameTextureDataFile_.push_back("Resource/Pause.png");
		break;
	case 2:
		ResultTextureDataFile_.push_back("Resource/Background.png");
		break;
	}
}

void TextureDataBase::TextureData::Release(int& scenetype)
{
	switch (scenetype)
	{
	case 0:
		for (auto itr = TitleTextureData_.begin(); itr != TitleTextureData_.end(); itr++)
		{
			DeleteGraph(*itr);
		}
		break;
	case 1:
		for (auto itr = GameTextureData_.begin(); itr != GameTextureData_.end(); itr++)
		{
			DeleteGraph(*itr);
		}
		break;
	case 2:
		for (auto itr = ResultTextureData_.begin(); itr != ResultTextureData_.end(); itr++)
		{
			DeleteGraph(*itr);
		}
		break;
	}
}

void TextureDataBase::TextureData::Loading(int& scenetype)
{
   
	switch (scenetype)
	{
	case 0:
		for (auto itr = TitleTextureDataFile_.begin(); itr != TitleTextureDataFile_.end(); itr++)
		{
			TitleTextureData_.push_back(LoadGraph(TitleTextureDataFile_[0].c_str()));
		}
		LoadingCheck_ = true;
		break;
	case 1:
		for (auto itr = GameTextureDataFile_.begin(); itr != GameTextureDataFile_.end(); itr++)
		{
			GameTextureData_.push_back(LoadGraph(itr->c_str()));
		}
		DrawString(250, 240 - 32, "Loading..", GetColor(255, 255, 255));
		
		LoadingCheck_ = true;
		break;
	case 2:
		for (auto itr = ResultTextureDataFile_.begin(); itr != ResultTextureDataFile_.end(); itr++)
		{
			ResultTextureData_.push_back(LoadGraph(itr->c_str()));
		}
		LoadingCheck_ = true;
		break;
	}
}

int TextureDataBase::TextureData::GetTitleTextureData(int titletexturenumber)
{
	return TitleTextureData_[titletexturenumber];
}

int TextureDataBase::TextureData::GetGameTextureData(int gametexturenumber)
{
	return GameTextureData_[gametexturenumber];
}

int TextureDataBase::TextureData::GetResultTextureData(int resulttexturenumber)
{
	return ResultTextureData_[resulttexturenumber];
}

bool TextureDataBase::TextureData::GetNowLoadingCheckFlag()
{
	return LoadingCheck_;
}
