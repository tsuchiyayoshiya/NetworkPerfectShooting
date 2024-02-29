#pragma once
#include "Engine/GameObject.h"
#include "Bullet.h"

class Bullet;

enum BossState {
	UpDown,
	Dancing,
	What
};

//�e�X�g�V�[�����Ǘ�����N���X
class Boss : public GameObject
{
	int hPict_;    //�摜�ԍ�
	int hBarrage_; //�e��
	bool turn;
	bool rotate;
	int movementCount;
	int dancingCount;

	int Random;

	Bullet* pBullet;

	Transform Bform_;

	float radius_; // ���a

	int hitCounter_; // �e�Ƃ̏Փˉ񐔂��J�E���g����ϐ�

	int Bbullet;

	// ���̑��̃����o�[�ϐ���֐�
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Boss(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	float GetBossPosX() { return Bform_.position_.x; }
	float GetBossPosY() { return Bform_.position_.y; }

	void BossUpDown();
	void BossDancing();
	void BossWhat();
};
