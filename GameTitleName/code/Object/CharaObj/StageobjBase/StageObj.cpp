#include "StageObj.h"

StageObj::StageObj(std::string tag)
    :GameObj(ObjTag.IMPEDIMENT)
{
    //‘«Œ³“–‚½‚è”»’èü•ªƒZƒbƒg
    mCollisionLine = LineSegment(VGet(0.0f, 20.0f, 0.0f), VGet(0.0, -10.0f, 0.0f));
}

StageObj::~StageObj()
{
    //ˆ—‚È‚µ
}
