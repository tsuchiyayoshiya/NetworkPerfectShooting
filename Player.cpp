#include "Player.h"
#include "Bullet.h"
#include "Gauge.h"
#include "Boss.h"

#include "Engine/Model.h"
#include "Engine/Image.h"
#include "Engine/Input.h"

// コンストラクタ
Player::Player(GameObject* parent)
    : GameObject(parent, "Player"), hPict_(-1), nowHp_(50), maxHp_(120)
{
}

// 初期化
void Player::Initialize()
{
    transform_.scale_ = { 0.2,0.2,0.2 };
    transform_.position_ = { 0,-0.5,0 };
    transform_.rotate_ = { 0,0,270 };

    // 画像データのロード
    hPict_ = Image::Load("Player.jpg");
    assert(hPict_ >= 0);
}

// 更新
void Player::Update()
{
    // プレイヤーの移動処理
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

    // スペースキーが押された場合の弾の生成処理はそのまま残す
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

    
}


// 描画
void Player::Draw()
{
    // プレイヤー
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);
}

// 開放
void Player::Release()
{
}