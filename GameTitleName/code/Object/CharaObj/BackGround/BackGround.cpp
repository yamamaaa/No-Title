#include "BackGround.h"

//�v���C���[��ROAD_COLLISION�͈͓̔��݈̂ړ��\
//��Q���͂��ׂ�STAGE_COLLISION���Q�ƁA������X�N���[��������
//�v���C���[�ȊO�̃I�u�W�F�N�g�͈��̃X�s�[�h�Ői��
//�v���C���[���~�܂��Ă�ROAD_COLLISION�͈͓̔��ɂƂǂ܂�(�����X�N���[��)
//���̎��A�I�u�W�F�N�g�ɋ��܂�A�͈͊O�ɏo�Ă��܂����玀�S�����ɂ���


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
    //�����Ȃ�
}

void BackGround::ModelLoad()
{
    //�R�c���f���̓ǂݍ���
    mModelHandle= MV1DuplicateModel(AssetManager::ModelInstance()->GetHandle(
        AssetManager::ModelInstance()->GetJsonData()[ObjTag.BACKGROUND.c_str()].GetString()));

    //�X�e�[�W�̃R���W�������f����ǂݍ���
    mCollisionModel.push_back(MV1DuplicateModel(AssetManager::ModelInstance()->GetHandle(
        AssetManager::ModelInstance()->GetJsonData()[ObjTag.STAGE_COLLISION.c_str()].GetString())));

    //���̃R���W�������f����ǂݍ���
    mCollisionModel.push_back(MV1DuplicateModel(AssetManager::ModelInstance()->GetHandle(
        AssetManager::ModelInstance()->GetJsonData()[ObjTag.ROAD_COLLISION.c_str()].GetString())));

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

    ModelSetting();
}

void BackGround::ModelposMove(VECTOR move)
{
    //���W�̐ݒ�
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
    //�X�e�[�W�̃X�N���[��
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
