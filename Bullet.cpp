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
    //pBoss = (Boss*)FindObject("Boss");
}

//初期化
void Bullet::Initialize()
{
    transform_.scale_ = { 0.2,0.2,0.2 };
   // transform_.position_ = { 0,-0.5,0 };

    //画像データのロード
    hPict_ = Image::Load("Bullet.jpg");
    assert(hPict_ >= 0);
}

//更新
void Bullet::Update()
{
    

    transform_.position_.x += 0.1f;
    if (transform_.position_.x > 1.0f)
    {
        this->KillMe();
    }
    
   // 弾とボスの当たり判定を行う
    CheckCollisionWithBoss();
}

// 弾とボスの当たり判定を行う関数
void Bullet::CheckCollisionWithBoss()
{
    // ボスオブジェクトを取得する
    Boss* pBoss = dynamic_cast<Boss*>(FindObject("Boss"));
    if (!pBoss)
        return; // ボスオブジェクトが見つからない場合は処理を終了する

    // ボスとプレイヤーの当たり判定を行う
    float distanceX = std::abs(transform_.position_.x - pBoss->GetPosition().x);
    float distanceY = std::abs(transform_.position_.y - pBoss->GetPosition().y);
    float radiusSum = 0.1f + pBoss->GetRadius();
    
    if (distanceX < radiusSum && distanceY < radiusSum)
    {
        // 当たり判定が発生した場合の処理を行う
        pBoss->OnCollisionEnter(this);
    }
   
}

//描画
void Bullet::Draw()
{
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);
}

//開放
void Bullet::Release()
{
}

void Bullet::OnCollision(GameObject* pTarget)
{
}