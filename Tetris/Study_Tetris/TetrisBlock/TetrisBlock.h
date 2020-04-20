#pragma once
// TetrisBlock.h
// テトリスのブロックを管理しているクラスです
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
		/// ホールドしているブロックの形状を知らせるメソッド
		/// </summary>
		/// <returns>ブロックの形状</returns>
		const int& GetHoldBlockType();
		/// <summary>
		/// ブロックの描画メソッド
		/// </summary>
		/// <param name="type">ブロックの形状</param>
		/// <param name="vertical">ブロックの縦列</param>
		/// <param name="side">ブロックの横列</param>
		/// <param name="positionX">操作している座標X</param>
		/// <param name="positionY">操作している座標Y</param>
		void DrawBlock(int type, int vertical, int side, int positionX, int positionY);
		/// <summary>
		/// ブロックを回転させるメソッド
		/// </summary>
		void ChangeRotate();
		/// <summary>
		/// 初期化メソッド
		/// </summary>
		void Init();
		/// <summary>
		/// 更新メソッド
		/// </summary>
		void Update();
		/// <summary>
		/// 描画メソッド
		/// </summary>
		void Draw();
		/// <summary>
		/// 解放メソッド
		/// </summary>
		void Release();
		/// <summary>
		/// ブロックをストックさせるメソッド
		/// </summary>
		void StockBlock();
		/// <summary>
		/// ストックしているブロックの順番を前にずらして最後に新しい情報を入れるメソッド
		/// </summary>
		void SwapBlock();
		/// <summary>
		/// 操作しているX座標を受け取るメソッド
		/// </summary>
		/// <returns>操作しているX座標</returns>
		const int& GetXBlockPosition();
		/// <summary>
		/// 操作しているY座標のメソッド
		/// </summary>
		/// <returns>操作しているY座標</returns>
		const int& GetYblockPosition();
		/// <summary>
		/// 現在操作しているブロックの形状を知らせるメソッド
		/// </summary>
		/// <returns>現在操作しているブロックの形状</returns>
		const int& GetBlockType();
		/// <summary>
		/// ブロックのデータをステージの配置に入れるメソッド
		/// </summary>
		/// <param name="data">操作しているブロックの形状</param>
		/// <param name="x">操作しているX座標</param>
		/// <param name="y">操作しているY座標</param>
		void SetBlockData(int data, int x, int y);
		/// <summary>
		/// ステージ内に配置されたブロックを確認するメソッド
		/// </summary>
		/// <param name="x">操作しているX座標</param>
		/// <param name="y">操作しているY座標</param>
		/// <returns>ステージに配置されているブロック:1~7もしくは空:0 情報</returns>
		const int& GetBlockData(int x, int y);
		/// <summary>
		/// ステージ内で操作しているブロックの左側の衝突判定メソッド
		/// </summary>
		void StageBlockCollisionLeft();
		/// <summary>
		/// ステージ内で操作しているブロックの右側の衝突判定メソッド
		/// </summary>
		void StageBlockCollisionRight();
		/// <summary>
		/// ステージ内で操作しているブロックの下側の衝突判定メソッド
		/// </summary>
		void StageBlockCollisionBottom();
		/// <summary>
		/// ステージ内で操作しているブロックとステージ内に配置しているブロックの有無を確認する衝突判定メソッド
		/// </summary>
		void StageBlockCollisionCenter();
		/// <summary>
		/// ブロックの回転時に確認するメソッド
		/// </summary>
		void BlockCollisionTurn();
		/// <summary>
		/// ブロックを新しく作り直すメソッド
		/// </summary>
		void MakeBlock();
		/// <summary>
		/// ストックしたブロック情報を取得するメソッド
		/// </summary>
		/// <param name="num">配列番号0 ~ 3までです。</param>
		/// <returns>ブロックの形状</returns>
		const int& GetStockBlock(int num);
		/// <summary>
		/// ブロックをSpaceボタンを使って落としているかどうかを確認するメソッド
		/// </summary>
		/// <returns>落下中か落下中ではないか確認するフラグ　0x000 : 落下していない, 0x001 :　落下中</returns>
		const signed short int& GetBlockDone();
		/// <summary>
		/// 操作しているブロックを落下させるメソッド
		/// </summary>
		/// <param name="blockdonecheck">ブロックを落下させた際に切り替えるフラグ</param>
		void SetBlockDone(signed short int blockdonecheck);
		/// <summary>
		/// ゲーム内での入力操作のステート管理メソッド
		/// </summary>
		void GameInputState();
		/// <summary>
		/// 入力をして一定フレームの間の入力処理メソッド
		/// </summary>
		/// <param name="leftkeyframe">左ボタンを押した時のフレーム数</param>
		/// <param name="rightkeyframe">右ボタンを押した時のフレーム数</param>
		void InputStateFirst(int& leftkeyframe,int& rightkeyframe);
		/// <summary>
		/// 入力をして一定フレームの間の入力メソッド
		/// </summary>
		/// <param name="leftkeyframe">左ボタンを押した時のフレーム数</param>
		/// <param name="rightkeyframe">右ボタンを押した時のフレーム数</param>
		void InputStateSecond(int& leftkeyframe, int& rightkeyframe);
		/// <summary>
		/// 左ボタン入力のメソッド
		/// </summary>
		void GameInputRight();
		/// <summary>
		/// 右ボタン入力のメソッド
		/// </summary>
		void GameInputLeft();
		/// <summary>
		/// 時間経過によって落下していくステートを管理するメソッド
		/// </summary>
		void GameBlockDownState();
		/// <summary>
		/// 経過時間によって落下する速度をを調整しているメソッド
		/// </summary>
		/// <param name="frame">経過時間</param>
		void GameBlockDownFirst(int& frame);
		/// <summary>
		/// 経過時間によって落下する速度をを調整しているメソッド
		/// </summary>
		/// <param name="frame">経過時間</param>
		void GameBlockDownSecond(int& frame);
		/// <summary>
		/// 経過時間によって落下する速度をを調整しているメソッド
		/// </summary>
		/// <param name="frame">経過時間</param>
		void GameBlockDownThird(int& frame);
	private:
		/// <value>現在のブロックをホールドに入れる際に使います</value>
		int SwapHoldBlockType_;
		/// <value>ホールドしているか確認するフラグです</value>
		signed short int HoldCheck_;
		/// <value>ホールドのストックを確認するフラグです</value>
		signed short int HoldStockCheck_;
		/// <value>ストックが存在した際に消したかどうかを確認するフラグです</value>
		signed short int BreakStockCheck_;
		/// <value>ストックするブロックの配列です</value>
		std::array<int, 4> StockBlocks_;
		/// <value>ステージ内のブロックが配置できる縦の長さを確認します</value>
		int YblockCount_;
		/// <value>スペースを押したか確認するフラグです</value>
		signed short int SpaceDownCheck_;
		/// <value>[↓]キーを押したか確認するフラグです</value>
		signed short int InputDownMoveCheck_;
		/// <value>[↓]キーを押して動いているか確認するフラグです</value>
		signed short int DownMoveCheck_;
		/// <value>[Space]キーを押して落下させているか確認するフラグです</value>
		signed short int BlockDownCheck_;
		/// <value>[↑]キーを押して回転しているか確認するフラグです</value>
		signed short int BlockRotateCheck_;
		/// <value>[Space]キーを押したか確認するフラグです</value>
		signed short int BlockDoneCheck_;
		/// <value>[Space]キーを再使用できるまでの時間です</value>
		signed short int SpaceBarRefreshCheck_;
		/// <value>ブロックの生成フラグです</value>
		signed short int MakeBlock_;
		/// <value>底辺に置かれているブロックの確認用のフラグです</value>
		signed short int BottomBlockCheck_;
		/// <value>底辺にブロックを配置した際に切り替わるフラグです</value>
		signed short int CheckBlock_;
		/// <value>ブロックが落下中なのか確認するフラグです</value>
		signed short int Blockdown_;
		/// <value>左側のブロック判定フラグです</value>
		bool LeftCollision_;
		/// <value>右側の判定フラグです</value>
		bool RightCollision_;
		/// <value>底辺の判定フラグです</value>
		bool BottomCollision_;
		/// <value>[Space]キーを押してからカウントされる現在の時間です</value>
		int SpaceBarRefreshNowTime_;
		/// <value>[Space]キーを押してから再度使用できるまでの時間です</value>
		int SpaceBarRefreshMaxTime_;
		/// <value>[↑]キーを押してからカウントされる時間です</value>
		int RotateNowTime_;
		/// <value>[↑]キーを押してから再度回転できる時間です</value>
		int RotateMaxTime_;
		/// <value>ブロックが下に移動している時にカウントされる時間です</value>
		int DownMoveNowTime_;
		/// <value>[↓]キーを押してからカウントされる時間です</value>
		int InputDownMoveNowTime_;
		/// <value>[←]キーを押して移動するまでの最大時間です</value>
		int LeftMoveMaxTime_;
		/// <value>[→]キーを押して移動するまでの最大時間です</value>
		int RightMoveMaxTime_;
		/// <value>ブロックが下に移動させるための最大時間です</value>
		int DownMoveMaxTime_;
		/// <value>[↓]キーを押した時に移動させるまでの最大時間です</value>
		int InputDownMoveMaxTime_;
		/// <value>[↓]キーを押した時に加速させる最大時間です</value>
		int DownMoveAcceleration_;
		/// <value>ブロックの形状を知らせます</value>
		int Blocknumber_;
		/// <value>ブロックのすべての形状と色が含まれているクラスです</value>
		BlockData BlocksData_;
		/// <value>現在のX,Y座標です</value>
		TetrisGameType::Vector2 Position_;
		/// <value>ブロックの形状を指定します</value>
		TetrisGameType::BlockType Type_;
		/// <value>全てのブロックを格納する配列です</value>
		TetrisGameType::Block Blocktype_[TetrisGameType::TetrisBlockTypeNum::MaxNumber][TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		/// <value>操作しているブロックをコピーする配列です</value>
		int CopyBlock_[TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		/// <value>ステージのブロックを配置する範囲になります</value>
		int Board_[TetrisGameType::StageHeight][TetrisGameType::StageWidth];
		/// <value>[Space]キーを押してから反応させるまでの最大時間です</value>
		int SpaceDownMaxTime_;
		/// <value>[Space]キーを押したときにカウントされる時間です</value>
		int SpaceDownNowTime_;
		/// <value>判定用の変数です</value>
		int Collision_;
		/// <value>ブロックが回転した際に保管する配列です</value>
		TetrisGameType::Color TurnColor_[TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		/// <value>操作しているブロックの形状を教える配列です</value>
		int DrawBlock_[TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		/// <value>操作しているブロックの色を教える配列です</value>
		TetrisGameType::Color DrawBlockColor_[TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		/// <value>ブロックが回転した際に色を補完する配列です</value>
		int TurnBlock_[TetrisGameType::BlockHeight][TetrisGameType::BlockWidth];
		/// <value>左右の移動量です</value>
		int SideSpeed_;
		/// <value>[←][→]を押した時に切り替わります</value>
		int InputSideCheck_;
		/// <value>ボタンを押してステートを切り替えるときに使います</value>
		int ChangeKeyStateCount_;
		/// <value>[←]ボタンを押した時にカウントされます</value>
		int LeftKeyFrame_;
		/// <value>[→]ボタンを押した時にカウントされます</value>
		int RightKeyFrame_;
		/// <value>ボタンを押して数秒経過する度に切り替わるステートです、ボタンを離したらステートが初期値に戻ります</value>
		int InputState_;
		/// <value>ブロックの移動量です</value>
		int BlockMoveSpeed_;
		/// <value>ゲーム内のブロックの落ちる速度を、時間で管理しているものです</value>
		int GameBlockLevelFrame_;
		/// <value>ゲーム内のブロックの落ちる速度を３段階で管理してます。</value>
		int GameBlockState_;
		/// <value>ブロックが底辺に着地してから新しいブロックが作られるまでの時間です。</value>
		int WaitMakeBlcokTime_;
	};
}