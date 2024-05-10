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
    //３Ｄモデルの読み込み
    mStageObj.push_back((AssetManager::ModelInstance()->GetHandle(
        AssetManager::ModelInstance()->GetJsonData()[ObjTag.BACKGROUND.c_str()].GetString())));

    //ステージのコリジョンモデルを読み込み
    mCollisionModel.push_back(AssetManager::ModelInstance()->GetHandle(
        AssetManager::ModelInstance()->GetJsonData()[ObjTag.STAGE_COLLISION.c_str()].GetString()));

    //道のコリジョンモデルを読み込み
    mCollisionModel.push_back(AssetManager::ModelInstance()->GetHandle(
        AssetManager::ModelInstance()->GetJsonData()[ObjTag.ROAD_COLLISION.c_str()].GetString()));

    //モデルの位置
    MV1SetPosition(mStageObj.front(), mPos);
    //スケールをセット
    MV1SetScale(mStageObj.front(), VGet(0.1f, 0.1f, 0.1f));

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
   for (int i = 1; i < 3; i++)
   {
      mStageObj.emplace_back(MV1DuplicateModel(mStageObj.front()));
      MV1SetScale(mStageObj[i], VGet(0.1f, 0.1f, 0.1f));
   }

   MV1SetPosition(mStageObj[1], mPos = VGet(65.0f, 0.0f, 0.0f));
   MV1SetPosition(mStageObj[2], mPos = VGet(-65.0f, 0.0f, 0.0f));
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

    for (auto m : mStageObj)
    {
        MV1DrawModel(m);
    }
    DrawCollider();
    /*SetCameraPositionAndTarget_UpVecY(VGet(-80, 80, 0), VGet(0, 0, 0));*/
}
