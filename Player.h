#pragma once
#include "Engine/GameObject.h"
#include <vector>

class Bullet;
class Timer;
class Text;

const int colRadius_ = 30;

//テストシーンを管理するクラス
class Player : public GameObject
{
	int hPict_;    //画像番号
	int nowHp_, maxHp_;

	bool isDamage_;

	bool isStart_;
	Timer* pTimer_;
	Text* pText_;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Player(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	Transform GetTransform() { return transform_; }

	void SetIsStart(bool _isStart) { isStart_ = _isStart; }

	float GetPlayTime();

	int GetColRadius() { return colRadius_; }

	//bool SetIsDamage(bool _isDamage) { isDamage_ = _isDamage; }
};