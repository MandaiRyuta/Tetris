#include "main.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ApplicationManager app;
	//Scenes = SceneManager::GetInstance().GetScene(TetrisGameType::SCENETYPE::TITLE);
	int scene_num = 0;
	bool change_scene = false;
	bool loopscene = false;
	
	FPS::FpsCounter fps;
	//float frametime = 0;
	//
	//LONGLONG NowTime;
	//LONGLONG Time;
	//float X, Add;
	//float DeltaTime;
	//int FPS;
	//int FPSCounter;
	//LONGLONG FPSCheckTime;
	

	ChangeWindowMode(TRUE);
	
	SetWaitVSyncFlag(FALSE);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	// �`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	app.Init();

	while (!loopscene)
	{
		// ���b�Z�[�W���[�v�ɑ��鏈��������
		if (ProcessMessage() == -1)
		{
			break;        // �G���[���N�����烋�[�v�𔲂���
		}

		ClearDrawScreen();
		fps.Update();
		app.Update(&loopscene, &scene_num, &change_scene);
		fps.Draw();
		app.Draw();

		ScreenFlip();
		fps.WaitTime();
	}

	app.Release();

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}