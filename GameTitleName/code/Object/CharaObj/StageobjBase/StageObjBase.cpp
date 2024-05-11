#include "StageObjBase.h"

StageObjBase::StageObjBase(std::string tag)
    :GameObj(tag)
{
    //処理なし
}

StageObjBase::~StageObjBase()
{
    //何か入っていたら
    if (!mStageObj.size() == 0)
    {
        //要素の削除
        mStageObj.clear();
    }
}
