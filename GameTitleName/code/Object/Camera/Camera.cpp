#include "Camera.h"

using namespace math;

Camera::Camera()
    :GameObj(ObjTag.CAMERA)
	, mPos()
	, mLookPos()
	, mCamOffset()
	, mAimCamPos()
{
	mCamOffset = VGet(-80.0f,80.0f,0.0f);
}

Camera::~Camera()
{
    //�����Ȃ�
}

void Camera::Update(const float deltaTime)
{
	//�J�����̒��ڒn�_=�v���C���[�̍��W
	GameObj*player=GameObjectManager::GetFirstGameObj(ObjTag.Player);

	if (player)
	{
		//�v���C���[�̈ʒu����ڕW�n�_�ɃZ�b�g
		mLookPos = player->GetObjPos();
		Move(deltaTime);
	}
}

void Camera::Move(const float deltaTime)
{
	//�J�����̃|�W�V����=���ړ_(�v���C���[�̍��W)+�R���X�g���N�^�ŏ����ݒ肵���v���C���[����̃J�����ʒu
	//�v���C���[�̍��W�͏�ɓ������ߒ��ړ_�Ƃ��Čv�Z����K�v������
	mAimCamPos = mLookPos + mCamOffset;

	//// �J�����ʒu����ڕW�_�Ɍ������x�N�g�����v�Z
	//VECTOR lookMoveDir = mAimLookPos - mLookPos;
	//VECTOR posMoveDir = mAimCamPos - mPos;

	//// �����_�ƁA�J�����ʒu�����X�ɖڕW�n�_�ɋ߂Â���
	//mLookPos += lookMoveDir * camSpringStrength * deltaTime;
	//mPos += posMoveDir * camSpringStrength * deltaTime;

	mPos += mAimCamPos-mPos;
}


void Camera::Draw()
{
	//�J�����̎��_�A�����_�A�A�b�v�x�N�g����ݒ肷��( �A�b�v�x�N�g���͂x���������瓱���o�� )
	SetCameraPositionAndTarget_UpVecY(mPos, mLookPos);
	//SetCameraPositionAndTarget_UpVecY(VGet(-50, 200, -100), VGet(0.0f, 50.0f, 0.0f));   //���΂ߏォ�璆�S������
}
