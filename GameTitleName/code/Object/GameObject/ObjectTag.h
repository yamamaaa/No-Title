#pragma once
#include<string.h>
#include<vector>

/// <summary>
/// ゲーム内アクター・当たり判定の種類別タグ
/// </summary>
static struct ObjectTag
{
	std::string Player = "player";						//プレイヤー
	std::string IMPEDIMENT = "impediment";				//障害物
	std::string BACKGROUND = "background";				//背景
	std::string CAMERA = "camera";						//カメラ
	std::string ROAD_COLLISION = "road_collision";		//ロードコリジョン
	std::string STAGE_COLLISION = "stage_collision";	//ステージコリジョン
}ObjTag;

/// <summary>
/// ループ制御用
/// </summary>
static std::vector<std::string> ObjectTagAll
{
	ObjTag.Player,
	ObjTag.IMPEDIMENT,
	ObjTag.BACKGROUND,
	ObjTag.CAMERA,
	ObjTag.ROAD_COLLISION,
	ObjTag.STAGE_COLLISION,
};