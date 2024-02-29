#include "Boss.h"
#include"BackGround.h"
#include "Engine/Image.h"
#include "Bullet.h"

//コンストラクタ
Boss::Boss(GameObject* parent)
	: GameObject(parent, "Boss"),hPict_(-1), turn(false), movementCount(1.0),dancingCount(1.0),hBarrage_(-1),hitCounter_(0),Bbullet(0),Random(0)
{
}

//初期化
void Boss::Initialize()
{
    Bform_.position_.x = 0.5;
    Bform_.position_.y = -0.5;
    Bform_.scale_ = { 0.7,0.7,0.7 };
	//画像データのロード
	hPict_ = Image::Load("Enemy.jpg");
	assert(hPict_ >= 0);
    //画像データのロード
    hBarrage_ = Image::Load("Enemy.jpg");
    assert(hBarrage_ >= 0);
}

//更新
void Boss::Update()
{
   
    
    Bbullet += 1;
    if (Bbullet % 50 == 0)
    {
        Bullet* pBullet = Instantiate<Bullet>(GetParent());
        pBullet->SetPos(Bform_.position_);
    }
    
    Random = rand() % 3 + 1;
    switch (UpDown)
    {
        BossUpDown();
        break;

    default:
        break;
    }
    
}

//描画
void Boss::Draw()
{
	Image::SetTransform(hPict_, Bform_);
	Image::Draw(hPict_);
    Image::SetTransform(hBarrage_, Bform_);
    Image::Draw(hBarrage_);
}

//開放
void Boss::Release()
{
}

void Boss::BossUpDown()
{
    // 1回動くごとに変数を増加
  // movementCountを小数で増加させる
    movementCount += 1.0f;

    // movementCountが60を超えたらturnをtrueにし
    if (movementCount > 120.0f) {
        turn = true;
    }
    if (movementCount > 240.0f)
    {
        movementCount = 0.0f;
        turn = false;
    }
    // turnがtrueの場合、プレイヤーを左に移動
    if (turn) {
        Bform_.position_.y -= 0.01f;
    }
    // turnがfalseの場合、プレイヤーを右に移動
    else {
        Bform_.position_.y += 0.01f;
    }
}

void Boss::BossDancing()
{
    // 1回動くごとに変数を増加
  // movementCountを小数で増加させる
    dancingCount += 1.0f;

    // movementCountが60を超えたらturnをtrueにし
    if (dancingCount > 120.0f) {
        turn = true;
    }
    if (dancingCount > 240.0f)
    {
        dancingCount = 0.0f;
        turn = false;
    }
    // turnがtrueの場合、プレイヤーを左に移動
    if (turn) {
        Bform_.position_.y -= 0.01f;
    }
    // turnがfalseの場合、プレイヤーを右に移動
    else {
        Bform_.position_.y += 0.01f;
    }
}
