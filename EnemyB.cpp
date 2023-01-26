#include <Novice.h>
#include "EnemyB.h"

EnemyB::EnemyB() {
	//‰Šú‰»
	object.posX = 400;
	object.posY = 500;
	object.radius = 15;
	object.speed = 8;
	object.isAlive = true;
	object.color = RED;
}

void EnemyB::Update() {
	//“G‚ÌˆÚ“®ˆ—
	if (1280 <= object.posX + object.radius) {
		object.speed = -object.speed;
	}
	else if (object.posX - object.radius < 0) {
		object.speed = -object.speed;
	}

	object.posX += object.speed;
}

void EnemyB::Draw() {
	//“G‚Ì•`‰æ
	Novice::DrawEllipse(object.posX, object.posY, object.radius, object.radius, 0.0f, object.color, kFillModeSolid);
}

void EnemyB::OnCollision() {
	object.isAlive = false;
}