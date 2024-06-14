#pragma once
#include <DxLib.h>
#include"../Math3D/Math3D.h"


namespace Collision
{
	/// <summary>
	/// ���������蔻��
	/// </summary>
	struct LineSegment
	{
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		LineSegment();

		/// <summary>
		/// �����l�Z�b�g�R���X�g���N�^
		/// </summary>
		/// <param name="startPos">�����J�n�n�_</param>
		/// <param name="endPos">�����I���n�_</param>
		LineSegment(const VECTOR& startPos, const VECTOR& endPos);

		/// <summary>
		/// �����̈ړ�����
		/// </summary>
		/// <param name="pos"></param>
		void Move(const VECTOR& pos);

		//���[�J�����W	�I�u�W�F�N�g�𒆐S�Ƃ������W�̎�
		//�e�̂�����W�𒆐S���W(x=0,y=0,z=0)�Ƃ������W

		//���[���h���W	�Q�[���I�u�W�F�N�g���̈ʒu���������W
		//3D��Ԃ̒��S�𒆐S���W(x=0,y=0,z=0)�Ƃ��Ď�����I�u�W�F�N�g���ǂ��ɂ���̂���\�����W
		//�����蔻��Ŏg�p��������

		//���Έʒu	�����鎩���̈ʒu����ɂ��Ĉʒu��\�����W

		//����	�v���C���[�����̔���
		VECTOR mLocalStart; // �����̃��[�J���J�n���W
		VECTOR mLocalEnd;   // �����̃��[�J���I�����W
		VECTOR mWorldStart; // �����̃��[���h�J�n���W
		VECTOR mWorldEnd;   // �����̃��[���h�I�����W
	};

	/// <summary>
	/// ���̓����蔻��
	/// </summary>
	struct Sphere
	{
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		Sphere();

		/// <summary>
		/// �R���X�g���N�^�����l�Z�b�g
		/// </summary>
		/// <param name="center">���W</param>
		/// <param name="radius">���a</param>
		Sphere(const VECTOR& center, float radius);

		/// <summary>
		/// ���̂̈ړ�����
		///	</summary>
		/// <param name="pos">�I�u�W�F�N�g���ݒn</param>
		void Move(const VECTOR& pos);


		VECTOR mLocalCenter; // ���̂̃��[�J�����S���W
		VECTOR mWorldCenter; // ���̂̃��[���h���S���W
		float  mRadius;      // ���̂̔��a
	};

	/// <summary>
	/// �����Ƌ��̂̓����蔻��
	/// </summary>
	/// <param name="line">����</param>
	/// <param name="sphere">����</param>
	/// <returns>�������Ă��邩�H</returns>
	bool CollisionPair(const LineSegment& line, const Sphere& sphere);

	/// <summary>
	/// �����ƃ��b�V���̓����蔻��
	/// </summary>
	/// <param name="line">����</param>
	/// <param name="modelHandle">���b�V���̃��f��ID</param>
	/// <param name="collisionInfo">�Փ˂����|���S�����X�g</param>
	/// <returns>�����������H</returns>
	bool CollisionPair(const LineSegment& line, const int modelHandle, MV1_COLL_RESULT_POLY& collisionInfo);

	/// <summary>
	/// ���̂ƃ��b�V���̓����蔻��
	/// </summary>
	/// <param name="sphere">��</param>
	/// <param name="modelHandle">���b�V���̃��f��ID</param>
	/// <param name="collisionInfo">HIT���̃|���S�����X�g</param>
	/// <returns>�������Ă��� : true</returns>
	bool CollisionPair(const Sphere* sphere, int modelHandle, MV1_COLL_RESULT_POLY_DIM& collisionInfo);

	/// <summary>
	/// ���̂ƃ��b�V���Ƃ̓����艟���߂��ʌv�Z
	/// </summary>
	/// <param name="sphere">����</param>
	/// <param name="collisionInfo">MV1CollCheck_Sphere()�֐����Ԃ��Փˏ��</param>
	/// <returns>���̂����b�V�����痣�������̈ړ��x�N�g��</returns>
	VECTOR CalcSpherePushBackVecFromMesh(const Sphere* sphere, const MV1_COLL_RESULT_POLY_DIM& collisionInfo);
};

