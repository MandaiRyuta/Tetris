#pragma once
// BlockCollection.h
// �Q�[���̃X�e�[�W���Ǘ����Ă���N���X�ł��B
#include <array>
#include "../../TetrisGameType\TetrisGameType.h"
#include "../TetrisBlock.h"
#include "../../Actor/Actor.h"

namespace TetrisBlocks
{
	class BlockCollection : public Actor
	{
	public:
		BlockCollection()
		{

		}
		~BlockCollection()
		{

		}
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
		/// �X�e�[�W�ɔz�u���ꂽ�u���b�N�������Ŋm�F���郁�\�b�h
		/// </summary>
		void StackBlockClearLineCheck();
		/// <summary>
		/// �����ŕ���ł���u���b�N���������\�b�h
		/// </summary>
		void StageBlockLineClear();
		/// <summary>
		/// �X�e�[�W�ɔz�u����Ă���u���b�N���m�F���邽�߂̃��\�b�h
		/// </summary>
		/// <param name="x">�m�F�������X�e�[�W����X���W</param>
		/// <param name="y">�m�F�������X�e�[�W����Y���W</param>
		/// <returns>�u���b�N�̗L���@�L: 1 ���� 7 ��: 0  �X�e�[�W�̊O : 9 �ʒu�ɂ���ĎQ�Ƃ���܂��B</returns>
		const int& GetBoardInfo(int x, int y);
	private:
		/// <value>�X�e�[�W�Ƀu���b�N���u����s�ł�</value>
		int ClearLine_[23];
		/// <value>�e�g���X�u���b�N���P�s����ł�����"0x001:(true)"�ɐݒ肵�������ۂ�"0x000:(false)"�ɕς��܂�</value>
		signed short int ClearCheck_;
		/// <value>�v���C���[������ł���u���b�N�N���X�ł�</value>
		TetrisBlock Block_;
		/// <value>�u���b�N������ł���A�������s�̐�</value>
		int ClearCount_;
		/// <value>�X�e�[�W�̕��A�������Ǘ����Ă���z��ł��B</value>
		std::array<std::array<int, TetrisGameType::StageWidth>, TetrisGameType::StageHeight> Board_;
	};
}