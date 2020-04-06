#include "main.h"

const float FRAME_TIME = 1.0f / 60.0f;
Scene Scenes;

void Init();
void Update(bool* loop,int *scenenum, bool *changescene);
void Draw();
void Release();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Scenes = SceneManager::GetInstance().GetScene(TetrisGameType::SCENETYPE::TITLE);
	int scene_num = 0;
	bool change_scene = false;
	bool loopscene = false;
	float frametime = 0;

	LONGLONG NowTime;
	LONGLONG Time;
	float X, Add;
	float DeltaTime;
	int FPS;
	int FPSCounter;
	LONGLONG FPSCheckTime;

	ChangeWindowMode(TRUE);
	
	SetWaitVSyncFlag(FALSE);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	// �`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	X = 0.0f;
	Add = 200.0f;
	NowTime = GetNowHiPerformanceCount();
	Time = GetNowHiPerformanceCount();
	DeltaTime = 0.000001f;
	FPSCheckTime = GetNowHiPerformanceCount();
	FPS = 0;
	FPSCounter = 0;
	
	Init();

	while (!loopscene)
	{
		// ���b�Z�[�W���[�v�ɑ��鏈��������
		if (ProcessMessage() == -1)
		{
			break;        // �G���[���N�����烋�[�v�𔲂���
		}

		X += Add * DeltaTime;
		if (X < 0.0f)
		{
			X = 0.0f;
			Add = -Add;
		}
		if (X > 640.0f)
		{
			X = 640.0f;
			Add = -Add;
		}

		ClearDrawScreen();

		Update(&loopscene, &scene_num, &change_scene);

		Draw();

		ScreenFlip();

		NowTime = GetNowHiPerformanceCount();

		DeltaTime = (NowTime - Time) / 1000000.0f;

		Time = NowTime;

		FPSCounter++;

		if (NowTime - FPSCheckTime > 1000000)
		{
			FPS = FPSCounter;
			FPSCounter = 0;
			FPSCheckTime = NowTime;
		}
	}

	Release();

	//DrawPixel(400, 240, GetColor(255, 255, 255));	// �_��ł�

	//WaitKey();				// �L�[���͑҂�

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}

void Init()
{
	Scenes.Init();
}

void Update(bool* loop,int* scenenum, bool* changescene)
{
	(*loop) = Scenes.GetLoop();
	switch (*scenenum)
	{
	case TetrisGameType::TITLESCENENUMBER:
		if ((*changescene) == true)
		{
			(*changescene) = false;
		}

		Scenes.Update();
		if (Scenes.GetSceneNumber() == TetrisGameType::GAMESCENENUMBER && (*changescene) == false)
		{
			Scenes.Release();
			Scenes = SceneManager::GetInstance().GetScene(TetrisGameType::SCENETYPE::GAME);
			Scenes.Init();
			(*scenenum) = TetrisGameType::GAMESCENENUMBER;
			(*changescene) = true;
		}
		break;
	case TetrisGameType::GAMESCENENUMBER:
		if ((*changescene) == true)
		{
			(*changescene) = false;
		}

		Scenes.Update();

		if (Scenes.GetSceneNumber() == TetrisGameType::RESULTSCENENUMBER && (*changescene) == false)
		{
			Scenes.Release();
			Scenes = SceneManager::GetInstance().GetScene(TetrisGameType::SCENETYPE::RESULT);
			Scenes.Init();
			(*scenenum) = TetrisGameType::RESULTSCENENUMBER;
			(*changescene) = true;
		}
		break;
	case TetrisGameType::RESULTSCENENUMBER:
		if ((*changescene) == true)
		{
			(*changescene) = false;
		}

		Scenes.Update();

		if (Scenes.GetSceneNumber() == TetrisGameType::TITLESCENENUMBER && (*changescene) == false)
		{
			Scenes.Release();
			Scenes = SceneManager::GetInstance().GetScene(TetrisGameType::SCENETYPE::TITLE);
			Scenes.Init();
			(*scenenum) = TetrisGameType::TITLESCENENUMBER;
			(*changescene) = true;
		}
		break;
	}
}

void Draw()
{
	Scenes.Draw();
}

void Release()
{
	Scenes.Release();
}

