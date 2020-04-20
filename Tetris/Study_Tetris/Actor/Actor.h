#pragma once
//Actor.h
//�`�悷��I�u�W�F�N�g�p���z�N���X

class Initialize
{
public:
	/// <summary>
	/// ���������\�b�h�̒��ۉ�
	/// </summary>
	virtual void Init() = 0;
};
class Clear
{
public:
	/// <summary>
	/// ������\�b�h�̒��ۉ�
	/// </summary>
	virtual void Release() = 0;
};

class Actor :
	public Initialize,
	public Clear
{

public:
	/// <summary>
	/// ���������\�b�h
	/// </summary>
	virtual void Init() override {};
	/// <summary>
	/// �X�V���\�b�h�̒��ۉ�
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// �`�惁�\�b�h�̒��ۉ�
	/// </summary>
	virtual void Draw() = 0;
	/// <summary>
	/// ������\�b�h
	/// </summary>
	virtual void Release() override {};
};