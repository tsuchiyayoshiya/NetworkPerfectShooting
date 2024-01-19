#include "PlayScene.h"
#include "BackGround.h"
#include "Player.h"
#include "Engine/Image.h"
//#include "Socket.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
    : GameObject(parent, "PlayScene")//, sock_(new Socket())
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
