#pragma once
#include"../CharaObjBase/CharaObjBase.h"

using namespace Collision;

class Player final:public CharaObjBase
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Player();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Player();

private:
    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="deltaTime">デルタタイム</param>
    void Update(const float deltaTime) override;

    /// <summary>
    /// キャラ動作処理
    /// </summary>
    /// <param name="deltaTime">:デルタタイム</param>
    void MoveChara(const float deltaTime)override;

    /// <summary>
    /// キー入力による移動処理
    /// </summary>
    /// <param name="keyName">:キー名</param>
    /// <param name="dir">:移動方向</param>
    /// <param name="deltaTime">:デルタタイム</param>
    void MoveByKey(const int keyName, const VECTOR dir, const float deltaTime);


    void OnCollisonEnter(const GameObj* other) override;
    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw() override;

    bool isJump = false;    //ジャンプ中か？
    bool isLanding = true;  //接地しているか？

    const float RUN_SPEED = 30.0f;  //移動速度
    const float mG = -0.3f;    //重力
 
    float mDownSpeed = 0;   //落下速度
};

