#pragma once
#include "../SceneBase/SceneBase.h"

/// <summary>
/// �^�C�g���V�[��
/// </summary>
class Title:public SceneBase
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Title();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Title();

	/// <summary>
	/// �V�[���X�V����
	/// </summary>
	/// <param name="deltaTime">�t���[�����[�g</param>
	/// <returns>���̃V�[��</returns>
	SceneBase* UpdateScene(const float deltaTime) override;

	/// <summary>
	/// �V�[���`�揈��
	/// </summary>
	void DrawScene() override;
};

