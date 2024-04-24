#pragma once
#include <unordered_map>
#include <memory>
#include <vector>
#include <DxLib.h>

#include "../GameObject/GameObject.h"
#include "../GameObject/ObjectTag.h"

//staticクラス	メンバがすべてstatic(静的)になっている、メンバはこのクラス内でしか使用しない
//staticメンバはインスタンス化の必要がないため、コンストラクタとデストラクタをprivateにしてインスタンス化を禁止にする
class GameObjectManager final
{
public:

	//　静的メンバとは、クラスのオブジェクト(インスタンス)ごとではなく、クラスに属するメンバ
	//　staticメンバ関数は、staticメンバ以外のメンバは直接参照できない
	//　通常の関数との違いは クラスに属するためprotected や private のメンバにもアクセスできる
	//　ststicクラスは同じ情報をクラス内で共有したいときに使われる

	/// <summary>
	/// 初期化
	/// </summary>
	static void Initialize();

	/// <summary>
	/// ゲームオブジェクト登録
	/// </summary>
	/// <param name="tag">登録する名前</param>
	/// <param name="newObj">オブジェクト</param>
	static void Entry(GameObj* newObj);

	/// <summary>
	/// 全オブジェクトの削除
	/// </summary>
	static void ReleaseAllObj();

	/// <summary>
	/// 全オブジェクトの更新処理
	/// </summary>
	/// <param name="deltaTime">デルタタイム</param>
	static void Update(float deltaTime);

	/// <summary>
	/// すべてのオブジェクトの描画
	/// </summary>
	static void Draw();

	/// <summary>
	/// 全オブジェクトの当たり判定
	/// </summary>
	static void Collision();

	/// <summary>
	/// タグ種類の初めのオブジェクトを返す
	/// </summary>
	/// <param name="tag">オブジェクトの種類</param>
	/// <returns>最初のオブジェクト</returns>
	static GameObj* GetFirstGameObj(std::string tag);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameObjectManager();
private:

	/// <summary>
	/// コンストラクタ(シングルトン)
	/// </summary>
	GameObjectManager();

	/// <summary>
	/// オブジェクト死亡処理
	/// </summary>
	static void onDeadobj();

	/// <summary>
	/// ゲームオブジェクトの削除処理
	/// </summary>
	/// <param name="unnecObj">不要なオブジェクト</param>
	static void Deleteobj(std::shared_ptr<GameObj> unnecObj);

	//std::unique_ptrとは
	//指定されたリソースへのポインタの所有権を唯一持っているかのように振舞える
	static std::unique_ptr<GameObjectManager> mpInstance;      // マネージャの実体

	//オブジェクトリスト　タグの種類からオブジェクトの個数を割り出す
	// mObjects[タグ種類][オブジェクト個数]; 
	std::unordered_map<std::string, std::vector<std::shared_ptr<GameObj>>> mObjects;
};

