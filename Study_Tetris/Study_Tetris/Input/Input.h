//#pragma once
///**
// * @file Input.h
// * @brief “ü—Íˆ—ƒNƒ‰ƒX‚Ìì¬
// * @author Mandai Ryuta
// * @data 2020/04/02
// */
//#include "main.h"
//#include "Utils.h"
//
//constexpr int KeyBuf = 256;
//
//class Input
//{
//public:
//	Input(int PadNumber);
//	~Input() {}
//public:
//	void Update();
//	signed short int GetKey(int KeyCode);
//	signed short int GetKeyDown(int KeyCode);
//	signed short int GetKeyUp(int KeyCode);
//	signed short int GetJoyPadButton(int KeyCode);
//	signed short int GetJoyPadButtonDown(int KeyCode);
//	signed short int GetJoyPadButtonUp(int KeyCode);
//	Utils::Vector2 GetDirection();
//private:
//	char Buf_[KeyBuf];
//	Utils::Vector2 Direction_;
//	int PadNumber_;
//	XINPUT_STATE Xinput_;
//};