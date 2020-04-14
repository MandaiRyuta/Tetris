#pragma once
#include <vector>
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
		std::vector<std::string> TitleTextureDataFile_;
		std::vector<std::string> GameTextureDataFile_;
		std::vector<std::string> ResultTextureDataFile_;
		std::vector<int> TitleTextureData_;
		std::vector<int> GameTextureData_;
		std::vector<int> ResultTextureData_;
		bool LoadingCheck_;
	};
}