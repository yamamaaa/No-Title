#include "BackGround.h"

//プレイヤーはROAD_COLLISIONの範囲内のみ移動可能
//障害物はすべてSTAGE_COLLISIONを参照、これもスクロールをする
//プレイヤー以外のオブジェクトは一定のスピードで進む
//プレイヤーが止まってもROAD_COLLISIONの範囲内にとどまる(強制スクロール)
//この時、オブジェクトに挟まり、範囲外に出てしまったら死亡扱いにする


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
    mCollisionModel.push_back(MV1DuplicateModel(AssetManager::ModelInstance()->GetHandle(
        AssetManager::ModelInstance()->GetJsonData()[ObjTag.STAGE_COLLISION.c_str()].GetString())));

    //道のコリジョンモデルを読み込み
    mCollisionModel.push_back(MV1DuplicateModel(AssetManager::ModelInstance()->GetHandle(
        AssetManager::ModelInstance()->GetJsonData()[ObjTag.ROAD_COLLISION.c_str()].GetString())));

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

    ModelSetting();
}

void BackGround::ModelposMove(VECTOR move)
{
    //座標の設定
    mPos= VAdd(mPos,move);
}

void BackGround::ModelSetting()
{
   /*for (int i = 1; i < 3; i++)
   {
      mStageObj.emplace_back(MV1DuplicateModel(mStageObj.front()));
      MV1SetScale(mStageObj[i], VGet(0.1f, 0.1f, 0.1f));
   }

   MV1SetPosition(mStageObj[1], mPos = VGet(65.0f, 0.0f, 0.0f));
   MV1SetPosition(mStageObj[2], mPos = VGet(-65.0f, 0.0f, 0.0f));*/
}

void BackGround::CollisionSet(int CollisionModel)
{
}

void BackGround::Update(float deltaTime)
{
    //ステージのスクロール
}

void BackGround::Draw()
{
    MV1DrawModel(mModelHandle);
    //DrawFormatString(0, 80, GetColor(255, 255, 255), "ST X:%f Y:%f Z:%f", mPos.x, mPos.y, mPos.z);

    /*for (auto mobj : mStageObj)
    {
        MV1DrawModel(mobj);
    }

    for (int i = 1; i < 3; i++)
    {
         DrawFormatString(0, 40, GetColor(255, 255, 255), "ST_0 X:%f Y:%f Z:%f", mStageObj[1].CalcObjPos(), mStageObj[1], mStageObj[1]);
    }*/
    DrawCollider();
    //.VGet(mPos.x, mPos.y, mPos.z));
    /*SetCameraPositionAndTarget_UpVecY(VGet(-80, 80, 0), VGet(0, 0, 0));*/
}
