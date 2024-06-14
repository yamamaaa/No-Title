#include<assert.h>
#include "GameObjectManager.h"

//実体の中身を空に
std::unique_ptr<GameObjectManager>GameObjectManager::mpInstance = nullptr;

GameObjectManager::GameObjectManager()
	: mObjects()
{
	mpInstance = nullptr;
}

GameObjectManager::~GameObjectManager()
{
	ReleaseAllObj();
}

void GameObjectManager::Initialize()
{
	//自身の中身が空ならインスタンス生成
	if (!mpInstance)
	{
		mpInstance.reset(new GameObjectManager);
	}
}

void GameObjectManager::Entry(GameObj* newObj)
{
	//タグの検索
	std::string tag=newObj->GetTag();
	// オブジェクトの登録
	mpInstance->mObjects[tag].emplace_back(newObj);
}

void GameObjectManager::ReleaseAllObj()
{
	// すべてのアクティブオブジェクトを削除
	//auto &をつけることによりtagゲームオブジェクトとタグの紐づけをする
	//関数の参照渡しと同じ原理で関数内のコピーした数字だけを消すのではなく関数内で直接削除する感覚
	for (std::string& tag : ObjectTagAll)
	{
		// 末尾から削除
		// empty()	指定した要素の中身を空にする
		// while (mObjects[tag]の中身が空じゃない間)
		while (!mpInstance->mObjects[tag].empty())
		{
			//delete	削除 箱の中身を消す
			//playerという箱がある	箱の中身(座標等)を削除
			delete mpInstance->mObjects[tag].back().get();

			//オブジェクトを保管している箱自体を削除
			//playerという箱がある	箱を削除
			mpInstance->mObjects[tag].pop_back();
		}
	}
}

void GameObjectManager::Update(float deltaTime)
{
	// すべてのアクターの更新
	for (auto& tag : ObjectTagAll)
	{
		// 該当タグにあるすべてのオブジェクトを更新
		for (auto& obj : mpInstance->mObjects[tag])
		{
			//更新
			obj->Update(deltaTime);
		}
	}

	//死亡オブジェクトを探す
	onDeadobj();
}

void GameObjectManager::onDeadobj()
{
	//全タグ分死亡オブジェクトを探して削除
	for (auto& tag : ObjectTagAll)
	{
		for (auto& dead : mpInstance->mObjects[tag])
		{
			//死んでいたらオブジェクト削除
			if (dead&&!dead->GetAlive())
			{
				Deleteobj(dead);
			}
		}
	}
}

void GameObjectManager::Deleteobj(std::shared_ptr<GameObj> unnecObj)
{
	//削除オブジェクトのタグ取得
	std::string tag = unnecObj->GetTag();

	//オブジェクトを検索
	auto endObj = mpInstance->mObjects[tag].end();
	auto findObj = std::find(mpInstance->mObjects[tag].begin(), endObj, unnecObj);

	//見つかったら末尾に移動させて削除
	if (findObj != endObj)
	{
		std::swap(findObj, endObj);
		mpInstance->mObjects[tag].pop_back();
	}
}

void GameObjectManager::Draw()
{
	//すべてのオブジェクトタグ
	for (auto& tag : ObjectTagAll)
	{
		for (auto& obj : mpInstance->mObjects[tag])
		{
			//	もしこのオブジェクトが見える状態だったら
			if (obj->GetVisible())
			{
				//そのオブジェクトと個数を表示させるようにする
				obj->Draw();
			}
		}
	}
}

void GameObjectManager::Collision()
{
	//playerに関する当たり判定
	for (auto& playernum : mpInstance->mObjects[ObjTag.Player])
	{
		// player vs BackGround 組み合わせチェック
		for (auto& bgnum : mpInstance->mObjects[ObjTag.BACKGROUND])
		{
			//壁とぶつかったら
			playernum->OnCollisonEnter(bgnum.get());
		}
		for (auto& sonum : mpInstance->mObjects[ObjTag.STAGE_OBJ])
		{
			//ゲームオーバーの線分に当たったら
			playernum->OnCollisonEnter(sonum.get());
		}

	//	// player vs 障害物 組み合わせチェック
	//	for (auto& Impnum : mpInstance->mObjects[ObjTag.Impediment])
	//	{
	//		//障害物とぶつかったら
	//		/*playernum->OnCollisonEnter(Impnum);*/
	//	}
	}
}

GameObj* GameObjectManager::GetFirstGameObj(std::string tag)
{
	//アクティブリストに何も入ってなかったら
	if (mpInstance->mObjects[tag].size() == 0)
	{
		//nullptr 空 何もない
		return nullptr;
	}
	//もし入っていたらアクティブリストのオブジェクトの一番目(個数)を返す
	return mpInstance->mObjects[tag][0].get();
}