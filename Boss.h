#pragma once
#include "Engine/GameObject.h"

class Bullet;



enum BossState {
	UpDown,
	Dancing,
	What
};

//テストシーンを管理するクラス
class Boss : public GameObject
{
	const float colRadius_;

	int nowHp_, maxHp_;

	int hPict_;    //画像番号
	int hBarrage_; //弾幕
	
	bool isDamage_;

	bool turn;
	bool rotate;
	int movementCount;
	int dancingCount;

	int Random;

	Bullet* pBullet;

	Transform Bform_;

	float radius_; // 半径

	int hitCounter_; // 弾との衝突回数をカウントする変数

	int Bbullet;

	// その他のメンバー変数や関数
public:
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

	XMFLOAT3 GetPos() { return Bform_.position_; }
	float GetColRadius() { return colRadius_; }

	void SetIsDamage(bool _isDamage) { isDamage_ = _isDamage; }
};
