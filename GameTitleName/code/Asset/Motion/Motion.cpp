#include<DxLib.h>

#include "../AssetManager/AssetManager.h"
#include "../Model/Model.h"
#include "../Motion/Motion.h"

Motion::Motion(class Model* model)
    :modelHandle(-1)
    , nowMotionTime(0)
    , nowHandle(-1)
    , attachedIndex(0)
{
    //json�t�@�C���ǂݍ���
    jsonFile = "MotionData.json";
    LoadJsonFile(jsonFile);

    //�I�u�W�F�N�g���f�[�^�ǉ�
    for (rapidjson::Value::ConstMemberIterator objType = GetJsonData().MemberBegin();
        objType != GetJsonData().MemberEnd(); objType++)
    {
        assert(model);
        modelHandle = model->GetHandle(model->GetJsonData()[objType->name.GetString()].GetString());
        for (rapidjson::Value::ConstMemberIterator motionType = objType->value.MemberBegin();
            motionType != objType->value.MemberEnd(); motionType++)
        {
            AddHandle(motionType->value[jsondata::dataKey.pass.c_str()].GetString());
            AddData(motionType->value);
        }
    }
    modelHandle = -1;
}

Motion::~Motion()
{
    //�����Ȃ�
}

void Motion::AddHandle(const std::string fileName)
{
    //���n���h��������
    holdHandle = -1;
    dupHandle = -1;

    //�t�@�C����������Ȃ�������n���h���𕡐����Ēǉ�
    auto findHandle = handle.find(fileName);
    if (findHandle == handle.end())
    {
        holdHandle = MV1LoadModel(fileName.c_str());
        dupHandle = MV1DuplicateModel(holdHandle);
        handle.emplace(fileName, dupHandle);
    }
}

void Motion::AddData(const rapidjson::Value& key)
{
    //�n���h������
    auto handle = GetHandle(key[jsondata::dataKey.pass.c_str()].GetString());
    auto findData = motionData.find(handle);

    //������Ȃ������烂�[�V�����f�[�^�ǉ�
    if (findData == motionData.end())
    {
        MotionParam param = {};
        param.isLoop = key[jsondata::dataKey.loop.c_str()].GetBool();
        param.playSpeed = key[jsondata::dataKey.speed.c_str()].GetFloat();

        //�f�[�^�������̂��߃A�^�b�`
        param.index = MV1GetAnimNum(modelHandle) - 1;
        attachedIndex.emplace(modelHandle, 0);
        attachedIndex[modelHandle] = MV1AttachAnim(modelHandle, param.index, handle, TRUE);
        param.totalTime = MV1GetAnimTotalTime(handle, param.index);
        MV1DetachAnim(modelHandle, attachedIndex[modelHandle]);

        motionData.emplace(handle, param);
    }
}

Motion::MotionParam::MotionParam()
    : isLoop(false)
    , playSpeed(0)
    , index(0)
    , totalTime(0)
{
    //�����Ȃ�
}

void Motion::DeleteHandle()
{
    //�n���h���ƃf�[�^���
    for (auto& iter : handle)
    {
        DeleteSoundMem(iter.second);
    }
    handle.clear();
    motionData.clear();
}

void Motion::AddMotionTime(const float deltaTime)
{
    //�Đ����x�ɍ��킹�ĉ��Z
    if (nowHandle && IsPlaying())
    {
        nowMotionTime += motionData[nowHandle].playSpeed * deltaTime;

        //���[�v�Đ�����
        if (motionData[nowHandle].isLoop &&
            nowMotionTime > motionData[nowHandle].totalTime)
        {
            nowMotionTime = 0.0f;
        }

        //���[�V�������ԃA�^�b�`
        MV1SetAttachAnimTime(modelHandle, attachedIndex[modelHandle], nowMotionTime);
    }
}

void Motion::StartMotion(int model, int handle)
{
    //���[�V�����؂�ւ�
    modelHandle = model;
    if (handle != nowHandle)
    {
        nowHandle = handle;
        if (nowHandle != -1)
        {
            MV1DetachAnim(modelHandle, attachedIndex[modelHandle]);
        }
        attachedIndex[modelHandle] = MV1AttachAnim(modelHandle, motionData[nowHandle].index,
            nowHandle, TRUE);

        //���Ԃ����Z�b�g���čĐ�
        nowMotionTime = 0.0f;
        MV1SetAttachAnimTime(modelHandle, attachedIndex[modelHandle], nowMotionTime);
    }
}

void Motion::StopMotion()
{
    //���[�V�������Ԃ𑍍Đ����Ԃɂ���
    nowMotionTime = motionData[nowHandle].totalTime;
}

bool Motion::IsPlaying()
{
    //���[�v�Đ��s�Ń��[�V�������Đ������������~��
    if (!motionData[nowHandle].isLoop &&
        nowMotionTime > motionData[nowHandle].totalTime)
    {
        return false;
    }

    //��{�͍Đ���
    return true;
}
