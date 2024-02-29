#pragma once
#include "Engine/GameObject.h"
#include <vector>

class Bullet;

//�e�X�g�V�[�����Ǘ�����N���X
class Player : public GameObject
{
	int hPict_;    //�摜�ԍ�
	int nowHp_, maxHp_;

	bool isStart_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Player(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	Transform GetTransform() { return transform_; }

	void SetIsOperateMe(bool _isStart) { isStart_ = _isStart; }
};