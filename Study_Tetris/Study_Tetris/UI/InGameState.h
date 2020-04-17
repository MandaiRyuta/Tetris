#pragma once
//InGameState.h
//�e�g���X�̏��s��\������N���X
#include "UI.h"

namespace TetrisUI
{
	namespace GameState
	{
		constexpr int GameClear = 1;
		constexpr int GameOver = 2;
	}
	class InGameState : public UI
	{
	public:
		InGameState() : GameClearTexture_(0), GameOverTexture_(0), NextSceneCount_(0){}
		~InGameState() {}
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
		/// �Q�[�����N���A���������s��������m�点�郁�\�b�h
		/// </summary>
		/// <returns>�Q�[�����N���A���������s���������Ԃ��Ă��܂�</returns>
		static int GetGameState();
		/// <summary>
		/// �Q�[�����N���A���������s���������w�肷�郁�\�b�h
		/// </summary>
		/// <param name="state">�N���A�������͎��s��ݒ肷��</param>
		static void SetGameState(int state);
	private:
		/// <value>�Q�[���N���A�e�N�X�`���[�ł�</value>
		int GameClearTexture_;
		/// <value>�Q�[���I�[�o�[�e�N�X�`���[�ł�</value>
		int GameOverTexture_;
		/// <value>�Q�[���̃N���A�A���s���Ǘ����܂�</value>
		static int GameState_;
		/// <value>���̃V�[���Ɉڂ�܂ł̃J�E���g�ł�</value>
		int NextSceneCount_;
	};
}