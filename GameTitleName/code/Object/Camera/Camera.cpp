#include "Camera.h"

Camera::Camera()
    :GameObj(ObjTag.CAMERA)
{
    SetCameraNearFar(0.1f, 500.0f);
}

Camera::~Camera()
{
    //ˆ—‚È‚µ
}

void Camera::Update(const float deltaTime)
{
    mPos = VGet(-80, 100, 0);
}

void Camera::Draw()
{
    SetCameraPositionAndTarget_UpVecY(mPos, VGet(0, 0, 0));
}
