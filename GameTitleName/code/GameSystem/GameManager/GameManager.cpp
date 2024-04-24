#include"../Window/Window.h"
#include"../GameSetting/GameSetting.h"
#include"../../Scene/SceneManager/SceneManager.h"
#include "GameManager.h"

GameManager::GameManager()
{
    //Log.txtを生成しないように設定
    SetOutApplicationLogValidFlag(false);

    Window::Init();
    GameSetting::Init();
    sceneManager.reset(new SceneManager);
}

GameManager::~GameManager()
{
    //処理なし
}

void GameManager::Procces()
{
    sceneManager->GameLoop();
}
