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
	TitleTextureDataFile_[0] = ("Resource/Background.png");

	GameTextureDataFile_[0] = ("Resource/Game_Score.png");
	GameTextureDataFile_[1] = ("Resource/Game_Timer.png");
	GameTextureDataFile_[2] = ("Resource/GameClear.png");
	GameTextureDataFile_[3] = ("Resource/GameOver.png");
	GameTextureDataFile_[4] = ("Resource/Background.png");
	GameTextureDataFile_[5] = ("Resource/Number.png");

	ResultTextureDataFile_[0] = ("Resource/TotalScore.png");
	ResultTextureDataFile_[1] = ("Resource/Background.png");
	ResultTextureDataFile_[2] = ("Resource/Number.bmp");

	LoadingCheck_ = false;
}

void TextureDataBase::TextureData::Release()
{
	DeleteGraph(TitleTextureDataHandle_[0]);

	for (int i = 0; i < 6; i++)
	{
		DeleteGraph(GameTextureDataHandle_[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		DeleteGraph(ResultTextureDataHandle_[i]);
	}
}

void TextureDataBase::TextureData::CreateTextureData(int& scenetype)
{

}


void TextureDataBase::TextureData::Loading(int& scenetype)
{
	SetUseASyncLoadFlag(TRUE);
	
	switch (scenetype)
	{
	case 0:
		TitleTextureDataHandle_[0] = LoadGraph(TitleTextureDataFile_[0].c_str());
		LoadingCheck_ = true;
		break;
	case 1:
		GameTextureDataHandle_[0] = LoadGraph(GameTextureDataFile_[0].c_str());
		GameTextureDataHandle_[1] = LoadGraph(GameTextureDataFile_[1].c_str());
		GameTextureDataHandle_[2] = LoadGraph(GameTextureDataFile_[2].c_str());
		GameTextureDataHandle_[3] = LoadGraph(GameTextureDataFile_[3].c_str());
		GameTextureDataHandle_[4] = LoadGraph(GameTextureDataFile_[4].c_str());
		LoadDivGraph(GameTextureDataFile_[5].c_str(), 10, 10, 1, 29, 28, NumberTexture_);
		LoadingCheck_ = true;
		break;
	case 2:
		ResultTextureDataHandle_[0] = LoadGraph(ResultTextureDataFile_[0].c_str());
		ResultTextureDataHandle_[1] = LoadGraph(ResultTextureDataFile_[1].c_str());
		
		LoadDivGraph(ResultTextureDataFile_[2].c_str(), 10, 10, 1, 29, 28, NumberTexture_);
		LoadingCheck_ = true;
		break;
	}
	SetUseASyncLoadFlag(FALSE);
}

const int& TextureDataBase::TextureData::GetTitleTextureData(int titletexturenumber)
{

	//FileRead_fullyLoad_delete(TitleTextureDataHandle_[titletexturenumber]);
	return TitleTextureDataHandle_[titletexturenumber];
}

const int& TextureDataBase::TextureData::GetGameTextureData(int gametexturenumber)
{

	return GameTextureDataHandle_[gametexturenumber];
}

const int& TextureDataBase::TextureData::GetResultTextureData(int resulttexturenumber)
{
	return ResultTextureDataHandle_[resulttexturenumber];
}

const int& TextureDataBase::TextureData::GetNumberTexture(int number)
{
	return NumberTexture_[number];
}

bool TextureDataBase::TextureData::GetNowLoadingCheckFlag()
{
	return LoadingCheck_;
}
