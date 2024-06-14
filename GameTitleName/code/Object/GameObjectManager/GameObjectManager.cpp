#include<assert.h>
#include "GameObjectManager.h"

//���̂̒��g�����
std::unique_ptr<GameObjectManager>GameObjectManager::mpInstance = nullptr;

GameObjectManager::GameObjectManager()
	: mObjects()
{
	mpInstance = nullptr;
}

GameObjectManager::~GameObjectManager()
{
	ReleaseAllObj();
}

void GameObjectManager::Initialize()
{
	//���g�̒��g����Ȃ�C���X�^���X����
	if (!mpInstance)
	{
		mpInstance.reset(new GameObjectManager);
	}
}

void GameObjectManager::Entry(GameObj* newObj)
{
	//�^�O�̌���
	std::string tag=newObj->GetTag();
	// �I�u�W�F�N�g�̓o�^
	mpInstance->mObjects[tag].emplace_back(newObj);
}

void GameObjectManager::ReleaseAllObj()
{
	// ���ׂẴA�N�e�B�u�I�u�W�F�N�g���폜
	//auto &�����邱�Ƃɂ��tag�Q�[���I�u�W�F�N�g�ƃ^�O�̕R�Â�������
	//�֐��̎Q�Ɠn���Ɠ��������Ŋ֐����̃R�s�[�������������������̂ł͂Ȃ��֐����Œ��ڍ폜���銴�o
	for (std::string& tag : ObjectTagAll)
	{
		// ��������폜
		// empty()	�w�肵���v�f�̒��g����ɂ���
		// while (mObjects[tag]�̒��g���󂶂�Ȃ���)
		while (!mpInstance->mObjects[tag].empty())
		{
			//delete	�폜 ���̒��g������
			//player�Ƃ�����������	���̒��g(���W��)���폜
			delete mpInstance->mObjects[tag].back().get();

			//�I�u�W�F�N�g��ۊǂ��Ă��锠���̂��폜
			//player�Ƃ�����������	�����폜
			mpInstance->mObjects[tag].pop_back();
		}
	}
}

void GameObjectManager::Update(float deltaTime)
{
	// ���ׂẴA�N�^�[�̍X�V
	for (auto& tag : ObjectTagAll)
	{
		// �Y���^�O�ɂ��邷�ׂẴI�u�W�F�N�g���X�V
		for (auto& obj : mpInstance->mObjects[tag])
		{
			//�X�V
			obj->Update(deltaTime);
		}
	}

	//���S�I�u�W�F�N�g��T��
	onDeadobj();
}

void GameObjectManager::onDeadobj()
{
	//�S�^�O�����S�I�u�W�F�N�g��T���č폜
	for (auto& tag : ObjectTagAll)
	{
		for (auto& dead : mpInstance->mObjects[tag])
		{
			//����ł�����I�u�W�F�N�g�폜
			if (dead&&!dead->GetAlive())
			{
				Deleteobj(dead);
			}
		}
	}
}

void GameObjectManager::Deleteobj(std::shared_ptr<GameObj> unnecObj)
{
	//�폜�I�u�W�F�N�g�̃^�O�擾
	std::string tag = unnecObj->GetTag();

	//�I�u�W�F�N�g������
	auto endObj = mpInstance->mObjects[tag].end();
	auto findObj = std::find(mpInstance->mObjects[tag].begin(), endObj, unnecObj);

	//���������疖���Ɉړ������č폜
	if (findObj != endObj)
	{
		std::swap(findObj, endObj);
		mpInstance->mObjects[tag].pop_back();
	}
}

void GameObjectManager::Draw()
{
	//���ׂẴI�u�W�F�N�g�^�O
	for (auto& tag : ObjectTagAll)
	{
		for (auto& obj : mpInstance->mObjects[tag])
		{
			//	�������̃I�u�W�F�N�g���������Ԃ�������
			if (obj->GetVisible())
			{
				//���̃I�u�W�F�N�g�ƌ���\��������悤�ɂ���
				obj->Draw();
			}
		}
	}
}

void GameObjectManager::Collision()
{
	//player�Ɋւ��铖���蔻��
	for (auto& playernum : mpInstance->mObjects[ObjTag.Player])
	{
		// player vs BackGround �g�ݍ��킹�`�F�b�N
		for (auto& bgnum : mpInstance->mObjects[ObjTag.BACKGROUND])
		{
			//�ǂƂԂ�������
			playernum->OnCollisonEnter(bgnum.get());
		}
		for (auto& sonum : mpInstance->mObjects[ObjTag.STAGE_OBJ])
		{
			//�Q�[���I�[�o�[�̐����ɓ���������
			playernum->OnCollisonEnter(sonum.get());
		}

	//	// player vs ��Q�� �g�ݍ��킹�`�F�b�N
	//	for (auto& Impnum : mpInstance->mObjects[ObjTag.Impediment])
	//	{
	//		//��Q���ƂԂ�������
	//		/*playernum->OnCollisonEnter(Impnum);*/
	//	}
	}
}

GameObj* GameObjectManager::GetFirstGameObj(std::string tag)
{
	//�A�N�e�B�u���X�g�ɉ��������ĂȂ�������
	if (mpInstance->mObjects[tag].size() == 0)
	{
		//nullptr �� �����Ȃ�
		return nullptr;
	}
	//���������Ă�����A�N�e�B�u���X�g�̃I�u�W�F�N�g�̈�Ԗ�(��)��Ԃ�
	return mpInstance->mObjects[tag][0].get();
}