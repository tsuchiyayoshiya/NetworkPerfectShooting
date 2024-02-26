#include "PlayScene.h"
#include "BackGround.h"
#include "Player.h"
#include "Boss.h"
#include "Gauge.h"
#include "Engine/Image.h"
#include "Socket.h"

SendElement sendElem_;

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
    pPlayer_ = Instantiate<Player>(this);
    pPlayer_ = (Player*)FindObject("Player");
    Instantiate<Gauge>(this);

    bool b;
    b = sock_->Init();
    b = sock_->InitSocket(SOCK_STREAM);
    b = sock_->Connect("127.0.0.2", SERVERPORT);

}

//�X�V
void PlayScene::Update()
{
    sendElem_.playerPos = pPlayer_->GetTransform();
    sock_->Send(sendElem_);
}

//�`��
void PlayScene::Draw()
{  
}

//�J��
void PlayScene::Release()
{
  
}
