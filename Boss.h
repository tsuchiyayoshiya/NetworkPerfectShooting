#pragma once
#include "Engine/GameObject.h"

class Bullet;



enum BossState {
	UpDown,
	Dancing,
	What
};

//�e�X�g�V�[�����Ǘ�����N���X
class Boss : public GameObject
{
	const float colRadius_;

	int nowHp_, maxHp_;

	int hPict_;    //�摜�ԍ�
	int hBarrage_; //�e��
	
	bool isDamage_;

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

	XMFLOAT3 GetPos() { return Bform_.position_; }
	float GetColRadius() { return colRadius_; }

	void SetIsDamage(bool _isDamage) { isDamage_ = _isDamage; }
};
