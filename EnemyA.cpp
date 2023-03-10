#include <Novice.h>
#include "EnemyA.h"

EnemyA::EnemyA() {
	//初期化
	object.posX = 100;
	object.posY = 300;
	object.radius = 15;
	object.speed = 7;
	object.isAlive = true;
	object.color = RED;
}

void EnemyA::Update() {
	//敵の移動処理
	if (1280 <= object.posX + object.radius) {
		object.speed = -object.speed;
	}
	else if (object.posX - object.radius < 0) {
		object.speed = -object.speed;
	}

	object.posX += object.speed;
}

void EnemyA::Draw() {
	//敵の描画
	Novice::DrawEllipse(object.posX, object.posY,object.radius, object.radius, 0.0f, object.color, kFillModeSolid);
}

void EnemyA::OnCollision() {
	object.isAlive = false;
}