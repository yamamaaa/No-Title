#pragma once
#include <DxLib.h>
#include "../../CharaObj/CharaObjBase/CharaObjBase.h"
#include"../../CharaObj/StageobjBase/StageObjBase.h"

class BackGround final:public StageObjBase
{
public :

    /// <summary>
    /// コンストラクタ
    /// </summary>
    BackGround();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~BackGround();

private:

    /// <summary>
    /// モデルの読み込み
    /// </summary>
    void ModelLoad();

    /// <summary>
    /// モデルのセッティング
    /// </summary>
    void ModelSetting();

    void CollisionSet(int CollisionModel);

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="deltaTime"></param>
    void Update(float deltaTime)override;

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw() override;
};

