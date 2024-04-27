#include "Play.h"
#include"../../Object/GameObjectManager/GameObjectManager.h"
#include"../../KeyStatus/KeyStatus.h"
#include"../Title/Title.h"
#include"../../Object/CharaObj/Player/Player.h"
#include"../../Object/Camera/Camera.h"
#include"../../Object/CharaObj/BackGround/BackGround.h"

Play::Play()
{
    //全オブジェクト生成
    GameObjectManager::Entry(new Player);
    GameObjectManager::Entry(new Camera);
    GameObjectManager::Entry(new BackGround);
}

Play::~Play()
{
    //処理なし
}

SceneBase* Play::UpdateScene(const float deltaTime)
{
    //オブジェクト更新
    GameObjectManager::Update(deltaTime);
    GameObjectManager::Collision();

    //エンターキーでゲーム終了
    if (KeyStatus::KeyStateDecision(KEY_INPUT_RETURN, ONINPUT))
    {
        GameObjectManager::ReleaseAllObj();
        /*return new Title;*/
        return 0;
    }

    return this;
}

void Play::DrawScene()
{
    //全オブジェクトの描画
    GameObjectManager::Draw();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "play");
}
