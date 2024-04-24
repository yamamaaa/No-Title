#pragma once
#include <DxLib.h>
#include"../Math3D/Math3D.h"

class Collision final
{
public:

	VECTOR mLocalCenter; // 球体のローカル中心座標
	VECTOR mWorldCenter; // 球体のワールド中心座標
	float  mRadius;      // 球体の半径

    /// <summary>
    /// コンストラクタ
    /// </summary>
    Collision();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Collision();

	/// <summary>
	/// 初期値セット　コンストラクタ
	/// </summary>
	/// <param name="center">座標</param>
	/// <param name="radius">半径</param>
	Collision(const VECTOR& center, float radius);

	/// <summary>
	/// 球体が動いたら
	/// </summary>
	/// <param name="pos">オブジェクト現在地</param>
	void Move(const VECTOR& pos);

	/// <summary>
	/// 球体とメッシュの当たり判定
	/// </summary>
	/// <param name="sphere">球</param>
	/// <param name="modelHandle">メッシュのモデルID</param>
	/// <param name="collisionInfo">HIT時のポリゴンリスト</param>
	/// <returns>当たっている : true</returns>
	bool CollisionPair(const Collision* sphere, int modelHandle, MV1_COLL_RESULT_POLY_DIM& collisionInfo);

	/// <summary>
	/// 球体とメッシュとの当たり押し戻し量計算
	/// </summary>
	/// <param name="sphere">球体</param>
	/// <param name="collisionInfo">MV1CollCheck_Sphere()関数が返す衝突情報</param>
	/// <returns>球体がメッシュから離れる向きの移動ベクトル</returns>
	VECTOR CalcSpherePushBackVecFromMesh(const Collision* sphere, const MV1_COLL_RESULT_POLY_DIM& collisionInfo);
};

