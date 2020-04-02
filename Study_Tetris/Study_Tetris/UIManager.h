#pragma once
#include <vector>
#include "UI.h"

namespace TetrisUI
{
	class UIManager
	{
	public:
		UIManager();
		~UIManager();
	public:
		void Create();
		void UpdateAll();
		void DrawAll();
		void ReleaseAll();
	private:
		std::vector<UI> obj_;
	};
}