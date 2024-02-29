#include "Boss.h"
#include "BackGround.h"
#include "Bullet.h"

#include "Engine/Image.h"

//�R���X�g���N�^
Boss::Boss(GameObject* parent)
	: GameObject(parent, "Boss"),hPict_(-1),  
    movementCount(1.0),dancingCount(1.0),
    hBarrage_(-1),hitCounter_(0),Bbullet(0),
    Random(0), turn(false),rotate(true),
    maxHp_(500), nowHp_(maxHp_),
    isDamage_(false)
{

}

//������
void Boss::Initialize()
{
    Bform_.position_.x = 0.5;
    Bform_.position_.y = -0.5;
    Bform_.scale_ = { 0.3,0.3,0.3 };
	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("Enemy.jpg");
	assert(hPict_ >= 0);
   
}

//�X�V
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

void Boss::BossUpDown()
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
}


void Boss::BossDancing()
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

    // 1�񓮂����Ƃɕϐ��𑝉�
   // movementCount�������ő���������
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

    // turn��true�̏ꍇ�A�v���C���[�����Ɉړ�
    if (turn) {
        Bform_.position_.y -= 0.01f;
    }
    // turn��false�̏ꍇ�A�v���C���[���E�Ɉړ�
    else {
        Bform_.position_.y += 0.01f;
    }
}

void Boss::BossWhat()
{

}
