#pragma once
#include <DxLib.h>
#include "../TetrisGameType/TetrisGameType.h"

namespace TetrisUI
{
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
		virtual void LoadTexture(int handle, int texturenumber = 0) = 0;
	};
}