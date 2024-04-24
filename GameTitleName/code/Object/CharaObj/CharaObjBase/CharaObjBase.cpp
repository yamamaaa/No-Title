#include "CharaObjBase.h"

using namespace math;

CharaObjBase::CharaObjBase(std::string tag)
    :GameObj(tag)
    , isMove(false)
    , moveSpeed(0.0f)
    , nowRotate(false)
    , aimDir(VGet(0, 0, 0))
    , rotRad(0.0f)
    , rotYRad(math::DegToRad(-PI_RAD / 2))
{
    rotYMat = MGetRotY(rotYRad);
    rotateMat = MMult(MGetScale(objScale), rotYMat);
}

CharaObjBase::~CharaObjBase()
{
    //�����Ȃ�
}

void CharaObjBase::RotateYAxis(const VECTOR dir, float velocity)
{
    //���������ڕW�����łȂ���Ή�]���ɂ���
    aimDir = dir;
    if (!(objDir == aimDir))
    {
        nowRotate = true;
    }

    //��]���Ȃ�
    if (nowRotate)
    {
        //�ڕW�����t�߂܂ŉ�]
        if (VDot(objDir, aimDir) < SIMILAR_ANGLE)
        {
            //��]�����Z�o���ăx�N�g���ƍs��̗�������]������
            rotYRad += CalcRotDir(velocity);
            objDir = VTransform(objDir, rotYMat);
            rotateMat = MMult(MGetScale(objScale), MGetRotY(rotYRad));
        }
        else
        {
            //�ڕW�����ɂ��ĉ�]��~
            objDir = aimDir;
            nowRotate = false;
        }
    }
}

float CharaObjBase::CalcRotDir(float velocity)
{
    //���W�A���p�ɂ��ĉ�]�s��֕ϊ�
    rotRad = math::DegToRad(velocity);
    rotYMat = MGetRotY(rotRad);

    //��]�������Z�o
    if (VCross(objDir, aimDir).y < 0)
    {
        rotYMat = MTranspose(rotYMat);
        return -rotRad;
    }
    return rotRad;
}

