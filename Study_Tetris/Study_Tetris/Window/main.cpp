#include "main.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ApplicationManager app;

	bool loopscene = false;
	
	FPS::FpsCounter fps;
	
	ChangeWindowMode(TRUE);
	
	SetWaitVSyncFlag(FALSE);

	if (DxLib_Init() == -1)
	{
		return -1;
	}
	SetGraphMode(640, 480, 32);

	SetDrawScreen(DX_SCREEN_BACK);

	app.Init();
	int bg = 0;
	bg = LoadGraph("Background.png");
	while (!loopscene)
	{
		
		if (ProcessMessage() == -1)
		{
			break;
		}

		ClearDrawScreen();
		fps.Update();
		app.Update(&loopscene);
		DrawGraph(0, 0, bg, true);
		app.Draw();
		fps.Draw();
		fps.WaitTime();
		ScreenFlip();
	}

	app.Release();

	DxLib_End();

	return 0;
}