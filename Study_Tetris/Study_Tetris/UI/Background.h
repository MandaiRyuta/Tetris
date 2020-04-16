#pragma once
#include "UI.h"

namespace TetrisUI
{
	class Background : public UI
	{
	public:
		Background(){}
		~Background() {}
	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void Draw() override;
		virtual void Release() override;
		virtual void LoadTexture(int handle, int texturenumber = 0) override;
	private:
		int BackGroundTexture_;
	};
}