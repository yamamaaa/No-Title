#include "BackGround.h"

//プレイヤーはROAD_COLLISIONの範囲内のみ移動可能
//障害物はすべてSTAGE_COLLISIONを参照、これもスクロールをする
//プレイヤー以外のオブジェクトは一定のスピードで進む
//プレイヤーが止まってもROAD_COLLISIONの範囲内にとどまる(強制スクロール)
//この時、オブジェクトに挟まり、範囲外に出てしまったら死亡扱いにする

using namespace math;

BackGround::BackGround(VECTOR mpos)
    :GameObj(ObjTag.BACKGROUND)
{
    mPos = mpos;
    ModelLoad();
}

//BackGround::BackGround(const BackGround& mground,VECTOR mpos)
//    :GameObj(ObjTag.BACKGROUND)
//{
//    mPos = mpos;
//    ModelLoad();
//}

BackGround::~BackGround()
{
    //処理なし
}

void BackGround::ModelLoad()
{
    //３Ｄモデルの読み込み
    mModelHandle= MV1DuplicateModel(AssetManager::ModelInstance()->GetHandle(
        AssetManager::ModelInstance()->GetJsonData()[ObjTag.BACKGROUND.c_str()].GetString()));

    //ステージのコリジョンモデルを読み込み
    /*mCollisionModel.push_back(MV1DuplicateModel(AssetManager::ModelInstance()->GetHandle(
        AssetManager::ModelInstance()->GetJsonData()[ObjTag.STAGE_COLLISION.c_str()].GetString())));*/

    //道のコリジョンモデルを読み込み
    /*mCollisionModel.push_back(AssetManager::ModelInstance()->GetHandle(
        AssetManager::ModelInstance()->GetJsonData()[ObjTag.ROAD_COLLISION.c_str()].GetString()));*/

    //モデルの位置
    MV1SetPosition(mModelHandle, mPos);
    //スケールをセット
    MV1SetScale(mModelHandle, VGet(0.1f, 0.1f, 0.1f));

    // コリジョンモデルの初期設定
    for (auto& CollisonObj : mCollisionModel)
    {
        //ステージの複製時に座標がずれるため再設定
        mPos = VGet(130.0f,0.0f,0.0f);
        //コリジョンモデルの位置設定
        MV1SetPosition(CollisonObj, mPos);
        //スケールをセット
        MV1SetScale(CollisonObj, VGet(7.0f, 2.0f, 2.0f));
        //コリジョン情報を構築
        MV1SetupCollInfo(CollisonObj);
        //当たり判定用モデルの不透明度を設定
        MV1SetOpacityRate(CollisonObj, 0.3f);
    }
}

void BackGround::ModelposMove(VECTOR move)
{
}

void BackGround::ModelSetting()
{
  
}

void BackGround::CollisionSet(int CollisionModel)
{
}

void BackGround::Update(float deltaTime)
{
    //ステージの移動処理
    if (mPos.x == MIN_X)
    {
        //端まで戻す
        mPos.x = MAX_X;
    }
    else
    {
        mPos.x -= SPEED * deltaTime;
    }
    //モデルの位置
    MV1SetPosition(mModelHandle, mPos);
}

void BackGround::Draw()
{
    MV1DrawModel(mModelHandle);
    DrawFormatString(0, 80, GetColor(255, 255, 255), "ST X:%f Y:%f Z:%f", mPos.x, mPos.y, mPos.z);
    DrawCollider();
}
