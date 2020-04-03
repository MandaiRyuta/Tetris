#pragma once
/**
 * @file Input.h
 * @brief “ü—Íˆ—ƒNƒ‰ƒX‚Ìì¬
 * @author Mandai Ryuta
 * @data 2020/04/02
 */
#include "main.h"

struct Vector2
{
	int x;
	int y;
};

constexpr int KeyBuf = 256;

class Input
{
public:
	Input(int PadNumber) 
		: PadNumber_(PadNumber)
	{
		Buf_[KeyBuf] = {};
		Direction_.x = 0;
		Direction_.y = 0;
	}
	~Input() {}
public:
	void Update();
	signed short int GetKey(int KeyCode);
	signed short int GetKeyDown(int KeyCode);
	signed short int GetKeyUp(int KeyCode);
	signed short int GetJoyPadButton(int KeyCode);
	signed short int GetJoyPadButtonDown(int KeyCode);
	signed short int GetJoyPadButtonUp(int KeyCode);
	Vector2 GetDirection();
private:
	char Buf_[KeyBuf];
	Vector2 Direction_;
	int PadNumber_;
	XINPUT_STATE Xinput_;
};