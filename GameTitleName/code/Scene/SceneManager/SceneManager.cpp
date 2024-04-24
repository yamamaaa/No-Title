#include <DxLib.h>
#include<assert.h>

#include "../../Object/GameObjectManager/GameObjectManager.h"
#include "../../Asset/AssetManager/AssetManager.h"
#include "../../Scene/SceneManager/SceneManager.h"
#include "../../Scene/SceneBase/SceneBase.h"
#include "../../KeyStatus/KeyStatus.h"
#include "../../FPS/FPS.h"
#include "../Title/Title.h"

SceneManager::SceneManager()
	:holdScene(nullptr)
	,fps(new FPS)
{
	//�����Z�b�g�A�b�v
	GameObjectManager::Initialize();
	AssetManager::InitAssetManager();
	KeyStatus::InitKeyStatus();
	//�^�C�g����ʂ�
	nowScene.emplace(new Title);
}

SceneManager::~SceneManager()
{
	//�����Ȃ�
}

void SceneManager::GameLoop()
{
	// �G�X�P�[�v�L�[��������邩�E�C���h�E��������܂Ń��[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//�V�[���̃t���[
		UpdateScene();    //�X�V����
		ChangeScene();    //�؂�ւ�����
		DrawScene();      //�`�揈��
	}
}

void SceneManager::UpdateScene()
{
	//���݂̃V�[�����X�V����holdscene�ɑ��
	fps->Update();
	//.top()	���̗v�f�ւ̎Q�Ƃ�Ԃ�
	holdScene = nowScene.top()->UpdateScene(fps->GetDeltaTime());
}

void SceneManager::DrawScene()
{
	ClearDrawScreen();					// ��ʂ��N���A
	nowScene.top()->DrawScene();		// ���̃V�[����\��
	ScreenFlip();						// ����ʂ̓��e��\��ʂɔ��f
}

void SceneManager::ChangeScene()
{
	// nowScene��tmpScene�ƈقȂ��Ă����������đ��
	// .get()	�^�v���ƌ��Ȃ���^����w�肵���ʒu�̗v�f���擾
	// ���̃V�[������������Ȃ�������
	if (nowScene.top().get() != holdScene)
	{
		//pop();	���̗v�f���폜
		nowScene.pop();

		//emplace()	�R���e�i�ɐV�����v�f��}��
		nowScene.emplace(holdScene);

		//assert()	���g���Ȃ�������v���O�������ُ�I��
		//empty()	�w�肵���v�f�̒��g����ɂ���
		assert(!nowScene.empty());
	}
}
