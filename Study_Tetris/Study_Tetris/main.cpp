#include "main.h"

int SceneNum = 0;

void Init();
void Update();
void Draw();
void Release();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Scene scene;

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	Init();

	while (1)
	{
		Update();
		Draw();
	}

	Release();

	//DrawPixel(400, 240, GetColor(255, 255, 255));	// �_��ł�

	//WaitKey();				// �L�[���͑҂�

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
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

