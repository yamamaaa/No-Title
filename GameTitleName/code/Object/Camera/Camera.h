#pragma once
#include"../GameObject/GameObject.h"
#include"../../Object/GameObjectManager/GameObjectManager.h"
#include"../../Object/CharaObj/Player/Player.h"
#include"../Math3D/Math3D.h"

/// <summary>
/// Camera�N���X
/// </summary>
class Camera final:public GameObj
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Camera();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Camera();

private:

    /// <summary>
    /// �X�V����
    /// </summary>
    /// <param name="deltaTime">:�f���^�^�C��</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// �J�����̈ړ�����
    /// </summary>
    /// <param name="deltaTime"></param>
    void Move(const float deltaTime);

    /// <summary>
    /// �`�揈��
    /// </summary>
    void Draw() override;

    VECTOR mPos;        //�J�����̈ʒu
    VECTOR mLookPos;    // �J�����̒��ړ_
    VECTOR mCamOffset;  // �v���C���[����̑��Έʒu
    VECTOR mAimCamPos;  // �J�����ڕW�ʒu�܂ł̌���
};

