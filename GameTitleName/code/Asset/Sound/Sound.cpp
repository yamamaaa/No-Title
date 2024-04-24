#include<DxLib.h>
#include "Sound.h"

Sound::Sound()
{
    //json�t�@�C���ǂݍ���
    jsonFile = "SoundData.json";
    LoadJsonFile(jsonFile);

    //�I�u�W�F�N�g���f�[�^�ǉ�
    for (rapidjson::Value::ConstMemberIterator objType = GetJsonData().MemberBegin();
        objType != GetJsonData().MemberEnd(); objType++)
    {
        for (rapidjson::Value::ConstMemberIterator soundType = objType->value.MemberBegin();
            soundType != objType->value.MemberEnd(); soundType++)
        {
            AddHandle(soundType->value[jsondata::dataKey.pass.c_str()].GetString());
            AddData(soundType->value);
        }
    }
}

Sound::~Sound()
{
    //�����Ȃ�
}

void Sound::AddHandle(const std::string fileName)
{
    //���n���h��������
    holdHandle = -1;
    dupHandle = -1;

    //�t�@�C����������Ȃ�������n���h���𕡐����Ēǉ�
    auto findHandle = handle.find(fileName);
    if (findHandle == handle.end())
    {
        holdHandle = LoadSoundMem(fileName.c_str());
        dupHandle = DuplicateSoundMem(holdHandle);
        handle.emplace(fileName, dupHandle);
    }
}

void Sound::AddData(const rapidjson::Value& key)
{
    //�n���h������
    auto handle = GetHandle(key[jsondata::dataKey.pass.c_str()].GetString());
    auto findData = soundData.find(handle);

    //������Ȃ�������T�E���h�f�[�^�ǉ�
    if (findData == soundData.end())
    {
        SoundParam param = {};
        param.soundType = key[jsondata::dataKey.type.c_str()].GetString();
        param.isLoop = key[jsondata::dataKey.loop.c_str()].GetBool();
        param.volume = key[jsondata::dataKey.volume.c_str()].GetInt();

        soundData.emplace(handle, param);
    }
}

Sound::SoundParam::SoundParam()
    :soundType("")
    , isLoop(false)
    , volume(0)
{
    //�����Ȃ�
}

void Sound::DeleteHandle()
{
    //�n���h���ƃf�[�^���
    for (auto& iter : handle)
    {
        DeleteSoundMem(iter.second);
    }
    handle.clear();
    soundData.clear();
}

void Sound::StartSound(int handle)
{
    //�Đ���Ԃ��m�F���čĐ�
    if (!CheckSoundMem(handle))
    {
        if (soundData[handle].isLoop)
        {
            PlaySoundMem(handle, DX_PLAYTYPE_LOOP);
        }
        else
        {
            PlaySoundMem(handle, DX_PLAYTYPE_BACK);
        }
    }
}

void Sound::StopSound(int handle)
{
    //�Đ���Ԃ��m�F���Ē�~
    if (CheckSoundMem(handle))
    {
        StopSoundMem(handle);
    }
}
