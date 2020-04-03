#include "main.h"

Scene scenes;

void Init();
void Update(int *scenenum, bool *changescene);
void Draw();
void Release();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	scenes = SceneManager::GetInstance().GetScene(Utils::SCENETYPE::TITLE);
	int scene_num = 0;
	bool change_scene = false;
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	Init();

	while (1)
	{
		Update(&scene_num,&change_scene);
		Draw();
	}

	Release();

	//DrawPixel(400, 240, GetColor(255, 255, 255));	// 点を打つ

	//WaitKey();				// キー入力待ち

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

void Init()
{
	scenes.Init();
}

void Update(int* scenenum, bool* changescene)
{
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

