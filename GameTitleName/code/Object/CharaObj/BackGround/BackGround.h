#pragma once
#include <DxLib.h>
#include "../../GameObject/GameObject.h"

class BackGround final:public GameObj
{
public :

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    BackGround();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~BackGround();

private:

    /// <summary>
    /// ���f���̓ǂݍ���
    /// </summary>
    void ModelLoad();

    /// <summary>
    /// ���f���̕���
    /// </summary>
    void ModelCopy();

    void CollisionSet(int CollisionModel);

    /// <summary>
    /// �X�V����
    /// </summary>
    /// <param name="deltaTime"></param>
    void Update(float deltaTime)override;

    /// <summary>
    /// �`�揈��
    /// </summary>
    void Draw() override;

    std::vector<int> mStageObj; //�X�e�[�W�p�I�u�W�F�N�g
};

