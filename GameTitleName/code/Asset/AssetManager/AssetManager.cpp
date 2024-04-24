#include"../Model/Model.h"
#include"../Motion/Motion.h"
#include"../Sound/Sound.h"
#include "../AssetManager/AssetManager.h"

std::unique_ptr<AssetManager> AssetManager::assetManager = nullptr;

void AssetManager::InitAssetManager()
{
    //���g�̒��g���󂾂�����C���X�^���X����
    if (!assetManager)
    {
        assetManager.reset(new AssetManager);
    }
}

AssetManager::AssetManager()
    :model(new Model)
    , motion(new Motion(model.get()))//���f���Ƃ̕R�t�̂���
    , sound(new Sound)
{
    //�����Ȃ�
}

AssetManager::~AssetManager()
{
    //�n���h���폜
    model->DeleteHandle();
    motion->DeleteHandle();
    sound->DeleteHandle();
}

Motion* AssetManager::MotionInstance()
{
    return assetManager->motion.get();
}
