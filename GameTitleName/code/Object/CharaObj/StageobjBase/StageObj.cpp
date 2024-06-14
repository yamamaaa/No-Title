#include "StageObj.h"

StageObj::StageObj()
    :GameObj(ObjTag.STAGE_OBJ)
{
    //�Q�[���I�[�o�[�̓����蔻������Z�b�g
    mCollisionLine = LineSegment(VGet(0.0f, 14.0f, 30.0f), VGet(0.0, 14.0f, -30.0f));
}

StageObj::~StageObj()
{
    //�����Ȃ�
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
    //�����̕\��
    DrawCollider();
}
