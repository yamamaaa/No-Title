#pragma once
#include"../../GameObject/GameObject.h"

/// <summary>
/// StageObj�N���X
/// </summary>
class StageObj:public GameObj
{
public:

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="tag">:�^�O��</param>
    StageObj(std::string tag);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~StageObj();

private:

};

