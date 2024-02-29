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
    hPlayer1_(-1), hPlayer2_(-1), hWin_(-1), p1Time_(0), p2Time_(0)
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

    sock_->Recv(&playerNum_);
}

//更新
void PlayScene::Update()
{
    pPlayer1_->SetIsStart(true);
    pBoss_->SetIsStart(true);

    if (pBoss_->GetIsDead())
    {
        pPlayer1_->SetIsStart(false);
        sock_->Send(pPlayer1_->GetPlayTime());
        sock_->Recv(&isClear_);

        isStart_ = false;
    }
    if (isClear_)
    {
        if (playerNum_ == 1)
        {
            p1Time_ = pPlayer1_->GetPlayTime();
            sock_->Recv(&p2Time_);
        }
        else if (playerNum_ == 2)
        {
            p2Time_ = pPlayer1_->GetPlayTime();
            sock_->Recv(&p1Time_);
        }
    }
}

//描画
void PlayScene::Draw()
{
    if (isClear_)
    {
        Transform hp1, hp2;
        hp1.position_ = XMFLOAT3(-0.5f, 0.2, 0);
        hp2.position_ = XMFLOAT3(0.5f, 0.2, 0);
        std::string str1 = std::to_string(p1Time_);
        std::string str2 = std::to_string(p2Time_);
        Image::SetTransform(hPlayer1_, hp1);
        Image::SetTransform(hPlayer2_, hp2);
        pText_->Draw(400, 300, str1.c_str());
        pText_->Draw(800, 300, str2.c_str());
    }
    else
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
