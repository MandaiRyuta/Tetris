#pragma once
#include "Scene.h"

enum class SCENETYPE
{
	TITLE,
	GAME,
	RESULT,
	NONE,
};


class SceneManager
{
public:
	static SceneManager& GetInstance()
	{
		static SceneManager Inst;
		return Inst;
	}

private:
	Scene Scenes[3];
};