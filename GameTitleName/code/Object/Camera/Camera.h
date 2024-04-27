#pragma once
#include"../GameObject/GameObject.h"
#include"../../Object/GameObjectManager/GameObjectManager.h"
#include"../../Object/CharaObj/Player/Player.h"
#include"../Math3D/Math3D.h"

/// <summary>
/// Cameraクラス
/// </summary>
class Camera final:public GameObj
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Camera();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Camera();

private:

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="deltaTime">:デルタタイム</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// カメラの移動処理
    /// </summary>
    /// <param name="deltaTime"></param>
    void Move(const float deltaTime);

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw() override;

    VECTOR mPos;        //カメラの位置
    VECTOR mLookPos;    // カメラの注目点
    VECTOR mCamOffset;  // プレイヤーからの相対位置
    VECTOR mAimCamPos;  // カメラ目標位置までの向き
};

