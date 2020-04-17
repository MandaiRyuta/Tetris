#pragma once
//Number.h
//数字を描画するクラス
#include "UI.h"

namespace TetrisUI
{
	//番号の描画させるサイズ
	constexpr int NumberDrawSize = 5;
	//番号を小さく描画させるサイズ
	constexpr int ReSizeDrawSize = 1;
	class Number : public UI
	{
	public:
		Number();
		~Number();
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
		/// 数字を描画するメソッド
		/// </summary>
		/// <param name="x">描画指定するX座標</param>
		/// <param name="y">描画指定するY座標</param>
		/// <param name="num">描画する数字</param>
		void DrawNumber(int x, int y, int num);
		/// <summary>
		/// 数字を描画するメソッド
		/// </summary>
		/// <param name="x">描画指定するX座標</param>
		/// <param name="y">描画指定するY座標</param>
		/// <param name="Num">描画する数字</param>
		void NumDraw(int x, int y, int Num);
		/// <summary>
		/// 描画する数字の設定
		/// </summary>
		/// <param name="x">描画指定するX座標</param>
		/// <param name="y">描画指定するY座標</param>
		/// <param name="num">描画する数字</param>
		/// <param name="size">描画させたい数字を入れる配列番号</param>
		/// <param name="resizecheck">サイズ変更フラグ</param>
		static void SetDrawNumber(int x, int y, int num, int size, signed short int resizecheck);
	private:
		/// <value>描画指定するX座標です</value>
		static int PositionX_[NumberDrawSize];
		/// <value>描画指定するY座標です</value>
		static int PositionY_[NumberDrawSize];
		/// <value>描画させる数字の番号です</value>
		static int Number_[NumberDrawSize];
		/// <value>大きさを修正させたときのX座標です</value>
		static int ReSizePositionX_[ReSizeDrawSize];
		/// <value>大きさを修正させたときのY座標です</value>
		static int ReSizePositionY_[ReSizeDrawSize];
		/// <value>大きさを変更させる数字です</value>
		static int ResizeNumber_[ReSizeDrawSize];
		/// <value>変更する画像サイズです</value>
		static int ReSize_;
		/// <value>画像の大きさを変更したか確認するフラグです</value>
		static signed short int ResizeCheck_;
		/// <value>数字のテクスチャーです</value>
		int DrawNumberTexture_[10];
	};
}
