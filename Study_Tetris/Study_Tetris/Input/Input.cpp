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
// * �X�V����
// * @brief �L�[�̓��͏�Ԃ̍X�V�����֐�
// */
//void Input::Update()
//{
//	GetJoypadXInputState(PadNumber_, &Xinput_);
//	GetHitKeyStateAll(Buf_);
//}
//
///**
// * @fn
// * �L�[���͂̏�Ԕc��
// * @brief �L�[���͂̉��������Ɨ��������̔���
// * @param (KeyCode) �L�[�̖��O
// * @return signed short int �̌^�Ł@0x001 = true, 0x000 = false�ɂ���悤�ɂ��܂���
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
// * �L�[���͂̉��������̂ݔ��肷��֐�
// * @brief �L�[���͂̉��������݂̂̔���
// * @param (KeyCode) �L�[�̖��O
// * @return signed short int �̌^�Ł@0x001 = true, 0x000 = false�ɂ���悤�ɂ��܂���
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
// * �L�[���̗͂��������̂ݔ��肷��֐�
// * @brief �L�[���̗͂��������݂̂̔���
// * @param (KeyCode) �L�[�̖��O
// * @return signed short int �̌^�Ł@0x001 = true, 0x000 = false�ɂ���悤�ɂ��܂���
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
// * �W���C�p�b�g�̓��͂������������������ɔ�������֐�
// * @brief�@�W���C�p�b�g���͂ŉ����������������ɐ��l���Ԃ��Ă���
// * @param (KeyCode) �L�[�̖��O
// * @return signed short int �̌^�Ł@0x001 = true, 0x000 = false�ɂ���悤�ɂ��܂���
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
// * �W���C�p�b�g���͂̉��������̂ݔ��肷��֐�
// * @brief �W���C�p�b�g���͂̉��������݂̂̔���
// * @param (KeyCode) �L�[�̖��O
// * @return signed short int �̌^�Ł@0x001 = true, 0x000 = false�ɂ���悤�ɂ��܂���
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
// * �L�[���̗͂��������̂ݔ��肷��֐�
// * @brief �L�[���̗͂��������݂̂̔���
// * @param (KeyCode) �L�[�̖��O
// * @return signed short int �̌^�Ł@0x001 = true, 0x000 = false�ɂ���悤�ɂ��܂���
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
