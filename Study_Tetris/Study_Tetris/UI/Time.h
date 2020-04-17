#pragma once
//Time.h
//時間を表示するクラス
#include "UI.h"

namespace TetrisUI
{
	constexpr int Minute = 3600;
	constexpr int Second = 60;
	class Time : public UI
	{
	public:
		Time():
			endtime_(0),
			Min_(0),
			Sec_(0),
			MinSec_(0){}
		~Time() {}
	public:
		/// <summary>
		/// 初期化メソッド
		/// </summary>
		virtual void Init() override;
		/// <summary>
		/// 更新メソッド
		/// </summary>
		virtual void Update() override;
		/// <summary>
		/// 描画メソッド
		/// </summary>
		virtual void Draw() override;
		/// <summary>
		/// 解放メソッド
		/// </summary>
		virtual void Release() override;
		/// <summary>
		/// ロードテクスチャーメソッド
		/// </summary>
		/// <param name="handle">登録したテクスチャー番号</param>
		/// <param name="texturenumber">数字テクスチャー用の番号 0 から 9</param>
		virtual void LoadTexture(int handle, int texturenumber = 0) override;
		/// <summary>
		/// 現在の時間を取得するメソッド
		/// </summary>
		/// <returns>現在の時間</returns>
		static int GetNowTime();
	private:
		/// <value></value>
		int TimeFontTexture_;
		/// <value></value>
		static int nowtime_;
		/// <value></value>
		int endtime_;
		/// <value></value>
		int Min_;
		/// <value></value>
		int Sec_;
		/// <value></value>
		int MinSec_;
		/// <value></value>		
		std::array<int, 3> Positionx_;
		/// <value></value>
		std::array<int, 3> Positiony_;
		/// <value></value>
		std::array<int, 3> Color_;
	};
}