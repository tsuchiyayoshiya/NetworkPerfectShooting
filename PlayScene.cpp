#include "PlayScene.h"
#include "BackGround.h"
#include "Player.h"
#include "Boss.h"
#include "Gauge.h"
#include "Engine/Image.h"
#include "Socket.h"

//SendElement elem_;

//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
    : GameObject(parent, "PlayScene"), sock_(new Socket())
{
    
}

//������
void PlayScene::Initialize()
{
    Instantiate<BackGround>(this);
    
    Instantiate<Boss>(this);
    Instantiate<Player>(this);
    Instantiate<Gauge>(this);

    sock_->Init();
    sock_->InitSocket(SOCK_STREAM);
    sock_->Connect("127.0.0.1", SERVERPORT);

}

//�X�V
void PlayScene::Update()
{
    SendElement elem;
    sock_->Send(elem);
}

//�`��
void PlayScene::Draw()
{  
}

//�J��
void PlayScene::Release()
{
  
}
