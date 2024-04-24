#include "Window.h"

//���̂����
std::unique_ptr<Window> Window::singleton = nullptr;

//������
void Window::Init()
{
    //���̂ɉ��������Ă��Ȃ�������
    if (!singleton)
    {
        //���̓��ɃC���X�^���X�𐶐�
        singleton.reset(new Window);
    }
}

//�R���X�g���N�^
Window::Window()
{
    //TRUE �E�B���h�E���[�h�ŋN��
    ChangeWindowMode(TRUE);
    // ��ʃ��[�h��ݒ�
    SetGraphMode(static_cast<int>(WINDOW_SIZE.x), static_cast<int>(WINDOW_SIZE.y), COLOR_BIT);
    //PC�̐ݒ�ŃE�B���h�E�T�C�Y�̔䗦��ύX���Ă��v���O�������̐ݒ�T�C�Y�̂܂ܕ\�������
    SetWindowSizeExtendRate(1.0);
    //�E�B���h�E�̃^�C�g����ύX�ł���
    SetMainWindowText("�^�C�g�����L��");
}

Window::~Window()
{
    //�����Ȃ�
}
