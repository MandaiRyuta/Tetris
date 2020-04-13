#pragma once
#include "UI.h"

namespace TetrisUI
{
	namespace GameState
	{
		constexpr int GameClear = 1;
		constexpr int GameOver = 2;
	}
	class InGameState : public UI
	{
	public:
		InGameState() : GameClearTexture_(0), GameOverTexture_(0), NextSceneCount_(0){}
		~InGameState() {}
	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void Draw() override;
		virtual void Release() override;

		static int GetGameState();
		static void SetGameState(int state);
	private:
		int GameClearTexture_;
		int GameOverTexture_;
		static int GameState_;
		int NextSceneCount_;
	};
}