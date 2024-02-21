#pragma once
#include "Engine/GameObject.h"
#include "Bullet.h"

//�e�X�g�V�[�����Ǘ�����N���X
class Boss : public GameObject
{
	int hPict_;    //�摜�ԍ�
	int hBarrage_; //�e��
	bool turn;
	int movementCount;

	//Bullet* pBullet;

	Transform Bform;

	float radius_; // ���a

	int hitCounter_; // �e�Ƃ̏Փˉ񐔂��J�E���g����ϐ�
	// ���̑��̃����o�[�ϐ���֐�
public:

	// �{�X�̈ʒu���擾����Q�b�^�[
	float GetPositionX() const { return Bform.position_.x; }
	float GetPositionY() const { return Bform.position_.y; }
	float GetPositionZ() const { return Bform.position_.z; }

	// �{�X�̃T�C�Y���擾����Q�b�^�[
	float GetScaleX() const { return Bform.scale_.x; }
	float GetScaleY() const { return Bform.scale_.y; }
	float GetScaleZ() const { return Bform.scale_.z; }
	
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

	
};