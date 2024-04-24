#include "Math3D.h"

namespace math
{
	bool operator==(const VECTOR& lhs, const VECTOR& rhs)
	{
		if (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z)
		{
			return true;
		}
		return false;
	}

	//-------------------------------------------------------------------------------
	// @brief �x�N�g�����m�̉��Z
	//-------------------------------------------------------------------------------
	VECTOR operator+(const VECTOR& lhs, const VECTOR& rhs)
	{
		VECTOR ret;
		ret.x = lhs.x + rhs.x;
		ret.y = lhs.y + rhs.y;
		ret.z = lhs.z + rhs.z;
		return ret;
	}
	//-------------------------------------------------------------------------------
	// @brief �x�N�g�����m�̌��Z
	//-------------------------------------------------------------------------------
	VECTOR operator-(const VECTOR& lhs, const VECTOR& rhs)
	{
		VECTOR ret;
		ret.x = lhs.x - rhs.x;
		ret.y = lhs.y - rhs.y;
		ret.z = lhs.z - rhs.z;
		return ret;
	}
	//-------------------------------------------------------------------------------
	// @brief �x�N�g���̃X�J���[�{
	//-------------------------------------------------------------------------------
	VECTOR operator*(float s, const VECTOR& rhs)
	{
		VECTOR ret;
		ret.x = s * rhs.x;
		ret.y = s * rhs.y;
		ret.z = s * rhs.z;
		return ret;
	}
	//-------------------------------------------------------------------------------
	// @brief �x�N�g���̃X�J���[�{
	//-------------------------------------------------------------------------------
	VECTOR operator*(const VECTOR& lhs, float s)
	{
		VECTOR ret;
		ret.x = s * lhs.x;
		ret.y = s * lhs.y;
		ret.z = s * lhs.z;
		return ret;
	}
	//-------------------------------------------------------------------------------
	// @brief += VECTOR�̉��Z�q
	//-------------------------------------------------------------------------------
	VECTOR operator+=(VECTOR& lhs, const VECTOR& rhs)
	{
		lhs = lhs + rhs;
		return lhs;
	}

	//-------------------------------------------------------------------------------
	// @brief *= VECTOR�̃X�J���[�{�̕���������Z�q
	//-------------------------------------------------------------------------------
	VECTOR operator*=(VECTOR& lhs, float rhs)
	{
		lhs = lhs * rhs;
		return lhs;
	}

	////-------------------------------------------------------------------------------
	//// @brief �Q�̃x�N�g���̊p�x�͂قړ�����
	//// @param[in] v1 �����������x�N�g��1
	//// @param[in] v2 �����������x�N�g��2
	//// @return ����قړ����p�x�ł���� true �قȂ��false��Ԃ�
	////-------------------------------------------------------------------------------
	//bool IsNearAngle(const VECTOR& v1, const VECTOR& v2)
	//{
	//	float dot = VDot(v1, v2);
	//	if (dot > 0.99f)
	//	{
	//		return true;
	//	}
	//	return false;
	//}

	////-------------------------------------------------------------------------------
	//// @param[in] nowVec ���݂̕����x�N�g��
	//// @param[in] dirVec �ڕW�����x�N�g��
	//// @return float ���v�������̎���+1.0 �����v�������̎��� -1.0��Ԃ�.
	////-------------------------------------------------------------------------------
	//float CalcRotationDirectionYAxis(const VECTOR& nowVec, const VECTOR& dirVec)
	//{
	//	VECTOR axis;
	//	axis = VCross(nowVec, dirVec);
	//	if (axis.y < 0.0f)
	//	{
	//		return -1.0f;
	//	}
	//	return 1.0f;
	//}

	////-------------------------------------------------------------------------------
	//// @brief nowVec���� aimVec�Ɍ�������degreeVerociy�̑��x��Y��]����.
	//// @param[in] nowVec ���݂̕����x�N�g��
	//// @param[in] aimVec �ڕW�����x�N�g��
	////-------------------------------------------------------------------------------
	//VECTOR RotateForAimVecYAxis(const VECTOR& nowVec, const VECTOR& aimVec, float degreeVerocity)
	//{
	//	// �p���x�i�x���j�����W�A���p�ɕϊ��A�E��肩����肩�𒲂ׂ�
	//	float rotRadian = (DX_PI_F * degreeVerocity / 180.0f);
	//	rotRadian *= CalcRotationDirectionYAxis(nowVec, aimVec);

	//	// Y����]�s����쐬����
	//	MATRIX yrotMat = MGetRotY(rotRadian);

	//	// Y����]����
	//	VECTOR rotVec;
	//	rotVec = VTransform(nowVec, yrotMat);

	//	return rotVec;
	//}
};