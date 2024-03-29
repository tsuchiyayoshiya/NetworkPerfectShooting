#pragma once
#include "Engine/GameObject.h"

class Text;

//テストシーンを管理するクラス
class BackGround : public GameObject
{
	int hPict_;    //画像番号

	Text* pText_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	BackGround(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};