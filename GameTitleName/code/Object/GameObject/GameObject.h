#pragma once
#include<DxLib.h>
#include<../Rapidjson/rapidjson.h>
#include<string>
#include <vector>

#include"../Collision/Collision.h"
#include"../Collision/CollisionType.h"

#include"ObjectTag.h"
#include"../../Asset/Model/Model.h"
#include"../../Asset/Motion/Motion.h"
#include"../../Asset/Sound/Sound.h"
#include"../../Asset/AssetManager/AssetManager.h"

class GameObj
{
	//�p��������̂�public��
public:
	/// <summary>
	/// �I�u�W�F�N�g�R���X�g���N�^ �I�u�W�F�N�g�̏�Ԃ��擾
	/// </summary>
	/// <param name="tag">�I�u�W�F�N�g�̖��O</param>
	GameObj(std::string tag);

	/*/// <summary>
	/// �I�u�W�F�N�g�R���X�g���N�^ �I�u�W�F�N�g�̈ʒu���Z�b�g
	/// </summary>
	/// <param name="tag"></param>
	/// <param name="pos"></param>
	GameObj(std::string tag, VECTOR pos);*/

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~GameObj();

	/*/// <summary>
	/// �ʒu���擾
	/// </summary>
	/// <returns>����̃I�u�W�F�N�g�̈ʒu</returns>
	const VECTOR& GetPos() const { return mPos; }*/

	/*/// <summary>
	/// �ʒu���Z�b�g
	/// </summary>
	/// <param name="set">�I�u�W�F�N�g�̈ʒu</param>
	void SetPos(const VECTOR set) { mPos = set; }*/

	/// <summary>
	/// ����Ԃ̎擾
	/// </summary>
	/// <returns>�����</returns>
	bool GetVisible() const { return mVisible; }

	/// <summary>
	/// ����Ԃ̃Z�b�g
	/// </summary>
	/// <param name="visible">�Z�b�g��������</param>
	void SetVisible(bool visible) { mVisible = visible; }

	/// <summary>
	/// �I�u�W�F�N�g�̐�������擾
	/// </summary>
	/// <returns>true:�����Ă���</returns>
	bool GetAlive() const { return mAlive; }

	/// <summary>
	/// ������Ԃ��Z�b�g
	/// </summary>
	/// <param name="alive">true:�����Ă���</param>
	void SetAlive(bool alive) { mAlive = alive; }

	//virtual �l���ς����� ���W��
	//�� bool����false��ture�����Ԃ��Ȃ����A���W�͂��̂��ђl���ς�� �p�ɂɕς����̂ɂ���

	/// <summary>
	/// �Q�[���I�u�W�F�N�g�̍X�V����
	/// </summary>
	/// <param name="deltaTime"�f���^�^�C��></param>
	virtual void  Update(float deltaTime) = 0;

	/// <summary>
	/// ���ׂẴQ�[���I�u�W�F�N�g�̕`��
	/// </summary>
	virtual void  Draw() {};

	/// <summary>
	/// �Q�[���I�u�W�F�N�g�̃^�O�擾
	/// </summary>
	/// <returns>�Q�[���I�u�W�F�N�g�̎��</returns>
	std::string     GetTag()const { return mTag; }

	// �����蔻��֘A
	virtual void  OnCollisonEnter(const GameObj* other) {}              // ���̃I�u�W�F�N�g�ƂԂ������Ƃ��̃��A�N�V�����i����΁j
	virtual void  ObjCollision(GameObj* other) {};                      // ���̃I�u�W�F�N�g�Ƃ̓����蔻��

	CollisionType GetCollisionType() const { return mCollisionType; }      // ���̃I�u�W�F�N�g�������Ă��铖���蔻�����擾
    Collision GetCollisionSphere() const { return mCollisionSphere; }  // �����蔻�苅��ԋp�i�����Ă���΁j
	std::vector<int> GetCollisionModel() const { return mCollisionModel; }    // �����蔻�胂�f����ԋp�i�����Ă����)

	//���N���X���� private �ɃN���X��h���������ꍇ�A
	//���N���X�̑S protected �����o�[�́A�h���N���X�� private �����o�[�ɂȂ�܂�
	//����N���X�܂��͓���C���X�^���X����сA�T�u�N���X����т��̃C���X�^���X���ł̂݃A�N�Z�X�\
protected:

	/// <summary>
	/// �I�u�W�F�N�g���W�Z�o����
	/// </summary>
	/// <returns>���W</returns>
	void CalcObjPos();

	void          DrawCollider();
	void          CollisionUpdate();                           // �����蔻��ʒu�̍X�V

	std::string   mTag;                                        // �I�u�W�F�N�g���

	bool          mVisible;                                    // �����
	bool          mAlive;                                      // �������

	int mModelHandle;       // ���f���n���h��
	VECTOR mPos;            // �I�u�W�F�N�g�ʒu
	VECTOR objScale;        //�I�u�W�F�N�g�̑傫��
	VECTOR objWorldPos;     //���[���h���W
	VECTOR objLocalPos;     //���[�J�����W
	VECTOR objDir;          //����

	class Model* model;     //���f��
	class Sound* sound;     //�T�E���h
	class Motion* motion;   //���[�V����

	// �����蔻��֘A

	CollisionType mCollisionType; // �����蔻��^�C�v
	Collision mCollisionSphere;   // �����蔻�苅

	std::vector<int> mCollisionModel;    //�����蔻��p���f��
};

