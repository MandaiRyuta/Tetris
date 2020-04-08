#pragma once
#include <DxLib.h>
#include <vector>
#include "../TetrisGameType/TetrisGameType.h"
#include "Time.h"
#include "Score.h"
#include "Particle.h"
#include "NextBlock.h"
#include "Menu.h"
#include "InGameState.h"
#include "Fade.h"
#include "Background.h"

//namespace TetrisUI
//{
	class UI
	{
	public:
		UI(){}
		virtual ~UI() {}
	public:
		virtual void Init() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;
		virtual void Release() = 0;
	};
//}