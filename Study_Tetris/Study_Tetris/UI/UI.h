#pragma once
#include <DxLib.h>
#include <vector>

struct Vector2
{
	int x;
	int y;
};

struct Color
{
	int r;
	int g;
	int b;
	int a;
};

enum class BlockType
{
	I,
	J,
	L,
	O,
	S,
	T,
	Z,
	W,
};
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