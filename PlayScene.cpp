#include "PlayScene.h"
#include "BackGround.h"
#include "Player.h"
#include "Boss.h"
#include "Gauge.h"
#include "Engine/Image.h"
#include "Socket.h"

//SendElement elem_;

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
    Instantiate<Player>(this);
    Instantiate<Gauge>(this);

    sock_->Init();
    sock_->InitSocket(SOCK_STREAM);
    sock_->Connect("127.0.0.1", SERVERPORT);

}

//更新
void PlayScene::Update()
{
    SendElement elem;
    sock_->Send(elem);
}

//描画
void PlayScene::Draw()
{  
}

//開放
void PlayScene::Release()
{
  
}
