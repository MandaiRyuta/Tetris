#pragma once
#include <array>
#include "../../TetrisGameType/TetrisGameType.h"
#include "../NextBlock.h"
#include "../Hold.h"
#include "../Time.h"
#include "../Score.h"
#include "../Number.h"
#include "../InGameState.h"
#include "../Fade.h"
#include "../Background.h"

#include "../UI.h"

namespace TetrisUI
{
	class UIManager
	{
	public:
		UIManager(int scenetype);
		~UIManager();
	public:
		void InitAll();
		void UpdateAll();
		void DrawAll();
		void ReleaseAll();
		template <class T>
		UI* Create()
		{
			UI* obj = new T;
			return  obj;
		}
	private:
		int SceneType_;
		std::array<UI*, 2> TitleObj_;
		std::array<UI*, 8> GameObj_;
		std::array<UI*, 4> ResultObj_;
	};
}