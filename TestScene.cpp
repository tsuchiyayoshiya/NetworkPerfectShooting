#include "TestScene.h"
#include "BackGround.h"

#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
//�R���X�g���N�^
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene"), hPict_(-1)
{
	
}

//������
void TestScene::Initialize()
{
	hPict_ = Image::Load("Title.png");
	assert(hPict_ >= 0);
}

//�X�V
void TestScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSM = (SceneManager*)FindObject("SceneManager");
		pSM->ChangeScene(SCENE_ID_PLAY);
	}
}

//�`��
void TestScene::Draw()
{
	Image::Draw(hPict_);
}

//�J��
void TestScene::Release()
{
}
