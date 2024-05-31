#include "Player.h"
//int MV1SetLoadModelPhysicsWorldGravity( float Gravity ) ;

//線分でステージとオブジェクトの設置判定
//ジャンプ処理のため今はステージとの接触判定するときか、フラグを管理する

//線分に柵が当たったら死亡にする

Player::Player() 
	: CharaObjBase(ObjTag.Player)
{
	// ３Ｄモデルの読み込み
	mModelHandle = AssetManager::ModelInstance()->GetHandle(
		AssetManager::ModelInstance()->GetJsonData()[ObjTag.Player.c_str()].GetString());
    objLocalPos = VGet(60.0f, 10.0f, 0.0f);

    // MV1SetScale()	モデルの拡大値をセット
    MV1SetScale(mModelHandle, VGet(0.02f, 0.02f, 0.02f));

    CalcObjPos();
	MV1SetPosition(mModelHandle, mPos);

    // 当たり判定球セット
    mCollisionType = CollisionType::Sphere;

    //足元当たり判定線分セット
    mCollisionLine = LineSegment(VGet(0.0f, 20.0f, 0.0f), VGet(0.0, -10.0f, 0.0f));

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
    //当たったゲームオブジェクトのタグを取得
    std::string tag = other->GetTag();

    if (tag == ObjTag.BACKGROUND)
    {
        MV1_COLL_RESULT_POLY_DIM colInfo{};
        MV1_COLL_RESULT_POLY colinfoLine;

        for (auto& colModel : other->GetCollisionModel())
        {
            if (CollisionPair(&mCollisionSphere, colModel, colInfo))
            {
                objLocalPos = VAdd(objLocalPos, CalcSpherePushBackVecFromMesh(&mCollisionSphere, colInfo));
                CollisionUpdate();
            }
            if (CollisionPair(mCollisionLine, colModel, colinfoLine))
            {
                // 当たっている場合は足元を衝突点に合わせる
                mPos = colinfoLine.HitPosition;
                CollisionUpdate();
            }
        }

        CalcObjPos();
        MV1SetMatrix(mModelHandle, MMult(rotateMat, MGetTranslate(mPos)));
    }
}

void Player::Draw()
{
	MV1DrawModel(mModelHandle);
    DrawCollider();

    DrawFormatString(0, 20, GetColor(255, 255, 255) ,"猫 X:%f Y:%f Z:%f", mPos.x,mPos.y,mPos.z);
}
