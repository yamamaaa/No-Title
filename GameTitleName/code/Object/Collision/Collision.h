#pragma once
#include <DxLib.h>
#include"../Math3D/Math3D.h"

class Collision final
{
public:

	VECTOR mLocalCenter; // ���̂̃��[�J�����S���W
	VECTOR mWorldCenter; // ���̂̃��[���h���S���W
	float  mRadius;      // ���̂̔��a

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Collision();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Collision();

	/// <summary>
	/// �����l�Z�b�g�@�R���X�g���N�^
	/// </summary>
	/// <param name="center">���W</param>
	/// <param name="radius">���a</param>
	Collision(const VECTOR& center, float radius);

	/// <summary>
	/// ���̂���������
	/// </summary>
	/// <param name="pos">�I�u�W�F�N�g���ݒn</param>
	void Move(const VECTOR& pos);

	/// <summary>
	/// ���̂ƃ��b�V���̓����蔻��
	/// </summary>
	/// <param name="sphere">��</param>
	/// <param name="modelHandle">���b�V���̃��f��ID</param>
	/// <param name="collisionInfo">HIT���̃|���S�����X�g</param>
	/// <returns>�������Ă��� : true</returns>
	bool CollisionPair(const Collision* sphere, int modelHandle, MV1_COLL_RESULT_POLY_DIM& collisionInfo);

	/// <summary>
	/// ���̂ƃ��b�V���Ƃ̓����艟���߂��ʌv�Z
	/// </summary>
	/// <param name="sphere">����</param>
	/// <param name="collisionInfo">MV1CollCheck_Sphere()�֐����Ԃ��Փˏ��</param>
	/// <returns>���̂����b�V�����痣�������̈ړ��x�N�g��</returns>
	VECTOR CalcSpherePushBackVecFromMesh(const Collision* sphere, const MV1_COLL_RESULT_POLY_DIM& collisionInfo);
};

