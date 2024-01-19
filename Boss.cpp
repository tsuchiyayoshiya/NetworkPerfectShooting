#include "Boss.h"
#include"BackGround.h"
#include "Engine/Image.h"

//コンストラクタ
Boss::Boss(GameObject* parent)
	: GameObject(parent, "Boss"),hPict_(-1)
{
}

//初期化
void Boss::Initialize()
{
	//画像データのロード
	hPict_ = Image::Load("donut.jpg");
	assert(hPict_ >= 0);
}

//更新
void Boss::Update()
{
}

//描画
void Boss::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void Boss::Release()
{
}
