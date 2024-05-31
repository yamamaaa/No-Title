#include "GameObject.h"

//ゲームオブジェクトの詳細取得
GameObj::GameObj(std::string tag)
	: mTag(tag)
	, model(AssetManager::ModelInstance())
	, motion(AssetManager::MotionInstance())
	, sound(AssetManager::SoundInstance())
	, mModelHandle(-1)
	, mPos(VGet(0, 0, 0))
	, objScale(VGet(1.0f, 1.0f, 1.0f))
	, objWorldPos(VGet(0, 0, 0))
	, objLocalPos(VGet(0, 0, 0))
	, objDir(VGet(1, 0, 0))
	, mVisible(true)
	, mAlive(true)
	, mCollisionType()
	, mCollisionLine()
	, mCollisionSphere()
	, mCollisionModel()
{
}

GameObj::~GameObj()
{
	if (mModelHandle != -1)//モデルハンドルを消す
	{
		/*AssetManager::ReleaseMesh(mModelHandle);*/
		mModelHandle = -1;
	}
}

void GameObj::CalcObjPos()
{
	//ワールド座標とローカル座標を足して座標を算出
	mPos = VAdd(objWorldPos, objLocalPos);
}

void GameObj::DrawCollider()
{
	//足元の線分
	DrawLine3D(mCollisionLine.mWorldStart, mCollisionLine.mWorldEnd, GetColor(255, 255, FALSE));
	// 球体当たり判定の描画
	DrawSphere3D(mCollisionSphere.mWorldCenter, mCollisionSphere.mRadius, 10, GetColor(0, 255, 255), GetColor(0, 0, 0), FALSE);

	// コリジョンモデルが存在する場合は半透明描画
	for (auto &CollisonObj : mCollisionModel)
	{
		if (CollisonObj != -1)
		{
			////描画をブレンドモードに
			//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
			//モデルの表示
			MV1DrawModel(CollisonObj);
			//// ブレンドモードの解除
			//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		}
	}
}

void GameObj::CollisionUpdate()
{
	//球体当たり判定の更新
	mCollisionSphere.Move(mPos);
	mCollisionLine.Move(mPos);

	// モデルの当たり判定情報を再構築
	for (auto& CollisonObj : mCollisionModel)
	{
		if (CollisonObj != -1)
		{
			MV1SetPosition(CollisonObj, mPos);		//モデルハンドルの座標取得(当たり判定用のモデル,モデル座標)
			MV1SetupCollInfo(CollisonObj);			//当たり判定情報を新しく作る
		}
	}
}