#pragma once
#include"../../GameObject/GameObject.h"
#include"../../../KeyStatus/KeyStatus.h"
#include"../../Math3D/Math3D.h"

/// <summary>
/// CharaObjBase�N���X
/// </summary>
class CharaObjBase:public GameObj
{
public:

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="tag">:�^�O��</param>
    CharaObjBase(std::string tag);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~CharaObjBase();

protected:
    /// <summary>
    /// �f�[�^���t�@�C���p�X�擾����
    /// </summary>
    /// <param name="objData">:�擾�������I�u�W�F�N�g�f�[�^</param>
    /// <returns>�t�@�C���p�X</returns>
    const std::string GetFilePass(const rapidjson::Value& objData) { return objData[jsondata::dataKey.pass.c_str()].GetString(); }

    /// <summary>
    /// �L�������쏈��
    /// </summary>
    /// <param name="deltaTime">:�f���^�^�C��</param>
    virtual void MoveChara(const float deltaTime) = 0;

    /// <summary>
    /// Y����]����
    /// </summary>
    /// <param name="dir">:�ڕW�̌���</param>
    /// <param name="velocity">:�p���x</param>
    void RotateYAxis(const VECTOR dir, float velocity);

    /// <summary>
    /// ��]�����Z�o����
    /// </summary>
    /// <returns>:</returns>
    /// <param name="velocity">:�p���x</param>
    float CalcRotDir(float velocity);

    bool isMove;                            //���씻��
    float moveSpeed;                        //�ړ����x

    const VECTOR FRONT = VGet(1, 0, 0);     //�O��
    const VECTOR BACK = VGet(-1, 0, 0);     //���
    const VECTOR LEFT = VGet(0, 0, 1);      //��
    const VECTOR RIGHT = VGet(0, 0, -1);    //�E

    const float PI_RAD = 180;               //180�x
    const float ROTATE_SPEED = 10.0f;        //��]���x
    bool nowRotate;                         //��]����
    MATRIX rotateMat;                       //��]�s��

    const rapidjson::Value& modelData = model->GetJsonData()[mTag.c_str()];      //���f���p�X�f�[�^
    const rapidjson::Value& soundData = sound->GetJsonData()[mTag.c_str()];      //�T�E���h�p�X�f�[�^
    const rapidjson::Value& motionData = motion->GetJsonData()[mTag.c_str()];    //���[�V�����p�X�f�[�^

private:
    const float SIMILAR_ANGLE = 0.999f;     //�����p
    VECTOR aimDir;                          //�ڕW���W
    float rotRad;                           //�p���x�̃��W�A���p
    float rotYRad;                          //Y�����W�A���p
    MATRIX rotYMat;                         //Y����]�s��
};

