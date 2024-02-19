#pragma once
#include "Engine/GameObject.h"


//テストシーンを管理するクラス
class Boss : public GameObject
{
	int hPict_;    //画像番号
	int hBarrage_; //弾幕
	bool turn;
	int movementCount;

	Transform Bform;

	float radius_; // 半径
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

	float GetRadius() const; // 半径を取得する関数を追加

	void OnCollisionEnter(GameObject* other); // 当たり判定時の処理を行う関数
};