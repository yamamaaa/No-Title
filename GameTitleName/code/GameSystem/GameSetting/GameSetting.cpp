#include<DxLib.h>
#include<assert.h>

#include "../GameSetting/GameSetting.h"
#include"../../Asset/AssetManager/AssetManager.h"
#include"../../Object/GameObjectManager/GameObjectManager.h"

//���̂̏�����
std::unique_ptr<GameSetting> GameSetting::singleton = nullptr;

//������
void GameSetting::Init()
{
    //���̂ɉ��������ĂȂ�������
    if (!singleton)
    {
        //�C���X�^���X�𐶐�
        singleton.reset(new GameSetting);
    }
}

//�R���X�g���N�^
GameSetting::GameSetting()
{
    BeforeLibInit();

    // �c�w���C�u��������������
    if (DxLib_Init() == -1)
    {
        //�G���[���N�����璼���ɏI��
        DebugBreak();
    }

    AfterLibInit();
}

GameSetting::~GameSetting()
{
    //���C�u�����I��
    DxLib_End();
}

void GameSetting::BeforeLibInit()
{
    //�A���`�G�C���A�X��ݒ�
    //�ȉ��̊֐����̉�ʉ𑜓x�̍����𑜓x�̉�ʂɕ`�悵�����ʂ��Y��ɏk�������悤�Ȍ��ʂ𓾂邱�Ƃ��ł���
    SetFullSceneAntiAliasingMode(4, 2);

    // �V�F�[�_�[�̐ݒ�
    SetUseDirect3DVersion(DX_DIRECT3D_9EX);

}

void GameSetting::AfterLibInit()
{
    //�`���𗠉�ʂɕύX
    SetDrawScreen(DX_SCREEN_BACK);

    //Z�o�b�t�@�ݒ�
    SetUseZBuffer3D(true);         //�y�o�b�t�@���g�p���邩�H
    SetWriteZBuffer3D(true);       //�y�o�b�t�@�ɏ������݂��s�����H

    AssetManager::InitAssetManager();          //�A�Z�b�g�}�l�[�W���[�̍쐬
    GameObjectManager::Initialize();     //�Q�[���I�u�W�F�N�g�}�l�[�W���[�̍쐬

    SetBackgroundColor(0, 0, 0);   // �w�i�F�ݒ�
}
