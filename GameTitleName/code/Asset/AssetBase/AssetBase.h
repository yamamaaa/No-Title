#pragma once

#include <../Rapidjson/istreamwrapper.h>
#include <../Rapidjson/document.h>
#include <fstream>
#include<string.h>
#include<string>
#include<memory>
#include<unordered_map>

#include "JsonKey.h"

/// <summary>
/// �A�Z�b�g���N���X
/// </summary>
class AssetBase
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	AssetBase();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~AssetBase();

    // <summary>
    /// Json�t�@�C���f�[�^�擾����
    /// </summary>
    /// <returns>json�t�@�C���f�[�^</returns>
    const rapidjson::Value& GetJsonData() { return doc[assetType.c_str()]; }

    /// <summary>
    /// �n���h���擾����
    /// </summary>
    /// <param name="handleName">:�n���h����</param>
    /// <returns>�n���h��</returns>
    const int GetHandle(const std::string handleName);

protected:

    /// <summary>
    /// Json�t�@�C���ǂݍ��ݏ���
    /// </summary>
    /// <param name="fileName">:�t�@�C����</param>
    void LoadJsonFile(const std::string fileName);

    /// <summary>
    /// �n���h���ǉ�����
    /// </summary>
    virtual void AddHandle(const std::string fileName) = 0;

    /// <summary>
    /// �n���h���폜����
    /// </summary>
    virtual void DeleteHandle() = 0;

    int holdHandle;                  //�ꎞ�ۑ��n���h��
    int dupHandle;                   //�����n���h��

    std::string assetType;                              //�A�Z�b�g�^�C�v
    std::unordered_map < std::string, int > handle;     //�n���h��

    std::string jsonFile;                               //json�t�@�C��
    rapidjson::Document doc;                            //�h�L�������g
};

