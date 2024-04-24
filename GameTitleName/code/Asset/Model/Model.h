#pragma once
#include"../AssetBase/AssetBase.h"

/// <summary>
/// ���f���Ǘ�
/// </summary>
class Model final :public AssetBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Model();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Model();

    /// <summary>
    /// �n���h���폜����
    /// </summary>
    virtual void DeleteHandle() override;

private:
    /// <summary>
    /// �n���h���ǉ�����
    /// </summary>
    /// <param name="fileName">:�t�@�C����</param>
    void AddHandle(const std::string fileName) override;
};
