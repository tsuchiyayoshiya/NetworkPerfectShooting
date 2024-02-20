#pragma once
#include "Engine/GameObject.h"
#include "Boss.h"


//�e�X�g�V�[�����Ǘ�����N���X
class Bullet : public GameObject //,Socket
{
	int hPict_;    //�摜�ԍ�
	XMFLOAT3 move_;

	//Boss* pBoss;

	Transform tBullet;

	
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

	// �e�̈ʒu���擾����Q�b�^�[
	float GetBulletPositionX() const { return tBullet.position_.x; }
	float GetBulletPositionY() const { return tBullet.position_.y; }
	float GetBulletPositionX() const { return tBullet.position_.z; }

	// �e�̃T�C�Y���擾����Q�b�^�[
	float GetBulletScaleX() const { return tBullet.scale_.x; }
	float GetBulletScaleY() const { return tBullet.scale_.y; }
	float GetBulletScaleZ() const { return tBullet.scale_.z; }
	
};