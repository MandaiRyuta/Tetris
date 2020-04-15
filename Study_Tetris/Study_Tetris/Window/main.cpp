#include "../App/ApplicationManager.h"
#include "../Fps/FpsCounter.h"
#include "../TetrisGameType/TetrisGameType.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	ApplicationManager* app;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	bool loopscene = false;

	FPS::FpsCounter fps;
	//TetrisUI::Background bg;
	ChangeWindowMode(TRUE);
	SetUse3DFlag(FALSE);
	SetWaitVSyncFlag(FALSE);
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetGraphMode(640, 480, 32);
	SetDrawScreen(DX_SCREEN_BACK);
	app = new ApplicationManager;
	app->Init();
	//bg.Init();
	
	while (!loopscene && ProcessMessage() == 0 /*&& CheckHandleASyncLoad(SceneTextureData->GetTitleTextureHandle(0))
		|| CheckHandleASyncLoad(SceneTextureData->GetGameTextureHandle(5))
		|| CheckHandleASyncLoad(SceneTextureData->GetResultTextureHandle(2))*/)
	{
		//if (loopscene)
		//{
		//	break;
		//}
		if (ProcessMessage() == -1)
		{
			break;
		}

		fps.Update();
		app->Update(loopscene);

		ClearDrawScreen();

		//bg.Draw();
		app->Draw();
		fps.Draw();
		DrawFormatString(0, 0, GetColor(0, 0, 0), "%d", GetGraphNum());
		fps.WaitTime();

		ScreenFlip();
	}

	//bg.Release();
	app->Release();
	delete app;
	DxLib_End();

	_CrtDumpMemoryLeaks();
	return 0;
}