#pragma once
//Actor.h
//描画するオブジェクト用仮想クラス

class Initialize
{
public:
	/// <summary>
	/// 初期化メソッドの抽象化
	/// </summary>
	virtual void Init() = 0;
};
class Clear
{
public:
	/// <summary>
	/// 解放メソッドの抽象化
	/// </summary>
	virtual void Release() = 0;
};

class Actor :
	public Initialize,
	public Clear
{

public:
	/// <summary>
	/// 初期化メソッド
	/// </summary>
	virtual void Init() override {};
	/// <summary>
	/// 更新メソッドの抽象化
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// 描画メソッドの抽象化
	/// </summary>
	virtual void Draw() = 0;
	/// <summary>
	/// 解放メソッド
	/// </summary>
	virtual void Release() override {};
};