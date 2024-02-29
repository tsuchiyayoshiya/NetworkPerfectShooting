#include "TestScene.h"
#include "BackGround.h"

#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene"), hPict_(-1)
{
	
}

//初期化
void TestScene::Initialize()
{
	hPict_ = Image::Load("Title.png");
	assert(hPict_ >= 0);
}

//更新
void TestScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSM = (SceneManager*)FindObject("SceneManager");
		pSM->ChangeScene(SCENE_ID_PLAY);
	}
}

//描画
void TestScene::Draw()
{
	Image::Draw(hPict_);
}

//開放
void TestScene::Release()
{
}
