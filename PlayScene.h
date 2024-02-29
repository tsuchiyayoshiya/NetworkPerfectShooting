#ifndef _WINSOCKAPI_
#define _WINSOCKAPI_
#endif
#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
class Socket;
class Player;
class Text;
class Timer;

//テストシーンを管理するクラス
class PlayScene : public GameObject
{
	bool isStart_;

	Socket* sock_;

	Timer* pTimer_;

	std::string text_;
	Text* pText_;
	Player* pPlayer1_;
	Player* pPlayer2_;
	
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
};