#pragma once
#include "Engine/GameObject.h"


//�e�X�g�V�[�����Ǘ�����N���X
class Gauge : public GameObject
{
	int hPict_;    //�摜�ԍ�
	int hPictGauge_;    //�摜�ԍ�
	int hPictFrame_;    //�摜�ԍ�

	int maxHp_, nowHp_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Gauge(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
	
	void SetHp(int nowHp, int maxHp)
	{
		nowHp_ = nowHp;
		maxHp_ = maxHp;
	}
	
};