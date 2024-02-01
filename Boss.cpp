#include "Boss.h"
#include"BackGround.h"
#include "Engine/Image.h"

//�R���X�g���N�^
Boss::Boss(GameObject* parent)
	: GameObject(parent, "Boss"),hPict_(-1), turn(false), movementCount(1.0)
{
}

//������
void Boss::Initialize()
{
    transform_.position_.x = 0.5;
    transform_.position_.y = -0.5;
    transform_.scale_ = { 0.7,0.7,0.7 };
	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("Enemy.jpg");
	assert(hPict_ >= 0);
}

//�X�V
void Boss::Update()
{
    // 1�񓮂����Ƃɕϐ��𑝉�
   // movementCount�������ő���������
    movementCount += 1.0f;

    // movementCount��60�𒴂�����turn��true�ɂ�
    if (movementCount > 20.0f) {
        turn = true;
    }
    if (movementCount > 40.0f)
    {
        movementCount = 0.0f;
        turn = false;
    }
    // turn��true�̏ꍇ�A�v���C���[�����Ɉړ�
    if (turn) {
        transform_.position_.y -= 0.05f;
    }
    // turn��false�̏ꍇ�A�v���C���[���E�Ɉړ�
    else {
        transform_.position_.y += 0.05f;
    }
}

//�`��
void Boss::Draw()
{
	
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void Boss::Release()
{
}
