#ifndef _WINSOCKAPI_
#define _WINSOCKAPI_
#endif

#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

class Socket;
class Player;

//テストシーンを管理するクラス
class PlayScene : public GameObject
{
	Socket* sock_;

	std::string text_;
	Player* pPlayer_;
	
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	PlayScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	std::string GetText() { return text_; }

	void SetPlayerPos(Transform _pos);
	void SetBulletPos(Transform _pos);
};