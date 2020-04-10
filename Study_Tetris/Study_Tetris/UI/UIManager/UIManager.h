#pragma once
#include <vector>
#include "../../TetrisGameType/TetrisGameType.h"
#include "../Background.h"
#include "../NextBlock.h"
#include "../Hold.h"
#include "../Time.h"
#include "../Score.h"
#include "../Number.h"
#include "../InGameState.h"

//#include "Particle.h"
//#include "NextBlock.h"
//#include "Menu.h"
//#include "InGameState.h"
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
		T* Create();
		void InitAll();
		void UpdateAll();
		void DrawAll();
		void ReleaseAll();
	private:
		std::vector<UI*> Obj_;
	};
	template<class T>
	inline T* UIManager::Create()
	{
		T* obj = new T;
		return obj;
	}
}