#include <Novice.h>
#include "EnemyA.h"

EnemyA::EnemyA() {
	//‰Šú‰»
	object.posX = 100;
	object.posY = 300;
	object.radius = 15;
	object.speed = 7;
	object.isAlive = true;
	object.color = RED;
}

void EnemyA::Update() {
	//“G‚ÌˆÚ“®ˆ—
	if (1280 <= object.posX + object.radius) {
		object.speed = -object.speed;
	}
	else if (object.posX - object.radius < 0) {
		object.speed = -object.speed;
	}

	object.posX += object.speed;
}

void EnemyA::Draw() {
	//“G‚Ì•`‰æ
	Novice::DrawEllipse(object.posX, object.posY,object.radius, object.radius, 0.0f, object.color, kFillModeSolid);
}

void EnemyA::OnCollision() {
	object.isAlive = false;
}