#include "main.h"

int SceneNum = 0;

void Init();
void Update();
void Draw();
void Release();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Scene scene;

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	Init();

	while (1)
	{
		Update();
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
	SceneManager::GetInstance().GetScene(Utils::SCENETYPE::TITLE).Init();
	SceneManager::GetInstance().GetScene(Utils::SCENETYPE::GAME).Init();
	SceneManager::GetInstance().GetScene(Utils::SCENETYPE::RESULT).Init();

	SceneNum = SceneManager::GetInstance().GetScene(Utils::SCENETYPE::TITLE).GetSceneNumber();
}

void Update()
{
	if (SceneNum == static_cast<int>(Utils::SCENETYPE::TITLE))
	{
		SceneManager::GetInstance().GetScene(Utils::SCENETYPE::TITLE).Update();
	}
	if (SceneNum == static_cast<int>(Utils::SCENETYPE::GAME))
	{
		SceneManager::GetInstance().GetScene(Utils::SCENETYPE::GAME).Update();
	}
	if (SceneNum == static_cast<int>(Utils::SCENETYPE::RESULT))
	{
		SceneManager::GetInstance().GetScene(Utils::SCENETYPE::RESULT).Update();
	}
}

void Draw()
{
	if (SceneNum == static_cast<int>(Utils::SCENETYPE::TITLE))
	{
		SceneManager::GetInstance().GetScene(Utils::SCENETYPE::TITLE).Draw();
	}
	if (SceneNum == static_cast<int>(Utils::SCENETYPE::GAME))
	{
		SceneManager::GetInstance().GetScene(Utils::SCENETYPE::GAME).Draw();
	}
	if (SceneNum == static_cast<int>(Utils::SCENETYPE::RESULT))
	{
		SceneManager::GetInstance().GetScene(Utils::SCENETYPE::RESULT).Draw();
	}
}

void Release()
{
	SceneManager::GetInstance().GetScene(Utils::SCENETYPE::TITLE).Release();
	SceneManager::GetInstance().GetScene(Utils::SCENETYPE::GAME).Release();
	SceneManager::GetInstance().GetScene(Utils::SCENETYPE::RESULT).Release();
}

