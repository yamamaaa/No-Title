#include "StageObj.h"

StageObj::StageObj()
    :GameObj(ObjTag.STAGE_OBJ)
{
    //ゲームオーバーの当たり判定線分セット
    mCollisionLine = LineSegment(VGet(0.0f, 14.0f, 30.0f), VGet(0.0, 14.0f, -30.0f));
}

StageObj::~StageObj()
{
    //処理なし
}

void StageObj::Update(float deltaTime)
{
    CollisionUpdate();
}

void StageObj::ObjCollision(GameObj* other)
{
 
}

void StageObj::Draw()
{
    //線分の表示
    DrawCollider();
}
