#include "BackGround.h"

//�v���C���[��ROAD_COLLISION�͈͓̔��݈̂ړ��\
//��Q���͂��ׂ�STAGE_COLLISION���Q�ƁA������X�N���[��������
//�v���C���[�ȊO�̃I�u�W�F�N�g�͈��̃X�s�[�h�Ői��
//�v���C���[���~�܂��Ă�ROAD_COLLISION�͈͓̔��ɂƂǂ܂�(�����X�N���[��)
//���̎��A�I�u�W�F�N�g�ɋ��܂�A�͈͊O�ɏo�Ă��܂����玀�S�����ɂ���

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
    //�����Ȃ�
}

void BackGround::ModelLoad()
{
    //�R�c���f���̓ǂݍ���
    mModelHandle= MV1DuplicateModel(AssetManager::ModelInstance()->GetHandle(
        AssetManager::ModelInstance()->GetJsonData()[ObjTag.BACKGROUND.c_str()].GetString()));

    //�X�e�[�W�̃R���W�������f����ǂݍ���
    /*mCollisionModel.push_back(MV1DuplicateModel(AssetManager::ModelInstance()->GetHandle(
        AssetManager::ModelInstance()->GetJsonData()[ObjTag.STAGE_COLLISION.c_str()].GetString())));*/

    //���̃R���W�������f����ǂݍ���
    /*mCollisionModel.push_back(AssetManager::ModelInstance()->GetHandle(
        AssetManager::ModelInstance()->GetJsonData()[ObjTag.ROAD_COLLISION.c_str()].GetString()));*/

    //���f���̈ʒu
    MV1SetPosition(mModelHandle, mPos);
    //�X�P�[�����Z�b�g
    MV1SetScale(mModelHandle, VGet(0.1f, 0.1f, 0.1f));

    // �R���W�������f���̏����ݒ�
    for (auto& CollisonObj : mCollisionModel)
    {
        //�X�e�[�W�̕������ɍ��W������邽�ߍĐݒ�
        mPos = VGet(130.0f,0.0f,0.0f);
        //�R���W�������f���̈ʒu�ݒ�
        MV1SetPosition(CollisonObj, mPos);
        //�X�P�[�����Z�b�g
        MV1SetScale(CollisonObj, VGet(7.0f, 2.0f, 2.0f));
        //�R���W���������\�z
        MV1SetupCollInfo(CollisonObj);
        //�����蔻��p���f���̕s�����x��ݒ�
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
    //�X�e�[�W�̈ړ�����
    if (mPos.x == MIN_X)
    {
        //�[�܂Ŗ߂�
        mPos.x = MAX_X;
    }
    else
    {
        mPos.x -= SPEED * deltaTime;
    }
    //���f���̈ʒu
    MV1SetPosition(mModelHandle, mPos);
}

void BackGround::Draw()
{
    MV1DrawModel(mModelHandle);
    DrawFormatString(0, 80, GetColor(255, 255, 255), "ST X:%f Y:%f Z:%f", mPos.x, mPos.y, mPos.z);
    DrawCollider();
}
