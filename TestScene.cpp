#include "TestScene.h"
#include"BackGround.h"
#include "Engine/Model.h"
//�R���X�g���N�^
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene"), hModel_(-1)
{
	
}

//������
void TestScene::Initialize()
{
	hModel_ = Model::Load("Enemy.fbx");
	assert(hModel_ >= 0);
}

//�X�V
void TestScene::Update()
{
}

//�`��
void TestScene::Draw()
{
	Model::Draw(hModel_);
}

//�J��
void TestScene::Release()
{
}
