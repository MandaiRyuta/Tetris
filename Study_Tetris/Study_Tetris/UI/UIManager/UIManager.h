#pragma once
#include <vector>
#include "../../TetrisGameType/TetrisGameType.h"
#include "../NextBlock.h"
#include "../UI.h"

namespace TetrisUI
{
	class UIManager
	{
	public:
		UIManager();
		~UIManager();
	public:
		template<class T>
		T* Create();
		void UpdateAll();
		void DrawAll();
		void ReleaseAll();
	private:
		std::vector<UI*> obj_;
	};
	template<class T>
	inline T* UIManager::Create()
	{
		T* obj = new T;
		return obj;
	}
}