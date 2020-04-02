#pragma once

namespace TetrisUI
{
	class UI
	{
	public:
		UI() {}
		~UI() {}
	public:
		virtual void Init() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;
		virtual void Release() = 0;
	};
}