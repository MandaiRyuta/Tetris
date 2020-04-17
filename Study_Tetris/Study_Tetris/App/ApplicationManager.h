#pragma once
// ApplicationManager.h
// �A�v���P�[�V���������Ǘ�����N���X

#include "../TetrisGameType/TetrisGameType.h"
#include "../Scene\SceneManager/SceneManager.h"

class ApplicationManager
{
public:
	ApplicationManager();
	~ApplicationManager();
public:
	/// <summary>
	/// ���������\�b�h
	/// </summary>
	void Init();
	/// <summary>
	/// �X�V���\�b�h
	/// <param name="loop">loop�̃t���O���Q�Ƃł�</param>
	/// </summary>
	void Update(bool &loop);
	/// <summary> 
	/// �`�惁�\�b�h
	/// </summary>
	void Draw();
	/// <summary>�@
	/// ������\�b�h
	/// </summary>
	void Release();
	/// <summary>�@
	/// ���[�v�̃t���O�Q�ƃ��\�b�h
	/// <returns>���[�v�̃t���O��Ԃ��܂�</returns>
	/// </summary>
	const bool& GetLoop();
	/// <summary>
	/// ���[�v�̃t���O�ݒ胁�\�b�h
	/// </summary>
	static void SetLoop(signed short int loopselect);
private:
	/// <value> �S�ẴV�[�����Ǘ����Ă���}�l�[�W���[�ł� </value>
	SceneManager* SceneManager_;
	/// <value> �Q�Ƃ������[�v���󂯎��t���O�@0x000 = false 0x001 = true </value>
	static signed short int Loop_;
};