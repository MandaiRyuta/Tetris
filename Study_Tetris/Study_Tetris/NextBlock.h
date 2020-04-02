#pragma once
#include "UI.h"

namespace TetrisUI
{
	class NextBlock : public UI
	{
	public:
		NextBlock(){}
		~NextBlock(){}
	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void Draw() override;
		virtual void Release() override;
		void SetNextBlockType(BlockType type);
		BlockType GetNextBlockType();
	private:
		BlockType type_;
	};
}