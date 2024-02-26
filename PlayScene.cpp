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
    sock_->Init();
    sock_->InitSocket(SOCK_STREAM);
    b = sock_->Connect("192.168.43.54", SERVERPORT);

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

void PlayScene::SetPlayerPos(Transform _pos)
{
    sendElem_.playerPos = _pos;
}

void PlayScene::SetBulletPos(Transform _pos)
{
    sendElem_.bulletPos.push_back(_pos);
}
