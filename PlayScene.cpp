#include "PlayScene.h"
#include "BackGround.h"
#include "Player.h"
#include "Boss.h"
#include "Gauge.h"
#include "Engine/Image.h"
#include "Socket.h"

#include "Engine/Text.h"

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
    : GameObject(parent, "PlayScene"), sock_(new Socket()), isStart_(false)
{
    pText_ = new Text();
    pText_->Initialize();
}

//初期化
void PlayScene::Initialize()
{
    Instantiate<BackGround>(this);
    Instantiate<Gauge>(this);
    Instantiate<Boss>(this);
    pPlayer1_ = Instantiate<Player>(this);
    pPlayer1_ = (Player*)FindObject("Player");
    pPlayer1_->SetIsOperateMe(true);

    sock_->Init();
    sock_->InitSocket(SOCK_STREAM);
    sock_->Connect("192.168.43.54", SERVERPORT);
}

//更新
void PlayScene::Update()
{
    sock_->Recv(&isStart_);
}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
  
}
