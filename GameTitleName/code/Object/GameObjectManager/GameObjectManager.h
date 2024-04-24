#pragma once
#include <unordered_map>
#include <memory>
#include <vector>
#include <DxLib.h>

#include "../GameObject/GameObject.h"
#include "../GameObject/ObjectTag.h"

//static�N���X	�����o�����ׂ�static(�ÓI)�ɂȂ��Ă���A�����o�͂��̃N���X���ł����g�p���Ȃ�
//static�����o�̓C���X�^���X���̕K�v���Ȃ����߁A�R���X�g���N�^�ƃf�X�g���N�^��private�ɂ��ăC���X�^���X�����֎~�ɂ���
class GameObjectManager final
{
public:

	//�@�ÓI�����o�Ƃ́A�N���X�̃I�u�W�F�N�g(�C���X�^���X)���Ƃł͂Ȃ��A�N���X�ɑ����郁���o
	//�@static�����o�֐��́Astatic�����o�ȊO�̃����o�͒��ڎQ�Ƃł��Ȃ�
	//�@�ʏ�̊֐��Ƃ̈Ⴂ�� �N���X�ɑ����邽��protected �� private �̃����o�ɂ��A�N�Z�X�ł���
	//�@ststic�N���X�͓��������N���X���ŋ��L�������Ƃ��Ɏg����

	/// <summary>
	/// ������
	/// </summary>
	static void Initialize();

	/// <summary>
	/// �Q�[���I�u�W�F�N�g�o�^
	/// </summary>
	/// <param name="tag">�o�^���閼�O</param>
	/// <param name="newObj">�I�u�W�F�N�g</param>
	static void Entry(GameObj* newObj);

	/// <summary>
	/// �S�I�u�W�F�N�g�̍폜
	/// </summary>
	static void ReleaseAllObj();

	/// <summary>
	/// �S�I�u�W�F�N�g�̍X�V����
	/// </summary>
	/// <param name="deltaTime">�f���^�^�C��</param>
	static void Update(float deltaTime);

	/// <summary>
	/// ���ׂẴI�u�W�F�N�g�̕`��
	/// </summary>
	static void Draw();

	/// <summary>
	/// �S�I�u�W�F�N�g�̓����蔻��
	/// </summary>
	static void Collision();

	/// <summary>
	/// �^�O��ނ̏��߂̃I�u�W�F�N�g��Ԃ�
	/// </summary>
	/// <param name="tag">�I�u�W�F�N�g�̎��</param>
	/// <returns>�ŏ��̃I�u�W�F�N�g</returns>
	static GameObj* GetFirstGameObj(std::string tag);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~GameObjectManager();
private:

	/// <summary>
	/// �R���X�g���N�^(�V���O���g��)
	/// </summary>
	GameObjectManager();

	/// <summary>
	/// �I�u�W�F�N�g���S����
	/// </summary>
	static void onDeadobj();

	/// <summary>
	/// �Q�[���I�u�W�F�N�g�̍폜����
	/// </summary>
	/// <param name="unnecObj">�s�v�ȃI�u�W�F�N�g</param>
	static void Deleteobj(std::shared_ptr<GameObj> unnecObj);

	//std::unique_ptr�Ƃ�
	//�w�肳�ꂽ���\�[�X�ւ̃|�C���^�̏��L����B�ꎝ���Ă��邩�̂悤�ɐU������
	static std::unique_ptr<GameObjectManager> mpInstance;      // �}�l�[�W���̎���

	//�I�u�W�F�N�g���X�g�@�^�O�̎�ނ���I�u�W�F�N�g�̌�������o��
	// mObjects[�^�O���][�I�u�W�F�N�g��]; 
	std::unordered_map<std::string, std::vector<std::shared_ptr<GameObj>>> mObjects;
};

