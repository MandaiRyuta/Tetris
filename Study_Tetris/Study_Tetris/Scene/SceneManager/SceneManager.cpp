#include "SceneManager.h"
TetrisGameType::SCENETYPE SceneManager::NowType_ = TetrisGameType::SCENETYPE::TITLE;
TetrisGameType::SCENETYPE SceneManager::Type_ = TetrisGameType::SCENETYPE::TITLE;
Scene* SceneManager::CurrentScene_ = nullptr;
int SceneManager::TotalScore_ = 0;

void SceneManager::Init()
{
    TotalScore_ = 0;
}

void SceneManager::Update()
{
    switch (Type_)
    {
    case TetrisGameType::SCENETYPE::TITLE:
        if (EnterInputNowTime_ > EnterInputMaxTime&& CheckHitKey(KEY_INPUT_RETURN) == 0x001)
        {
            Type_ = TetrisGameType::SCENETYPE::GAME;
            ChangeScene(TetrisGameType::SCENETYPE::GAME);
            EnterInputNowTime_ = 0;
        }
        break;
    case TetrisGameType::SCENETYPE::GAME:
        if (TetrisUI::InGameState::GetGameState() != 0)
        {
            Type_ = TetrisGameType::SCENETYPE::RESULT;
            ChangeScene(TetrisGameType::SCENETYPE::RESULT);
        }
        break;
    case TetrisGameType::SCENETYPE::RESULT:
        if (EnterInputNowTime_ > EnterInputMaxTime&& CheckHitKey(KEY_INPUT_RETURN) == 0x001)
        {
            Type_ = TetrisGameType::SCENETYPE::TITLE;
            ChangeScene(TetrisGameType::SCENETYPE::TITLE);
            EnterInputNowTime_ = 0;
            break;
        }
    }
 

    if (this->CurrentScene_ == nullptr) return;

    this->CurrentScene_->Update();

    EnterInputNowTime_++;
}

void SceneManager::Draw()
{
    if (this->CurrentScene_ == nullptr) return;
    this->CurrentScene_->Draw();
}

void SceneManager::Release()
{
    if (this->CurrentScene_ != nullptr)
    {
        this->CurrentScene_->Release();
        delete CurrentScene_;
    }
}

void SceneManager::ChangeScene(TetrisGameType::SCENETYPE Type)
{
    Type_ = Type;

    if (CurrentScene_ != nullptr)
    {
        CurrentScene_->Release();
        delete CurrentScene_;
    }
    auto CreateScene = [](TetrisGameType::SCENETYPE  Type)
    {
        if (Type == TetrisGameType::SCENETYPE::TITLE)
        {
            SetFontSize(20);
            NowType_ = TetrisGameType::SCENETYPE::TITLE;
            return new Scene(0);
        }
        else if (Type == TetrisGameType::SCENETYPE::GAME)
        {
            SetFontSize(12);
            NowType_ = TetrisGameType::SCENETYPE::GAME;
            return new Scene(1);
        }
        else if (Type == TetrisGameType::SCENETYPE::RESULT)
        {
            SetFontSize(20);
            NowType_ = TetrisGameType::SCENETYPE::RESULT;
            SceneManager::SetTotalScore(TetrisUI::Score::GetScore());
            return new Scene(2);
        }
    };

    CurrentScene_ = CreateScene(Type);
    CurrentScene_->Init();
}

void SceneManager::SetTotalScore(int score)
{
    TotalScore_ = score;
}

int SceneManager::GetTotalScore()
{
    return TotalScore_;
}

TetrisGameType::SCENETYPE SceneManager::GetNowScene()
{
    return NowType_;
}


