#pragma once
#include<DxLib.h>
#include<memory>

/// <summary>
/// �Q�[���Ǘ�
/// </summary>
class GameManager final
{
public:

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    GameManager();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~GameManager();

    /// <summary>
    /// �㏈��
    /// </summary>
    void Procces();

private:

    //�V�[���}�l�[�W���[
    std::unique_ptr<class SceneManager> sceneManager;
};

