#include "Boss.h"
#include"BackGround.h"
#include "Engine/Image.h"

//�R���X�g���N�^
Boss::Boss(GameObject* parent)
	: GameObject(parent, "Boss"),hPict_(-1)
{
}

//������
void Boss::Initialize()
{
	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("donut.jpg");
	assert(hPict_ >= 0);
}

//�X�V
void Boss::Update()
{
}

//�`��
void Boss::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void Boss::Release()
{
}
