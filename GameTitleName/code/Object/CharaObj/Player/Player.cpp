#include "Player.h"

using namespace math;

Player::Player() 
	: CharaObjBase(ObjTag.Player)
{
	// ３Ｄモデルの読み込み
	mModelHandle = AssetManager::ModelInstance()->GetHandle(
		AssetManager::ModelInstance()->GetJsonData()[ObjTag.Player.c_str()].GetString());
    objLocalPos = VGet(65.0f, 2.2f, 0.0f);

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
    //落下処理
    /*mDownSpeed += mG;
    mPos.y = mDownSpeed * deltaTime;*/

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

    //落下速度をリセット
    mDownSpeed = 0;
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
      
        for (auto& colModel : other->GetCollisionModel())
        {
            if (CollisionPair(&mCollisionSphere, colModel, colInfo))
            {
                objLocalPos = VAdd(objLocalPos, CalcSpherePushBackVecFromMesh(&mCollisionSphere, colInfo));
                CollisionUpdate();
            }
        }
        CalcObjPos();
        MV1SetMatrix(mModelHandle, MMult(rotateMat, MGetTranslate(mPos)));
    }
    if (tag == ObjTag.STAGE_OBJ)
    {
        if (CollisionPair(other->GetCollisionLine(), mCollisionSphere))
        {
            //当たっていたら死亡にする
            mAlive = false;
        }
    }
    
}

void Player::Draw()
{
	MV1DrawModel(mModelHandle);
    DrawCollider();

    DrawFormatString(0, 20, GetColor(255, 255, 255) ,"猫 X:%f Y:%f Z:%f", mPos.x,mPos.y,mPos.z);
}
