#pragma once
//SceneManager.h
//�e�V�[�����Ǘ����Ă��܂��B
#include "../Scene.h"
#include "../../TetrisGameType\TetrisGameType.h"

///<value> �V�[����A���Ő؂�ւ��Ȃ��ׂɍ��ꂽEnter�̓��͂𐧌����鐔�l�ł� </value>
constexpr int EnterInputMaxTime = 120;
class SceneManager
{
public:
	SceneManager() 
	{

	}
	~SceneManager() {}
	/// <summary>
	/// ���������\�b�h
	/// </summary>
	void Init();
	/// <summary> 
	/// �X�V���\�b�h
	/// </summary>
	void Update();
	/// <summary>
	/// �`�惁�\�b�h
	/// </summary>
	void Draw();
	/// <summary>
	/// ������\�b�h
	/// </summary>
	void Release();
	/// <summary>
	/// �V�[����؂�ւ��郁�\�b�h
	/// </summary>
	static void ChangeScene(TetrisGameType::SCENETYPE Type);
	/// <summary>
	/// �Q�[���̃X�R�A��ݒ肷�郁�\�b�h
	/// </summary>
	static void SetTotalScore(int score);
	/// <summary>
	/// ���U���g�V�[���Ńg�[�^���X�R�A���Q�Ƃ��郁�\�b�h
	/// <returns>�g�[�^���X�R�A��Ԃ��܂��B</returns>
	///</summary>
	static const int& GetTotalScore();
	/// <summary> 
	/// ���ݕ`�悵�Ă���V�[���̔ԍ����Q�Ƃ��郁�\�b�h
	/// </summary>
	static const TetrisGameType::SCENETYPE& GetNowScene();
private:
	///<value>�g�[�^���X�R�A���Ǘ����Ă��܂�</value>
	static int TotalScore_;
	///<value>���݂̃V�[���̃^�C�v�ł�</value>
	static TetrisGameType::SCENETYPE NowType_;
	///<value>�V�[���؂�ւ����Ɍ��݂̃V�[�����󂯎��p�ɍ���Ă܂��B</value>
	static TetrisGameType::SCENETYPE Type_;
	///<value>�V�[�����Ǘ����Ă��܂��B</value>
	static Scene* CurrentScene_;
	///<value>�V�[���؂�ւ����ɕK�v��Enter�̓��͂��Ǘ����Ă��܂��B</value>
	unsigned int EnterInputNowTime_[3];
};