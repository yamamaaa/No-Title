#include "GameObject.h"

//�Q�[���I�u�W�F�N�g�̏ڍ׎擾
GameObj::GameObj(std::string tag)
	: mTag(tag)
	, model(AssetManager::ModelInstance())
	, motion(AssetManager::MotionInstance())
	, sound(AssetManager::SoundInstance())
	, mModelHandle(-1)
	, mPos(VGet(0, 0, 0))
	, objScale(VGet(1.0f, 1.0f, 1.0f))
	, objWorldPos(VGet(0, 0, 0))
	, objLocalPos(VGet(0, 0, 0))
	, objDir(VGet(1, 0, 0))
	, mVisible(true)
	, mAlive(true)
	, mCollisionType()
	, mCollisionLine()
	, mCollisionSphere()
	, mCollisionModel()
{
}

GameObj::~GameObj()
{
	if (mModelHandle != -1)//���f���n���h��������
	{
		/*AssetManager::ReleaseMesh(mModelHandle);*/
		mModelHandle = -1;
	}
}

void GameObj::CalcObjPos()
{
	//���[���h���W�ƃ��[�J�����W�𑫂��č��W���Z�o
	mPos = VAdd(objWorldPos, objLocalPos);
}

void GameObj::DrawCollider()
{
	//�����̐���
	DrawLine3D(mCollisionLine.mWorldStart, mCollisionLine.mWorldEnd, GetColor(255, 255, FALSE));
	// ���̓����蔻��̕`��
	DrawSphere3D(mCollisionSphere.mWorldCenter, mCollisionSphere.mRadius, 10, GetColor(0, 255, 255), GetColor(0, 0, 0), FALSE);

	// �R���W�������f�������݂���ꍇ�͔������`��
	for (auto &CollisonObj : mCollisionModel)
	{
		if (CollisonObj != -1)
		{
			////�`����u�����h���[�h��
			//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
			//���f���̕\��
			MV1DrawModel(CollisonObj);
			//// �u�����h���[�h�̉���
			//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		}
	}
}

void GameObj::CollisionUpdate()
{
	//���̓����蔻��̍X�V
	mCollisionSphere.Move(mPos);
	mCollisionLine.Move(mPos);

	// ���f���̓����蔻������č\�z
	for (auto& CollisonObj : mCollisionModel)
	{
		if (CollisonObj != -1)
		{
			MV1SetPosition(CollisonObj, mPos);		//���f���n���h���̍��W�擾(�����蔻��p�̃��f��,���f�����W)
			MV1SetupCollInfo(CollisonObj);			//�����蔻�����V�������
		}
	}
}