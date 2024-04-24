#include"../Window/Window.h"
#include"../GameSetting/GameSetting.h"
#include"../../Scene/SceneManager/SceneManager.h"
#include "GameManager.h"

GameManager::GameManager()
{
    //Log.txt�𐶐����Ȃ��悤�ɐݒ�
    SetOutApplicationLogValidFlag(false);

    Window::Init();
    GameSetting::Init();
    sceneManager.reset(new SceneManager);
}

GameManager::~GameManager()
{
    //�����Ȃ�
}

void GameManager::Procces()
{
    sceneManager->GameLoop();
}
