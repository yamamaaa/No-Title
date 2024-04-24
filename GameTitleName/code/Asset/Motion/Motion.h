#pragma once
#include"../AssetBase/AssetBase.h"

/// <summary>
/// ���f���̃��[�V�����Ǘ�
/// </summary>
class Motion final :public AssetBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="model">:���f���C���X�^���X</param>
    Motion(class Model* model);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Motion();

    /// <summary>
    /// ���[�V�������Ԍo�ߏ���
    /// </summary>
    /// <param name="deltaTime">:�f���^�^�C��</param>
    void AddMotionTime(const float deltaTime);

    /// <summary>
    /// ���[�V�����Đ�����
    /// </summary>
    /// <param name="model">:���f���n���h��</param>
    /// <param name="handle">:�n���h��</param>
    void StartMotion(int model, int handle);

    /// <summary>
    /// ���[�V������~����
    /// </summary>
    /// <param name="handle">:�n���h��</param>
    void StopMotion();

    /// <summary>
    /// �Đ�����
    /// </summary>
    /// <returns>�Đ���:true|��~��:false</returns>
    bool IsPlaying();

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
    /// ���[�V�����p�����[�^�[
    /// </summary>
    struct MotionParam
    {
    public:
        MotionParam();

        float playSpeed;            //�Đ����x
        bool isLoop;                //���[�v�Đ�����
        int index;                  //�C���f�b�N�X�ԍ�
        float totalTime;            //���Đ�����
    };

    int modelHandle;                                    //���f���n���h��
    float nowMotionTime;                                //���݂̃��[�V��������

    int nowHandle;                                      //���݂̃n���h��

    std::unordered_map<int, MotionParam> motionData;    //���[�V�����f�[�^
    std::unordered_map<int, int> attachedIndex;         //�A�^�b�`��̃C���f�b�N�X�f�[�^
};