#pragma once
#include "../TetrisGameType\TetrisGameType.h"
#include "../TetrisBlock\BlockCollection\BlockCollection.h"
#include "../UI/UIManager/UIManager.h"
#include "../Resource/TextureData.h"
#include "../Resource/Block.h"

class GameObjectFactory
{
public:

	//template<class T>
	//static TextureDataBase::TextureData* CreateTexture()
	//{
	//	TextureDataBase::TextureData* obj = new T;
	//	return obj;
	//}

	template<class T>
	static TetrisUI::UIManager* CreateUI(int number)
	{
		TetrisUI::UIManager* obj = new T(number);
		return obj;
	}

	template<class T>
	static TetrisBlocks::BlockCollection* CreateBlock()
	{
		TetrisBlocks::BlockCollection* obj = new T;
		return obj;
	}

	template<class T>
	static BlockData* CreateBlockData()
	{
		BlockData* obj = new T;
		return obj;
	}
	
	template<class T>
	static TetrisBlocks::TetrisBlock* CreateTetorisBlock()
	{
		TetrisBlocks::TetrisBlock* obj = new T;
		return obj;
	}
};