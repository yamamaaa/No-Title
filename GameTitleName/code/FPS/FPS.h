#pragma once

/// <summary>
/// �f���^�^�C���̊Ǘ�
/// </summary>
class FPS
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	FPS();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~FPS();

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �f���^�^�C���擾
	/// </summary>
	/// <returns>�f���^�^�C��</returns>
	float GetDeltaTime()const { return deltaTime; }

private:
	float nowTime;		//���݂̎���
	float prevTime;		//�ߋ��̎���
	float deltaTime;	//�f���^�^�C��
};

