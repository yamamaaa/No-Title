#pragma once
#include"../../GameObject/GameObject.h"

/// <summary>
/// StageObjクラス
/// </summary>
class StageObj final:public GameObj
{
public:

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="tag">:タグ名</param>
    StageObj();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~StageObj();

private:

    /// <summary>
   /// 更新処理
   /// </summary>
   /// <param name="deltaTime"></param>
    void  Update(float deltaTime)override;

    /// <summary>
    /// 当たったら
    /// </summary>
    /// <param name="other"></param>
    void  ObjCollision(GameObj* other)override;

    /// <summary>
    /// 描画
    /// </summary>
    void  Draw()override;
};

