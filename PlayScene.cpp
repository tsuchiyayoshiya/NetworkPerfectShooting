#include "PlayScene.h"
#include "BackGround.h"
#include "Player.h"
#include "Boss.h"
#include "Engine/Image.h"
//#include "Socket.h"

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
    : GameObject(parent, "PlayScene")//, sock_(new Socket())
    , text_("")
{
}

//初期化
void PlayScene::Initialize()
{
    Instantiate<BackGround>(this);
    Instantiate<Player>(this);
    Instantiate<Boss>(this);

    /*if (!sock_->Init())
    {
        text_ = "Error:Init()";
    }
    text_ = "Success:Init()";

    if (!sock_->InitSocket(SOCK_STREAM))
    {
        text_ = "Error:Socket()";
    }
    text_ = "Success:Socket()";

    if (!sock_->Connect("127.0.0.1", SERVERPORT))
    {
        text_ = "Error:Connect()";
    }
    text_ = "Success:Connet()";*/
}

//更新
void PlayScene::Update()
{
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
