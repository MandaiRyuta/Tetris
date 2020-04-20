#pragma once
//TextureData.h
//テクスチャーを管理しています。
#include <array>
#include <string>

namespace TextureDataBase
{
	class TextureData
	{
	public:
		TextureData();
		~TextureData();
		/// <summary> 
		/// 初期化メソッド
		/// </summary>
		void Init();
		/// <summary> 
		/// 解放メソッド
		/// </summary>
		void Release();
		/// <summary> 
		/// ローディングメソッド
		/// <para>シーンの番号を参照し、シーンに沿ったテクスチャーを非同期で読み込む関数です。</para>
		/// </summary>
		void Loading(int& scenetype);
		/// <summary>
		/// タイトルのテクスチャーデータを参照するメソッド
		/// </summary>
		/// <param name = "titletexturenumber">タイトルテクスチャーデータに登録してある番号を指定します。</param>
		const int& GetTitleTextureData(int titletexturenumber);
		/// <summary> 
		/// ゲームのテクスチャーデータを参照するメソッド
		/// </summary>
		/// <param name = "gametexturenumber">ゲームテクスチャーデータに登録してある番号を指定します。</param>
		const int& GetGameTextureData(int gametexturenumber);
		/// <summary>
		/// リザルトのテクスチャーデータを参照するメソッド
		/// </summary>
		/// <param name = "resulttexturenumber">リザルトのテクスチャーデータに登録してある番号を指定します。</param>
		const int& GetResultTextureData(int resulttexturenumber);
		/// <summary>
		/// 数字テクスチャーを参照するメソッド
		/// </summary>
		/// <param name = "number">数字テクスチャーの番号を指定します。</param>
		const int& GetNumberTexture(int number);
	private:
		///<value>タイトルのテクスチャーデータを管理している配列</value>
		std::array<int,1> TitleTextureDataHandle_;
		///<value>ゲームのテクスチャーデータを管理している配列</value>
		std::array<int,6> GameTextureDataHandle_;
		///<value>リザルトのテクスチャーデータを管理している配列</value>
		std::array<int,3> ResultTextureDataHandle_;
		///<value>番号のテクスチャーを管理している配列</value>
		int NumberTexture_[10];
	};
}