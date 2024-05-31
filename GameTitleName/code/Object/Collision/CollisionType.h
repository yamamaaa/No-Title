#pragma once

namespace Collision
{
enum class CollisionType //当たり判定のタイプ 形状
{
	Line,          // 線分
	Sphere,        // 球
	Model          // モデル（メッシュ)
};

}