#pragma once
#include "Engine/GameObject.h"


//テストシーンを管理するクラス
class Gauge : public GameObject
{
	int hPict_;    //画像番号
	int hPictGauge_;    //画像番号
	int hPictFrame_;    //画像番号

	int maxHp_, nowHp_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Gauge(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
	
	void SetHp(int nowHp, int maxHp)
	{
		nowHp_ = nowHp;
		maxHp_ = maxHp;
	}
	
};