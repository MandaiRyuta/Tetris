#pragma once
#include "UI.h"

namespace TetrisUI
{
	class Particle : public UI
	{
	public:
		Particle() {}
		~Particle() {}
	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void Draw() override;
		virtual void Release() override;
	private:
		std::vector<char> texture_name_;
		std::vector<Vector2> position_;
		std::vector<Vector2> rotate_;
		std::vector<Vector2> scale_;
		std::vector<Color> color_;
	};
}