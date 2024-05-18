#pragma once
#include <DxLib.h>
#include "../../GameObject/GameObject.h"

class BackGround final:public GameObj
{
public :

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    BackGround();

    /// <summary>
    /// �R�s�[�R���X�g���N�^
    /// </summary>
    /// <param name="background">�C���X�^���X�𐶐�����N���X</param>
    BackGround(const BackGround& mground);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~BackGround();

    /// <summary>
   /// ���f���̍��W��ύX
   /// </summary>
   /// <param name="move">�v���X���鍷��</param>
    void ModelposMove(VECTOR move);

private:

    /// <summary>
    /// ���f���̓ǂݍ���
    /// </summary>
    void ModelLoad();

    /// <summary>
    /// ���f���̕���
    /// </summary>
    /*void ModelCopy();*/

   

    /// <summary>
    /// ���f���̃Z�b�e�B���O
    /// </summary>
    void ModelSetting();

    void CollisionSet(int CollisionModel);

    /// <summary>
    /// �X�V����
    /// </summary>
    /// <param name="deltaTime"></param>
    void Update(float deltaTime)override;

    /// <summary>
    /// �`�揈��
    /// </summary>
    void Draw() override;
};

