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

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	// 描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	app.Init();

	while (!loopscene)
	{
		// メッセージループに代わる処理をする
		if (ProcessMessage() == -1)
		{
			break;        // エラーが起きたらループを抜ける
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

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}