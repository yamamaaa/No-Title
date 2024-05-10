#pragma once
#include"../../GameObject/GameObject.h"

/// <summary>
/// StageObjBaseクラス
/// </summary>
class StageObjBase:public GameObj
{
public:

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="tag">:タグ名</param>
    StageObjBase(std::string tag);

    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~StageObjBase();

protected:

    std::vector<int> mStageObj;     //プレイヤーを除いたオブジェクト
};

