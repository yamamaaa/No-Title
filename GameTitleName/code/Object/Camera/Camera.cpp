#include "Camera.h"


Camera::Camera()
    :GameObj(ObjTag.CAMERA)
{
    SetCameraNearFar(0.1f, 500.0f);
}

Camera::~Camera()
{
    //処理なし
}

void Camera::Update(const float deltaTime)
{
 //   mPos = VGet(-100, 100, 0);

	//// カメラの注視目標点と、カメラの位置目標点を計算
	//GameObjectManager::Entry(new Player);

	////カメラの注目地点=プレイヤーの座標
	//std::shared_ptr<Player> player(new Player);

	//mAimLookPos = player->GetPos();

	////カメラのポジション=注目点(プレイヤーの座標)+コンストラクタで初期設定したプレイヤーからのカメラ位置
	////プレイヤーの座標は常に動くため注目点として計算する必要がある
	//mAimCamPos = mAimLookPos + mCamOffset;

	////ゲーム開始からのカメラの動き///////////////////////////

	//// カメラ位置から目標点に向かうベクトルを計算
	//VECTOR lookMoveDir = mAimLookPos - mLookPos;
	//VECTOR posMoveDir = mAimCamPos - mPos;

	//// 注視点と、カメラ位置を徐々に目標地点に近づける
	//mLookPos += lookMoveDir * camSpringStrength * deltaTime;
	//mPos += posMoveDir * camSpringStrength * deltaTime;

	///////////////////////////////////////////////////////////

	////SetCameraPositionAndTarget_UpVecY()↓
	////カメラの視点、注視点、アップベクトルを設定する( アップベクトルはＹ軸方向から導き出す )
	//SetCameraPositionAndTarget_UpVecY(mPos, mLookPos);
}

void Camera::Draw()
{
 /*   SetCameraPositionAndTarget_UpVecY(mPos, VGet(0, 0, 0));*/
	SetCameraPositionAndTarget_UpVecY(VGet(-50, 200, -100), VGet(0.0f, 50.0f, 0.0f));   //左斜め上から中心を見る
}
