#pragma once
#include <DxLib.h>

namespace math
{
    /// <summary>
   /// 角度からラジアンへの変換処理
   /// </summary>
   /// <param name="degre">:角度</param>
   /// <returns>変換後のラジアン角</returns>
    template <typename T> float DegToRad(T degre)
    {
        return degre * DX_PI_F / 180.0f;
    }

    /// <summary>
    /// ラジアンから角度への変換処理
    /// </summary>
    /// <param name="rad">:</param>
    /// <returns>変換後の角度</returns>
    template <typename T> float RadToDeg(T rad)
    {
        return rad * 180.0f / DX_PI_F;
    }

    /// <summary>
    /// ベクトルの相似判定
    /// </summary>
    /// <param name="lhs">:左辺ベクトル</param>
    /// <param name="rhs">:右辺ベクトル</param>
    /// <returns>ベクトルの一致:true|不一致:false</returns>
    bool operator==(const VECTOR& lhs, const VECTOR& rhs);


    // @brief ベクトル同士の加算
    VECTOR operator+(const VECTOR& lhs, const VECTOR& rhs);

    // @brief ベクトル同士の減算
    VECTOR operator-(const VECTOR& lhs, const VECTOR& rhs);

    // @brief ベクトルのスカラー倍
    VECTOR operator*(float s, const VECTOR& rhs);

    // @brief ベクトルのスカラー倍
    VECTOR operator*(const VECTOR& lhs, float s);

    // @brief += VECTORの演算子
    VECTOR operator+=(VECTOR& lhs, const VECTOR& rhs);

    // @brief -= VECTORの演算子
    VECTOR operator-=(VECTOR& lhs, const VECTOR& rhs);

    // @brief *= VECTORのスカラー倍の複合代入演算子
    VECTOR operator*=(VECTOR& lhs, float rhs);

    //// @brief ２つのベクトルの角度はほぼ同じか
    //bool IsNearAngle(const VECTOR& v1, const VECTOR& v2);

    //// @brief nowVecからdirVecの最短の回転方向を調べる（Y軸回転を想定)
    //float CalcRotationDirectionYAxis(const VECTOR& nowVec, const VECTOR& dirVec);

    //// @brief nowVecから aimVecに向かってdegreeVerociyの速度でY回転する.
    //VECTOR RotateForAimVecYAxis(const VECTOR& nowVec, const VECTOR& aimVec, float degreeVerocity);
};