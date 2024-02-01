#include "Boss.h"
#include"BackGround.h"
#include "Engine/Image.h"

//コンストラクタ
Boss::Boss(GameObject* parent)
	: GameObject(parent, "Boss"),hPict_(-1), turn(false), movementCount(1.0)
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
}

//更新
void Boss::Update()
{
    // 1回動くごとに変数を増加
   // movementCountを小数で増加させる
    movementCount += 1.0f;

    // movementCountが60を超えたらturnをtrueにし
    if (movementCount > 20.0f) {
        turn = true;
    }
    if (movementCount > 40.0f)
    {
        movementCount = 0.0f;
        turn = false;
    }
    // turnがtrueの場合、プレイヤーを左に移動
    if (turn) {
        transform_.position_.y -= 0.05f;
    }
    // turnがfalseの場合、プレイヤーを右に移動
    else {
        transform_.position_.y += 0.05f;
    }
}

//描画
void Boss::Draw()
{
	
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void Boss::Release()
{
}
