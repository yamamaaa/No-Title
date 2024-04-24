#pragma once
#include<DxLib.h>
#include<memory>

/// <summary>
/// ゲーム管理
/// </summary>
class GameManager final
{
public:

    /// <summary>
    /// コンストラクタ
    /// </summary>
    GameManager();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~GameManager();

    /// <summary>
    /// 後処理
    /// </summary>
    void Procces();

private:

    //シーンマネージャー
    std::unique_ptr<class SceneManager> sceneManager;
};

