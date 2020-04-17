#pragma once
//TextureData.h
//�e�N�X�`���[���Ǘ����Ă��܂��B
#include <array>
#include <string>

namespace TextureDataBase
{
	class TextureData
	{
	public:
		TextureData();
		~TextureData();
		/// <summary> 
		/// ���������\�b�h
		/// </summary>
		void Init();
		/// <summary> 
		/// ������\�b�h
		/// </summary>
		void Release();
		/// <summary> 
		/// ���[�f�B���O���\�b�h
		/// <para>�V�[���̔ԍ����Q�Ƃ��A�V�[���ɉ������e�N�X�`���[��񓯊��œǂݍ��ފ֐��ł��B</para>
		/// </summary>
		void Loading(int& scenetype);
		/// <summary>
		/// �^�C�g���̃e�N�X�`���[�f�[�^���Q�Ƃ��郁�\�b�h
		/// </summary>
		/// <param name = "titletexturenumber">�^�C�g���e�N�X�`���[�f�[�^�ɓo�^���Ă���ԍ����w�肵�܂��B</param>
		const int& GetTitleTextureData(int titletexturenumber);
		/// <summary> 
		/// �Q�[���̃e�N�X�`���[�f�[�^���Q�Ƃ��郁�\�b�h
		/// </summary>
		/// <param name = "gametexturenumber">�Q�[���e�N�X�`���[�f�[�^�ɓo�^���Ă���ԍ����w�肵�܂��B</param>
		const int& GetGameTextureData(int gametexturenumber);
		/// <summary>
		/// ���U���g�̃e�N�X�`���[�f�[�^���Q�Ƃ��郁�\�b�h
		/// </summary>
		/// <param name = "resulttexturenumber">���U���g�̃e�N�X�`���[�f�[�^�ɓo�^���Ă���ԍ����w�肵�܂��B</param>
		const int& GetResultTextureData(int resulttexturenumber);
		/// <summary>
		/// �����e�N�X�`���[���Q�Ƃ��郁�\�b�h
		/// </summary>
		/// <param name = "number">�����e�N�X�`���[�̔ԍ����w�肵�܂��B</param>
		const int& GetNumberTexture(int number);
	private:
		///<value>�^�C�g���̃e�N�X�`���[�f�[�^���Ǘ����Ă���z��</value>
		std::array<int,1> TitleTextureDataHandle_;
		///<value>�Q�[���̃e�N�X�`���[�f�[�^���Ǘ����Ă���z��</value>
		std::array<int,6> GameTextureDataHandle_;
		///<value>���U���g�̃e�N�X�`���[�f�[�^���Ǘ����Ă���z��</value>
		std::array<int,3> ResultTextureDataHandle_;
		///<value>�ԍ��̃e�N�X�`���[���Ǘ����Ă���z��</value>
		int NumberTexture_[10];
	};
}