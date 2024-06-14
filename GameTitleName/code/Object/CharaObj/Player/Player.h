#pragma once
#include"../CharaObjBase/CharaObjBase.h"

using namespace Collision;

class Player final:public CharaObjBase
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Player();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Player();

private:
    /// <summary>
    /// �X�V����
    /// </summary>
    /// <param name="deltaTime">�f���^�^�C��</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// �L�������쏈��
    /// </summary>
    /// <param name="deltaTime">:�f���^�^�C��</param>
    void MoveChara(const float deltaTime)override;

    /// <summary>
    /// �L�[���͂ɂ��ړ�����
    /// </summary>
    /// <param name="keyName">:�L�[��</param>
    /// <param name="dir">:�ړ�����</param>
    /// <param name="deltaTime">:�f���^�^�C��</param>
    void MoveByKey(const int keyName, const VECTOR dir, const float deltaTime);


    void OnCollisonEnter(const GameObj* other) override;
    /// <summary>
    /// �`�揈��
    /// </summary>
    void Draw() override;

    bool isJump = false;    //�W�����v�����H
    bool isLanding = true;  //�ڒn���Ă��邩�H

    const float RUN_SPEED = 30.0f;  //�ړ����x
    const float mG = -0.3f;    //�d��
 
    float mDownSpeed = 0;   //�������x
};

