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
	BackgroundTextureData_ = 0;
	BackgroundTextureFile_ = ("Resource/Background.png");

	BackgroundTextureData_ = LoadGraph(BackgroundTextureFile_.c_str());
	
	LoadingCheck_ = false;
}

void TextureDataBase::TextureData::CreateTextureData(int& scenetype)
{
	switch (scenetype)
	{
	case 0:
		break;
	case 1:
		GameTextureDataFile_[0] = ("Resource/Number.png");
		GameTextureDataFile_[1] = ("Resource/Game_Score.png");
		GameTextureDataFile_[2] = ("Resource/Game_Timer.png");
		GameTextureDataFile_[3] = ("Resource/GameClear.png");
		GameTextureDataFile_[4] = ("Resource/GameOver.png");
		break;
	case 2:
		ResultTextureDataFile_[0] = ("Resource/Number.png");
		ResultTextureDataFile_[1] = ("Resource/TotalScore.png");
		break;
	}
}

void TextureDataBase::TextureData::Release(int& scenetype)
{
	switch (scenetype)
	{
	case 0:

		break;
	case 1:
		DeleteGraph(GameTextureData_[0]);
		DeleteGraph(GameTextureData_[1]);
		DeleteGraph(GameTextureData_[2]);
		DeleteGraph(GameTextureData_[3]);
		DeleteGraph(GameTextureData_[4]);
		break;
	case 2:
		DeleteGraph(ResultTextureData_[0]);
		DeleteGraph(ResultTextureData_[1]);
		break;
	}
}

void TextureDataBase::TextureData::Loading(int& scenetype)
{
	switch (scenetype)
	{
	case 0:
		DrawString(250, 240 - 32, "Loading..", GetColor(255, 255, 255));
		LoadingCheck_ = true;
		break;
	case 1:
		GameTextureData_[0] = LoadGraph(GameTextureDataFile_[0].c_str());
		GameTextureData_[1] = LoadGraph(GameTextureDataFile_[1].c_str());
		GameTextureData_[2] = LoadGraph(GameTextureDataFile_[2].c_str());
		GameTextureData_[3] = LoadGraph(GameTextureDataFile_[3].c_str());
		GameTextureData_[4] = LoadGraph(GameTextureDataFile_[4].c_str());
		DrawString(250, 240 - 32, "Loading..", GetColor(255, 255, 255));
		
		LoadingCheck_ = true;
		break;
	case 2:
		ResultTextureData_[0] = LoadGraph(ResultTextureDataFile_[0].c_str());
		ResultTextureData_[1] = LoadGraph(ResultTextureDataFile_[1].c_str());
		
		DrawString(250, 240 - 32, "Loading..", GetColor(255, 255, 255));
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

int TextureDataBase::TextureData::GetBackgroundData()
{
	return BackgroundTextureData_;
}
