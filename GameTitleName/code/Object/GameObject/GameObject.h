#pragma once
#include<DxLib.h>
#include<../Rapidjson/rapidjson.h>
#include<string>
#include <vector>

#include"../Collision/Collision.h"
#include"../Collision/CollisionType.h"

#include"ObjectTag.h"
#include"../../Asset/Model/Model.h"
#include"../../Asset/Motion/Motion.h"
#include"../../Asset/Sound/Sound.h"
#include"../../Asset/AssetManager/AssetManager.h"

class GameObj
{
	//継承するものはpublicに
public:
	/// <summary>
	/// オブジェクトコンストラクタ オブジェクトの状態を取得
	/// </summary>
	/// <param name="tag">オブジェクトの名前</param>
	GameObj(std::string tag);

	/*/// <summary>
	/// オブジェクトコンストラクタ オブジェクトの位置をセット
	/// </summary>
	/// <param name="tag"></param>
	/// <param name="pos"></param>
	GameObj(std::string tag, VECTOR pos);*/

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~GameObj();

	/*/// <summary>
	/// 位置情報取得
	/// </summary>
	/// <returns>特定のオブジェクトの位置</returns>
	const VECTOR& GetPos() const { return mPos; }*/

	/*/// <summary>
	/// 位置情報セット
	/// </summary>
	/// <param name="set">オブジェクトの位置</param>
	void SetPos(const VECTOR set) { mPos = set; }*/

	/// <summary>
	/// 可視状態の取得
	/// </summary>
	/// <returns>可視状態</returns>
	bool GetVisible() const { return mVisible; }

	/// <summary>
	/// 可視状態のセット
	/// </summary>
	/// <param name="visible">セットする可視状態</param>
	void SetVisible(bool visible) { mVisible = visible; }

	/// <summary>
	/// オブジェクトの生死判定取得
	/// </summary>
	/// <returns>true:生きている</returns>
	bool GetAlive() const { return mAlive; }

	/// <summary>
	/// 生死状態をセット
	/// </summary>
	/// <param name="alive">true:生きている</param>
	void SetAlive(bool alive) { mAlive = alive; }

	//virtual 値が変わるもの 座標等
	//例 boolだとfalseかtureしか返さないが、座標はそのたび値が変わる 頻繁に変わるものにつける

	/// <summary>
	/// ゲームオブジェクトの更新処理
	/// </summary>
	/// <param name="deltaTime"デルタタイム></param>
	virtual void  Update(float deltaTime) = 0;

	/// <summary>
	/// すべてのゲームオブジェクトの描画
	/// </summary>
	virtual void  Draw() {};

	/// <summary>
	/// ゲームオブジェクトのタグ取得
	/// </summary>
	/// <returns>ゲームオブジェクトの種類</returns>
	std::string     GetTag()const { return mTag; }

	// 当たり判定関連
	virtual void  OnCollisonEnter(const GameObj* other) {}              // 他のオブジェクトとぶつかったときのリアクション（あれば）
	virtual void  ObjCollision(GameObj* other) {};                      // このオブジェクトとの当たり判定

	CollisionType GetCollisionType() const { return mCollisionType; }      // このオブジェクトが持っている当たり判定種を取得
    Collision GetCollisionSphere() const { return mCollisionSphere; }  // 当たり判定球を返却（持っていれば）
	std::vector<int> GetCollisionModel() const { return mCollisionModel; }    // 当たり判定モデルを返却（持っていれば)

	//基底クラスから private にクラスを派生させた場合、
	//基底クラスの全 protected メンバーは、派生クラスの private メンバーになります
	//同一クラスまたは同一インスタンスおよび、サブクラスおよびそのインスタンス内でのみアクセス可能
protected:

	/// <summary>
	/// オブジェクト座標算出処理
	/// </summary>
	/// <returns>座標</returns>
	void CalcObjPos();

	void          DrawCollider();
	void          CollisionUpdate();                           // 当たり判定位置の更新

	std::string   mTag;                                        // オブジェクト種類

	bool          mVisible;                                    // 可視状態
	bool          mAlive;                                      // 生死状態

	int mModelHandle;       // モデルハンドル
	VECTOR mPos;            // オブジェクト位置
	VECTOR objScale;        //オブジェクトの大きさ
	VECTOR objWorldPos;     //ワールド座標
	VECTOR objLocalPos;     //ローカル座標
	VECTOR objDir;          //方向

	class Model* model;     //モデル
	class Sound* sound;     //サウンド
	class Motion* motion;   //モーション

	// 当たり判定関連

	CollisionType mCollisionType; // 当たり判定タイプ
	Collision mCollisionSphere;   // 当たり判定球

	std::vector<int> mCollisionModel;    //当たり判定用モデル
};

