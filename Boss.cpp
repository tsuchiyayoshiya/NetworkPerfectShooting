#include "Boss.h"
#include "BackGround.h"
#include "Bullet.h"

#include "Engine/Image.h"

//コンストラクタ
Boss::Boss(GameObject* parent)
	: GameObject(parent, "Boss"),hPict_(-1),  
    movementCount(1.0),dancingCount(1.0),
    hBarrage_(-1),hitCounter_(0),Bbullet(0),
    Random(0), turn(false),rotate(true),
    maxHp_(500), nowHp_(maxHp_),
    isDamage_(false)
{

}

//初期化
void Boss::Initialize()
{
    Bform_.position_.x = 0.5;
    Bform_.position_.y = -0.5;
    Bform_.scale_ = { 0.3,0.3,0.3 };
	//画像データのロード
	hPict_ = Image::Load("Enemy.jpg");
	assert(hPict_ >= 0);
   
}

//更新
void Boss::Update()
{
    Bbullet += 1;
    if (Bbullet % 50 == 0)
    {
        Bullet* pBullet = Instantiate<Bullet>(GetParent());
        pBullet->SetPos(Bform_.position_);
        pBullet->SetFiredObj(this->GetObjectName());
        pBullet->SetMove(XMFLOAT3(1, 1, 0));
    }
    
   // if(pBullet->)

    /*Random = rand() % 3 + 1;
    int i = 1;
    if (i == 1)
    {
        BossDancing();
    }
    switch (0)
    {
        BossDancing();
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

    // 1回動くごとに変数を増加
   // movementCountを小数で増加させる
    dancingCount += 1.0f;

    if (dancingCount > 20.0f) {
        rotate = true;
    }
    if (dancingCount > 40.0f){
        dancingCount = 0.0f;
        rotate = false;
    }

    if (rotate){
        Bform_.position_.x -= 0.01f;        
    }
    else {
        Bform_.position_.x += 0.01f;
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

void Boss::BossWhat()
{

}
