#pragma once
#include<unordered_map>
#include<memory>

constexpr int UNINPUT = 0x0001;     //�����͎�
constexpr int NOWUNINPUT = 0x0002;  //�����͒�
constexpr int ONINPUT = 0x0004;     //���͎�
constexpr int NOWONINPUT = 0x0008;  //���͒�

/// <summary>
/// KeyStatus�N���X
/// </summary>
class KeyStatus final
{
public:
	/// <summary>
	/// �L�[���͏���������
	/// </summary>
	static void InitKeyStatus();

	/// <summary>
	/// ���͔��菈��
	/// </summary>
	/// <param name="key">���肵�����L�[</param>
	/// <param name="flag">����t���O</param>
	/// <returns>�L�[�X�e�[�^�X���t���O�ƈ�v : true|�s��v : false</returns>
	static bool KeyStateDecision(int key, int flag);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~KeyStatus();

private:

	//�V���O���g���̃N���X	�ŏ��̂P�x�̂ݍ쐬�����C���X�^���X���N���X���S�̂Ŏg����
	//�N���X�̃C���X�^���X��������������Ȃ����̂��w��

	/// <summary>
	/// �R���X�g���N�^�@�V���O���g��
	/// </summary>
	KeyStatus();

	struct KeyParam
	{
	public:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		KeyParam();

		int inputState;			//���̓X�e�[�^�X
	};

	/// <summary>
	/// �L�[�X�e�[�^�X�؂�ւ�����
	/// </summary>
	/// <param name="key">:�؂�ւ������L�[</param>
	static void ChangeKeyState(int key);

	//���Ԃ̓N���X���̏�񂷂ׂĂ������Ă���@�C���X�^���X�����Ɠ����l����
	static std::unique_ptr<KeyStatus> singleton;        //���g�̎���

	//�\���̂̃f�[�^������
	std::unordered_map<int, KeyParam> keyData;          //�L�[�f�[�^
};

