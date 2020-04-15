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
	TitleTextureDataFile_[0] = ("Resource/Background.png");


	GameTextureDataFile_[0] = ("Resource/Number.png");
	GameTextureDataFile_[1] = ("Resource/Game_Score.png");
	GameTextureDataFile_[2] = ("Resource/Game_Timer.png");
	GameTextureDataFile_[3] = ("Resource/GameClear.png");
	GameTextureDataFile_[4] = ("Resource/GameOver.png");
	GameTextureDataFile_[5] = ("Resource/Background.png");


	ResultTextureDataFile_[0] = ("Resource/Number.bmp");
	ResultTextureDataFile_[1] = ("Resource/TotalScore.png");
	ResultTextureDataFile_[2] = ("Resource/Background.png");
	BackgroundTextureData_ = LoadGraph(BackgroundTextureFile_.c_str());
	
	LoadingCheck_ = false;
}

void TextureDataBase::TextureData::Release()
{
	DeleteGraph(TitleTextureDataHandle_[0]);
	DeleteGraph(GameTextureDataHandle_[0]);
	DeleteGraph(GameTextureDataHandle_[1]);
	DeleteGraph(GameTextureDataHandle_[2]);
	DeleteGraph(GameTextureDataHandle_[3]);
	DeleteGraph(GameTextureDataHandle_[4]);
	DeleteGraph(GameTextureDataHandle_[5]);
	DeleteGraph(ResultTextureDataHandle_[0]);
	DeleteGraph(ResultTextureDataHandle_[1]);
	DeleteGraph(ResultTextureDataHandle_[2]);
}

void TextureDataBase::TextureData::CreateTextureData(int& scenetype)
{
	TitleTextureDataFile_[0] = ("Resource/Background.png");


	GameTextureDataFile_[0] = ("Resource/Number.png");
	GameTextureDataFile_[1] = ("Resource/Game_Score.png");
	GameTextureDataFile_[2] = ("Resource/Game_Timer.png");
	GameTextureDataFile_[3] = ("Resource/GameClear.png");
	GameTextureDataFile_[4] = ("Resource/GameOver.png");
	GameTextureDataFile_[5] = ("Resource/Background.png");


	ResultTextureDataFile_[0] = ("Resource/Number.bmp");
	ResultTextureDataFile_[1] = ("Resource/TotalScore.png");
	ResultTextureDataFile_[2] = ("Resource/Background.png");
}


void TextureDataBase::TextureData::Loading(int& scenetype)
{
	SetUseASyncLoadFlag(TRUE);
	
	switch (scenetype)
	{
	case 0:
		TitleTextureDataHandle_[0] = LoadGraph(TitleTextureDataFile_[0].c_str());
		DrawString(250, 240 - 32, "Loading..", GetColor(255, 255, 255));
		LoadingCheck_ = true;
		break;
	case 1:

		GameTextureDataHandle_[0] = LoadGraph(GameTextureDataFile_[0].c_str());
		GameTextureDataHandle_[1] = LoadGraph(GameTextureDataFile_[1].c_str());
		GameTextureDataHandle_[2] = LoadGraph(GameTextureDataFile_[2].c_str());
		GameTextureDataHandle_[3] = LoadGraph(GameTextureDataFile_[3].c_str());
		GameTextureDataHandle_[4] = LoadGraph(GameTextureDataFile_[4].c_str());
		GameTextureDataHandle_[5] = LoadGraph(GameTextureDataFile_[5].c_str());
		DrawString(250, 240 - 32, "Loading..", GetColor(255, 255, 255));
		
		LoadingCheck_ = true;
		break;
	case 2:
		ResultTextureDataHandle_[0] = LoadGraph(ResultTextureDataFile_[0].c_str());
		ResultTextureDataHandle_[1] = LoadGraph(ResultTextureDataFile_[1].c_str());
		ResultTextureDataHandle_[2] = LoadGraph(ResultTextureDataFile_[2].c_str());
		DrawString(250, 240 - 32, "Loading..", GetColor(255, 255, 255));
		LoadingCheck_ = true;
		break;
	}
	SetUseASyncLoadFlag(FALSE);
}

const int& TextureDataBase::TextureData::GetTitleTextureHandle(int number)
{
	return TitleTextureDataHandle_[number];
}

const int& TextureDataBase::TextureData::GetGameTextureHandle(int number)
{
	return GameTextureDataHandle_[number];
}

const int& TextureDataBase::TextureData::GetResultTextureHandle(int number)
{
	return ResultTextureDataHandle_[number];
}

const int TextureDataBase::TextureData::GetTitleTextureData(int titletexturenumber)
{

	//FileRead_fullyLoad_delete(TitleTextureDataHandle_[titletexturenumber]);
	return TitleTextureDataHandle_[titletexturenumber];
}

const int TextureDataBase::TextureData::GetGameTextureData(int gametexturenumber)
{

	return GameTextureDataHandle_[gametexturenumber];
}

const int TextureDataBase::TextureData::GetResultTextureData(int resulttexturenumber)
{
	return ResultTextureDataHandle_[resulttexturenumber];
}

bool TextureDataBase::TextureData::GetNowLoadingCheckFlag()
{
	return LoadingCheck_;
}

int TextureDataBase::TextureData::GetBackgroundData()
{
	return BackgroundTextureData_;
}
