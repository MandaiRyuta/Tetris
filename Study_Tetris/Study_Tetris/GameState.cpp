#include "GameState.h"

/**
 * @fn
 * @brief シーンが切り替わるときなどの初期化関数
 * @param (score) 初期のスコア数
 */
void GameState::SetScore(unsigned int score)
{
	now_socre_ = score;
}
/**
 * @fn
 * @brief スコアの加算する為の関数
 * @param (score) 初期のスコア数
 */
void GameState::AddScore(unsigned int score)
{
    now_socre_ += score;
}
/**
 * @fn
 * @brief 現在のスコアを受け取る関数
 * @return 現在のスコア
 */
unsigned int GameState::GetScore()
{
	return now_socre_;
}
/**
 * @fn
 * @brief ゲームのポーズ状態を確認する関数
 * @return 0x000 ポーズ中ではない 0x001 ポーズ中である 
 */
signed short int GameState::GetGameState()
{
	return game_state_;
}
/**
 * @fn
 * @brief ポーズ状態に切り替える関数
 * @return 0x000 ポーズ中ではない 0x001 ポーズ中である
 */
void GameState::SetGameState(signed short int state)
{
	game_state_ = state;
}
/**
 * @fn
 * @brief　ゲームの開始か終了かを判断する関数
 * @return 0x000 ゲームの開始 0x001 ゲームの終了　0x002 それ以外
 */
signed short int GameState::GetStartEndRoutine()
{
	return game_start_end_state_;
}
/**
 * @fn
 * @brief　ゲームの開始もしくは終了が始まった時に設定する関数
 * @return 0x000 ゲームの開始 0x001 ゲームの終了 0x002 それ以外
 */
void GameState::SetStartEndRoutine(signed short int state)
{
	game_start_end_state_ = state;
}
