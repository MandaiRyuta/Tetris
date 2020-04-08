#pragma once
#include "UI.h"

namespace TetrisUI
{
	class Hold : public UI
	{
	public:
		Hold();
		~Hold();
	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void Draw() override;
		virtual void Release() override;
		void BlockInit();
		static void GetHoldBlockType(int type)
		{
			HoldBlockType_ = type;
		}
	private:
		TetrisGameType::Block Blocktype_[TetrisGameType::TetrisBlockTypeNum::MaxNumber][TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		static int HoldBlockType_;
	};
}