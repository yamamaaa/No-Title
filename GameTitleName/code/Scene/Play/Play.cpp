#include "Play.h"
#include"../../Object/GameObjectManager/GameObjectManager.h"
#include"../../KeyStatus/KeyStatus.h"
#include"../Title/Title.h"
#include"../../Object/CharaObj/Player/Player.h"
#include"Camera.h"
#include"BackGround.h"

Play::Play()
{
    //�S�I�u�W�F�N�g����
    GameObjectManager::Entry(new Player);
    GameObjectManager::Entry(new Camera);
    GameObjectManager::Entry(new BackGround);
}

Play::~Play()
{
    //�����Ȃ�
}

SceneBase* Play::UpdateScene(const float deltaTime)
{
    //�I�u�W�F�N�g�X�V
    GameObjectManager::Update(deltaTime);
    GameObjectManager::Collision();

    if (KeyStatus::KeyStateDecision(KEY_INPUT_RETURN, ONINPUT))
    {
        GameObjectManager::ReleaseAllObj();
        return new Title;
    }

    return this;
}

void Play::DrawScene()
{
    //�S�I�u�W�F�N�g�̕`��
    GameObjectManager::Draw();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "play");
}
