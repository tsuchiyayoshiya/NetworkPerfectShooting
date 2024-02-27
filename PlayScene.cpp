#include "PlayScene.h"
#include "BackGround.h"
#include "Player.h"
#include "Boss.h"
#include "Gauge.h"
#include "Engine/Image.h"
#include "Socket.h"

NetWorkValue sendElem_, recvElem_;

//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
    : GameObject(parent, "PlayScene"), sock_(new Socket())
{
    
}

//������
void PlayScene::Initialize()
{
    Instantiate<BackGround>(this);
    Instantiate<Gauge>(this);
    Instantiate<Boss>(this);
    pPlayer1_ = Instantiate<Player>(this);
    pPlayer1_ = (Player*)FindObject("Player");
    pPlayer1_->SetIsOperateMe(true);
    pPlayer2_ = Instantiate<Player>(this);
    pPlayer2_ = (Player*)FindObject("Player");

    sock_->Init();
    sock_->InitSocket(SOCK_STREAM);
    sock_->Connect("192.168.42.16", SERVERPORT);
}

//�X�V
void PlayScene::Update()
{
    //sendElem_.playerPos = pPlayer1_->GetTransform();
    sock_->Send(sendElem_);
    sock_->Recv(&recvElem_);
    pPlayer2_->SetPosition(recvElem_.playerPos.position_);
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

void PlayScene::SetBulletPos(std::vector<Transform> _pos)
{
    sendElem_.bulletPos = _pos;
}

void PlayScene::EraseBullet(int _eraseNum)
{
    auto itr = sendElem_.bulletPos.begin();
    sendElem_.bulletPos.erase(itr + _eraseNum);
}
