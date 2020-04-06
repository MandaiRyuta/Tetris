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

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	// 描画先を裏画面にする
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
		// メッセージループに代わる処理をする
		if (ProcessMessage() == -1)
		{
			break;        // エラーが起きたらループを抜ける
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

	//DrawPixel(400, 240, GetColor(255, 255, 255));	// 点を打つ

	//WaitKey();				// キー入力待ち

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
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

