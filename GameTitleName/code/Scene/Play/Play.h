#pragma once
#include"../SceneBase/SceneBase.h"
#include"../../Object/CharaObj/BackGround/BackGround.h"
#include"../../Object/GameObjectManager/GameObjectManager.h"

#include<vector>

class Play:public SceneBase
{
public:
    
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Play();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Play();

private:

    /// <summary>
    /// �V�[���X�V����
    /// </summary>
    /// <param name="deltaTime">�f���^�^�C��</param>
    /// <returns>���t���[���̃V�[��</returns>
    SceneBase* UpdateScene(const float deltaTime)override;

    /// <summary>
    /// �V�[���`�揈��
    /// </summary>
    void DrawScene() override;

    //std::vector<BackGround> mbackground;     //background�̃C���X�^���X����
    //std::vector<GameObjectManager> md;     //background�̃C���X�^���X����

};

