#pragma once
#include "Object.h"

//弾のクラス
class Bullet 
{
public:

	//メンバ変数
	static int bulletMax;
	static int bulletCount;
	static bool isShot[];
	static Object bullet_[];

public:

	Bullet();

	//メンバ関数
	void Update(char* keys);
	void Draw();
};