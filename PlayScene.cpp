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
    : GameObject(parent, "PlayScene"), sock_(new Socket()), 
    isCountDown_(false), isStart_(false), playerNum_(0.0f),
    hPlayer1_(-1), hPlayer2_(-1), hWin_(-1)
{
    pText_ = new Text();
    pText_->Initialize();
}

//初期化
void PlayScene::Initialize()
{
    hPlayer1_ = Image::Load("Player1.png");
    hPlayer2_ = Image::Load("Player2.png");
    hWin_ = Image::Load("Winner.png");

    Instantiate<Gauge>(this);
    pBoss_ = Instantiate<Boss>(this);
    pBoss_ = (Boss*)FindObject("Boss");
    pPlayer1_ = Instantiate<Player>(this);
    pPlayer1_ = (Player*)FindObject("Player");

    pTimer_ = new Timer(3);

    sock_->Init();
    sock_->InitSocket(SOCK_STREAM);
    sock_->Connect("192.168.43.82", SERVERPORT);
}

//更新
void PlayScene::Update()
{
    if (isStart_)
    {
        pPlayer1_->SetIsStart(true);
        pBoss_->SetIsStart(true);
    }
    if (isCountDown_)
    {
        pTimer_->UpData();
    }
    else
    {
        sock_->Recv(&isCountDown_);
        sock_->Recv(&playerNum_);
    }
    if (pBoss_->GetIsDead())
    {
        pPlayer1_->SetIsStart(false);
        sock_->Send(pPlayer1_->GetPlayTime());
        isStart_ = false;
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
    if (isStart_)
    {
        Transform hp;
        hp.position_ = XMFLOAT3(0, 0.5f, 0);
        if ((int)playerNum_ == 1)
        {
            Image::SetTransform(hPlayer1_, hp);
            Image::Draw(hPlayer1_);
        }
        else if ((int)playerNum_ == 2)
        {
            Image::SetTransform(hPlayer2_, hp);
            Image::Draw(hPlayer2_);
        }
    }
}

//開放
void PlayScene::Release()
{
    delete pTimer_;
}
