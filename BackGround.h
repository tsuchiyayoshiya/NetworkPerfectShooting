#pragma once
#include "Engine/GameObject.h"

class Text;

//�e�X�g�V�[�����Ǘ�����N���X
class BackGround : public GameObject
{
	int hPict_;    //�摜�ԍ�

	Text* pText_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	BackGround(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};