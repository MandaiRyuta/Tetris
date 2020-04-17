#pragma once
// TetrisBlock.h
// �e�g���X�̃u���b�N���Ǘ����Ă���N���X�ł�
#include "../TetrisGameType/TetrisGameType.h"
#include "../Resource/Block.h"
namespace TetrisBlocks
{
	class TetrisBlock
	{
	public:
		TetrisBlock() :
			Blocknumber_(0),
			//Input_(nullptr),
			Type_(TetrisGameType::BlockType::I),
			BlockDoneCheck_(0x000),
			DownMoveAcceleration_(0),
			DownMoveCheck_(0x000),
			DownMoveMaxTime_(10),
			DownMoveNowTime_(0),
			SpaceDownCheck_(0x000),
			SpaceDownMaxTime_(15),
			SpaceDownNowTime_(0),
			RotateNowTime_(0),
			RotateMaxTime_(10),
			BlockDownCheck_(0x000),
			YblockCount_(0),
			Collision_(0),
			MakeBlock_(0x000),
			CheckBlock_(0x000),
			Blockdown_(0x000),
			LeftCollision_(false),
			RightCollision_(false),
			BottomCollision_(false),
			SpaceBarRefreshNowTime_(0),
			SpaceBarRefreshMaxTime_(15),
			SpaceBarRefreshCheck_(0x000),
			SideSpeed_(1),
			InputDownMoveCheck_(0x000),
			InputDownMoveMaxTime_(1),
			InputDownMoveNowTime_(0),
			SwapHoldBlockType_(9),
			HoldCheck_(0x000),
			HoldStockCheck_(1),
			BreakStockCheck_(0x000),
			GameBlockLevelFrame_(0),
			ChangeKeyStateCount_(0),
			WaitMakeBlcokTime_(0)
		{
			Position_.y = 0;
			Position_.x = 4;
			GameBlockState_ = 0;
		}
		~TetrisBlock(){}
	public:
		/// <summary>
		/// �z�[���h���Ă���u���b�N�̌`���m�点�郁�\�b�h
		/// </summary>
		/// <returns>�u���b�N�̌`��</returns>
		const int& GetHoldBlockType();
		/// <summary>
		/// �u���b�N�̕`�惁�\�b�h
		/// </summary>
		/// <param name="type">�u���b�N�̌`��</param>
		/// <param name="vertical">�u���b�N�̏c��</param>
		/// <param name="side">�u���b�N�̉���</param>
		/// <param name="positionX">���삵�Ă�����WX</param>
		/// <param name="positionY">���삵�Ă�����WY</param>
		void DrawBlock(int type, int vertical, int side, int positionX, int positionY);
		/// <summary>
		/// �u���b�N����]�����郁�\�b�h
		/// </summary>
		void ChangeRotate();
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
		/// �u���b�N���X�g�b�N�����郁�\�b�h
		/// </summary>
		void StockBlock();
		/// <summary>
		/// �X�g�b�N���Ă���u���b�N�̏��Ԃ�O�ɂ��炵�čŌ�ɐV�����������郁�\�b�h
		/// </summary>
		void SwapBlock();
		/// <summary>
		/// ���삵�Ă���X���W���󂯎�郁�\�b�h
		/// </summary>
		/// <returns>���삵�Ă���X���W</returns>
		const int& GetXBlockPosition();
		/// <summary>
		/// ���삵�Ă���Y���W�̃��\�b�h
		/// </summary>
		/// <returns>���삵�Ă���Y���W</returns>
		const int& GetYblockPosition();
		/// <summary>
		/// ���ݑ��삵�Ă���u���b�N�̌`���m�点�郁�\�b�h
		/// </summary>
		/// <returns>���ݑ��삵�Ă���u���b�N�̌`��</returns>
		const int& GetBlockType();
		/// <summary>
		/// �u���b�N�̃f�[�^���X�e�[�W�̔z�u�ɓ���郁�\�b�h
		/// </summary>
		/// <param name="data">���삵�Ă���u���b�N�̌`��</param>
		/// <param name="x">���삵�Ă���X���W</param>
		/// <param name="y">���삵�Ă���Y���W</param>
		void SetBlockData(int data, int x, int y);
		/// <summary>
		/// �X�e�[�W���ɔz�u���ꂽ�u���b�N���m�F���郁�\�b�h
		/// </summary>
		/// <param name="x">���삵�Ă���X���W</param>
		/// <param name="y">���삵�Ă���Y���W</param>
		/// <returns>�X�e�[�W�ɔz�u����Ă���u���b�N:1~7�������͋�:0 ���</returns>
		const int& GetBlockData(int x, int y);
		/// <summary>
		/// �X�e�[�W���ő��삵�Ă���u���b�N�̍����̏Փ˔��胁�\�b�h
		/// </summary>
		void StageBlockCollisionLeft();
		/// <summary>
		/// �X�e�[�W���ő��삵�Ă���u���b�N�̉E���̏Փ˔��胁�\�b�h
		/// </summary>
		void StageBlockCollisionRight();
		/// <summary>
		/// �X�e�[�W���ő��삵�Ă���u���b�N�̉����̏Փ˔��胁�\�b�h
		/// </summary>
		void StageBlockCollisionBottom();
		/// <summary>
		/// �X�e�[�W���ő��삵�Ă���u���b�N�ƃX�e�[�W���ɔz�u���Ă���u���b�N�̗L�����m�F����Փ˔��胁�\�b�h
		/// </summary>
		void StageBlockCollisionCenter();
		/// <summary>
		/// �u���b�N�̉�]���Ɋm�F���郁�\�b�h
		/// </summary>
		void BlockCollisionTurn();
		/// <summary>
		/// �u���b�N��V������蒼�����\�b�h
		/// </summary>
		void MakeBlock();
		/// <summary>
		/// �X�g�b�N�����u���b�N�����擾���郁�\�b�h
		/// </summary>
		/// <param name="num">�z��ԍ�0 ~ 3�܂łł��B</param>
		/// <returns>�u���b�N�̌`��</returns>
		const int& GetStockBlock(int num);
		/// <summary>
		/// �u���b�N��Space�{�^�����g���ė��Ƃ��Ă��邩�ǂ������m�F���郁�\�b�h
		/// </summary>
		/// <returns>���������������ł͂Ȃ����m�F����t���O�@0x000 : �������Ă��Ȃ�, 0x001 :�@������</returns>
		const signed short int& GetBlockDone();
		/// <summary>
		/// ���삵�Ă���u���b�N�𗎉������郁�\�b�h
		/// </summary>
		/// <param name="blockdonecheck">�u���b�N�𗎉��������ۂɐ؂�ւ���t���O</param>
		void SetBlockDone(signed short int blockdonecheck);
		/// <summary>
		/// �Q�[�����ł̓��͑���̃X�e�[�g�Ǘ����\�b�h
		/// </summary>
		void GameInputState();
		/// <summary>
		/// ���͂����Ĉ��t���[���̊Ԃ̓��͏������\�b�h
		/// </summary>
		/// <param name="leftkeyframe">���{�^�������������̃t���[����</param>
		/// <param name="rightkeyframe">�E�{�^�������������̃t���[����</param>
		void InputStateFirst(int& leftkeyframe,int& rightkeyframe);
		/// <summary>
		/// ���͂����Ĉ��t���[���̊Ԃ̓��̓��\�b�h
		/// </summary>
		/// <param name="leftkeyframe">���{�^�������������̃t���[����</param>
		/// <param name="rightkeyframe">�E�{�^�������������̃t���[����</param>
		void InputStateSecond(int& leftkeyframe, int& rightkeyframe);
		/// <summary>
		/// ���{�^�����͂̃��\�b�h
		/// </summary>
		void GameInputRight();
		/// <summary>
		/// �E�{�^�����͂̃��\�b�h
		/// </summary>
		void GameInputLeft();
		/// <summary>
		/// ���Ԍo�߂ɂ���ė������Ă����X�e�[�g���Ǘ����郁�\�b�h
		/// </summary>
		void GameBlockDownState();
		/// <summary>
		/// �o�ߎ��Ԃɂ���ė������鑬�x���𒲐����Ă��郁�\�b�h
		/// </summary>
		/// <param name="frame">�o�ߎ���</param>
		void GameBlockDownFirst(int& frame);
		/// <summary>
		/// �o�ߎ��Ԃɂ���ė������鑬�x���𒲐����Ă��郁�\�b�h
		/// </summary>
		/// <param name="frame">�o�ߎ���</param>
		void GameBlockDownSecond(int& frame);
		/// <summary>
		/// �o�ߎ��Ԃɂ���ė������鑬�x���𒲐����Ă��郁�\�b�h
		/// </summary>
		/// <param name="frame">�o�ߎ���</param>
		void GameBlockDownThird(int& frame);
	private:
		/// <value>���݂̃u���b�N���z�[���h�ɓ����ۂɎg���܂�</value>
		int SwapHoldBlockType_;
		/// <value>�z�[���h���Ă��邩�m�F����t���O�ł�</value>
		signed short int HoldCheck_;
		/// <value>�z�[���h�̃X�g�b�N���m�F����t���O�ł�</value>
		signed short int HoldStockCheck_;
		/// <value>�X�g�b�N�����݂����ۂɏ��������ǂ������m�F����t���O�ł�</value>
		signed short int BreakStockCheck_;
		/// <value>�X�g�b�N����u���b�N�̔z��ł�</value>
		std::array<int, 4> StockBlocks_;
		/// <value>�X�e�[�W���̃u���b�N���z�u�ł���c�̒������m�F���܂�</value>
		int YblockCount_;
		/// <value>�X�y�[�X�����������m�F����t���O�ł�</value>
		signed short int SpaceDownCheck_;
		/// <value>[��]�L�[�����������m�F����t���O�ł�</value>
		signed short int InputDownMoveCheck_;
		/// <value>[��]�L�[�������ē����Ă��邩�m�F����t���O�ł�</value>
		signed short int DownMoveCheck_;
		/// <value>[Space]�L�[�������ė��������Ă��邩�m�F����t���O�ł�</value>
		signed short int BlockDownCheck_;
		/// <value>[��]�L�[�������ĉ�]���Ă��邩�m�F����t���O�ł�</value>
		signed short int BlockRotateCheck_;
		/// <value>[Space]�L�[�����������m�F����t���O�ł�</value>
		signed short int BlockDoneCheck_;
		/// <value>[Space]�L�[���Ďg�p�ł���܂ł̎��Ԃł�</value>
		signed short int SpaceBarRefreshCheck_;
		/// <value>�u���b�N�̐����t���O�ł�</value>
		signed short int MakeBlock_;
		/// <value>��ӂɒu����Ă���u���b�N�̊m�F�p�̃t���O�ł�</value>
		signed short int BottomBlockCheck_;
		/// <value>��ӂɃu���b�N��z�u�����ۂɐ؂�ւ��t���O�ł�</value>
		signed short int CheckBlock_;
		/// <value>�u���b�N���������Ȃ̂��m�F����t���O�ł�</value>
		signed short int Blockdown_;
		/// <value>�����̃u���b�N����t���O�ł�</value>
		bool LeftCollision_;
		/// <value>�E���̔���t���O�ł�</value>
		bool RightCollision_;
		/// <value>��ӂ̔���t���O�ł�</value>
		bool BottomCollision_;
		/// <value>[Space]�L�[�������Ă���J�E���g����錻�݂̎��Ԃł�</value>
		int SpaceBarRefreshNowTime_;
		/// <value>[Space]�L�[�������Ă���ēx�g�p�ł���܂ł̎��Ԃł�</value>
		int SpaceBarRefreshMaxTime_;
		/// <value>[��]�L�[�������Ă���J�E���g����鎞�Ԃł�</value>
		int RotateNowTime_;
		/// <value>[��]�L�[�������Ă���ēx��]�ł��鎞�Ԃł�</value>
		int RotateMaxTime_;
		/// <value>�u���b�N�����Ɉړ����Ă��鎞�ɃJ�E���g����鎞�Ԃł�</value>
		int DownMoveNowTime_;
		/// <value>[��]�L�[�������Ă���J�E���g����鎞�Ԃł�</value>
		int InputDownMoveNowTime_;
		/// <value>[��]�L�[�������Ĉړ�����܂ł̍ő厞�Ԃł�</value>
		int LeftMoveMaxTime_;
		/// <value>[��]�L�[�������Ĉړ�����܂ł̍ő厞�Ԃł�</value>
		int RightMoveMaxTime_;
		/// <value>�u���b�N�����Ɉړ������邽�߂̍ő厞�Ԃł�</value>
		int DownMoveMaxTime_;
		/// <value>[��]�L�[�����������Ɉړ�������܂ł̍ő厞�Ԃł�</value>
		int InputDownMoveMaxTime_;
		/// <value>[��]�L�[�����������ɉ���������ő厞�Ԃł�</value>
		int DownMoveAcceleration_;
		/// <value>�u���b�N�̌`���m�点�܂�</value>
		int Blocknumber_;
		/// <value>�u���b�N�̂��ׂĂ̌`��ƐF���܂܂�Ă���N���X�ł�</value>
		BlockData BlocksData_;
		/// <value>���݂�X,Y���W�ł�</value>
		TetrisGameType::Vector2 Position_;
		/// <value>�u���b�N�̌`����w�肵�܂�</value>
		TetrisGameType::BlockType Type_;
		/// <value>�S�Ẵu���b�N���i�[����z��ł�</value>
		TetrisGameType::Block Blocktype_[TetrisGameType::TetrisBlockTypeNum::MaxNumber][TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		/// <value>���삵�Ă���u���b�N���R�s�[����z��ł�</value>
		int CopyBlock_[TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		/// <value>�X�e�[�W�̃u���b�N��z�u����͈͂ɂȂ�܂�</value>
		int Board_[TetrisGameType::StageHeight][TetrisGameType::StageWidth];
		/// <value>[Space]�L�[�������Ă��甽��������܂ł̍ő厞�Ԃł�</value>
		int SpaceDownMaxTime_;
		/// <value>[Space]�L�[���������Ƃ��ɃJ�E���g����鎞�Ԃł�</value>
		int SpaceDownNowTime_;
		/// <value>����p�̕ϐ��ł�</value>
		int Collision_;
		/// <value>�u���b�N����]�����ۂɕۊǂ���z��ł�</value>
		TetrisGameType::Color TurnColor_[TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		/// <value>���삵�Ă���u���b�N�̌`���������z��ł�</value>
		int DrawBlock_[TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		/// <value>���삵�Ă���u���b�N�̐F��������z��ł�</value>
		TetrisGameType::Color DrawBlockColor_[TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		/// <value>�u���b�N����]�����ۂɐF��⊮����z��ł�</value>
		int TurnBlock_[TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		/// <value>���E�̈ړ��ʂł�</value>
		int SideSpeed_;
		/// <value>[��][��]�����������ɐ؂�ւ��܂�</value>
		int InputSideCheck_;
		/// <value>�{�^���������ăX�e�[�g��؂�ւ���Ƃ��Ɏg���܂�</value>
		int ChangeKeyStateCount_;
		/// <value>[��]�{�^�������������ɃJ�E���g����܂�</value>
		int LeftKeyFrame_;
		/// <value>[��]�{�^�������������ɃJ�E���g����܂�</value>
		int RightKeyFrame_;
		/// <value>�{�^���������Đ��b�o�߂���x�ɐ؂�ւ��X�e�[�g�ł��A�{�^���𗣂�����X�e�[�g�������l�ɖ߂�܂�</value>
		int InputState_;
		/// <value>�u���b�N�̈ړ��ʂł�</value>
		int BlockMoveSpeed_;
		/// <value>�Q�[�����̃u���b�N�̗����鑬�x���A���ԂŊǗ����Ă�����̂ł�</value>
		int GameBlockLevelFrame_;
		/// <value>�Q�[�����̃u���b�N�̗����鑬�x���R�i�K�ŊǗ����Ă܂��B</value>
		int GameBlockState_;
		/// <value>�u���b�N����ӂɒ��n���Ă���V�����u���b�N�������܂ł̎��Ԃł��B</value>
		int WaitMakeBlcokTime_;
	};
}