#pragma once
//UIManager.h
//画面に表示するすべてのUIを管理しているクラスです。
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
		/// <summary>
		/// 初期化メソッド
		/// </summary>
		virtual void Init() override;
		/// <summary>
		/// 更新メソッド
		/// </summary>
		virtual void Update() override;
		/// <summary>
		/// 描画メソッド
		/// </summary>
		virtual void Draw() override;
		/// <summary>
		/// 解放メソッド
		/// </summary>
		virtual void Release() override;
		/// <summary>
		/// テクスチャー情報を取得するメソッド
		/// </summary>
		/// <param name="type">シーンの番号</param>
		/// <param name="number">配列に格納しているテクスチャー番号</param>
		/// <returns>指定した画像のハンドル</returns>
		static const int& GetTextureHandle(int type, int number);
		/// <summary>
		/// シーンを指定するメソッド
		/// </summary>
		/// <param name="type">シーン番号</param>
		void SetType(int type);
		/// <summary>
		/// 全てのUIを初期化するメソッド
		/// </summary>
		void InitAll();
		/// <summary>
		/// 全てのUIを更新するメソッド
		/// </summary>
		void UpdateAll();
		/// <summary>
		/// 全てのUIを描画するメソッド
		/// </summary>
		void DrawAll();
		/// <summary>
		/// 全てのUIを解放するメソッド
		/// </summary>
		void ReleaseAll();
		/// <summary>
		/// UIを生成するメソッド
		/// </summary>
		template <class T>
		UI* Create()
		{
			UI* obj = new T;
			return  obj;
		}
	private:
		/// <value>シーン番号です</value>
		int SceneType_;
		/// <value>テクスチャーを管理しているクラスです</value>
		static TextureDataBase::TextureData texture_;
		/// <value>タイトルで使われるUIオブジェクトです</value>
		std::array<UI*, 2> TitleObj_;
		/// <value>ゲームで使われるUIオブジェクトです</value>
		std::array<UI*, 8> GameObj_;
		/// <value>リザルトで使われるUIオブジェクトです</value>
		std::array<UI*, 4> ResultObj_;
	};
}