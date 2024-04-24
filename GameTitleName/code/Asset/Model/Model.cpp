#include<DxLib.h>
#include<assert.h>
#include<future>

#include "Model.h"

Model::Model()
    :AssetBase()
{
    //json�t�@�C���ǂݍ���
    jsonFile = "ModelData.json";
    LoadJsonFile(jsonFile);

    //�I�u�W�F�N�g���n���h���ǉ�
    for (rapidjson::Value::ConstMemberIterator objType = GetJsonData().MemberBegin();
        objType != GetJsonData().MemberEnd(); objType++)
    {
        AddHandle(objType->value.GetString());
    }
}

Model::~Model()
{
    //�����Ȃ�
}

void Model::AddHandle(const std::string fileName)
{
    //���n���h��������
    holdHandle = -1;
    dupHandle = -1;

    //�t�@�C����������Ȃ�������n���h���𕡐����Ēǉ�
    auto iter = handle.find(fileName);
    if (iter == handle.end())
    {
        holdHandle = MV1LoadModel(fileName.c_str());
        dupHandle = MV1DuplicateModel(holdHandle);
        handle.emplace(fileName, dupHandle);
    }
}

void Model::DeleteHandle()
{
    //�n���h���ƃf�[�^���
    for (auto& iter : handle)
    {
        MV1DeleteModel(iter.second);
    }
    handle.clear();
}
