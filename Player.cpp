#include "Player.h"
#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/Image.h"
#include "Engine/Input.h"

//�R���X�g���N�^
Player::Player(GameObject* parent)
    : GameObject(parent, "Player"), hPict_(-1)
{
}

//������
void Player::Initialize()
{
    transform_.scale_ = { 0.2,0.2,0.2 };
    transform_.position_ = { 0,-0.5,0 };
    transform_.rotate_ = { 0,0,270 };

    //�摜�f�[�^�̃��[�h
    hPict_ = Image::Load("Player.jpg");
    assert(hPict_ >= 0);
}

//�X�V
void Player::Update()
{
    if (Input::IsKey(DIK_W))
    {
    transform_.position_.y += 0.05f;
    }
    if (Input::IsKey(DIK_S))
    {
      transform_.position_.y -= 0.05f;
    }
    if (Input::IsKey(DIK_A))
    {
       transform_.position_.x -= 0.05f;
    }
    if (Input::IsKey(DIK_D))
    {
        transform_.position_.x += 0.05f;
    }

    if (Input::IsKeyDown(DIK_SPACE))
    {
        Bullet* pBullet = Instantiate<Bullet>(GetParent());
        pBullet->SetPosition(transform_.position_);
    }
}

//�`��
void Player::Draw()
{
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);
}

//�J��
void Player::Release()
{
}
