#include "PlayScene.h"
#include"BackGround.h"
#include"Player.h"
#include "Engine/Image.h"


//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
    : GameObject(parent, "PlayScene"), hPict_(-1)
{
}

//������
void PlayScene::Initialize()
{
    Instantiate<BackGround>(this);
    Instantiate<Player>(this);
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
