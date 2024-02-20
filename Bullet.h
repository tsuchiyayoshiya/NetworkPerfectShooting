#pragma once
#include "Engine/GameObject.h"
#include "Boss.h"


//テストシーンを管理するクラス
class Bullet : public GameObject //,Socket
{
	int hPict_;    //画像番号
	XMFLOAT3 move_;

	Boss* pBoss;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Bullet(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;


	
};