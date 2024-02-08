#include "PlayScene.h"
#include "BackGround.h"
#include "Player.h"
#include "Boss.h"
#include "Gauge.h"
#include "Engine/Image.h"
#include "Socket.h"

SendElement elem_;

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
    : GameObject(parent, "PlayScene"), sock_(new Socket())
    , text_("")
{
    text_ = sock_->GetText();
}

//初期化
void PlayScene::Initialize()
{
    Instantiate<BackGround>(this);
    Instantiate<Player>(this);
    Instantiate<Boss>(this);
    Instantiate<Gauge>(this);

    /*if (!sock_->Init())
    {
        text_ = "Error:Init()";
    }
    text_ = "Success:Init()";
    elem_.playerPos = transform_;
}

//更新
void PlayScene::Update()
{
    sock_->Send(elem_);
}

//描画
void PlayScene::Draw()
{  
}

//開放
void PlayScene::Release()
{
   /* if (!sock_->Exit())
    {

    }*/
}
