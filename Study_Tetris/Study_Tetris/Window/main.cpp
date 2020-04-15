#include "main.h"
#include "../App/ApplicationManager.h"
#include "../Fps/FpsCounter.h"
#include "../TetrisGameType/TetrisGameType.h"
#include "../UI/Background.h"

TextureDataBase::TextureData SceneTextureData;
BlockData BlcoksData;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ApplicationManager app;
	
	bool loopscene = false;

	FPS::FpsCounter fps;
	TetrisUI::Background bg;
	ChangeWindowMode(TRUE);
	
	SetWaitVSyncFlag(FALSE);
	SetUseASyncLoadFlag(FALSE);
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetGraphMode(640, 480, 32);
	SetDrawScreen(DX_SCREEN_BACK);

	//最終的にためしたところです。
	int scenetype = 0;
	SceneTextureData.Init();
	//データを読み込んだ後に、Ui/Background.cpp側のInitで呼び出します。

	BlcoksData.Init();
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