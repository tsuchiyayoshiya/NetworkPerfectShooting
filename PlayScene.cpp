#include "PlayScene.h"
#include "BackGround.h"
#include "Player.h"
#include "Boss.h"
#include "Gauge.h"
#include "Engine/Image.h"
#include "Socket.h"

SendElement elem_;

//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
    : GameObject(parent, "PlayScene"), sock_(new Socket())
    , text_("")
{
    text_ = sock_->GetText();
}

//������
void PlayScene::Initialize()
{
    Instantiate<BackGround>(this);
    Instantiate<Player>(this);
    Instantiate<Boss>(this);
    Instantiate<Gauge>(this);

    /*if (!sock_->Init())
    {
        text_ = "Error:Init()";
    }
    text_ = "Success:Init()";
    elem_.playerPos = transform_;
}

//�X�V
void PlayScene::Update()
{
    sock_->Send(elem_);
}

//�`��
void PlayScene::Draw()
{  
}

//�J��
void PlayScene::Release()
{
   /* if (!sock_->Exit())
    {

    }*/
}
