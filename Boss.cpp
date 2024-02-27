#include "Boss.h"
#include"BackGround.h"
#include "Engine/Image.h"
#include "Bullet.h"


//�R���X�g���N�^
Boss::Boss(GameObject* parent)
	: GameObject(parent, "Boss"),hPict_(-1), turn(false), movementCount(1.0),hBarrage_(-1),hitCounter_(0)
{
}

//������
void Boss::Initialize()
{
    Bform_.position_.x = 0.5;
    Bform_.position_.y = -0.5;
    Bform_.scale_ = { 0.7,0.7,0.7 };
	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("Enemy.jpg");
	assert(hPict_ >= 0);
    //�摜�f�[�^�̃��[�h
    hBarrage_ = Image::Load("Enemy.jpg");
    assert(hBarrage_ >= 0);
}

//�X�V
void Boss::Update()
{
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

      /* if (pBullet->GetBulletPosX() == Bform_.position_.x ||
            pBullet->GetBulletPosY() == Bform_.position_.y)
        {
            this->KillMe();
        }*/
}

//�`��
void Boss::Draw()
{
	Image::SetTransform(hPict_, Bform_);
	Image::Draw(hPict_);
    Image::SetTransform(hBarrage_, Bform_);
    Image::Draw(hBarrage_);
}

//�J��
void Boss::Release()
{
}


