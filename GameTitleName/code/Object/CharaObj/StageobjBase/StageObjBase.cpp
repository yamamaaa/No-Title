#include "StageObjBase.h"

StageObjBase::StageObjBase(std::string tag)
    :GameObj(tag)
{
}

StageObjBase::~StageObjBase()
{
    //���������Ă�����
    if (!mStageObj.size() == 0)
    {
        //�v�f�̍폜
        mStageObj.clear();
    }
}
