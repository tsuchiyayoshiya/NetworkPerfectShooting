#include "Bullet.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Player.h"
#include "Boss.h"
#include "Engine/BoxCollider.h"

//コンストラクタ
Bullet::Bullet(GameObject* parent)
    : GameObject(parent, "Bullet"), hPict_(-1)
{
   
    //pBoss_ = (Boss*)FindObject("Boss");
}

//初期化
void Bullet::Initialize()
{
    
    tBullet_.scale_ = { 0.2,0.2,0.2 };
   // transform_.position_ = { 0,-0.5,0 };

    //画像データのロード
    hPict_ = Image::Load("Bullet.jpg");
    assert(hPict_ >= 0);
}

//更新
void Bullet::Update()
{
    Boss* pBoss_;
    tBullet_.position_.x += 0.1f;
    if (tBullet_.position_.x > 1.0f)
    {
        this->KillMe();
    }

    // ボスの位置を取得し、衝突判定を行う
    if (pBoss_->GetBossPosX() == transform_.position_.x || pBoss_->GetBossPosY() == transform_.position_.y)  {
        pBoss_->KillMe(); // ボスを削除する
        this->KillMe(); // 自身も削除する
    }
}



//描画
void Bullet::Draw()
{
    Image::SetTransform(hPict_, tBullet_);
    Image::Draw(hPict_);
}

//開放
void Bullet::Release()
{
}

