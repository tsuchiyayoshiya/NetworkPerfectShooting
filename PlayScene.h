#pragma once
#include "Engine/GameObject.h"

#pragma comment( lib, "ws2_32.lib")

class Socket;

//�e�X�g�V�[�����Ǘ�����N���X
class PlayScene : public GameObject
{
	Socket* sock_;
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
};