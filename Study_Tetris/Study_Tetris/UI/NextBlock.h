#pragma once
// NextBlock.h
// �X�g�b�N�������u���b�N��\������N���X
#include "UI.h"
#include "../Resource/Block.h"

namespace TetrisUI
{
	class NextBlock : public UI
	{	
	public:
		NextBlock(){
		}
		~NextBlock() {}
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
		/// �X�^�b�N���Ă���u���b�N��`�悷�郁�\�b�h
		/// </summary>
		void NextBlockPlaceDraw();
		/// <summary>
		/// �u���b�N�̏��������\�b�h
		/// </summary>
		void BlockInit();
		/// <summary>
		/// �X�g�b�N���Ă���u���b�N���擾���郁�\�b�h
		/// </summary>
		/// <param name="num">�X�g�b�N������ԍ�</param>
		/// <param name="type">�X�g�b�N������u���b�N�̌`��</param>
		static void GetNextBlockType(int num, int type)
		{
			BlockNumber_[num] = type;
		}
	private:	
		/// <value>�u���b�N�̃f�[�^�ł�</value>
		BlockData BlocksData_;
		/// <value>�X�g�b�N�����Ă���u���b�N�̔ԍ��ł�</value>
		static std::array<int, 3> BlockNumber_;
		/// <value>�`�悳����u���b�N�̔z��ł�</value>
		TetrisGameType::Block Blocktype_[TetrisGameType::TetrisBlockTypeNum::MaxNumber][TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
	};
}