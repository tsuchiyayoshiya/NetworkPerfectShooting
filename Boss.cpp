#include "Boss.h"
#include "BackGround.h"
#include "Bullet.h"

#include "Engine/Image.h"

const int FPS = 60;

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
    
    if (Bbullet % FPS == 0)
    {
        Random =  0;
        switch (Random)
        {
        case 0:
            pBullets_.resize(3);
            for (int i = 0; i < pBullets_.size(); i++)
            {
                pBullets_[i] = Instantiate<Bullet>(GetParent());
                pBullets_[i]->SetPos(Bform_.position_);
                pBullets_[i]->SetFiredObj(this->GetObjectName());
            }
            pBullets_[0]->SetMove(XMFLOAT3(-1, 1, 0));
            pBullets_[1]->SetMove(XMFLOAT3(-1, 0, 0));
            pBullets_[2]->SetMove(XMFLOAT3(-1, -1, 0));

            
            break;
        /*case 1:
            pBullets_.resize(3);
            for (int i = 0; i < pBullets_.size(); i++)
            {
                pBullets_[i] = Instantiate<Bullet>(GetParent());
                pBullets_[i]->SetPos(Bform_.position_);
                pBullets_[i]->SetFiredObj(this->GetObjectName());
            }
            pBullets_[0]->SetMove(XMFLOAT3(-1, 1, 0));
            pBullets_[1]->SetMove(XMFLOAT3(-1, 0, 0));
            pBullets_[2]->SetMove(XMFLOAT3(-1, -1, 0));*/

        }
    }
    
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
