#pragma once
#include "Object.h"

//�GA�̃N���X
class EnemyA
{
public:

	//�����o�ϐ�
	Object object;
	EnemyA();

	//�����o�֐�
	void Update();
	void Draw();
	void OnCollision();
};