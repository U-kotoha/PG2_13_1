#pragma once
#include "Object.h"

//�e�̃N���X
class Bullet 
{
public:

	//�����o�ϐ�
	static int bulletMax;
	static int bulletCount;
	static bool isShot[];
	static Object bullet_[];

public:

	Bullet();

	//�����o�֐�
	void Update(char* keys);
	void Draw();
};