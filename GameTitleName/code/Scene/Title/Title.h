#pragma once
#include "../SceneBase/SceneBase.h"

/// <summary>
/// タイトルシーン
/// </summary>
class Title:public SceneBase
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Title();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Title();

	/// <summary>
	/// シーン更新処理
	/// </summary>
	/// <param name="deltaTime">フレームルート</param>
	/// <returns>次のシーン</returns>
	SceneBase* UpdateScene(const float deltaTime) override;

	/// <summary>
	/// シーン描画処理
	/// </summary>
	void DrawScene() override;
};

