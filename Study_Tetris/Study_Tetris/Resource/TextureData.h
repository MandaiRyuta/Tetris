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
		void CreateTextureData(int& scenetype);
		void Release(int& scenetype);
		int GetTitleTextureData(int titletexturenumber);
		void Loading(int& scenetype);
		int GetGameTextureData(int gametexturenumber);
		int GetResultTextureData(int resulttexturenumber);
		bool GetNowLoadingCheckFlag();
		int GetBackgroundData();
	private:;
		std::array<std::string,1> TitleTextureDataFile_;
		std::array<std::string,5> GameTextureDataFile_;
		std::array<std::string,2> ResultTextureDataFile_;
		std::string BackgroundTextureFile_;
		std::array<int,1> TitleTextureData_;
		std::array<int,5> GameTextureData_;
		std::array<int,2> ResultTextureData_;
		int BackgroundTextureData_;
		bool LoadingCheck_;
	};
}