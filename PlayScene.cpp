#include "PlayScene.h"
#include "BackGround.h"
#include "Player.h"
#include "Engine/Image.h"
//#include "Socket.h"

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
    : GameObject(parent, "PlayScene")//, sock_(new Socket())
{

}

//初期化
void PlayScene::Initialize()
{
    Instantiate<BackGround>(this);
    Instantiate<Player>(this);
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
}
