#include "Camera.h"


Camera::Camera()
    :GameObj(ObjTag.CAMERA)
{
    SetCameraNearFar(0.1f, 500.0f);
}

Camera::~Camera()
{
    //�����Ȃ�
}

void Camera::Update(const float deltaTime)
{
 //   mPos = VGet(-100, 100, 0);

	//// �J�����̒����ڕW�_�ƁA�J�����̈ʒu�ڕW�_���v�Z
	//GameObjectManager::Entry(new Player);

	////�J�����̒��ڒn�_=�v���C���[�̍��W
	//std::shared_ptr<Player> player(new Player);

	//mAimLookPos = player->GetPos();

	////�J�����̃|�W�V����=���ړ_(�v���C���[�̍��W)+�R���X�g���N�^�ŏ����ݒ肵���v���C���[����̃J�����ʒu
	////�v���C���[�̍��W�͏�ɓ������ߒ��ړ_�Ƃ��Čv�Z����K�v������
	//mAimCamPos = mAimLookPos + mCamOffset;

	////�Q�[���J�n����̃J�����̓���///////////////////////////

	//// �J�����ʒu����ڕW�_�Ɍ������x�N�g�����v�Z
	//VECTOR lookMoveDir = mAimLookPos - mLookPos;
	//VECTOR posMoveDir = mAimCamPos - mPos;

	//// �����_�ƁA�J�����ʒu�����X�ɖڕW�n�_�ɋ߂Â���
	//mLookPos += lookMoveDir * camSpringStrength * deltaTime;
	//mPos += posMoveDir * camSpringStrength * deltaTime;

	///////////////////////////////////////////////////////////

	////SetCameraPositionAndTarget_UpVecY()��
	////�J�����̎��_�A�����_�A�A�b�v�x�N�g����ݒ肷��( �A�b�v�x�N�g���͂x���������瓱���o�� )
	//SetCameraPositionAndTarget_UpVecY(mPos, mLookPos);
}

void Camera::Draw()
{
 /*   SetCameraPositionAndTarget_UpVecY(mPos, VGet(0, 0, 0));*/
	SetCameraPositionAndTarget_UpVecY(VGet(-50, 200, -100), VGet(0.0f, 50.0f, 0.0f));   //���΂ߏォ�璆�S������
}
