#pragma once
#include <DxLib.h>
#include "../../GameObject/GameObject.h"

class BackGround final:public GameObj
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
    /// モデルの複製
    /// </summary>
    void ModelCopy();

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

    std::vector<int> mStageObj; //ステージ用オブジェクト
};

