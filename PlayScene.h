#ifndef _WINSOCKAPI_
#define _WINSOCKAPI_
#endif
#pragma once
#include "Engine/GameObject.h"
#include <vector>

class Socket;
class Player;
class Text;
class Timer;
class Boss;

//テストシーンを管理するクラス
class PlayScene : public GameObject
{
	int hPlayer1_, hPlayer2_, hWin_, hLose_;
	float p1Time_, p2Time_;

	bool isCountDown_, isStart_;

	float playerNum_;

	bool isClear_;

	Socket* sock_;

	Timer* pTimer_;

	std::string text_;
	Text* pText_;
	Player* pPlayer1_;
	Boss* pBoss_;
	
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