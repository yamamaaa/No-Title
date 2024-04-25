#include "Collision.h"
#include"../../Object/Math3D/Math3D.h"
#include <DxLib.h>
using namespace math;

Collision::Collision()
	: mLocalCenter()
	, mWorldCenter()
	, mRadius(0.0f)
{
}

Collision::~Collision()
{
	//�����Ȃ�
}

Collision::Collision(const VECTOR& center, float radius)
	: mLocalCenter(center)
	, mWorldCenter(center)
	, mRadius(radius)
{
}

void Collision::Move(const VECTOR& pos)
{
	//�I�u�W�F�N�g���ݒn(pos)�ƈړ��O�̃��[�J�����W�𑫂����ƂŃ��[���h���W���o��
	mWorldCenter = VAdd(mLocalCenter, pos);
}

bool Collision::CollisionPair(const Collision* sphere, int modelHandle, MV1_COLL_RESULT_POLY_DIM& collisionInfo)
{
	// �����蔻��̋��ƃ��f���̓����蔻��
	collisionInfo = MV1CollCheck_Sphere(modelHandle, -1, sphere->mWorldCenter, sphere->mRadius);

	//�������Ă���|���S�����[���ł����
	if (collisionInfo.HitNum == 0)
	{
		return false;
	}
	return true;
}

VECTOR Collision::CalcSpherePushBackVecFromMesh(const Collision* sphere, const MV1_COLL_RESULT_POLY_DIM& collisionInfo)
{
	// �Փˋ�
	// �����S��� ���̒��S���W�̃R�s�[(�v�Z�Ɏg���̂Ńv���O�����ɉe��������ۂ̒��S�������Ă��Ă͂����Ȃ�)
	VECTOR moveCandidate = sphere->mWorldCenter;
	float  radius = sphere->mRadius; // �����a

	//�|���S���̗��\�𔻒�A�\�̂ق��ɖ�󂪍s��
	VECTOR planeNormal;                    // �|���S�����ʖ@��

	VECTOR moveVec = VGet(0, 0, 0);    // �ړ��x�N�g��
	float  moveLen = 0.0f;           // �ړ���

	VECTOR newCenter = sphere->mWorldCenter; // �ړ����

	int i = 0, j = 0;

	// �Փ˃|���S�������ׂĉ���āA���̂߂荞�݂���������
	//collisionInfo.HitNum	���������|���S���̐�
	for (i = 0; i < collisionInfo.HitNum; ++i)
	{
		// �Փ˃|���S���̕� 
		//���������|���S���̒��_���m����Ō���
		//�|���S���̕ӂ����o���邱�Ƃɂ��O�p�̌`���ł���
		VECTOR edge1, edge2;

		//�|���S���̒��_0�����_�Ƃ���
		//0����1�̃x�N�g��(����)(01�x�N�g����1-0������Ƃł���)
		edge1 = collisionInfo.Dim[i].Position[1] - collisionInfo.Dim[i].Position[0];
		//0����2�̃x�N�g��(����)
		edge2 = collisionInfo.Dim[i].Position[2] - collisionInfo.Dim[i].Position[0];

		// �Փ˃|���S���̕ӂ��A�|���S���ʂ̖@���x�N�g��(�|���S���̕\��)�����߂�
		//�x�N�g���̊O�ς��v�Z(�x�N�g���̊O�ς��v�Z���邱�Ƃɂ��@���x�N�g�����ꏏ�ɋ��߂��邽��)
		//�x�N�g���̊O��	��̐����̌��������킹������ ��̌����̐^��
		//���̎��@���x�N�g���̓|���S���̌��_0����o�Ă���
		planeNormal = VCross(edge1, edge2);

		//�x�N�g���̐��K��	�x�N�g���̌�����ς����ɑ傫��(����)��1�ɂ��鎖
		//���K������Ă��Ȃ��x�N�g���͑傫���̏�񂪊܂܂�Ă��邽�߁A������񂾂����~�����ꍇ�s�v�ȏ�񂪓����Ă���
		//����̈ʒu����x�N�g���̌����ɑ΂��Ď����{�������ꍇ�A�x�N�g���̑傫�������ꂳ��Ă��Ȃ��ƌ��ʂ��قȂ�
		planeNormal = VNorm(planeNormal);

		// �����S�ɍł��߂��|���S�����ʂ̓_�����߂�
		// ���̒��S���W����q�b�g�����|���S���̍��W������(��Ԍ��ʂ̐������Ȃ����̂����S�ɋ߂�)
		//tmp	���_0���璆�S�܂ł̃x�N�g��
		VECTOR tmp = moveCandidate - collisionInfo.Dim[i].Position[0];

		//�@���x�N�g���Ɠ��������|���S������
		//�x�N�g���̓���	2�̐����̊p�x
		//dot	tmp(���S�܂ł̃x�N�g��)��planeNormal(�@���x�N�g��)�̓���
		float  dot = VDot(planeNormal, tmp);

		// �Փ˓_
		//���̒��S���W-�@���x�N�g��
		//planeNormal * dot	planeNormal(���K�����ꂽ�@���x�N�g��)��dot(�p�x�A�傫��)�������Ă���̂Ō�����tmp�����Ɠ����ł���
		//planeNormal * dot����moveCandidate(���S)�Ɍ������ăx�N�g��hitPos�𐶐�
		//����hitPos�͌����ƍ��W�����߂Ă���傫���ł͂Ȃ�
		//�T�O�Ƃ��Ă�planeNormal * dot��������moveCandidate�����ɂ���Ƃ���_
		VECTOR hitPos = moveCandidate - planeNormal * dot;

		// �����ǂꂭ�炢�߂荞��ł��邩���Z�o
		//moveCandidate(���̒��S)����hitpos�����Ƀx�N�g��tmp2�𐶐�
		//����tmp2��hitPos(�Ƃ���_)����moveCandidate(���S)�Ɍ������Č����Ƒ傫�����������x�N�g��
		VECTOR tmp2 = moveCandidate - hitPos;
		//tmp2�̋������Z�o
		float  len = VSize(tmp2);

		// �߂荞��ł���ꍇ�͋��̒��S�������߂�
		// HitCheck_Sphere_Triangle();	���ƎO�p�`�̓����蔻��A�߂荞��ł��邩�H
		//moveCandidate(���S) radius(���a)	�����蔻��̋�
		//collisionInfo.Dim[i].Position[0~2]	���������|���S���̒��_
		if (HitCheck_Sphere_Triangle(moveCandidate, radius,
			collisionInfo.Dim[i].Position[0],
			collisionInfo.Dim[i].Position[1],
			collisionInfo.Dim[i].Position[2]) == TRUE)
		{
			// �߂荞�݉�������ʒu�܂ňړ�
			VECTOR moveVec;

			//���a����߂荞�݉����ʒu�܂ł̋������}�C�i�X
			len = radius - len;

			//�@���x�N�g���̌����ɏ]�����߂荞�݉����ʒu�̏���moveVec��
			moveVec = planeNormal * len;

			//���̒��S����moveVec�𑫂��ċ��̒��S���ǂ��̍��W�Ɏ����Ă������v�Z
			moveCandidate += moveVec;
		}
	}
	// �ړ������ړ��ʒu�ɂ���
	//�v�Z�������W���ړ��ʒu�Ƃ��Ċm��
	newCenter = moveCandidate;

	// �����߂��ʂ�ԋp
	// ���ۂ̒��S����ړ��ʒu�܂ł̃x�N�g����ԋp
	return newCenter - sphere->mWorldCenter;
}
