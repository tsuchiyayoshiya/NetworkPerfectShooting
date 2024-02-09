#include "PlayScene.h"
#include "BackGround.h"
#include "Player.h"
#include "Boss.h"
#include "Gauge.h"
#include "Engine/Image.h"
//#include "Socket.h"

//SendElement elem_;

//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
    : GameObject(parent, "PlayScene")
{
    
}

//������
void PlayScene::Initialize()
{
    Instantiate<BackGround>(this);
    Instantiate<Player>(this);
    Instantiate<Boss>(this);
    Instantiate<Gauge>(this);

    
}

//�X�V
void PlayScene::Update()
{
    
}

//�`��
void PlayScene::Draw()
{  
}

//�J��
void PlayScene::Release()
{
  
}
