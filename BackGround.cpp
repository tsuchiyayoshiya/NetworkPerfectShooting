#include "BackGround.h"
#include "Engine/Image.h"
#include "Engine/Text.h"
#include "PlayScene.h"

//�R���X�g���N�^
BackGround::BackGround(GameObject* parent)
	: GameObject(parent, "BackGround"),hPict_(-1), pText_(new Text())
{
}

//������
void BackGround::Initialize()
{
    //�摜�f�[�^�̃��[�h
    hPict_ = Image::Load("donut.jpg");
    assert(hPict_ >= 0);

    pText_->Initialize();
}

//�X�V
void BackGround::Update()
{
}

//�`��
void BackGround::Draw()
{
    
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);

    PlayScene* pPS = (PlayScene*)FindObject("PlayScene");
    pText_->Draw(300, 200, (char*)pPS->GetText());
}

//�J��
void BackGround::Release()
{
}
