#pragma once
#include"../SceneBase/SceneBase.h"
#include"../../Object/CharaObj/BackGround/BackGround.h"
#include"../../Object/GameObjectManager/GameObjectManager.h"

#include<vector>

class Play:public SceneBase
{
public:
    
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Play();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Play();

private:

    /// <summary>
    /// シーン更新処理
    /// </summary>
    /// <param name="deltaTime">デルタタイム</param>
    /// <returns>次フレームのシーン</returns>
    SceneBase* UpdateScene(const float deltaTime)override;

    /// <summary>
    /// シーン描画処理
    /// </summary>
    void DrawScene() override;

    //std::vector<BackGround> mbackground;     //backgroundのインスタンス複製
    //std::vector<GameObjectManager> md;     //backgroundのインスタンス複製

};

