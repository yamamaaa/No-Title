#pragma once
#include <DxLib.h>
#include"../../GameObject/GameObject.h"

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

    //int mRoad_Collision;	//���̓����蔻�胂�f��
    //int mStage_Collision;	//�X�e�[�W�S�̂̓����蔻�胂�f��
};

