#pragma once
#include "Object.h"
#include "Bullet.h"

//�v���C���[�̃N���X
class Player 
{
public:
	//�����o�ϐ�
	Object object;
	Bullet* P_Bullet;

	Player();

	//�����o�֐�
	void Move(Bullet* P_Bullet, char* keys, char* preKeys);
	void Draw(Bullet* P_Bullet);
};