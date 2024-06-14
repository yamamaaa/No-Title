#pragma once
#include"../../GameObject/GameObject.h"

/// <summary>
/// StageObj�N���X
/// </summary>
class StageObj final:public GameObj
{
public:

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="tag">:�^�O��</param>
    StageObj();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~StageObj();

private:

    /// <summary>
   /// �X�V����
   /// </summary>
   /// <param name="deltaTime"></param>
    void  Update(float deltaTime)override;

    /// <summary>
    /// ����������
    /// </summary>
    /// <param name="other"></param>
    void  ObjCollision(GameObj* other)override;

    /// <summary>
    /// �`��
    /// </summary>
    void  Draw()override;
};

