#pragma once
#include "UI.h"

namespace TetrisUI
{
	class Background : public UI
	{
	public:
		Background() {}
		~Background() {}
	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void Draw() override;
		virtual void Release() override;
	private:
		std::vector<char> backgroundtexture_;
		std::vector<Vector2> position_;
		std::vector<Vector2> scale_;
		std::vector<Color> color_;
	};
}