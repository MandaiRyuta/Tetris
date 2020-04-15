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

#include "../UI.h"

namespace TetrisUI
{
	class UIManager
	{
	public:
		UIManager(int scenetype);
		~UIManager();
	public:
		template<class T>
		UI* Create() {
			T* obj = new T;
			return obj;
		}
		void InitAll();
		void UpdateAll();
		void DrawAll();
		void ReleaseAll();
	private:
		std::array<UI*, 7> Obj_;
	};
}