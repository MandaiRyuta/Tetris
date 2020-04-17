#pragma once
//UIManager.h
//��ʂɕ\�����邷�ׂĂ�UI���Ǘ����Ă���N���X�ł��B
#include <array>
#include "../../TetrisGameType/TetrisGameType.h"
#include "../NextBlock.h"
#include "../Hold.h"
#include "../Time.h"
#include "../Score.h"
#include "../Number.h"
#include "../InGameState.h"
#include "../Fade.h"
#include "../Background.h"

#include "../UI.h"
#include "../../Actor/Actor.h"
#include "../../Resource/TextureData.h"

namespace TetrisUI
{
	class UIManager : public Actor
	{
	public:
		UIManager();
		~UIManager();
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
		/// �e�N�X�`���[�����擾���郁�\�b�h
		/// </summary>
		/// <param name="type">�V�[���̔ԍ�</param>
		/// <param name="number">�z��Ɋi�[���Ă���e�N�X�`���[�ԍ�</param>
		/// <returns>�w�肵���摜�̃n���h��</returns>
		static const int& GetTextureHandle(int type, int number);
		/// <summary>
		/// �V�[�����w�肷�郁�\�b�h
		/// </summary>
		/// <param name="type">�V�[���ԍ�</param>
		void SetType(int type);
		/// <summary>
		/// �S�Ă�UI�����������郁�\�b�h
		/// </summary>
		void InitAll();
		/// <summary>
		/// �S�Ă�UI���X�V���郁�\�b�h
		/// </summary>
		void UpdateAll();
		/// <summary>
		/// �S�Ă�UI��`�悷�郁�\�b�h
		/// </summary>
		void DrawAll();
		/// <summary>
		/// �S�Ă�UI��������郁�\�b�h
		/// </summary>
		void ReleaseAll();
		/// <summary>
		/// UI�𐶐����郁�\�b�h
		/// </summary>
		template <class T>
		UI* Create()
		{
			UI* obj = new T;
			return  obj;
		}
	private:
		/// <value>�V�[���ԍ��ł�</value>
		int SceneType_;
		/// <value>�e�N�X�`���[���Ǘ����Ă���N���X�ł�</value>
		static TextureDataBase::TextureData texture_;
		/// <value>�^�C�g���Ŏg����UI�I�u�W�F�N�g�ł�</value>
		std::array<UI*, 2> TitleObj_;
		/// <value>�Q�[���Ŏg����UI�I�u�W�F�N�g�ł�</value>
		std::array<UI*, 8> GameObj_;
		/// <value>���U���g�Ŏg����UI�I�u�W�F�N�g�ł�</value>
		std::array<UI*, 4> ResultObj_;
	};
}