#pragma once
#include "Object.h"

//�GB�̃N���X
class EnemyB
{
public:

	//�����o�ϐ�
	Object object;
	EnemyB();

	//�����o�֐�
	void Update();
	void Draw();
	void OnCollision();
};