#include<Dxlib.h>
#include "KeyStatus.h"

//ポインターの中身を空に
std::unique_ptr<KeyStatus> KeyStatus::singleton = nullptr;

void KeyStatus::InitKeyStatus()
{
    //自身の中身が空だったらインスタンス生成
    if (!singleton)
    {
        singleton.reset(new KeyStatus);
    }
}

KeyStatus::KeyStatus()
{
    //処理なし
}

//使いかた
//シーン切り替え if (KeyStatus::KeyStateDecision(KEY_INPUT_RETURN, ONINPUT))
//(エンターキー、入力中)
bool KeyStatus::KeyStateDecision(int key, int flag)
{
    //first();       指定された範囲から値を取得
    //end();         最後尾要素の次を指すイテレータを取得
    auto findData = singleton->keyData.find(key);

    //キーが格納されていなかったら保存
    if (findData == singleton->keyData.end())
    {
        //構造体の初期化
        KeyParam keyParam = {};
        //キーの状態を格納する
        //任意の位置に要素を直接構築で挿入する (入力されたキー,キーステータス)
        singleton->keyData.emplace(key, keyParam);
    }

    //ステータス切り替え
    ChangeKeyState(key);

    //判定結果を返す
    //キーの今の状態と判定したい状態を判定する
    if (singleton->keyData[key].inputState & flag)
    {
        //同じだったらtrueを返す
        return true;
    }
    return false;
}

void KeyStatus::ChangeKeyState(int key)
{
    //キーが格納されてたら切り替え処理
    auto findData = singleton->keyData.find(key);

    //findDataに何も入ってなかったら
    if (findData != singleton->keyData.end())
    {
        //変数にコピーを作らない型 auto&
        auto& data = singleton->keyData[key];

        //ステータスの切り替えをする
        //キーが押されていたら
        if (CheckHitKey(key))
        {
            //初期化処理
            //キーを最初に入力したとき
            if (data.inputState & (UNINPUT | NOWUNINPUT))
            {
                data.inputState = ONINPUT;
                return;
            }
            data.inputState = NOWONINPUT;
        }
        else//押されていなかったら
        {
            //初期化処理
            //キー入力を最初に終えた時
            if (data.inputState & (ONINPUT | NOWONINPUT))
            {
                data.inputState = UNINPUT;
                return;
            }
            //キー入力がない間
            data.inputState = NOWUNINPUT;
        }
    }
}

//キー状態を未入力にセット
KeyStatus::KeyParam::KeyParam()
    :inputState(UNINPUT)
{
    //処理なし
}

KeyStatus::~KeyStatus()
{
    //データの中身があるなら削除
    if (keyData.size() > 0)
    {
        keyData.clear();
    }
}
