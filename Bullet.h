#pragma once
#include "Engine/GameObject.h"

class Boss;

//テストシーンを管理するクラス
class Bullet : public GameObject 
{
	int hPict_;    //画像番号
	int BPict_;
	XMFLOAT3 move_;

	std::string firedObj_;

	Transform tBullet_;
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

	void SetMove(XMFLOAT3 move) { move_ = move; }
	void SetPos(XMFLOAT3 _pos) { tBullet_.position_ = _pos; }



	XMFLOAT3 GetPos() { return tBullet_.position_; }

	void SetFiredObj(std::string _str) { firedObj_ = _str; }
};