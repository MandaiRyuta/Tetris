#pragma once
// Hold.h
// �u���b�N��ێ������邽�߂̃N���X�ł��B
#include "UI.h"
#include "../Resource/Block.h"

namespace TetrisUI
{
	class Hold : public UI
	{
	public:
		Hold();
		~Hold();
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
		/// �u���b�N���̏��������\�b�h
		/// </summary>
		void BlockInit();
		/// <summary>
		/// �ێ����Ă���u���b�N�̌`����Ǘ����郁�\�b�h
		/// </summary>
		/// <param name="type">�ێ����Ă���u���b�N�̌`��</param>
		static void GetHoldBlockType(int type)
		{
			HoldBlockType_ = type;
		}
	private:
		/// <value>�u���b�N�̃f�[�^�ł�</value>
		BlockData BlocksData_;
		/// <value>�ێ����Ă���u���b�N�̌`���`�悷�邽�߂̔z��ł�</value>
		TetrisGameType::Block Blocktype_[TetrisGameType::TetrisBlockTypeNum::MaxNumber][TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		/// <value>�z�[���h���Ă���u���b�N�̌`��ł�</value>
		static int HoldBlockType_;
	};
}