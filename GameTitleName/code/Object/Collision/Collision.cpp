#include "Collision.h"
#include"../../Object/Math3D/Math3D.h"
#include <DxLib.h>
using namespace math;

Collision::Collision()
	: mLocalCenter()
	, mWorldCenter()
	, mRadius(0.0f)
{
}

Collision::~Collision()
{
	//処理なし
}

Collision::Collision(const VECTOR& center, float radius)
	: mLocalCenter(center)
	, mWorldCenter(center)
	, mRadius(radius)
{
}

void Collision::Move(const VECTOR& pos)
{
	//オブジェクト現在地(pos)と移動前のローカル座標を足すことでワールド座標が出る
	mWorldCenter = VAdd(mLocalCenter, pos);
}

bool Collision::CollisionPair(const Collision* sphere, int modelHandle, MV1_COLL_RESULT_POLY_DIM& collisionInfo)
{
	// 当たり判定の球とモデルの当たり判定
	collisionInfo = MV1CollCheck_Sphere(modelHandle, -1, sphere->mWorldCenter, sphere->mRadius);

	//当たっているポリゴンがゼロであれば
	if (collisionInfo.HitNum == 0)
	{
		return false;
	}
	return true;
}

VECTOR Collision::CalcSpherePushBackVecFromMesh(const Collision* sphere, const MV1_COLL_RESULT_POLY_DIM& collisionInfo)
{
	// 衝突球
	// 球中心候補 球の中心座標のコピー(計算に使うのでプログラムに影響する実際の中心をもってきてはいけない)
	VECTOR moveCandidate = sphere->mWorldCenter;
	float  radius = sphere->mRadius; // 球半径

	//ポリゴンの裏表を判定、表のほうに矢印が行く
	VECTOR planeNormal;                    // ポリゴン平面法線

	VECTOR moveVec = VGet(0, 0, 0);    // 移動ベクトル
	float  moveLen = 0.0f;           // 移動量

	VECTOR newCenter = sphere->mWorldCenter; // 移動候補

	int i = 0, j = 0;

	// 衝突ポリゴンをすべて回って、球のめり込みを解消する
	//collisionInfo.HitNum	当たったポリゴンの数
	for (i = 0; i < collisionInfo.HitNum; ++i)
	{
		// 衝突ポリゴンの辺 
		//当たったポリゴンの頂点同士を線で結ぶ
		//ポリゴンの辺を二つ抽出することにより三角の形ができる
		VECTOR edge1, edge2;

		//ポリゴンの頂点0を原点とする
		//0から1のベクトル(向き)(01ベクトルは1-0をするとできる)
		edge1 = collisionInfo.Dim[i].Position[1] - collisionInfo.Dim[i].Position[0];
		//0から2のベクトル(向き)
		edge2 = collisionInfo.Dim[i].Position[2] - collisionInfo.Dim[i].Position[0];

		// 衝突ポリゴンの辺より、ポリゴン面の法線ベクトル(ポリゴンの表面)を求める
		//ベクトルの外積を計算(ベクトルの外積を計算することにより法線ベクトルも一緒に求められるため)
		//ベクトルの外積	二つの成分の向きを合わせたもの 二つの向きの真ん中
		//この時法線ベクトルはポリゴンの原点0から出ている
		planeNormal = VCross(edge1, edge2);

		//ベクトルの正規化	ベクトルの向きを変えずに大きさ(長さ)を1にする事
		//正規化されていないベクトルは大きさの情報が含まれているため、向き情報だけが欲しい場合不要な情報が入っている
		//特定の位置からベクトルの向きに対して実数倍したい場合、ベクトルの大きさが統一されていないと結果が異なる
		planeNormal = VNorm(planeNormal);

		// 球中心に最も近いポリゴン平面の点を求める
		// 球の中心座標からヒットしたポリゴンの座標を引く(一番結果の数が少ないものが中心に近い)
		//tmp	原点0から中心までのベクトル
		VECTOR tmp = moveCandidate - collisionInfo.Dim[i].Position[0];

		//法線ベクトルと当たったポリゴン平面
		//ベクトルの内積	2つの成分の角度
		//dot	tmp(中心までのベクトル)とplaneNormal(法線ベクトル)の内積
		float  dot = VDot(planeNormal, tmp);

		// 衝突点
		//球の中心座標-法線ベクトル
		//planeNormal * dot	planeNormal(正規化された法線ベクトル)にdot(角度、大きさ)をかけているので向きはtmp方向と同じである
		//planeNormal * dotからmoveCandidate(中心)に向かってベクトルhitPosを生成
		//このhitPosは向きと座標を求めており大きさではない
		//概念としてはplaneNormal * dot方向からmoveCandidate方向にあるとある点
		VECTOR hitPos = moveCandidate - planeNormal * dot;

		// 球がどれくらいめり込んでいるかを算出
		//moveCandidate(球の中心)からhitpos方向にベクトルtmp2を生成
		//このtmp2はhitPos(とある点)からmoveCandidate(中心)に向かって向きと大きさを持ったベクトル
		VECTOR tmp2 = moveCandidate - hitPos;
		//tmp2の距離を算出
		float  len = VSize(tmp2);

		// めり込んでいる場合は球の中心を押し戻し
		// HitCheck_Sphere_Triangle();	球と三角形の当たり判定、めり込んでいるか？
		//moveCandidate(中心) radius(半径)	当たり判定の球
		//collisionInfo.Dim[i].Position[0~2]	当たったポリゴンの頂点
		if (HitCheck_Sphere_Triangle(moveCandidate, radius,
			collisionInfo.Dim[i].Position[0],
			collisionInfo.Dim[i].Position[1],
			collisionInfo.Dim[i].Position[2]) == TRUE)
		{
			// めり込み解消する位置まで移動
			VECTOR moveVec;

			//半径からめり込み解消位置までの距離をマイナス
			len = radius - len;

			//法線ベクトルの向きに従っためり込み解消位置の情報をmoveVecに
			moveVec = planeNormal * len;

			//球の中心からmoveVecを足して球の中心をどこの座標に持っていくか計算
			moveCandidate += moveVec;
		}
	}
	// 移動候補を移動位置にする
	//計算した座標を移動位置として確定
	newCenter = moveCandidate;

	// 押し戻し量を返却
	// 実際の中心から移動位置までのベクトルを返却
	return newCenter - sphere->mWorldCenter;
}
