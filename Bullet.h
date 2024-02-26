#pragma once
#include "Engine/GameObject.h"
#include "Boss.h"


//�e�X�g�V�[�����Ǘ�����N���X
class Bullet : public GameObject //,Socket
{
	int hPict_;    //�摜�ԍ�
	XMFLOAT3 move_;

	//Boss* pBoss;

	Transform tBullet_;

	bool isKillMe_;

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

	void SetMove(XMFLOAT3 move) { move_ = move; }
	void SetPos(XMFLOAT3 _pos) { tBullet_.position_ = _pos; }

	//�����ɓ�������
	//�����FpTarget ������������
	void OnCollision(GameObject* pTarget) override;

	XMFLOAT3 GetPos() { return tBullet_.position_; }
	float GetBulletPosX();
	float GetBulletPosY();

	bool GetIsKillMe() { return isKillMe_; }
};