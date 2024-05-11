#include "StageObjBase.h"

StageObjBase::StageObjBase(std::string tag)
    :GameObj(tag)
{
    //ˆ—‚È‚µ
}

StageObjBase::~StageObjBase()
{
    //‰½‚©“ü‚Á‚Ä‚¢‚½‚ç
    if (!mStageObj.size() == 0)
    {
        //—v‘f‚Ìíœ
        mStageObj.clear();
    }
}
