#include "Player.h"
//int MV1SetLoadModelPhysicsWorldGravity( float Gravity ) ;

Player::Player() 
	: CharaObjBase(ObjTag.Player)
{

   

	// ３Ｄモデルの読み込み
	mModelHandle = AssetManager::ModelInstance()->GetHandle(
		AssetManager::ModelInstance()->GetJsonData()[ObjTag.Player.c_str()].GetString());
    objLocalPos = VGet(0, 50, 0);

    // MV1SetScale()	モデルの拡大値をセット
    MV1SetScale(mModelHandle, VGet(0.02f, 0.02f, 0.02f));

    CalcObjPos();
	MV1SetPosition(mModelHandle, mPos);

    // 当たり判定球セット
    mCollisionType = CollisionType::Sphere;

    //球の半径セット
    mCollisionSphere.mRadius = 8.0f;

    //移動速度は走る速度
    moveSpeed = RUN_SPEED;
}

Player::~Player()
{
	//処理なし
}

void Player::Update(float deltaTime)
{
    a += deltaTime;
    //アニメーション時間再生
    motion->AddMotionTime(deltaTime);

    //キャラ移動
    MoveChara(deltaTime);


    //動作中
    if (isMove)
    {
        //オブジェクトの座標算出
        CalcObjPos();

        //行列でモデルの動作
        MV1SetMatrix(mModelHandle, MMult(rotateMat, MGetTranslate(mPos)));
    }
    //停止中
    else
    {
        //通常時アニメーション再生
        motion->StartMotion(mModelHandle,
            motion->GetHandle(GetFilePass(motionData[jsondata::objKey.nomal.c_str()])));
    }

    //Pキーが押されたら
    if (KeyStatus::KeyStateDecision(KEY_INPUT_P, ONINPUT))
    {
        //死亡にする
        mAlive = false;

        //サウンド再生
        sound->StartSound(sound->GetHandle(GetFilePass(soundData[jsondata::objKey.walk.c_str()])));
    }

    //当たり判定モデルも位置更新
    CollisionUpdate();
    //停止中にする
    isMove = false;
}

void Player::MoveChara(const float deltaTime)
{
    //キー入力による上下左右移動
    MoveByKey(KEY_INPUT_W, FRONT, deltaTime);
    MoveByKey(KEY_INPUT_S, BACK, deltaTime);
    MoveByKey(KEY_INPUT_A, LEFT, deltaTime);
    MoveByKey(KEY_INPUT_D, RIGHT, deltaTime);
}

void Player::MoveByKey(const int keyName, const VECTOR dir, const float deltaTime)
{
    //キーが入力されていたら移動時の処理実行
    if (KeyStatus::KeyStateDecision(keyName, ONINPUT | NOWONINPUT))
    {
        //移動アニメーション再生
        motion->StartMotion(mModelHandle,
            motion->GetHandle(GetFilePass(motionData[jsondata::objKey.walk.c_str()])));

        //座標・方向の算出
        objLocalPos = VAdd(objLocalPos, VScale(dir, moveSpeed * deltaTime));
        RotateYAxis(dir, ROTATE_SPEED);

        //動作中にする
        isMove = true;
    }
}

void Player::OnCollisonEnter(const GameObj* other)
{
    MV1_COLL_RESULT_POLY_DIM colInfo{};
    for (auto& colModel : other->GetCollisionModel())
    {
        if (mCollisionSphere.CollisionPair(&mCollisionSphere, colModel, colInfo))
        {
            objLocalPos =VAdd(objLocalPos, mCollisionSphere.CalcSpherePushBackVecFromMesh(&mCollisionSphere, colInfo));
        }
    }
    //球体当たり判定の更新
    CollisionUpdate();

    CalcObjPos();
    MV1SetMatrix(mModelHandle, MMult(rotateMat, MGetTranslate(mPos)));
}



void Player::Draw()
{
    int CrY = GetColor(255, 255, 0);//黄色
    int CrR = GetColor(255, 0, 0);//赤色
    int CrB = GetColor(0, 0, 255);//青色
    //線の表示(中心0,0,0)
    DrawLine3D(VGet(-1000, 0, 0), VGet(1000, 0, 0), CrR);//横 x　赤
    DrawLine3D(VGet(0, -1000, 0), VGet(0, 1000, 0), CrY);//縦 y　黄
    DrawLine3D(VGet(0, 0, -1000), VGet(0, 0, 1000), CrB);//奥(前後) z　青
	MV1DrawModel(mModelHandle);
	/*SetCameraPositionAndTarget_UpVecY(VGet(-110, 80, 0), VGet(0, 0, 0));*/
    DrawCollider();
   /* DrawFormatString(0, 20, GetColor(255, 255, 255) ,"猫 %f", mPos);*/
}
