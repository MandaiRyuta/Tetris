#include "SceneManager.h"
static signed short int set = 0x000;

void SceneManager::Init()
{

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
        switch (type_)
        {
        case TetrisGameType::SCENETYPE::TITLE:
            type_ = TetrisGameType::SCENETYPE::GAME;
            ChangeScene(TetrisGameType::SCENETYPE::GAME);
            break;
        case TetrisGameType::SCENETYPE::GAME:
            type_ = TetrisGameType::SCENETYPE::RESULT;
            ChangeScene(TetrisGameType::SCENETYPE::RESULT);
            break;
        case TetrisGameType::SCENETYPE::RESULT:
            type_ = TetrisGameType::SCENETYPE::TITLE;
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
    type_ = Type;
    
    auto CreateScene = [](TetrisGameType::SCENETYPE  Type)
    {
        if (Type == TetrisGameType::SCENETYPE::TITLE)
            return new Scene(0);
        else if (Type == TetrisGameType::SCENETYPE::GAME)
            return new Scene(1);
        else if (Type == TetrisGameType::SCENETYPE::RESULT)
            return new Scene(2);
        else
            return new Scene(0);
    };

    this->CurrentScene_ = CreateScene(Type);
}
