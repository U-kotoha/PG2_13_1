#pragma once
#include "Object.h"

//敵Aのクラス
class EnemyA
{
public:

	//メンバ変数
	Object object;
	EnemyA();

	//メンバ関数
	void Update();
	void Draw();
	void OnCollision();
};