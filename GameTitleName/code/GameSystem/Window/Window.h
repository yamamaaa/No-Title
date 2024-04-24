#pragma once
#include<DxLib.h>
#include<memory>

/// <summary>
/// �E�B���h�E
/// </summary>
class Window
{
public:

    /// <summary>
    /// ����������
    /// </summary>
    static void Init();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Window();

    /// <summary>
    /// �E�B���h�E�T�C�Y�擾����
    /// </summary>
    /// <returns>�E�B���h�E�T�C�Y</returns>
    static const VECTOR GetWindowSize() { return singleton->WINDOW_SIZE; }

private:

    /// <summary>
    /// �R���X�g���N�^(�V���O���g��)
    /// </summary>
    Window();

    const VECTOR WINDOW_SIZE = VGet(1920, 1080, 0);     //�E�B���h�E�T�C�Y

    static std::unique_ptr<Window> singleton;           //���g�̎���
    const int COLOR_BIT = 16;                           //�J���[�r�b�g
};
