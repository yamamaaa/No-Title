#pragma once
#include"../../GameObject/GameObject.h"

/// <summary>
/// StageObjクラス
/// </summary>
class StageObj:public GameObj
{
public:

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="tag">:タグ名</param>
    StageObj(std::string tag);

    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~StageObj();

private:

};

