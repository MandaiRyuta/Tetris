#pragma once
//Score.h
//�X�R�A��\������N���X
#include "UI.h"

namespace TetrisUI
{
	class Score : public UI
	{
	public:
		Score()
		{
			Position_.x = 600;
			Position_.y = 100;
		}
		~Score() {}
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
		/// �X�R�A���Z�b�g���郁�\�b�h
		/// </summary>
		/// <param name="score">�X�R�A</param>
		static void SetScore(int score);
		/// <summary>
		/// �X�R�A�̏����󂯎�郁�\�b�h
		/// </summary>
		/// <returns>���݂̃X�R�A</returns>
		static unsigned int GetScore();
		/// <summary>
		/// �X�R�A�����Z���郁�\�b�h
		/// </summary>
		/// <param name="addscore">���Z����X�R�A</param>
		static void AddScore(int addscore);
	private:
		/// <value>���U���g���̃X�R�A�e�N�X�`���[�ł�</value>
		int ScoreTexture_;
		/// <value>�`�掞�Ԃł�</value>
		int DrawTime_;
		/// <value>�Q�[���v���C���̕����̃X�R�A�e�N�X�`���[�ł�</value>
		int FontScoreTexture_;
		/// <value>�X�R�A�ł�</value>
		static unsigned int Score_;
		/// <value>�`��ʒu�ł�</value>
		TetrisGameType::Vector2 Position_;
	};
}