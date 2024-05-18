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
    /// コピーコンストラクタ
    /// </summary>
    /// <param name="background">インスタンスを生成するクラス</param>
    BackGround(const BackGround& mground);

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~BackGround();

    /// <summary>
   /// モデルの座標を変更
   /// </summary>
   /// <param name="move">プラスする差分</param>
    void ModelposMove(VECTOR move);

private:

    /// <summary>
    /// モデルの読み込み
    /// </summary>
    void ModelLoad();

    /// <summary>
    /// モデルの複製
    /// </summary>
    /*void ModelCopy();*/

   

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

