#include "Bullet.h"
#include "Engine/Image.h"
#include "Engine/Input.h"

//�R���X�g���N�^
Bullet::Bullet(GameObject* parent)
    : GameObject(parent, "Bullet"), hPict_(-1)
{
}

//������
void Bullet::Initialize()
{
    transform_.scale_ = { 0.2,0.2,0.2 };
   // transform_.position_ = { 0,-0.5,0 };

    //�摜�f�[�^�̃��[�h
    hPict_ = Image::Load("Bullet.png");
    assert(hPict_ >= 0);
}

//�X�V
void Bullet::Update()
{
    transform_.position_.y += 0.01;
}

//�`��
void Bullet::Draw()
{
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);
}

//�J��
void Bullet::Release()
{
}
/*
void Bullet::GetPosition(float Bpos_)
{
       return Bpos;
}
*/