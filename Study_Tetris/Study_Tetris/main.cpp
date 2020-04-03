#include "main.h"

const float FRAME_TIME = 1.0f / 60.0f;
Scene scenes;

void Init();
void Update(bool* loop,int *scenenum, bool *changescene);
void Draw();
void Release();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	scenes = SceneManager::GetInstance().GetScene(Utils::SCENETYPE::TITLE);
	int scene_num = 0;
	bool change_scene = false;
	bool loopscene = false;
	float frametime = 0;

	LONGLONG NowTime;
	LONGLONG Time;
	float x, add;
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

	x = 0.0f;
	add = 200.0f;
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

		x += add * DeltaTime;
		if (x < 0.0f)
		{
			x = 0.0f;
			add = -add;
		}
		if (x > 640.0f)
		{
			x = 640.0f;
			add = -add;
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
	scenes.Init();
}

void Update(bool* loop,int* scenenum, bool* changescene)
{
	(*loop) = scenes.GetLoop();

	if ((*scenenum) == static_cast<int>(Utils::SCENETYPE::TITLE))
	{
		if ((*changescene) == true)
		{
			(*changescene) = false;
		}

		scenes.Update();
		if (scenes.GetSceneNumber() == static_cast<int>(Utils::SCENETYPE::GAME) && (*changescene) == false)
		{
			scenes.Release();
			scenes = SceneManager::GetInstance().GetScene(Utils::SCENETYPE::GAME);
			scenes.Init();
			(*scenenum) = static_cast<int>(Utils::SCENETYPE::GAME);
			(*changescene) = true;
		}
	}
	if ((*scenenum) == static_cast<int>(Utils::SCENETYPE::GAME))
	{
		if ((*changescene) == true)
		{
			(*changescene) = false;
		}

		scenes.Update();

		if (scenes.GetSceneNumber() == static_cast<int>(Utils::SCENETYPE::RESULT) && (*changescene) == false)
		{
			scenes.Release();
			scenes = SceneManager::GetInstance().GetScene(Utils::SCENETYPE::RESULT);
			scenes.Init();
			(*scenenum) = static_cast<int>(Utils::SCENETYPE::RESULT);
			(*changescene) = true;
		}
	}
	if ((*scenenum) == static_cast<int>(Utils::SCENETYPE::RESULT))
	{
		if ((*changescene) == true)
		{
			(*changescene) = false;
		}

		scenes.Update();

		if (scenes.GetSceneNumber() == static_cast<int>(Utils::SCENETYPE::TITLE) && (*changescene) == false)
		{
			scenes.Release();
			scenes = SceneManager::GetInstance().GetScene(Utils::SCENETYPE::TITLE);
			scenes.Init();
			(*scenenum) = static_cast<int>(Utils::SCENETYPE::TITLE);
			(*changescene) = true;
		}
	}
}

void Draw()
{
	scenes.Draw();
}

void Release()
{
	scenes.Release();
}

