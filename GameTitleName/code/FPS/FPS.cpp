#include <DxLib.h>

#include "FPS.h"

FPS::FPS()
	:nowTime(static_cast<float>(GetNowCount()))
	,prevTime(nowTime)
	,deltaTime(0.0f)
{
	//�����Ȃ�
}

FPS::~FPS()
{
	//�����Ȃ�
}

void FPS::Update()
{
	//�t���[�����[�g�Z�o
	nowTime = static_cast<float>(GetNowCount());
	deltaTime = (nowTime - prevTime) / 1000.0f;
	prevTime = nowTime;
}
