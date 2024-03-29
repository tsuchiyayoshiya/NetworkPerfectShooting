#include "Gauge.h"
#include "Engine/Camera.h"
#include "Player.h"
#include "Engine/Image.h"

//コンストラクタ
Gauge::Gauge(GameObject* parent)
	: GameObject(parent, "Gauge"), hPictGauge_(-1), hPictFrame_(-1),
	maxHp_(180), nowHp_(30)
{

}

/*
//デストラクタ
Gauge::Gauge()
{

}
*/

//初期化
void Gauge::Initialize()
{
	hPictGauge_ = Image::Load("HPGauge.png");
	assert(hPictGauge_ >= 0);

	hPictFrame_ = Image::Load("HPGaugeFrame.png");
	assert(hPictFrame_ >= 0);

	transform_.position_.x = -0.95f;
	transform_.position_.y = 0.85f;

	//transform_.scale_.x = 0.5f;
}

//更新
void Gauge::Update()
{
}

//描画
void Gauge::Draw()
{
	Transform transGauge = transform_;
	transGauge.scale_.x = (float)nowHp_ / maxHp_;
	Image::SetTransform(hPictGauge_, transGauge);
	Image::Draw(hPictGauge_);
	Image::SetTransform(hPictFrame_, transform_);
	Image::Draw(hPictFrame_);


}

//開放
void Gauge::Release()
{
}