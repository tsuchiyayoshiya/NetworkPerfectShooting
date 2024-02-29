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
    : GameObject(parent, "PlayScene"), sock_(new Socket()), isCountDown_(true), isStart_(false)
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
    if (isStart_)
    {
        pPlayer1_->SetIsStart(true);
    }
    if (isCountDown_)
    {
        pTimer_->UpData();
    }
    else
    {
        sock_->Recv(&isCountDown_);
    }
    
   
}

//描画
void PlayScene::Draw()
{
    if (pTimer_->GetRestTime() >= -1)
    {
        std::string resStr = std::to_string((int)pTimer_->GetRestTime() + 1);
        if (pTimer_->isTimeUpped())
        {
            resStr = "START";
            isStart_ = true;
        }
        pText_->Draw(600, 100, resStr.c_str());
    }
    else
    {
        isCountDown_ = false;
    }
}

//開放
void PlayScene::Release()
{
    delete pTimer_;
}
