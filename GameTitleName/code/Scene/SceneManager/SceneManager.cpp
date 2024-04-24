#include <DxLib.h>
#include<assert.h>

#include "../../Object/GameObjectManager/GameObjectManager.h"
#include "../../Asset/AssetManager/AssetManager.h"
#include "../../Scene/SceneManager/SceneManager.h"
#include "../../Scene/SceneBase/SceneBase.h"
#include "../../KeyStatus/KeyStatus.h"
#include "../../FPS/FPS.h"
#include "../Title/Title.h"

SceneManager::SceneManager()
	:holdScene(nullptr)
	,fps(new FPS)
{
	//初期セットアップ
	GameObjectManager::Initialize();
	AssetManager::InitAssetManager();
	KeyStatus::InitKeyStatus();
	//タイトル画面へ
	nowScene.emplace(new Title);
}

SceneManager::~SceneManager()
{
	//処理なし
}

void SceneManager::GameLoop()
{
	// エスケープキーが押されるかウインドウが閉じられるまでループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//シーンのフロー
		UpdateScene();    //更新処理
		ChangeScene();    //切り替え処理
		DrawScene();      //描画処理
	}
}

void SceneManager::UpdateScene()
{
	//現在のシーンを更新してholdsceneに代入
	fps->Update();
	//.top()	次の要素への参照を返す
	holdScene = nowScene.top()->UpdateScene(fps->GetDeltaTime());
}

void SceneManager::DrawScene()
{
	ClearDrawScreen();					// 画面をクリア
	nowScene.top()->DrawScene();		// 次のシーンを表示
	ScreenFlip();						// 裏画面の内容を表画面に反映
}

void SceneManager::ChangeScene()
{
	// nowSceneがtmpSceneと異なっていたら解放して代入
	// .get()	タプルと見なせる型から指定した位置の要素を取得
	// 次のシーンが同じじゃなかったら
	if (nowScene.top().get() != holdScene)
	{
		//pop();	次の要素を削除
		nowScene.pop();

		//emplace()	コンテナに新しい要素を挿入
		nowScene.emplace(holdScene);

		//assert()	中身がなかったらプログラムを異常終了
		//empty()	指定した要素の中身を空にする
		assert(!nowScene.empty());
	}
}
