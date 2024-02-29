#include "Bullet.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Player.h"
#include "Boss.h"
#include "Engine/BoxCollider.h"

//�R���X�g���N�^
Bullet::Bullet(GameObject* parent)
    : GameObject(parent, "Bullet"), hPict_(-1)
{
    pBoss_ = (Boss*)FindObject("Boss");
}

//������
void Bullet::Initialize()
{
    
    tBullet_.scale_ = { 0.2,0.2,0.2 };
   // transform_.position_ = { 0,-0.5,0 };

    //�摜�f�[�^�̃��[�h
    hPict_ = Image::Load("Bullet.png");
    assert(hPict_ >= 0);
}

//�X�V
void Bullet::Update()
{
    tBullet_.position_.x += 0.01f;
    if (tBullet_.position_.x > 1.0f)
    {
        this->KillMe();
    }

    
}



//�`��
void Bullet::Draw()
{
    Image::SetTransform(hPict_, tBullet_);
    Image::Draw(hPict_);
}

//�J��
void Bullet::Release()
{
}

