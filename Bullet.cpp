#include "Bullet.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Player.h"
#include "Boss.h"
#include "Engine/BoxCollider.h"

//コンストラクタ
Bullet::Bullet(GameObject* parent)
    : GameObject(parent, "Bullet"), hPict_(-1), firedObj_(""), BPict_(-1), move_{0, 0, 0}
{
    pBoss_ = (Boss*)FindObject("Boss");
    pPlayer_ = (Player*)FindObject("Player");
}

//初期化
void Bullet::Initialize()
{
    tBullet_.scale_ = { 0.2,0.2,0.2 };
   // transform_.position_ = { 0,-0.5,0 };

    //画像データのロード
    hPict_ = Image::Load("Bullet.png");
    assert(hPict_ >= 0);
    //画像データのロード
    BPict_ = Image::Load("BossBullet.png");
    assert(hPict_ >= 0);
}

//更新
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

//描画
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

//開放
void Bullet::Release()
{
}

