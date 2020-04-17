#pragma once
//Number.h
//������`�悷��N���X
#include "UI.h"

namespace TetrisUI
{
	//�ԍ��̕`�悳����T�C�Y
	constexpr int NumberDrawSize = 5;
	//�ԍ����������`�悳����T�C�Y
	constexpr int ReSizeDrawSize = 1;
	class Number : public UI
	{
	public:
		Number();
		~Number();
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
		/// ������`�悷�郁�\�b�h
		/// </summary>
		/// <param name="x">�`��w�肷��X���W</param>
		/// <param name="y">�`��w�肷��Y���W</param>
		/// <param name="num">�`�悷�鐔��</param>
		void DrawNumber(int x, int y, int num);
		/// <summary>
		/// ������`�悷�郁�\�b�h
		/// </summary>
		/// <param name="x">�`��w�肷��X���W</param>
		/// <param name="y">�`��w�肷��Y���W</param>
		/// <param name="Num">�`�悷�鐔��</param>
		void NumDraw(int x, int y, int Num);
		/// <summary>
		/// �`�悷�鐔���̐ݒ�
		/// </summary>
		/// <param name="x">�`��w�肷��X���W</param>
		/// <param name="y">�`��w�肷��Y���W</param>
		/// <param name="num">�`�悷�鐔��</param>
		/// <param name="size">�`�悳����������������z��ԍ�</param>
		/// <param name="resizecheck">�T�C�Y�ύX�t���O</param>
		static void SetDrawNumber(int x, int y, int num, int size, signed short int resizecheck);
	private:
		/// <value>�`��w�肷��X���W�ł�</value>
		static int PositionX_[NumberDrawSize];
		/// <value>�`��w�肷��Y���W�ł�</value>
		static int PositionY_[NumberDrawSize];
		/// <value>�`�悳���鐔���̔ԍ��ł�</value>
		static int Number_[NumberDrawSize];
		/// <value>�傫�����C���������Ƃ���X���W�ł�</value>
		static int ReSizePositionX_[ReSizeDrawSize];
		/// <value>�傫�����C���������Ƃ���Y���W�ł�</value>
		static int ReSizePositionY_[ReSizeDrawSize];
		/// <value>�傫����ύX�����鐔���ł�</value>
		static int ResizeNumber_[ReSizeDrawSize];
		/// <value>�ύX����摜�T�C�Y�ł�</value>
		static int ReSize_;
		/// <value>�摜�̑傫����ύX�������m�F����t���O�ł�</value>
		static signed short int ResizeCheck_;
		/// <value>�����̃e�N�X�`���[�ł�</value>
		int DrawNumberTexture_[10];
	};
}
