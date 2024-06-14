#include "StageObj.h"

StageObj::StageObj(std::string tag)
    :GameObj(ObjTag.IMPEDIMENT)
{
    //足元当たり判定線分セット
    mCollisionLine = LineSegment(VGet(0.0f, 20.0f, 0.0f), VGet(0.0, -10.0f, 0.0f));
}

StageObj::~StageObj()
{
    //処理なし
}
