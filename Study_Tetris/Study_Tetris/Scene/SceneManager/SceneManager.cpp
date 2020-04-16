#include "SceneManager.h"
TetrisGameType::SCENETYPE SceneManager::NowType_ = TetrisGameType::SCENETYPE::TITLE;
TetrisGameType::SCENETYPE SceneManager::Type_ = TetrisGameType::SCENETYPE::TITLE;
Scene* SceneManager::CurrentScene_ = nullptr;
int SceneManager::TotalScore_ = 0;

void SceneManager::Init()
{
    CurrentScene_ = new Scene(0);
    CurrentScene_->AddUIObject<TetrisUI::UIManager>(0);
    CurrentScene_->Init();
    EnterInputNowTime_[0] = 0;
    EnterInputNowTime_[1] = 0;
    EnterInputNowTime_[2] = 0;
    Type_ = TetrisGameType::SCENETYPE::TITLE;
    NowType_ = TetrisGameType::SCENETYPE::TITLE;
    TotalScore_ = 0;
}

void SceneManager::Update()
{
    switch (Type_)
    {
    case TetrisGameType::SCENETYPE::TITLE:
        if (EnterInputNowTime_[0] > EnterInputMaxTime&& CheckHitKey(KEY_INPUT_RETURN) == 0x001)
        {
            Type_ = TetrisGameType::SCENETYPE::GAME;
            EnterInputNowTime_[0] = 0;
            ChangeScene(TetrisGameType::SCENETYPE::GAME);
        }

        EnterInputNowTime_[0]++;
        break;
    case TetrisGameType::SCENETYPE::GAME:
        if (TetrisUI::InGameState::GetGameState() != 0)
        {
            EnterInputNowTime_[1] = 0;
            Type_ = TetrisGameType::SCENETYPE::RESULT;
            ChangeScene(TetrisGameType::SCENETYPE::RESULT);
        }

        EnterInputNowTime_[1]++;
        break;
    case TetrisGameType::SCENETYPE::RESULT:
        if (EnterInputNowTime_[2] > EnterInputMaxTime&& CheckHitKey(KEY_INPUT_RETURN) == 0x001)
        {
            EnterInputNowTime_[2] = 0;
            Type_ = TetrisGameType::SCENETYPE::TITLE;
            ChangeScene(TetrisGameType::SCENETYPE::TITLE);
        }        
        EnterInputNowTime_[2]++;
        break;
    }
 

    if (this->CurrentScene_ == nullptr) return;

    this->CurrentScene_->Update();
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
        CurrentScene_->Release();
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
        if (Type == TetrisGameType::SCENETYPE::GAME)
        {
            SetFontSize(12);
            NowType_ = TetrisGameType::SCENETYPE::GAME;
            return new Scene(1);
        }
        if (Type == TetrisGameType::SCENETYPE::RESULT)
        {
            SetFontSize(20);
            NowType_ = TetrisGameType::SCENETYPE::RESULT;
            SceneManager::SetTotalScore(TetrisUI::Score::GetScore());
            return new Scene(2);
        }
        else
        {
            return new Scene(0);
        }
    };

    CurrentScene_ = CreateScene(Type);

    int scenenumber = static_cast<int>(Type);
    switch (scenenumber)
    {
    case 0:
        CurrentScene_->AddUIObject<TetrisUI::UIManager>(scenenumber);
        break;
    case 1:
        CurrentScene_->AddUIObject<TetrisUI::UIManager>(scenenumber);
        CurrentScene_->AddBlockObject<TetrisBlocks::BlockCollection>();
        break;
    case 2:
        CurrentScene_->AddUIObject<TetrisUI::UIManager>(scenenumber);
        break;
    }
    CurrentScene_->Init();
}

void SceneManager::SetTotalScore(int score)
{
    TotalScore_ = score;
}

const int& SceneManager::GetTotalScore()
{
    return TotalScore_;
}

const TetrisGameType::SCENETYPE& SceneManager::GetNowScene()
{
    return NowType_;
}


