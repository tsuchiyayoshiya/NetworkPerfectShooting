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

//�e�X�g�V�[�����Ǘ�����N���X
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
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	PlayScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	std::string GetText() { return text_; }
};