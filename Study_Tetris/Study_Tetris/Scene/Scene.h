#pragma once
//Scene.h
//�V�[�����Ǘ����Ă���N���X�ł��B
#include <algorithm>
#include <vector>
#include <iterator>
#include <deque>
#include <list>
#include "../TetrisGameType\TetrisGameType.h"
#include "../TetrisBlock\BlockCollection\BlockCollection.h"
#include "../UI/UIManager/UIManager.h"
#include "../Actor/Actor.h"

class Scene
{
public:
	Scene(int type);
	~Scene();
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
	/// �|�[�Y���̉�ʕ`������Ă��郁�\�b�h
	/// </summary>
	void PauseDraw();
	/// <summary>
	/// �|�[�Y���̑I�����Ǘ����Ă��郁�\�b�h
	/// </summary>
	void PauseSelect();
	/// <summary>
	/// �O���Ő������ꂽScene��Ui��ǉ����郁�\�b�h
	/// </summary>
	template<class T>
	void AddUIObject(int scenetype);
	/// <summary>
	/// �O���Ő������ꂽScene�ŃQ�[���̃u���b�N��ǉ����郁�\�b�h
	/// </summary>
	template<class T>
	void AddBlockObject();
private:
	/// <summary>
	/// �������[��������郁�\�b�h
	/// <param name="vector">T�^�ō��ꂽstd::vector���Q�Ƃ��܂��B</param>
	/// </summary>
	void ObjectReleaseMemory();
private:
	/// <value>Enter�L�[�̓��͂��ł���܂ł̑ҋ@���Ԃł�</value>
	int EnterKeyMaxTime_;
	/// <value>���݂̃t���[������</value>
	int EnterKeyNowTime_;
	/// <value>[��]�L�[�̓��͂��ł���܂ł̑ҋ@���Ԃł�</value>
	int UpArrowKeyMaxTime_;
	/// <value>���݂̃t���[������</value>
	int UpArrowKeyNowTime_;
	/// <value>[��]�L�[�̓��͂��ł���܂ł̑ҋ@���Ԃł�</value>
	int DownArrowKeyMaxTime_;
	/// <value>���݂̃t���[������</value>
	int DownArrowKeyNowTime_;
	/// <value>���j���[�̑I��ԍ��ł��B</value>
	int MenuSelectNumber_;
	/// <value>[P]�L�[�̓��͂��ł���܂ł̑ҋ@���Ԃł�</value>
	int PauseKeyMaxTime_;
	/// <value>���݂̃t���[�����Ԃł�</value>
	int PauseKeyNowTime_;
	/// <value>�|�[�Y�̃t���O�ł��@�@�@ 1 : �|�[�Y�����@-1 : �|�[�Y�J�n</value>
	int Pause_;
	/// <value>�V�[���̔ԍ��ł��B</value>
	int Scenenumber_;
	/// <value>�^�C�g���œ���̕�����_�ł����邽�߂ɍ���Ă܂��B</value>
	int TitleDrawTime_;
	/// <value>UiManager�N���X��BlockCollection�N���X���܂߂�ׂɍ��ꂽ�z��ł�</value>
	std::vector<Actor*> Actor_;
};

template<class T>
inline void Scene::AddUIObject(int scenetype)
{
	TetrisUI::UIManager* obj = new T;
	obj->SetType(scenetype);
	Actor_.push_back(obj);
}

template<class T>
inline void Scene::AddBlockObject()
{
	TetrisBlocks::BlockCollection* obj = new T;
	Actor_.push_back(obj);
}

inline void Scene::ObjectReleaseMemory()
{
	for (int i = 0; i < Actor_.size(); ++i)
	{
		delete Actor_[i];
	}
	Actor_.clear();
}
