#include "PlayScene.h"
#include "BackGround.h"
#include "Player.h"
#include "Boss.h"
#include "Gauge.h"
#include "Socket.h"
#include "Timer.h"

#include "Engine/Text.h"
#include "Engine/Image.h"


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
    //Instantiate<BackGround>(this);
    Instantiate<Gauge>(this);
    Instantiate<Boss>(this);
    pPlayer1_ = Instantiate<Player>(this);
    pPlayer1_ = (Player*)FindObject("Player");

    pTimer_ = new Timer(3);

    sock_->Init();
    sock_->InitSocket(SOCK_STREAM);
    sock_->Connect("192.168.43.54", SERVERPORT);
}

//更新
void PlayScene::Update()
{
    sock_->Recv(&isStart_);
    if (isStart_)
    {
        pTimer_->UpData();
        pPlayer1_->SetIsStart(true);
    }
}

//描画
void PlayScene::Draw()
{
    std::string resStr = std::to_string((int)pTimer_->GetTime());
    if (pTimer_->isTimeUpped())
    {
        resStr = "START";
    }
    pText_->Draw(400, 300, resStr.c_str());
}

//開放
void PlayScene::Release()
{
  
}
