#include "Player.h"
#include "Bullet.h"
#include "Gauge.h"
#include "Boss.h"
#include "PlayScene.h"
#include "Timer.h"

#include "Engine/Model.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Text.h"

// �R���X�g���N�^
Player::Player(GameObject* parent)
    : GameObject(parent, "Player"), hPict_(-1), nowHp_(120), maxHp_(120), isStart_(false),
    pTimer_(new Timer()), pText_(new Text()), colRadius_(80.0f / 800.0f)
{
}

// ������
void Player::Initialize()
{
    transform_.scale_ = { 0.2,0.2,0.2 };
    //transform_.position_ = { 0,-0.5,0 };
    transform_.rotate_ = { 0,0,270 };

    // �摜�f�[�^�̃��[�h
    hPict_ = Image::Load("Player.jpg");
    assert(hPict_ >= 0);

    pText_->Initialize();
}

// �X�V
void Player::Update()
{
    if (isStart_)
    {
        pTimer_->UpData();

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
        if (Input::IsKeyDown(DIK_SPACE))
        {
            Bullet* pBullet = Instantiate<Bullet>(GetParent());
            pBullet->SetPos(transform_.position_);
            pBullet->SetFiredObj(this->GetObjectName());
            pBullet->SetMove(XMFLOAT3(1, 0, 0));
        }
    }

    if (isDamage_)
    {
        nowHp_ -= 30;
        if (nowHp_ > maxHp_)
        {
            nowHp_ = maxHp_;
        }
        isDamage_ = false;
    }
    Gauge* pGauge = (Gauge*)FindObject("Gauge");
    pGauge->SetHp(nowHp_, maxHp_);

}


// �`��
void Player::Draw()
{
    if (isStart_)
    {
        std::string str = std::to_string(pTimer_->GetTime());
        pText_->Draw(60, 120, str.c_str());
    }

    // �v���C���[
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);
}

// �J��
void Player::Release()
{
}

float Player::GetPlayTime()
{
    return pTimer_->GetTime(); 
}
