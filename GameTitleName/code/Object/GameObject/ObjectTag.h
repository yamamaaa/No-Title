#pragma once
#include<string.h>
#include<vector>

/// <summary>
/// �Q�[�����A�N�^�[�E�����蔻��̎�ޕʃ^�O
/// </summary>
static struct ObjectTag
{
	std::string Player = "player";						//�v���C���[
	std::string IMPEDIMENT = "impediment";				//��Q��
	std::string BACKGROUND = "background";				//�w�i
	std::string CAMERA = "camera";						//�J����
	std::string ROAD_COLLISION = "road_collision";		//���[�h�R���W����
	std::string STAGE_COLLISION = "stage_collision";	//�X�e�[�W�R���W����
}ObjTag;

/// <summary>
/// ���[�v����p
/// </summary>
static std::vector<std::string> ObjectTagAll
{
	ObjTag.Player,
	ObjTag.IMPEDIMENT,
	ObjTag.BACKGROUND,
	ObjTag.CAMERA,
	ObjTag.ROAD_COLLISION,
	ObjTag.STAGE_COLLISION,
};