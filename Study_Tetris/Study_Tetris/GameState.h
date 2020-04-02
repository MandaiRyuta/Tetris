#pragma once
/**
 * @file GameState.h
 * @brief ゲーム中のスコアやポーズ機能や開始終了用のクラス
 * @author Mandai Ryuta
 * @date 2020/04/02
 */

constexpr int InitScore = 0;
constexpr signed short int GameNowState = 0x000;
constexpr signed short int GameStartEndState = 0x000;

class GameState
{
public:
	GameState()
		:  now_socre_(InitScore),
		game_state_(GameNowState),
		game_start_end_state_(GameStartEndState)
	{}
	~GameState(){}
public:
	void SetScore(unsigned int score);
	void AddScore(unsigned int score);
	unsigned int GetScore();
	signed short int GetGameState();
	void SetGameState(signed short int state);
	signed short int GetStartEndRoutine();
	void SetStartEndRoutine(signed short int state);

private:
	unsigned int now_socre_;
	signed short int game_state_;
	signed short int game_start_end_state_;
};