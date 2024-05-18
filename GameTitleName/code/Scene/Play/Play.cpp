#include "Play.h"
#include"../../KeyStatus/KeyStatus.h"
#include"../Title/Title.h"
#include"../../Object/CharaObj/Player/Player.h"
#include"../../Object/Camera/Camera.h"

Play::Play()
{
    //�S�I�u�W�F�N�g����
    GameObjectManager::Entry(new Player);
    GameObjectManager::Entry(new Camera);
    GameObjectManager::Entry(new BackGround);

   /* VECTOR n = VGet(65.0f, 0.0f, 0.0f);*/

    //�X�e�[�W�̕���
   /* mbackground.push_back(BackGround());
    mbackground.push_back(BackGround());

    mbackground[0].ModelposMove(VGet(65.0f, 0.0f, 0.0f));
    mbackground[1].ModelposMove(VGet(130.0f, 0.0f, 0.0f));*/
    //vector �C���X�^���X�̐��� c++

    md.push_back(GameObjectManager());
}

Play::~Play()
{
    //�����Ȃ�
}

SceneBase* Play::UpdateScene(const float deltaTime)
{
    //�I�u�W�F�N�g�X�V
    GameObjectManager::Update(deltaTime);
    for (auto& mBackGround : mbackground)
    {
        //�v���C���[������������W�̕ύX
        //mBackGround.;
    }
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
