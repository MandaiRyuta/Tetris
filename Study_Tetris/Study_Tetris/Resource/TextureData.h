#pragma once
#include <array>
#include <string>

namespace TextureDataBase
{
	class TextureData
	{
	public:
		TextureData();
		~TextureData();
		void Init();
		void Release();
		void Loading(int& scenetype);
		const int& GetTitleTextureData(int titletexturenumber);
		const int& GetGameTextureData(int gametexturenumber);
		const int& GetResultTextureData(int resulttexturenumber);
		const int& GetNumberTexture(int number);
	private:;
		std::array<int,1> TitleTextureDataHandle_;
		std::array<int,6> GameTextureDataHandle_;
		std::array<int,3> ResultTextureDataHandle_;
		int NumberTexture_[10];
	};
}