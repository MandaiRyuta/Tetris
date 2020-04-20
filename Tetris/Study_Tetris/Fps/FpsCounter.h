#pragma once
//FpsCounter.h
//ゲームのフレームレートを管理しています。

namespace FPS
{
	///<value> StartTime_と比較するための60フレーム </value>
	constexpr int Fps_N = 60;
	///<value> 待機フレームの計算式に導入する用です </value>
	constexpr int FpsFrame = 60;

	class FpsCounter 
	{
	public:
		FpsCounter() {
			StartTime_ = 0;
			TimeCount_ = 0;
			Fps_ = 0;
		}
		~FpsCounter()
		{
			StartTime_ = 0;
			TimeCount_ = 0;
			Fps_ = 0;
		}
		/// <summary>
		/// 更新メソッド
		/// </summary>
		void Update();
		/// <summary>
		/// 更新メソッド
		/// <para>デバッグ時にFPS表示させるための関数です</para>
		/// </summary>
		void Draw();
		/// <summary>
		/// 待機時間メソッド
		/// </summary>
		void WaitTime();
	private:
		///<value>開始時間</value>
		unsigned int StartTime_;
		///<value>フレームカウント</value>
		unsigned int TimeCount_;
		///<value> Fps表示用 </value>
		float Fps_;
	};
}