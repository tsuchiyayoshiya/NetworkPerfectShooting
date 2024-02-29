#include "Boss.h"
#include "BackGround.h"
#include "Bullet.h"

#include "Engine/Image.h"

const int FPS = 60;

//�R���X�g���N�^
Boss::Boss(GameObject* parent)
	: GameObject(parent, "Boss"),hPict_(-1),
    movementCount(1.0),dancingCount(1.0),
    hBarrage_(-1),hitCounter_(0),Bbullet(0),
    Random(0), turn(false),rotate(true),
    maxHp_(500), nowHp_(maxHp_),
    isDamage_(false), colRadius_(300.0f / 800.0f)
{

}

//������
void Boss::Initialize()
{
    Bform_.position_.x = 0.7;
	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("Enemy.jpg");
	assert(hPict_ >= 0);
    
}

//�X�V
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
    
    // 1�񓮂����Ƃɕϐ��𑝉�
            // movementCount�������ő���������
    movementCount += 1.0f;

    // movementCount��60�𒴂�����turn��true�ɂ�
    if (movementCount > 120.0f) {
        turn = true;
    }
    if (movementCount > 240.0f)
    {
        movementCount = 0.0f;
        turn = false;
    }
    // turn��true�̏ꍇ�A�v���C���[�����Ɉړ�
    if (turn) {
        Bform_.position_.y -= 0.01f;
    }
    // turn��false�̏ꍇ�A�v���C���[���E�Ɉړ�
    else {
        Bform_.position_.y += 0.01f;
    }
    
}

//�`��
void Boss::Draw()
{
	Image::SetTransform(hPict_, Bform_);
	Image::Draw(hPict_);  
}

//�J��
void Boss::Release()
{
}
