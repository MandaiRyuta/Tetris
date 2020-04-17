#pragma once
//Time.h
//���Ԃ�\������N���X
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
		/// ���������\�b�h
		/// </summary>
		virtual void Init() override;
		/// <summary>
		/// �X�V���\�b�h
		/// </summary>
		virtual void Update() override;
		/// <summary>
		/// �`�惁�\�b�h
		/// </summary>
		virtual void Draw() override;
		/// <summary>
		/// ������\�b�h
		/// </summary>
		virtual void Release() override;
		/// <summary>
		/// ���[�h�e�N�X�`���[���\�b�h
		/// </summary>
		/// <param name="handle">�o�^�����e�N�X�`���[�ԍ�</param>
		/// <param name="texturenumber">�����e�N�X�`���[�p�̔ԍ� 0 ���� 9</param>
		virtual void LoadTexture(int handle, int texturenumber = 0) override;
		/// <summary>
		/// ���݂̎��Ԃ��擾���郁�\�b�h
		/// </summary>
		/// <returns>���݂̎���</returns>
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