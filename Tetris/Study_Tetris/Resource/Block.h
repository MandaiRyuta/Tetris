#pragma once
//Block.h
//�u���b�N�̐F�A�z�u���Ǘ����Ă���N���X
#include "../TetrisGameType/TetrisGameType.h"

class BlockData
{
public:
	BlockData();
	~BlockData();
public:
	/// <summary> 
	/// ���������\�b�h
	/// </summary>
	void Init();
	/// <summary>
	/// �u���b�N�̔z�u���W���󂯎�郁�\�b�h
	/// <para>�e�u���b�N�̕\�����s���ہA�������̃^�C�~���O�ŌĂяo���Ďg���܂�</para>
	/// </summary>
	const TetrisGameType::Block& GetBlockPosition(int type, int x, int y);
private:
	///<value>�e�g���X�̊e�u���b�N���Ǘ����Ă��܂�</value>
	TetrisGameType::Block Block_[TetrisGameType::TetrisBlockTypeNum::MaxNumber][TetrisGameType::BlockHeight][TetrisGameType::BlockHeight];
};