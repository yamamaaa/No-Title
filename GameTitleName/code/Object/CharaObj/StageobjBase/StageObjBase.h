#pragma once
#include"../../GameObject/GameObject.h"

/// <summary>
/// StageObjBase�N���X
/// </summary>
class StageObjBase:public GameObj
{
public:

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="tag">:�^�O��</param>
    StageObjBase(std::string tag);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~StageObjBase();

protected:

    std::vector<int> mStageObj;     //�v���C���[���������I�u�W�F�N�g
};

