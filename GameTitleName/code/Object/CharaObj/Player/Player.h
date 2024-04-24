#pragma once
#include"../CharaObjBase/CharaObjBase.h"

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

    const float RUN_SPEED = 30.0f;
    float a = 0;
};

