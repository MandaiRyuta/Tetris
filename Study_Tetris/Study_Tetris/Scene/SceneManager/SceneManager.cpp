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
    if (ArrowInputNowTime_ > ArrowInputMaxTime && Arrow_Up_Down_ == 0x000)
    {
        if (CheckHitKey(KEY_INPUT_UP) == 0x001)
        {
            Arrow_Up_Down_ = 0x001;
            ArrowInputNowTime_ = 0;
        }
    }
    else if (ArrowInputNowTime_ > ArrowInputMaxTime&& Arrow_Up_Down_ == 0x001)
    {
        if (CheckHitKey(KEY_INPUT_DOWN) == 0x001)
        {
            Arrow_Up_Down_ = 0x000;
            ArrowInputNowTime_ = 0;
        }
    }
    if (EnterInputNowTime_ > EnterInputMaxTime && Arrow_Up_Down_ == 0x001 && CheckHitKey(KEY_INPUT_RETURN) == 0x001)
    {
        switch (Type_)
        {
        case TetrisGameType::SCENETYPE::TITLE:
            Type_ = TetrisGameType::SCENETYPE::GAME;
            ChangeScene(TetrisGameType::SCENETYPE::GAME);
            break;
        case TetrisGameType::SCENETYPE::GAME:
            Type_ = TetrisGameType::SCENETYPE::RESULT;
            ChangeScene(TetrisGameType::SCENETYPE::RESULT);
            break;
        case TetrisGameType::SCENETYPE::RESULT:
            Type_ = TetrisGameType::SCENETYPE::TITLE;
            ChangeScene(TetrisGameType::SCENETYPE::TITLE);
            break;
        }
        EnterInputNowTime_ = 0;
    }
    if (this->CurrentScene_ == nullptr) return;
    this->CurrentScene_->Update();

    EnterInputNowTime_++;
    ArrowInputNowTime_++;
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

    auto CreateScene = [](TetrisGameType::SCENETYPE  Type)
    {
        if (Type == TetrisGameType::SCENETYPE::TITLE)
        {
            NowType_ = TetrisGameType::SCENETYPE::TITLE;
            return new Scene(0);
        }
        else if (Type == TetrisGameType::SCENETYPE::GAME)
        {
            NowType_ = TetrisGameType::SCENETYPE::GAME;
            return new Scene(1);
        }
        else if (Type == TetrisGameType::SCENETYPE::RESULT)
        {
            NowType_ = TetrisGameType::SCENETYPE::RESULT;
            SceneManager::SetTotalScore(TetrisUI::Score::GetScore());
            return new Scene(2);
        }
        else
            return new Scene(0);
    };
    TetrisUI::Fade::SetStartFade(2);

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
