#include "Camera.h"

using namespace math;

Camera::Camera()
    :GameObj(ObjTag.CAMERA)
	, mPos()
	, mLookPos()
	, mCamOffset()
	, mAimCamPos()
{
	mCamOffset = VGet(-80.0f,80.0f,0.0f);
}

Camera::~Camera()
{
    //処理なし
}

void Camera::Update(const float deltaTime)
{
	//カメラの注目地点=プレイヤーの座標
	GameObj*player=GameObjectManager::GetFirstGameObj(ObjTag.Player);

	if (player)
	{
		//プレイヤーの位置情報を目標地点にセット
		mLookPos = player->GetObjPos();
		Move(deltaTime);
	}
}

void Camera::Move(const float deltaTime)
{
	//カメラのポジション=注目点(プレイヤーの座標)+コンストラクタで初期設定したプレイヤーからのカメラ位置
	//プレイヤーの座標は常に動くため注目点として計算する必要がある
	mAimCamPos = mLookPos + mCamOffset;

	//// カメラ位置から目標点に向かうベクトルを計算
	//VECTOR lookMoveDir = mAimLookPos - mLookPos;
	//VECTOR posMoveDir = mAimCamPos - mPos;

	//// 注視点と、カメラ位置を徐々に目標地点に近づける
	//mLookPos += lookMoveDir * camSpringStrength * deltaTime;
	//mPos += posMoveDir * camSpringStrength * deltaTime;

	mPos += mAimCamPos-mPos;
}


void Camera::Draw()
{
	//カメラの視点、注視点、アップベクトルを設定する( アップベクトルはＹ軸方向から導き出す )
	SetCameraPositionAndTarget_UpVecY(mPos, mLookPos);
	//SetCameraPositionAndTarget_UpVecY(VGet(-50, 200, -100), VGet(0.0f, 50.0f, 0.0f));   //左斜め上から中心を見る
}
