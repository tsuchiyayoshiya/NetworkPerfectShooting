#include "TestScene.h"
#include"BackGround.h"
#include "Engine/Model.h"
//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene"), hModel_(-1)
{
	
}

//初期化
void TestScene::Initialize()
{
	hModel_ = Model::Load("Enemy.fbx");
	assert(hModel_ >= 0);
}

//更新
void TestScene::Update()
{
}

//描画
void TestScene::Draw()
{
	Model::Draw(hModel_);
}

//開放
void TestScene::Release()
{
}
