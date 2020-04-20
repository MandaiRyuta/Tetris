#pragma once
//FpsCounter.h
//�Q�[���̃t���[�����[�g���Ǘ����Ă��܂��B

namespace FPS
{
	///<value> StartTime_�Ɣ�r���邽�߂�60�t���[�� </value>
	constexpr int Fps_N = 60;
	///<value> �ҋ@�t���[���̌v�Z���ɓ�������p�ł� </value>
	constexpr int FpsFrame = 60;

	class FpsCounter 
	{
	public:
		FpsCounter() {
			StartTime_ = 0;
			TimeCount_ = 0;
			Fps_ = 0;
		}
		~FpsCounter()
		{
			StartTime_ = 0;
			TimeCount_ = 0;
			Fps_ = 0;
		}
		/// <summary>
		/// �X�V���\�b�h
		/// </summary>
		void Update();
		/// <summary>
		/// �X�V���\�b�h
		/// <para>�f�o�b�O����FPS�\�������邽�߂̊֐��ł�</para>
		/// </summary>
		void Draw();
		/// <summary>
		/// �ҋ@���ԃ��\�b�h
		/// </summary>
		void WaitTime();
	private:
		///<value>�J�n����</value>
		unsigned int StartTime_;
		///<value>�t���[���J�E���g</value>
		unsigned int TimeCount_;
		///<value> Fps�\���p </value>
		float Fps_;
	};
}