#ifndef _WINSOCKAPI_
#define _WINSOCKAPI_
#endif

#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

class Socket;
class Player;

//�e�X�g�V�[�����Ǘ�����N���X
class PlayScene : public GameObject
{
	Socket* sock_;

	std::string text_;
	Player* pPlayer_;
	
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

	void SetPlayerPos(Transform _pos);
	void SetBulletPos(Transform _pos);
};