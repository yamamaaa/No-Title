#pragma once
#include"../SceneBase/SceneBase.h"

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
};

