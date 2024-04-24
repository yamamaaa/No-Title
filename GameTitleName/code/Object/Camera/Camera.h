#pragma once
#include"../GameObject/GameObject.h"

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
    /// �`�揈��
    /// </summary>
    void Draw() override;
};

