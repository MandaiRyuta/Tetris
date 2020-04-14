#include "../App/ApplicationManager.h"
#include "../Fps/FpsCounter.h"
#include "../TetrisGameType/TetrisGameType.h"
#include "../UI/Background.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ApplicationManager app;

	bool loopscene = false;

	FPS::FpsCounter fps;
	TetrisUI::Background bg;
	ChangeWindowMode(TRUE);
	
	SetWaitVSyncFlag(FALSE);
	SetUseASyncLoadFlag(TRUE);
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetGraphMode(640, 480, 32);
	SetDrawScreen(DX_SCREEN_BACK);

	app.Init();
	bg.Init();

	while (!loopscene)
	{
		
		if (ProcessMessage() == -1)
		{
			break;
		}


		fps.Update();
		app.Update(loopscene);

		ClearDrawScreen();
		bg.Draw();
		app.Draw();
		fps.Draw();
		fps.WaitTime();
		ScreenFlip();
	}

	bg.Release();
	app.Release();

	DxLib_End();
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
	return 0;
}