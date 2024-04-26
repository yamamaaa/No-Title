#include "Player.h"
//int MV1SetLoadModelPhysicsWorldGravity( float Gravity ) ;

Player::Player() 
	: CharaObjBase(ObjTag.Player)
{

   

	// �R�c���f���̓ǂݍ���
	mModelHandle = AssetManager::ModelInstance()->GetHandle(
		AssetManager::ModelInstance()->GetJsonData()[ObjTag.Player.c_str()].GetString());
    objLocalPos = VGet(0, 50, 0);

    // MV1SetScale()	���f���̊g��l���Z�b�g
    MV1SetScale(mModelHandle, VGet(0.02f, 0.02f, 0.02f));

    CalcObjPos();
	MV1SetPosition(mModelHandle, mPos);

    // �����蔻�苅�Z�b�g
    mCollisionType = CollisionType::Sphere;

    //���̔��a�Z�b�g
    mCollisionSphere.mRadius = 8.0f;

    //�ړ����x�͑��鑬�x
    moveSpeed = RUN_SPEED;
}

Player::~Player()
{
	//�����Ȃ�
}

void Player::Update(float deltaTime)
{
    a += deltaTime;
    //�A�j���[�V�������ԍĐ�
    motion->AddMotionTime(deltaTime);

    //�L�����ړ�
    MoveChara(deltaTime);


    //���쒆
    if (isMove)
    {
        //�I�u�W�F�N�g�̍��W�Z�o
        CalcObjPos();

        //�s��Ń��f���̓���
        MV1SetMatrix(mModelHandle, MMult(rotateMat, MGetTranslate(mPos)));
    }
    //��~��
    else
    {
        //�ʏ펞�A�j���[�V�����Đ�
        motion->StartMotion(mModelHandle,
            motion->GetHandle(GetFilePass(motionData[jsondata::objKey.nomal.c_str()])));
    }

    //P�L�[�������ꂽ��
    if (KeyStatus::KeyStateDecision(KEY_INPUT_P, ONINPUT))
    {
        //���S�ɂ���
        mAlive = false;

        //�T�E���h�Đ�
        sound->StartSound(sound->GetHandle(GetFilePass(soundData[jsondata::objKey.walk.c_str()])));
    }

    //�����蔻�胂�f�����ʒu�X�V
    CollisionUpdate();
    //��~���ɂ���
    isMove = false;
}

void Player::MoveChara(const float deltaTime)
{
    //�L�[���͂ɂ��㉺���E�ړ�
    MoveByKey(KEY_INPUT_W, FRONT, deltaTime);
    MoveByKey(KEY_INPUT_S, BACK, deltaTime);
    MoveByKey(KEY_INPUT_A, LEFT, deltaTime);
    MoveByKey(KEY_INPUT_D, RIGHT, deltaTime);
}

void Player::MoveByKey(const int keyName, const VECTOR dir, const float deltaTime)
{
    //�L�[�����͂���Ă�����ړ����̏������s
    if (KeyStatus::KeyStateDecision(keyName, ONINPUT | NOWONINPUT))
    {
        //�ړ��A�j���[�V�����Đ�
        motion->StartMotion(mModelHandle,
            motion->GetHandle(GetFilePass(motionData[jsondata::objKey.walk.c_str()])));

        //���W�E�����̎Z�o
        objLocalPos = VAdd(objLocalPos, VScale(dir, moveSpeed * deltaTime));
        RotateYAxis(dir, ROTATE_SPEED);

        //���쒆�ɂ���
        isMove = true;
    }
}

void Player::OnCollisonEnter(const GameObj* other)
{
    MV1_COLL_RESULT_POLY_DIM colInfo{};
    for (auto& colModel : other->GetCollisionModel())
    {
        if (mCollisionSphere.CollisionPair(&mCollisionSphere, colModel, colInfo))
        {
            objLocalPos =VAdd(objLocalPos, mCollisionSphere.CalcSpherePushBackVecFromMesh(&mCollisionSphere, colInfo));
        }
    }
    //���̓����蔻��̍X�V
    CollisionUpdate();

    CalcObjPos();
    MV1SetMatrix(mModelHandle, MMult(rotateMat, MGetTranslate(mPos)));
}



void Player::Draw()
{
    int CrY = GetColor(255, 255, 0);//���F
    int CrR = GetColor(255, 0, 0);//�ԐF
    int CrB = GetColor(0, 0, 255);//�F
    //���̕\��(���S0,0,0)
    DrawLine3D(VGet(-1000, 0, 0), VGet(1000, 0, 0), CrR);//�� x�@��
    DrawLine3D(VGet(0, -1000, 0), VGet(0, 1000, 0), CrY);//�c y�@��
    DrawLine3D(VGet(0, 0, -1000), VGet(0, 0, 1000), CrB);//��(�O��) z�@��
	MV1DrawModel(mModelHandle);
	/*SetCameraPositionAndTarget_UpVecY(VGet(-110, 80, 0), VGet(0, 0, 0));*/
    DrawCollider();
   /* DrawFormatString(0, 20, GetColor(255, 255, 255) ,"�L %f", mPos);*/
}
