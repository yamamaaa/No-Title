#pragma once
#include<memory>

//final 継承を防ぐ為のもの
class GameSetting final
{
public:

    // 実体があるときに初期化するためコンストラクタとは別に初期化の関数を作る

    /// <summary>
    /// 初期化
    /// </summary>
    static void Init();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~GameSetting();

private:

    // 実体を作成した場合にprivateにコンストラクタを作る

    /// <summary>
    /// コンストラクタ
    /// </summary>
    GameSetting();

    /// <summary>
    /// ライブラリ初期化前の処理
    /// </summary>
    static void BeforeLibInit();

    /// <summary>
    /// ライブラリ初期化後の処理
    /// </summary>
    static void AfterLibInit();

    //std::unique_ptrとは
    //指定されたリソースへのポインタの所有権を唯一持っているかのように振舞える
    //これを使うと後処理をしなくても良い

    //クラスの実体
    //インスタンス生成を一回しかしない場合に作る
    static std::unique_ptr<GameSetting> singleton;
};

