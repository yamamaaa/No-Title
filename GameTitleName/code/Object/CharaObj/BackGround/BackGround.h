#pragma once
#include <DxLib.h>
#include "../../CharaObj/CharaObjBase/CharaObjBase.h"
#include"../../CharaObj/StageobjBase/StageObjBase.h"

class BackGround final:public StageObjBase
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
    /// ���f���̃Z�b�e�B���O
    /// </summary>
    void ModelSetting();

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
};

