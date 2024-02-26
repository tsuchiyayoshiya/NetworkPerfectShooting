#include "Player.h"
#include "Bullet.h"
#include "Gauge.h"
#include "Boss.h"
#include "PlayScene.h"

#include "Engine/Model.h"
#include "Engine/Image.h"
#include "Engine/Input.h"

// コンストラクタ
Player::Player(GameObject* parent)
    : GameObject(parent, "Player"), hPict_(-1), nowHp_(50), maxHp_(120), isOperateMe_(false)
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
    PlayScene* pPS = (PlayScene*)FindObject("PlayScene");
    pPS->SetPlayerPos(transform_);

    if (!isOperateMe_)
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
        if (Input::IsKeyDown(DIK_SPACE))
        {
            Bullet* pBullet = Instantiate<Bullet>(GetParent());
            pBullet->SetPos(transform_.position_);
            pBullets_.push_back(pBullet);
            Transform b;
            b.position_ = pBullet->GetPos();
            bulletPos_.push_back(b);
            pPS->SetBulletPos(bulletPos_);
        }
        auto itr = bulletPos_.begin();
        while (itr != bulletPos_.end())
        {
            int i = (int)(itr - bulletPos_.begin());
            if (pBullets_[i]->GetIsKillMe())
            {
                pPS->EraseBullet(i);
                bulletPos_.erase(itr);
                pBullets_[i]->KillMe();
                auto bulItr = pBullets_.begin();
                pBullets_.erase(bulItr + i);
                break;
            }
            else
            {
                itr += 1;
            }
        }
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