#include "BackGround.h"

BackGround::BackGround()
    :GameObj(ObjTag.BACKGROUND)
{
    ModelLoad();
}

BackGround::~BackGround()
{
    //�����Ȃ�
}

void BackGround::ModelLoad()
{
    // �R�c���f���̓ǂݍ���
    mModelHandle = AssetManager::ModelInstance()->GetHandle(
        AssetManager::ModelInstance()->GetJsonData()[ObjTag.BACKGROUND.c_str()].GetString());

    //�X�e�[�W�̃R���W�������f����ǂݍ���
    mCollisionModel.push_back(AssetManager::ModelInstance()->GetHandle(
        AssetManager::ModelInstance()->GetJsonData()[ObjTag.STAGE_COLLISION.c_str()].GetString()));

    //���̃R���W�������f����ǂݍ���
    mCollisionModel.push_back(AssetManager::ModelInstance()->GetHandle(
        AssetManager::ModelInstance()->GetJsonData()[ObjTag.ROAD_COLLISION.c_str()].GetString()));

    //���f���̈ʒu
    MV1SetPosition(mModelHandle, mPos);
    //�X�P�[�����Z�b�g
    MV1SetScale(mModelHandle, VGet(0.1f, 0.1f, 0.1f));

    // �R���W�������f���̏����ݒ�
    for (auto& CollisonObj : mCollisionModel)
    {
        //�R���W�������f���̈ʒu�ݒ�
        MV1SetPosition(CollisonObj, mPos);
        //�X�P�[�����Z�b�g
        MV1SetScale(CollisonObj, VGet(0.1f, 0.1f, 0.1f));
        //�R���W���������\�z
        MV1SetupCollInfo(CollisonObj);
        //�����蔻��p���f���̕s�����x��ݒ�
        MV1SetOpacityRate(CollisonObj, 0.3f);
    }

    ModelCopy();
}

void BackGround::ModelCopy()
{
    // �R�s�[�֘A
   for (auto &mModelCopy: mDrawModelobj)
   {
       //�X�e�[�W
       mModelCopy = MV1DuplicateModel(mModelHandle);
       //���f���̈ʒu
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
