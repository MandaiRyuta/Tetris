#pragma once
#include "../Scene.h"
#include "../../TetrisGameType\TetrisGameType.h"

const int SCENEINDEX = 3;
class SceneManager
{
public:
	static SceneManager& GetInstance()
	{
		static SceneManager Inst;
		return Inst;
	}

	Scene& GetScene(TetrisGameType::SCENETYPE type)
	{
		const auto Index = static_cast<int>(type);
		Scenes_[Index].SetSceneNumber(Index);
		return Scenes_[Index];
	}

private:
	Scene Scenes_[SCENEINDEX];
};