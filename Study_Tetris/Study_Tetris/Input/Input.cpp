//#include "Input.h"
//
//
//constexpr int BUTTONDOWN = 1;
//constexpr int BUTTONUP = 0;
//
//Input::Input(int PadNumber)
//	: PadNumber_(PadNumber)
//{
//	*Buf_ = {};
//	ZeroMemory(&Xinput_, sizeof(XINPUT_STATE));
//	Direction_.x = 0;
//	Direction_.y = 0;
//}
//
///**
// * @fn
// * 更新処理
// * @brief キーの入力状態の更新処理関数
// */
//void Input::Update()
//{
//	GetJoypadXInputState(PadNumber_, &Xinput_);
//	GetHitKeyStateAll(Buf_);
//}
//
///**
// * @fn
// * キー入力の状態把握
// * @brief キー入力の押した時と離した時の判定
// * @param (KeyCode) キーの名前
// * @return signed short int の型で　0x001 = true, 0x000 = falseにするようにしました
// */
//signed short int Input::GetKey(int KeyCode)
//{
//	if (Buf_[KeyCode] == 1)
//	{
//		return 0x001;
//	}
//	else
//	{
//		return 0x000;
//	}
//}
///**
// * @fn
// * キー入力の押した時のみ判定する関数
// * @brief キー入力の押した時のみの判定
// * @param (KeyCode) キーの名前
// * @return signed short int の型で　0x001 = true, 0x000 = falseにするようにしました
// */
//signed short int Input::GetKeyDown(int KeyCode)
//{
//	if (Buf_[KeyCode] == BUTTONDOWN)
//	{
//		return 0x001;
//	}
//
//	return 0x000;
//}
///**
// * @fn
// * キー入力の離した時のみ判定する関数
// * @brief キー入力の離した時のみの判定
// * @param (KeyCode) キーの名前
// * @return signed short int の型で　0x001 = true, 0x000 = falseにするようにしました
// */
//signed short int Input::GetKeyUp(int KeyCode)
//{
//	if (Buf_[KeyCode] != BUTTONDOWN)
//	{
//		return 0x001;
//	}
//
//	return 0x000;
//}
///**
// * @fn
// * ジョイパットの入力が押した時離した時に反応する関数
// * @brief　ジョイパット入力で押した時離した時に数値が返ってくる
// * @param (KeyCode) キーの名前
// * @return signed short int の型で　0x001 = true, 0x000 = falseにするようにしました
// */
//signed short int Input::GetJoyPadButton(int KeyCode)
//{
//	if ((Xinput_.Buttons[KeyCode]) != BUTTONUP)
//	{
//		return 0x001;
//	}
//	else
//	{
//		return 0x000;
//	}
//}
///**
// * @fn
// * ジョイパット入力の押した時のみ判定する関数
// * @brief ジョイパット入力の押した時のみの判定
// * @param (KeyCode) キーの名前
// * @return signed short int の型で　0x001 = true, 0x000 = falseにするようにしました
// */
//signed short int Input::GetJoyPadButtonDown(int KeyCode)
//{
//	if ((Xinput_.Buttons[KeyCode]) != BUTTONUP)
//	{
//		return 0x001;
//	}
//	
//	return 0x000;
//}
///**
// * @fn
// * キー入力の離した時のみ判定する関数
// * @brief キー入力の離した時のみの判定
// * @param (KeyCode) キーの名前
// * @return signed short int の型で　0x001 = true, 0x000 = falseにするようにしました
// */
//signed short int Input::GetJoyPadButtonUp(int KeyCode)
//{
//	if ((Xinput_.Buttons[KeyCode]) == BUTTONUP)
//	{
//		return 0x001;
//	}
//
//	return 0x000;
//}
//
//Utils::Vector2 Input::GetDirection()
//{
//	Direction_.x = Xinput_.ThumbLX;
//	Direction_.y = Xinput_.ThumbLY;
//
//	return Direction_;
//}
