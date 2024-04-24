#include"../Window/Window.h"
#include"../GameSetting/GameSetting.h"
#include"../../Scene/SceneManager/SceneManager.h"
#include "GameManager.h"

GameManager::GameManager()
{
    //Log.txt‚ð¶¬‚µ‚È‚¢‚æ‚¤‚ÉÝ’è
    SetOutApplicationLogValidFlag(false);

    Window::Init();
    GameSetting::Init();
    sceneManager.reset(new SceneManager);
}

GameManager::~GameManager()
{
    //ˆ—‚È‚µ
}

void GameManager::Procces()
{
    sceneManager->GameLoop();
}
