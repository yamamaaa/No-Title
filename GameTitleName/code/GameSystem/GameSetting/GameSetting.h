#pragma once
#include<memory>

//final �p����h���ׂ̂���
class GameSetting final
{
public:

    // ���̂�����Ƃ��ɏ��������邽�߃R���X�g���N�^�Ƃ͕ʂɏ������̊֐������

    /// <summary>
    /// ������
    /// </summary>
    static void Init();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~GameSetting();

private:

    // ���̂��쐬�����ꍇ��private�ɃR���X�g���N�^�����

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    GameSetting();

    /// <summary>
    /// ���C�u�����������O�̏���
    /// </summary>
    static void BeforeLibInit();

    /// <summary>
    /// ���C�u������������̏���
    /// </summary>
    static void AfterLibInit();

    //std::unique_ptr�Ƃ�
    //�w�肳�ꂽ���\�[�X�ւ̃|�C���^�̏��L����B�ꎝ���Ă��邩�̂悤�ɐU������
    //������g���ƌ㏈�������Ȃ��Ă��ǂ�

    //�N���X�̎���
    //�C���X�^���X��������񂵂����Ȃ��ꍇ�ɍ��
    static std::unique_ptr<GameSetting> singleton;
};

