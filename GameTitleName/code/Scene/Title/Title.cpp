#include <Dxlib.h>

#include "Title.h"
#include"Play.h"
#include "SceneBase.h"
#include "KeyStatus.h"

Title::Title()
	:SceneBase()
{
	//処理なし
}

Title::~Title()
{
	//処理なし
}

SceneBase* Title::UpdateScene(const float deltaTime)
{

	//シーン切り替え
	if (KeyStatus::KeyStateDecision(KEY_INPUT_RETURN, ONINPUT))
	{
		//プレイ中に切り替え
		return new Play;
	}

	return this;
}

void Title::DrawScene()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
	//オブジェクト描画
}
