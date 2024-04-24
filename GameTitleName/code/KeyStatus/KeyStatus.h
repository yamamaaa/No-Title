#pragma once
#include<unordered_map>
#include<memory>

constexpr int UNINPUT = 0x0001;     //未入力時
constexpr int NOWUNINPUT = 0x0002;  //未入力中
constexpr int ONINPUT = 0x0004;     //入力時
constexpr int NOWONINPUT = 0x0008;  //入力中

/// <summary>
/// KeyStatusクラス
/// </summary>
class KeyStatus final
{
public:
	/// <summary>
	/// キー入力初期化処理
	/// </summary>
	static void InitKeyStatus();

	/// <summary>
	/// 入力判定処理
	/// </summary>
	/// <param name="key">判定したいキー</param>
	/// <param name="flag">判定フラグ</param>
	/// <returns>キーステータスがフラグと一致 : true|不一致 : false</returns>
	static bool KeyStateDecision(int key, int flag);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~KeyStatus();

private:

	//シングルトンのクラス	最初の１度のみ作成したインスタンスをクラス内全体で使い回す
	//クラスのインスタンスを一つしか生成しないものを指す

	/// <summary>
	/// コンストラクタ　シングルトン
	/// </summary>
	KeyStatus();

	struct KeyParam
	{
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		KeyParam();

		int inputState;			//入力ステータス
	};

	/// <summary>
	/// キーステータス切り替え処理
	/// </summary>
	/// <param name="key">:切り替えたいキー</param>
	static void ChangeKeyState(int key);

	//実態はクラス内の情報すべてを持っている　インスタンス生成と同じ考え方
	static std::unique_ptr<KeyStatus> singleton;        //自身の実体

	//構造体のデータを持つ
	std::unordered_map<int, KeyParam> keyData;          //キーデータ
};

