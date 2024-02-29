#pragma once
#include "Engine/GameObject.h"
#include <vector>

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
	bool isDead_;

	bool turn;
	bool rotate;
	int movementCount;
	int dancingCount;

	int Random;

	std::vector<Bullet*> pBullets_;

	Transform Bform_;

	float radius_; // 半径

	int hitCounter_; // 弾との衝突回数をカウントする変数

	int Bbullet;

	bool isStart_;

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
	bool GetIsDead() { return isDead_; }

	void SetIsStart(bool _isStart) { isStart_ = _isStart; }
};
