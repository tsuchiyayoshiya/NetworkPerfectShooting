#include "BackGround.h"
#include "Engine/Image.h"

//�R���X�g���N�^
BackGround::BackGround(GameObject* parent)
	: GameObject(parent, "BackGround"),hPict_(-1)
{
}

//������
void BackGround::Initialize()
{
    //�摜�f�[�^�̃��[�h
    hPict_ = Image::Load("donut.jpg");
    assert(hPict_ >= 0);
}

//�X�V
void BackGround::Update()
{
}

//�`��
void BackGround::Draw()
{
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);
}

//�J��
void BackGround::Release()
{
}
