#pragma once
#include "Object.h"

//敵Bのクラス
class EnemyB
{
public:

	//メンバ変数
	Object object;
	EnemyB();

	//メンバ関数
	void Update();
	void Draw();
	void OnCollision();
};