#pragma once
//Fade.h
//�t�F�[�h���Ǘ����Ă���N���X
#include "UI.h"

namespace TetrisUI
{
	class Fade : public UI
	{
	public:
		Fade() {}
		~Fade() {}
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
		/// <param name="handle">�e�N�X�`���[�n���h��</param>
		/// <param name="texturenumber">�����e�N�X�`���[��</param>
		virtual void LoadTexture(int handle, int texturenumber = 0) override;
		/// <summary>
		/// �t�F�[�h�C�����\�b�h
		/// </summary>
		/// <returns></returns>
		signed short int FadeIn();
		/// <summary>
		/// �t�F�[�h�A�E�g
		/// </summary>
		/// <returns></returns>
		signed short int FadeOut();
		/// <summary>
		/// �t�F�[�h�̃^�C�v���w�肷�郁�\�b�h�ł�
		/// </summary>
		/// <param name="type"></param>
		static void SetStartFade(int type);
		/// <summary>
		/// �t�F�[�h���I�������
		/// </summary>
		/// <returns>�t�F�[�h�̏�Ԃ��擾</returns>
		static signed short int GetFadeCheck();
	private:
		/// <value>�t�F�[�h�`�F�b�N�t���O�ł�</value>
		static signed short int FadeCheck_;
		/// <value>�t�F�[�h�����Ȃ����A�t�F�[�h�C�����邩�A�t�F�[�h�A�E�g���邩���w�肷��X�e�[�g�ł�</value>
		static int State_;
		/// <value>�F���</value>
		TetrisGameType::Color Color_;
	};
}