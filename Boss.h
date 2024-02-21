#pragma once
#include "Engine/GameObject.h"


//�e�X�g�V�[�����Ǘ�����N���X
class Boss : public GameObject
{
	int hPict_;    //�摜�ԍ�
	int hBarrage_; //�e��
	bool turn;
	int movementCount;

	Transform Bform;

	float radius_; // ���a

	int hitCounter_; // �e�Ƃ̏Փˉ񐔂��J�E���g����ϐ�
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

	//float GetRadius() const; // ���a���擾����֐���ǉ�

	// �{�X�̈ʒu���擾����Q�b�^�[
	float GetPositionX(){ return Bform.position_.x; }
	float GetPositionY(){ return Bform.position_.y; }
	float GetPositionZ(){ return Bform.position_.z; }

	void OnCollisionEnter(GameObject* other); // �����蔻�莞�̏������s���֐�
};