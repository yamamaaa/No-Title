#include "Play.h"
#include"../../KeyStatus/KeyStatus.h"
#include"../Title/Title.h"
#include"../../Object/CharaObj/Player/Player.h"
#include"../../Object/Camera/Camera.h"
#include"../../Object/CharaObj/StageobjBase/StageObj.h"

Play::Play()
{
    //�S�I�u�W�F�N�g����
    GameObjectManager::Entry(new Player);
    GameObjectManager::Entry(new Camera);
    GameObjectManager::Entry(new StageObj);

    GameObjectManager::Entry(new BackGround(VGet(0,0,0)));
    GameObjectManager::Entry(new BackGround(VGet(65.0f, 0, 0)));
    GameObjectManager::Entry(new BackGround(VGet(130.0f, 0, 0)));
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

    //�G���^�[�L�[�ŃQ�[���I��
    if (KeyStatus::KeyStateDecision(KEY_INPUT_RETURN, ONINPUT))
    {
        GameObjectManager::ReleaseAllObj();
        /*return new Title;*/
        return 0;
    }

    return this;
}

void Play::DrawScene()
{
    //�S�I�u�W�F�N�g�̕`��
    GameObjectManager::Draw();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "play");
}
