#pragma once
#include "Engine/GameObject.h"
#include "Bullet.h"

//テストシーンを管理するクラス
class Boss : public GameObject
{
	int hPict_;    //画像番号
	int hBarrage_; //弾幕
	bool turn;
	int movementCount;

	//Bullet* pBullet;

	Transform Bform;

	float radius_; // 半径

	int hitCounter_; // 弾との衝突回数をカウントする変数
	// その他のメンバー変数や関数
public:

	// ボスの位置を取得するゲッター
	float GetPositionX() const { return Bform.position_.x; }
	float GetPositionY() const { return Bform.position_.y; }
	float GetPositionZ() const { return Bform.position_.z; }

	// ボスのサイズを取得するゲッター
	float GetScaleX() const { return Bform.scale_.x; }
	float GetScaleY() const { return Bform.scale_.y; }
	float GetScaleZ() const { return Bform.scale_.z; }
	
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Boss(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	
};