#include "GameState.h"

/**
 * @fn
 * @brief �V�[�����؂�ւ��Ƃ��Ȃǂ̏������֐�
 * @param (score) �����̃X�R�A��
 */
void GameState::SetScore(unsigned int score)
{
	now_socre_ = score;
}
/**
 * @fn
 * @brief �X�R�A�̉��Z����ׂ̊֐�
 * @param (score) �����̃X�R�A��
 */
void GameState::AddScore(unsigned int score)
{
    now_socre_ += score;
}
/**
 * @fn
 * @brief ���݂̃X�R�A���󂯎��֐�
 * @return ���݂̃X�R�A
 */
unsigned int GameState::GetScore()
{
	return now_socre_;
}
/**
 * @fn
 * @brief �Q�[���̃|�[�Y��Ԃ��m�F����֐�
 * @return 0x000 �|�[�Y���ł͂Ȃ� 0x001 �|�[�Y���ł��� 
 */
signed short int GameState::GetGameState()
{
	return game_state_;
}
/**
 * @fn
 * @brief �|�[�Y��Ԃɐ؂�ւ���֐�
 * @return 0x000 �|�[�Y���ł͂Ȃ� 0x001 �|�[�Y���ł���
 */
void GameState::SetGameState(signed short int state)
{
	game_state_ = state;
}
/**
 * @fn
 * @brief�@�Q�[���̊J�n���I�����𔻒f����֐�
 * @return 0x000 �Q�[���̊J�n 0x001 �Q�[���̏I���@0x002 ����ȊO
 */
signed short int GameState::GetStartEndRoutine()
{
	return game_start_end_state_;
}
/**
 * @fn
 * @brief�@�Q�[���̊J�n�������͏I�����n�܂������ɐݒ肷��֐�
 * @return 0x000 �Q�[���̊J�n 0x001 �Q�[���̏I�� 0x002 ����ȊO
 */
void GameState::SetStartEndRoutine(signed short int state)
{
	game_start_end_state_ = state;
}
