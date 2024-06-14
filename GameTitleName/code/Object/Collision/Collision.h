#pragma once
#include <DxLib.h>
#include"../Math3D/Math3D.h"


namespace Collision
{
	/// <summary>
	/// 線分当たり判定
	/// </summary>
	struct LineSegment
	{
		/// <summary>
		/// コンストラクタ
		/// </summary>
		LineSegment();

		/// <summary>
		/// 初期値セットコンストラクタ
		/// </summary>
		/// <param name="startPos">線分開始地点</param>
		/// <param name="endPos">線分終了地点</param>
		LineSegment(const VECTOR& startPos, const VECTOR& endPos);

		/// <summary>
		/// 線分の移動処理
		/// </summary>
		/// <param name="pos"></param>
		void Move(const VECTOR& pos);

		//ローカル座標	オブジェクトを中心とした座標の事
		//親のいる座標を中心座標(x=0,y=0,z=0)とした座標

		//ワールド座標	ゲームオブジェクト等の位置を示す座標
		//3D空間の中心を中心座標(x=0,y=0,z=0)として自分やオブジェクトがどこにいるのかを表す座標
		//当たり判定で使用されるもの

		//相対位置	今いる自分の位置を基準にして位置を表す座標

		//線分	プレイヤー足元の判定
		VECTOR mLocalStart; // 線分のローカル開始座標
		VECTOR mLocalEnd;   // 線分のローカル終了座標
		VECTOR mWorldStart; // 線分のワールド開始座標
		VECTOR mWorldEnd;   // 線分のワールド終了座標
	};

	/// <summary>
	/// 球体当たり判定
	/// </summary>
	struct Sphere
	{
		/// <summary>
		/// コンストラクタ
		/// </summary>
		Sphere();

		/// <summary>
		/// コンストラクタ初期値セット
		/// </summary>
		/// <param name="center">座標</param>
		/// <param name="radius">半径</param>
		Sphere(const VECTOR& center, float radius);

		/// <summary>
		/// 球体の移動処理
		///	</summary>
		/// <param name="pos">オブジェクト現在地</param>
		void Move(const VECTOR& pos);


		VECTOR mLocalCenter; // 球体のローカル中心座標
		VECTOR mWorldCenter; // 球体のワールド中心座標
		float  mRadius;      // 球体の半径
	};

	/// <summary>
	/// 線分と球体の当たり判定
	/// </summary>
	/// <param name="line">線分</param>
	/// <param name="sphere">球体</param>
	/// <returns>当たっているか？</returns>
	bool CollisionPair(const LineSegment& line, const Sphere& sphere);

	/// <summary>
	/// 線分とメッシュの当たり判定
	/// </summary>
	/// <param name="line">線分</param>
	/// <param name="modelHandle">メッシュのモデルID</param>
	/// <param name="collisionInfo">衝突したポリゴンリスト</param>
	/// <returns>当たったか？</returns>
	bool CollisionPair(const LineSegment& line, const int modelHandle, MV1_COLL_RESULT_POLY& collisionInfo);

	/// <summary>
	/// 球体とメッシュの当たり判定
	/// </summary>
	/// <param name="sphere">球</param>
	/// <param name="modelHandle">メッシュのモデルID</param>
	/// <param name="collisionInfo">HIT時のポリゴンリスト</param>
	/// <returns>当たっている : true</returns>
	bool CollisionPair(const Sphere* sphere, int modelHandle, MV1_COLL_RESULT_POLY_DIM& collisionInfo);

	/// <summary>
	/// 球体とメッシュとの当たり押し戻し量計算
	/// </summary>
	/// <param name="sphere">球体</param>
	/// <param name="collisionInfo">MV1CollCheck_Sphere()関数が返す衝突情報</param>
	/// <returns>球体がメッシュから離れる向きの移動ベクトル</returns>
	VECTOR CalcSpherePushBackVecFromMesh(const Sphere* sphere, const MV1_COLL_RESULT_POLY_DIM& collisionInfo);
};

