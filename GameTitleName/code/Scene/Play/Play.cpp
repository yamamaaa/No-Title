#include "Play.h"
#include"../../KeyStatus/KeyStatus.h"
#include"../Title/Title.h"
#include"../../Object/CharaObj/Player/Player.h"
#include"../../Object/Camera/Camera.h"

Play::Play()
{
    //全オブジェクト生成
    GameObjectManager::Entry(new Player);
    GameObjectManager::Entry(new Camera);
    GameObjectManager::Entry(new BackGround);

   /* VECTOR n = VGet(65.0f, 0.0f, 0.0f);*/

    //ステージの複製
   /* mbackground.push_back(BackGround());
    mbackground.push_back(BackGround());

    mbackground[0].ModelposMove(VGet(65.0f, 0.0f, 0.0f));
    mbackground[1].ModelposMove(VGet(130.0f, 0.0f, 0.0f));*/
    //vector インスタンスの生成 c++

    md.push_back(GameObjectManager());
}

Play::~Play()
{
    //処理なし
}

SceneBase* Play::UpdateScene(const float deltaTime)
{
    //オブジェクト更新
    GameObjectManager::Update(deltaTime);
    for (auto& mBackGround : mbackground)
    {
        //プレイヤーが動いたら座標の変更
        //mBackGround.;
    }
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
