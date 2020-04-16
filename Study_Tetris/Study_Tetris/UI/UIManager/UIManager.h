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
#include "../../Actor/Actor.h"
#include "../../Resource/TextureData.h"

namespace TetrisUI
{
	class UIManager : public Actor
	{
	public:
		UIManager();
		~UIManager();
	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void Draw() override;
		virtual void Release() override;
		static const int& GetTextureHandle(int type, int number);
		void SetType(int type);
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
		static TextureDataBase::TextureData texture_;
		std::array<UI*, 2> TitleObj_;
		std::array<UI*, 8> GameObj_;
		std::array<UI*, 4> ResultObj_;
	};
}