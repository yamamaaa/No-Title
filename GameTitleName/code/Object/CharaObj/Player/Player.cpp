#include "Player.h"
//int MV1SetLoadModelPhysicsWorldGravity( float Gravity ) ;

//�����ŃX�e�[�W�ƃI�u�W�F�N�g�̐ݒu����
//�W�����v�����̂��ߍ��̓X�e�[�W�Ƃ̐ڐG���肷��Ƃ����A�t���O���Ǘ�����

//�����ɍ򂪓��������玀�S�ɂ���

Player::Player() 
	: CharaObjBase(ObjTag.Player)
{
	// �R�c���f���̓ǂݍ���
	mModelHandle = AssetManager::ModelInstance()->GetHandle(
		AssetManager::ModelInstance()->GetJsonData()[ObjTag.Player.c_str()].GetString());
    objLocalPos = VGet(60.0f, 10.0f, 0.0f);

    // MV1SetScale()	���f���̊g��l���Z�b�g
    MV1SetScale(mModelHandle, VGet(0.02f, 0.02f, 0.02f));

    CalcObjPos();
	MV1SetPosition(mModelHandle, mPos);

    // �����蔻�苅�Z�b�g
    mCollisionType = CollisionType::Sphere;

    //���������蔻������Z�b�g
    mCollisionLine = LineSegment(VGet(0.0f, 20.0f, 0.0f), VGet(0.0, -10.0f, 0.0f));

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
    //���������Q�[���I�u�W�F�N�g�̃^�O���擾
    std::string tag = other->GetTag();

    if (tag == ObjTag.BACKGROUND)
    {
        MV1_COLL_RESULT_POLY_DIM colInfo{};
        MV1_COLL_RESULT_POLY colinfoLine;

        for (auto& colModel : other->GetCollisionModel())
        {
            if (CollisionPair(&mCollisionSphere, colModel, colInfo))
            {
                objLocalPos = VAdd(objLocalPos, CalcSpherePushBackVecFromMesh(&mCollisionSphere, colInfo));
                CollisionUpdate();
            }
            if (CollisionPair(mCollisionLine, colModel, colinfoLine))
            {
                // �������Ă���ꍇ�͑������Փ˓_�ɍ��킹��
                mPos = colinfoLine.HitPosition;
                CollisionUpdate();
            }
        }

        CalcObjPos();
        MV1SetMatrix(mModelHandle, MMult(rotateMat, MGetTranslate(mPos)));
    }
}

void Player::Draw()
{
	MV1DrawModel(mModelHandle);
    DrawCollider();

    DrawFormatString(0, 20, GetColor(255, 255, 255) ,"�L X:%f Y:%f Z:%f", mPos.x,mPos.y,mPos.z);
}
