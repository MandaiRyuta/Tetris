#include "../TetrisGameType/TetrisGameType.h"
#ifndef DEBUGCHECK
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "../App/ApplicationManager.h"
#include "../Fps/FpsCounter.h"
#include "../TetrisGameType/TetrisGameType.h"
#else
#include "../App/ApplicationManager.h"
#include "../Fps/FpsCounter.h"
#include "../TetrisGameType/TetrisGameType.h"
#endif //!DEBUGCHECK

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
#ifndef DEBUGCHECK
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif //!DEBUGCHECK
	ApplicationManager* app;
	bool loopscene = false;

	FPS::FpsCounter fps;
	
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
	
	while (ProcessMessage() == 0 && TetrisUI::UIManager::GetTextureHandle(0,0) || TetrisUI::UIManager::GetTextureHandle(1,5) || TetrisUI::UIManager::GetTextureHandle(2,2))
	{
		if (loopscene)
		{
			break;
		}
		if (ProcessMessage() == -1)
		{
			break;
		}

		fps.Update();
		app->Update(loopscene);

		ClearDrawScreen();

		app->Draw();
		fps.Draw();

		fps.WaitTime();

		ScreenFlip();
	}

	app->Release();
	delete app;
	DxLib_End();
#ifndef DEBUGCHECK
	_CrtDumpMemoryLeaks();
#endif //!DEBUGCHECK
	return 0;
}