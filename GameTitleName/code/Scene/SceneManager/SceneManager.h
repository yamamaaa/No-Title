#pragma once
#include <memory>
#include <stack>

/// <summary>
/// �V�[���̊Ǘ�
/// </summary>
class SceneManager final
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	SceneManager();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~SceneManager();

	/// <summary>
	/// �Q�[�����[�v
	/// </summary>
	void GameLoop();

	/// <summary>
	/// �V�[���X�V����
	/// </summary>
	void UpdateScene();

	/// <summary>
	/// �V�[���`�揈��
	/// </summary>
	void DrawScene();

	/// <summary>
	/// �V�[���؂�ւ�����
	/// </summary>
	void ChangeScene();

private:
	std::shared_ptr<class FPS> fps;							//�^�C���}�l�[�W���[

	std::stack<std::shared_ptr<class SceneBase>> nowScene;	//���݂̃V�[��
	SceneBase* holdScene;									//�ێ��V�[��
};

