#include "StageObj.h"

StageObj::StageObj(std::string tag)
    :GameObj(ObjTag.IMPEDIMENT)
{
    //���������蔻������Z�b�g
    mCollisionLine = LineSegment(VGet(0.0f, 20.0f, 0.0f), VGet(0.0, -10.0f, 0.0f));
}

StageObj::~StageObj()
{
    //�����Ȃ�
}
