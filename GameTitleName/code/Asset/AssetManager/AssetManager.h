#pragma once
#include<memory>

/// <summary>
/// �A�Z�b�g�Ǘ�
/// </summary>
class AssetManager final
{
public:

    // ���̂�����Ƃ��ɏ��������邽�߃R���X�g���N�^�Ƃ͕ʂɏ������̊֐������

    /// <summary>
    /// �A�Z�b�g�}�l�[�W���[����������
    /// </summary>
    static void InitAssetManager();

    /// <summary>
    /// ���f���C���X�^���X
    /// </summary>
    /// <returns>Model�N���X</returns>
    static class Model* ModelInstance() { return assetManager->model.get(); }

    /// <summary>
    /// ���[�V�����C���X�^���X
    /// </summary>
    /// <returns>Motion�N���X</returns>
    static class Motion* MotionInstance();

    /// <summary>
    /// �T�E���h�C���X�^���X
    /// </summary>
    /// <returns>Sound�N���X</returns>
    static class Sound* SoundInstance() { return assetManager->sound.get(); }

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~AssetManager();

private:
    /// <summary>
    /// �R���X�g���N�^(�V���O���g��)
    /// </summary>
    AssetManager();

    static std::unique_ptr<AssetManager> assetManager;      //���g�̎���

    std::unique_ptr<class Model> model;                           //���f��
    std::unique_ptr<class Motion> motion;                         //���[�V����
    std::unique_ptr<class Sound> sound;                           //�T�E���h
};

