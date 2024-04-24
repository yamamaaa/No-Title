#pragma once

#include"../AssetBase/AssetBase.h"

/// <summary>
/// �T�E���h�Ǘ�
/// </summary>
class Sound final :public AssetBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Sound();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Sound();

    /// <summary>
    /// �T�E���h�Đ�����
    /// </summary>
    /// <param name="handle">:�n���h��</param>
    void StartSound(int handle);

    /// <summary>
    /// �T�E���h��~����
    /// </summary>
    /// <param name="handle">:�n���h��</param>
    void StopSound(int handle);

    /// <summary>
    /// �n���h���폜����
    /// </summary>
    virtual void DeleteHandle() override;

private:
    /// <summary>
    /// �n���h���ǉ�����
    /// </summary>
    /// <param name="fileName">:�t�@�C����</param>
    void AddHandle(std::string fileName) override;

    /// <summary>
    /// �f�[�^�ǉ�����
    /// </summary>
    /// <param name="key">:json�f�[�^�擾�L�[</param>
    void AddData(const rapidjson::Value& key);

    /// <summary>
    /// �T�E���h�p�����[�^�[
    /// </summary>
    struct SoundParam
    {
    public:
        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        SoundParam();

        std::string soundType;                          //�T�E���h�^�C�v
        bool isLoop;                                    //���[�v�Đ�����
        int volume;                                     //����
    };

    std::unordered_map<int, SoundParam> soundData;      //�T�E���h�f�[�^
};