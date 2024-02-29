#include "Bullet.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Player.h"
#include "Boss.h"
#include "Engine/BoxCollider.h"

//�R���X�g���N�^
Bullet::Bullet(GameObject* parent)
    : GameObject(parent, "Bullet"), hPict_(-1), firedObj_(""), BPict_(-1), move_{0, 0, 0}
{
    pBoss_ = (Boss*)FindObject("Boss");
    pPlayer_ = (Player*)FindObject("Player");
}

//������
void Bullet::Initialize()
{
    tBullet_.scale_ = { 0.2,0.2,0.2 };
   // transform_.position_ = { 0,-0.5,0 };

    //�摜�f�[�^�̃��[�h
    hPict_ = Image::Load("Bullet.png");
    assert(hPict_ >= 0);
    //�摜�f�[�^�̃��[�h
    BPict_ = Image::Load("BossBullet.png");
    assert(hPict_ >= 0);
}

//�X�V
void Bullet::Update()
{
    XMStoreFloat3(&move_, XMVector3Normalize(XMLoadFloat3(&move_)));
    tBullet_.position_.x += move_.x / 50;
    tBullet_.position_.y += move_.y / 50;
    if (tBullet_.position_.x > 1.0f)
    {
        this->KillMe();
    }
    XMFLOAT3 pPos, bPos;
    pPos = pPlayer_->GetTransform().position_;
    bPos = pBoss_->GetPos();
    XMVECTOR bulletPos, playerPos, bossPos;
    bulletPos = XMLoadFloat3(&tBullet_.position_);
    playerPos = XMLoadFloat3(&pPos);
    bossPos = XMLoadFloat3(&bPos);
    XMVECTOR btoPVec, btoBVec;
    btoPVec = XMVector3Length(bulletPos - playerPos);
    btoBVec = XMVector3Length(bulletPos - bossPos);
    float btoPLength, btoBLength;
    btoPLength = XMVectorGetX(btoPVec);
    btoBLength = XMVectorGetX(btoBVec);

    if (firedObj_ == "Boss" &&
        btoPLength <= pPlayer_->GetColRadius())
    {
        pPlayer_->SetIsDamage(true);
        this->KillMe();
    }
     if (firedObj_ == "Player" && 
         btoBLength <= pBoss_->GetColRadius())
     {
         pBoss_->SetIsDamage(true);
         this->KillMe();
     }
}

//�`��
void Bullet::Draw()
{
    if (firedObj_ == "Player")
    {
        Image::SetTransform(hPict_, tBullet_);
        Image::Draw(hPict_);
    }
    else if (firedObj_ == "Boss")
    {
        Image::SetTransform(BPict_, tBullet_);
        Image::Draw(BPict_);
    }
}

//�J��
void Bullet::Release()
{
}

