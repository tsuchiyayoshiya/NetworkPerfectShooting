#include "PlayScene.h"
#include "BackGround.h"
#include "Player.h"
#include "Boss.h"
#include "Gauge.h"
#include "Engine/Image.h"
#include "Socket.h"

SendElement sendElem_;

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
    : GameObject(parent, "PlayScene"), sock_(new Socket())
{
    
}

//初期化
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

//更新
void PlayScene::Update()
{
    sendElem_.playerPos = pPlayer_->GetTransform();
    sock_->Send(sendElem_);
}

//描画
void PlayScene::Draw()
{  
}

//開放
void PlayScene::Release()
{
  
}
