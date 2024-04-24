#include <Dxlib.h>

#include "Title.h"
#include"Play.h"
#include "SceneBase.h"
#include "KeyStatus.h"

Title::Title()
	:SceneBase()
{
	//�����Ȃ�
}

Title::~Title()
{
	//�����Ȃ�
}

SceneBase* Title::UpdateScene(const float deltaTime)
{

	//�V�[���؂�ւ�
	if (KeyStatus::KeyStateDecision(KEY_INPUT_RETURN, ONINPUT))
	{
		//�v���C���ɐ؂�ւ�
		return new Play;
	}

	return this;
}

void Title::DrawScene()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
	//�I�u�W�F�N�g�`��
}
