#pragma once
#include <array>
#include <string>

namespace TextureDataBase
{
	enum class TitleTextureNumber : int
	{
		BackGroundData,
		NONE,
	};
	enum class GameTextureNumber : int
	{
		BackGroundData = 0,
		GameScoreData,
		GameTimerData,
		GameClearData,
		GameOverData,
		MenuGameEndData,
		MenuGameRestartData,
		MenuGameTitleData,
		NumberData,
		PauseData,
		NONE,
	};
	enum class ResultTextureNumber : int 
	{
		BackGroundData = 0,
		NONE,
	};
	class TextureData
	{
	public:
		TextureData();
		~TextureData();
		void Init();
		void Release();
		void CreateTextureData(int& scenetype);
		void Loading(int& scenetype);
		const int& GetTitleTextureData(int titletexturenumber);
		const int& GetGameTextureData(int gametexturenumber);
		const int& GetResultTextureData(int resulttexturenumber);
		const int& GetNumberTexture(int number);
		bool GetNowLoadingCheckFlag();
	private:;
		std::array<std::string,1> TitleTextureDataFile_;
		std::array<std::string,6> GameTextureDataFile_;
		std::array<std::string,3> ResultTextureDataFile_;
		std::string BackgroundTextureFile_;
		std::array<int,1> TitleTextureDataHandle_;
		std::array<int,6> GameTextureDataHandle_;
		std::array<int,3> ResultTextureDataHandle_;
		std::array<int,1> TitleTexture_;
		std::array<int,6> GameTexture_;
		std::array<int,3> ResultTexture_;
		int NumberTexture_[10];
		bool LoadingCheck_;
	};
}