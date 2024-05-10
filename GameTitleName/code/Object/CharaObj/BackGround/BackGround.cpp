#include "BackGround.h"

BackGround::BackGround()
    :GameObj(ObjTag.BACKGROUND)
{
    ModelLoad();
}

BackGround::~BackGround()
{
    //処理なし
}

void BackGround::ModelLoad()
{
    // ３Ｄモデルの読み込み
    mModelHandle = AssetManager::ModelInstance()->GetHandle(
        AssetManager::ModelInstance()->GetJsonData()[ObjTag.BACKGROUND.c_str()].GetString());

    //ステージのコリジョンモデルを読み込み
    mCollisionModel.push_back(AssetManager::ModelInstance()->GetHandle(
        AssetManager::ModelInstance()->GetJsonData()[ObjTag.STAGE_COLLISION.c_str()].GetString()));

    //道のコリジョンモデルを読み込み
    mCollisionModel.push_back(AssetManager::ModelInstance()->GetHandle(
        AssetManager::ModelInstance()->GetJsonData()[ObjTag.ROAD_COLLISION.c_str()].GetString()));

    //モデルの位置
    MV1SetPosition(mModelHandle, mPos);
    //スケールをセット
    MV1SetScale(mModelHandle, VGet(0.1f, 0.1f, 0.1f));

    // コリジョンモデルの初期設定
    for (auto& CollisonObj : mCollisionModel)
    {
        //コリジョンモデルの位置設定
        MV1SetPosition(CollisonObj, mPos);
        //スケールをセット
        MV1SetScale(CollisonObj, VGet(0.1f, 0.1f, 0.1f));
        //コリジョン情報を構築
        MV1SetupCollInfo(CollisonObj);
        //当たり判定用モデルの不透明度を設定
        MV1SetOpacityRate(CollisonObj, 0.3f);
    }

    ModelCopy();
}

void BackGround::ModelCopy()
{
    // コピー関連
   for (auto &mModelCopy: mDrawModelobj)
   {
       //ステージ
       mModelCopy = MV1DuplicateModel(mModelHandle);
       //モデルの位置
       MV1SetPosition(mModelCopy, mPos=VGet(30.0f, 30.0f, 30.0f));
   }

   mDrawModelobj;///push_back
}

void BackGround::CollisionSet(int CollisionModel)
{
}

void BackGround::Update(float deltaTime)
{

}

void BackGround::Draw()
{
    MV1DrawModel(mModelHandle);
    //for (auto& CollisonObj : mCollisionModel)

    for (auto m : mDrawModelobj)
    {
        MV1DrawModel(m);
    }
    DrawCollider();
    /*SetCameraPositionAndTarget_UpVecY(VGet(-80, 80, 0), VGet(0, 0, 0));*/
}
