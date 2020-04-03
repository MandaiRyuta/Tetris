#pragma once
#include "Scene.h"
#include "Utils.h"

class SceneManager
{
public:
	static SceneManager& GetInstance()
	{
		static SceneManager Inst;
		return Inst;
	}

	Scene& GetScene(Utils::SCENETYPE type)
	{
		Scenes[static_cast<int>(type)].SetSceneNumber(static_cast<int>(type));
		return Scenes[static_cast<int>(type)];
	}

private:
	Scene Scenes[3];
};