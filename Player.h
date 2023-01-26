#pragma once
#include "Object.h"
#include "Bullet.h"

//プレイヤーのクラス
class Player 
{
public:
	//メンバ変数
	Object object;
	Bullet* P_Bullet;

	Player();

	//メンバ関数
	void Move(Bullet* P_Bullet, char* keys, char* preKeys);
	void Draw(Bullet* P_Bullet);
};