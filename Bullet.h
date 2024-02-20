#pragma once
#include "Engine/GameObject.h"
#include "Boss.h"


//テストシーンを管理するクラス
class Bullet : public GameObject //,Socket
{
	int hPict_;    //画像番号
	XMFLOAT3 move_;

	//Boss* pBoss;

	Transform tBullet;

	
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

	// 弾の位置を取得するゲッター
	float GetBulletPositionX() const { return tBullet.position_.x; }
	float GetBulletPositionY() const { return tBullet.position_.y; }
	float GetBulletPositionX() const { return tBullet.position_.z; }

	// 弾のサイズを取得するゲッター
	float GetBulletScaleX() const { return tBullet.scale_.x; }
	float GetBulletScaleY() const { return tBullet.scale_.y; }
	float GetBulletScaleZ() const { return tBullet.scale_.z; }
	
};