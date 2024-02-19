#include "Player.h"
#include "Bullet.h"
#include "Gauge.h"
#include "Boss.h"

#include "Engine/Model.h"
#include "Engine/Image.h"
#include "Engine/Input.h"

// �R���X�g���N�^
Player::Player(GameObject* parent)
    : GameObject(parent, "Player"), hPict_(-1), nowHp_(50), maxHp_(120)
{
}

// ������
void Player::Initialize()
{
    transform_.scale_ = { 0.2,0.2,0.2 };
    transform_.position_ = { 0,-0.5,0 };
    transform_.rotate_ = { 0,0,270 };

    // �摜�f�[�^�̃��[�h
    hPict_ = Image::Load("Player.jpg");
    assert(hPict_ >= 0);
}

// �X�V
void Player::Update()
{
    // �v���C���[�̈ړ�����
    if (Input::IsKey(DIK_W))
    {
        if (transform_.position_.y + 0.05f < 1.0f)
            transform_.position_.y += 0.05f;
    }
    if (Input::IsKey(DIK_S))
    {
        if (transform_.position_.y - 0.05f > -1.0f)
            transform_.position_.y -= 0.05f;
    }
    if (Input::IsKey(DIK_A))
    {
        if (transform_.position_.x - 0.05f > -1.0f)
            transform_.position_.x -= 0.05f;
    }
    if (Input::IsKey(DIK_D))
    {
        if (transform_.position_.x + 0.05f < 1.0f)
            transform_.position_.x += 0.05f;
    }

    // �X�y�[�X�L�[�������ꂽ�ꍇ�̒e�̐��������͂��̂܂܎c��
    if (Input::IsKey(DIK_SPACE))
    {
        Bullet* pBullet = Instantiate<Bullet>(GetParent());
        pBullet->SetPosition(transform_.position_);
    }
    if (Input::IsKey(DIK_M))
    {
        nowHp_ += 30;
        if (nowHp_ > maxHp_)
        {
            nowHp_ = maxHp_;
        }
    }
    if (Input::IsKey(DIK_N))
    {
        nowHp_ -= 30;
        if (nowHp_ < 0)
        {
            nowHp_ = 0;
        }
    }
    Gauge* pGauge = (Gauge*)FindObject("Gauge");
    pGauge->SetHp(nowHp_, maxHp_);

    // �v���C���[�̓����蔻����s��
    CheckCollisionWithBoss(); // �{�X�Ƃ̓����蔻����s��
}

// �v���C���[�ƃ{�X�̓����蔻����s���֐�
void Player::CheckCollisionWithBoss()
{
    // �{�X�I�u�W�F�N�g���擾����
    Boss* pBoss = dynamic_cast<Boss*>(FindObject("Boss"));
    if (!pBoss)
        return; // �{�X�I�u�W�F�N�g��������Ȃ��ꍇ�͏������I������

    // �{�X�ƃv���C���[�̓����蔻����s��
    float distanceX = std::abs(transform_.position_.x - pBoss->GetPosition().x);
    float distanceY = std::abs(transform_.position_.y - pBoss->GetPosition().y);
    float radiusSum = 0.1f + pBoss->GetRadius(); 
    /*
    if (distanceX < radiusSum && distanceY < radiusSum)
    {
        // �����蔻�肪���������ꍇ�̏������s��
        pBoss->OnCollisionEnter(this);
    }
    */
}

// �`��
void Player::Draw()
{
    // �v���C���[
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);
}

// �J��
void Player::Release()
{
}