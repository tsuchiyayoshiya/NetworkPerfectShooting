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
    isDamage_(false), colRadius_(300.0f / 800.0f)
{

}

//初期化
void Boss::Initialize()
{
    Bform_.position_.x = 0.7;
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
        pBullet->SetMove(XMFLOAT3(-1, 0, 0));
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
