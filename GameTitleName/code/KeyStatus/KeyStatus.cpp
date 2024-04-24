#include<Dxlib.h>
#include "KeyStatus.h"

//�|�C���^�[�̒��g�����
std::unique_ptr<KeyStatus> KeyStatus::singleton = nullptr;

void KeyStatus::InitKeyStatus()
{
    //���g�̒��g���󂾂�����C���X�^���X����
    if (!singleton)
    {
        singleton.reset(new KeyStatus);
    }
}

KeyStatus::KeyStatus()
{
    //�����Ȃ�
}

//�g������
//�V�[���؂�ւ� if (KeyStatus::KeyStateDecision(KEY_INPUT_RETURN, ONINPUT))
//(�G���^�[�L�[�A���͒�)
bool KeyStatus::KeyStateDecision(int key, int flag)
{
    //first();       �w�肳�ꂽ�͈͂���l���擾
    //end();         �Ō���v�f�̎����w���C�e���[�^���擾
    auto findData = singleton->keyData.find(key);

    //�L�[���i�[����Ă��Ȃ�������ۑ�
    if (findData == singleton->keyData.end())
    {
        //�\���̂̏�����
        KeyParam keyParam = {};
        //�L�[�̏�Ԃ��i�[����
        //�C�ӂ̈ʒu�ɗv�f�𒼐ڍ\�z�ő}������ (���͂��ꂽ�L�[,�L�[�X�e�[�^�X)
        singleton->keyData.emplace(key, keyParam);
    }

    //�X�e�[�^�X�؂�ւ�
    ChangeKeyState(key);

    //���茋�ʂ�Ԃ�
    //�L�[�̍��̏�ԂƔ��肵������Ԃ𔻒肷��
    if (singleton->keyData[key].inputState & flag)
    {
        //������������true��Ԃ�
        return true;
    }
    return false;
}

void KeyStatus::ChangeKeyState(int key)
{
    //�L�[���i�[����Ă���؂�ւ�����
    auto findData = singleton->keyData.find(key);

    //findData�ɉ��������ĂȂ�������
    if (findData != singleton->keyData.end())
    {
        //�ϐ��ɃR�s�[�����Ȃ��^ auto&
        auto& data = singleton->keyData[key];

        //�X�e�[�^�X�̐؂�ւ�������
        //�L�[��������Ă�����
        if (CheckHitKey(key))
        {
            //����������
            //�L�[���ŏ��ɓ��͂����Ƃ�
            if (data.inputState & (UNINPUT | NOWUNINPUT))
            {
                data.inputState = ONINPUT;
                return;
            }
            data.inputState = NOWONINPUT;
        }
        else//������Ă��Ȃ�������
        {
            //����������
            //�L�[���͂��ŏ��ɏI������
            if (data.inputState & (ONINPUT | NOWONINPUT))
            {
                data.inputState = UNINPUT;
                return;
            }
            //�L�[���͂��Ȃ���
            data.inputState = NOWUNINPUT;
        }
    }
}

//�L�[��Ԃ𖢓��͂ɃZ�b�g
KeyStatus::KeyParam::KeyParam()
    :inputState(UNINPUT)
{
    //�����Ȃ�
}

KeyStatus::~KeyStatus()
{
    //�f�[�^�̒��g������Ȃ�폜
    if (keyData.size() > 0)
    {
        keyData.clear();
    }
}
