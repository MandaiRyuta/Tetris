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
	InitGraph();
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

	for (int i = 0; i < 10; i++)
	{
		DeleteGraph(NumberTexture_[i]);
	}
}

void TextureDataBase::TextureData::Loading(int& scenetype)
{
	SetUseASyncLoadFlag(TRUE);
	
	switch (scenetype)
	{
	case 0:
		TitleTextureDataHandle_[0] = LoadGraph("Resource/Background.png");
		break;
	case 1:
		GameTextureDataHandle_[0] = LoadGraph("Resource/Game_Score.png");
		GameTextureDataHandle_[1] = LoadGraph("Resource/Game_Timer.png");
		GameTextureDataHandle_[2] = LoadGraph("Resource/GameClear.png");
		GameTextureDataHandle_[3] = LoadGraph("Resource/GameOver.png");
		GameTextureDataHandle_[4] = LoadGraph("Resource/Background.png");
		LoadDivGraph("Resource/Number.png", 10, 10, 1, 29, 28, NumberTexture_);
		break;
	case 2:
		ResultTextureDataHandle_[0] = LoadGraph("Resource/TotalScore.png");
		ResultTextureDataHandle_[1] = LoadGraph("Resource/Background.png");
		
		LoadDivGraph("Resource/Number.png", 10, 10, 1, 29, 28, NumberTexture_);
		break;
	}
	SetUseASyncLoadFlag(FALSE);
}

const int& TextureDataBase::TextureData::GetTitleTextureData(int titletexturenumber)
{
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