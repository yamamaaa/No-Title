#include<DxLib.h>
#include<assert.h>

#include "../GameSetting/GameSetting.h"
#include"../../Asset/AssetManager/AssetManager.h"
#include"../../Object/GameObjectManager/GameObjectManager.h"

//実体の初期化
std::unique_ptr<GameSetting> GameSetting::singleton = nullptr;

//初期化
void GameSetting::Init()
{
    //実体に何も入ってなかったら
    if (!singleton)
    {
        //インスタンスを生成
        singleton.reset(new GameSetting);
    }
}

//コンストラクタ
GameSetting::GameSetting()
{
    BeforeLibInit();

    // ＤＸライブラリ初期化処理
    if (DxLib_Init() == -1)
    {
        //エラーが起きたら直ちに終了
        DebugBreak();
    }

    AfterLibInit();
}

GameSetting::~GameSetting()
{
    //ライブラリ終了
    DxLib_End();
}

void GameSetting::BeforeLibInit()
{
    //アンチエイリアスを設定
    //以下の関数元の画面解像度の高い解像度の画面に描画した結果を綺麗に縮小したような効果を得ることができる
    SetFullSceneAntiAliasingMode(4, 2);

    // シェーダーの設定
    SetUseDirect3DVersion(DX_DIRECT3D_9EX);

}

void GameSetting::AfterLibInit()
{
    //描画先を裏画面に変更
    SetDrawScreen(DX_SCREEN_BACK);

    //Zバッファ設定
    SetUseZBuffer3D(true);         //Ｚバッファを使用するか？
    SetWriteZBuffer3D(true);       //Ｚバッファに書き込みを行うか？

    AssetManager::InitAssetManager();          //アセットマネージャーの作成
    GameObjectManager::Initialize();     //ゲームオブジェクトマネージャーの作成

    SetBackgroundColor(0, 0, 0);   // 背景色設定
}
