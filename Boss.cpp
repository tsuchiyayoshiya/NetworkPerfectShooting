#include "Boss.h"
#include"BackGround.h"
#include "Engine/Image.h"
#include "Bullet.h"

//コンストラクタ
Boss::Boss(GameObject* parent)
	: GameObject(parent, "Boss"),hPict_(-1), turn(false), movementCount(1.0),hBarrage_(-1),hitCounter_(0)
{
}

//初期化
void Boss::Initialize()
{
    transform_.position_.x = 0.5;
    transform_.position_.y = -0.5;
    transform_.scale_ = { 0.7,0.7,0.7 };
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
    Bform.position_.x += 0.01f;

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
        transform_.position_.y -= 0.01f;
    }
    // turnがfalseの場合、プレイヤーを右に移動
    else {
        transform_.position_.y += 0.01f;
    }


}

//描画
void Boss::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
    Image::SetTransform(hBarrage_, transform_);
    Image::Draw(hBarrage_);
}

//開放
void Boss::Release()
{
}

void Boss::OnCollisionEnter(GameObject* other) {
    if(dynamic_cast<Bullet*>(other)) {
        int hitCounter_ = 0;
        hitCounter_ += 1; // 弾との衝突回数をインクリメントする
        if (hitCounter_ >= 3) {
            //弾が三回ボスに当たった場合、ボスを破壊する
           this->KillMe();
        }
    }
}
