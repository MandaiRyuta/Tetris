#include "main.h"

const float FRAME_TIME = 1.0f / 60.0f;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ApplicationManager app;
	//Scenes = SceneManager::GetInstance().GetScene(TetrisGameType::SCENETYPE::TITLE);
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
	
	//Init();
	app.Init();

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

		app.Update(&loopscene, &scene_num, &change_scene);

		app.Draw();

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

	app.Release();

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}