#pragma once
// TetrisGameType.h
// �e�g���X�Q�[���Ɋ֌W��������܂Ƃ߂Ă܂�
#include <DxLib.h>
#include <array>

//�f�o�b�O�p��define�ł��B
#define DEBUGCHECK 
/// <summary>
/// �V�[���̔ԍ��ł�
/// </summary>
namespace SceneNumber
{
	constexpr int TitleSceneNumber = 0;
	constexpr int GameSceneNumber = 1;
	constexpr int ResultSceneNumber = 2;
}
/// <summary>
/// �e�g���X�̃Q�[���ɂ��������ł�
/// </summary>
namespace TetrisGameType
{
	//�u���b�N�̎��
	namespace TetrisBlockTypeNum
	{
		constexpr int MaxNumber = 7;
	}
	//�u���b�N�̌`��������ԍ�
	namespace TetrisBlockType
	{
		constexpr int TYPEI = 0;
		constexpr int TYPEJ = 1;
		constexpr int TYPEL = 2;
		constexpr int TYPEO = 3;
		constexpr int TYPES = 4;
		constexpr int TYPET = 5;
		constexpr int TYPEZ = 6;
	}

	//�X�g�b�N����u���b�N�̐�
	constexpr int StockBlockSize = 4;
	//�u���b�N�̍���
	constexpr int BlockHeight = 5;
	//�u���b�N�̕�
	constexpr int BlockWidth = 5;
	//�X�e�[�W�̍���
	constexpr int StageHeight = 23;
	//�X�e�[�W�̕�
	constexpr int StageWidth = 13;
	//�`�悵�Ă���u���b�N�̕�
	constexpr int DrawBlockWidth = 20;
	//�u���b�N�̑��x
	constexpr int BlockSpeed = 5;
	//�P�t���[��
	constexpr int KeyFrame = 1;

	//�I�u�W�F�N�g�̃^�C�v
	enum class ObjectType
	{
		BACKGROUND,
		TETRIS,
	};

	//�I�u�W�F�N�g�̌`��
	enum class BlockType
	{
		I,
		J,
		L,
		O,
		S,
		T,
		Z,
	};
	//�V�[���̎��
	enum class SCENETYPE
	{
		TITLE,
		GAME,
		RESULT,
		NONE,
	};
	//�Q�������W
	struct Vector2
	{
		int x;
		int y;
	};
	//�F���
	struct Color
	{
		int r;
		int g;
		int b;
		int a;
	};
	//�u���b�N�̌`��ƐF���
	struct Block
	{
		int r;
		int g;
		int b;
		int a;
		int type;
	};
}