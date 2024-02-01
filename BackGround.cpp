#include "BackGround.h"
#include "Engine/Image.h"
#include "Engine/Text.h"
#include "PlayScene.h"

//コンストラクタ
BackGround::BackGround(GameObject* parent)
	: GameObject(parent, "BackGround"),hPict_(-1), pText_(new Text())
{
}

//初期化
void BackGround::Initialize()
{
    //画像データのロード
    hPict_ = Image::Load("donut.jpg");
    assert(hPict_ >= 0);

    pText_->Initialize();
}

//更新
void BackGround::Update()
{
}

//描画
void BackGround::Draw()
{
    
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);

    PlayScene* pPS = (PlayScene*)FindObject("PlayScene");
    pText_->Draw(300, 200, (char*)pPS->GetText());
}

//開放
void BackGround::Release()
{
}
