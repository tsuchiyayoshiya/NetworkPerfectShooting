#pragma once
#include "Engine/GameObject.h"
#include "Boss.h"


//�e�X�g�V�[�����Ǘ�����N���X
class Bullet : public GameObject //,Socket
{
	int hPict_;    //�摜�ԍ�
	XMFLOAT3 move_;

	Boss* pBoss;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Bullet(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;


	
};