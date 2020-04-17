#pragma once
//UI.h
//UI�̉��z�N���X
#include <DxLib.h>
#include "../TetrisGameType/TetrisGameType.h"

namespace TetrisUI
{
	class UI
	{
	public:
		UI(){}
		virtual ~UI() {}
	public:
		/// <summary>
		/// ���������\�b�h�̒��ۉ�
		/// </summary>
		virtual void Init() =0;
		/// <summary>
		/// �X�V���\�b�h���ۉ�
		/// </summary>
		virtual void Update() =0;
		/// <summary>
		/// �`�惁�\�b�h���ۉ�
		/// </summary>
		virtual void Draw() =0;
		/// <summary>
		/// ������\�b�h���ۉ�
		/// </summary>
		virtual void Release() =0;
		/// <summary>
		/// ���[�h�e�N�X�`���[���\�b�h�̒��ۉ�
		/// </summary>
		/// <param name="handle">�o�^�����e�N�X�`���[�ԍ�</param>
		/// <param name="texturenumber">�����e�N�X�`���[�p�̔ԍ� 0 ���� 9</param>
		virtual void LoadTexture(int handle, int texturenumber = 0) = 0;
	};
}