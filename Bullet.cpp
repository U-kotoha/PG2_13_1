#include <Novice.h>
#include "Bullet.h"

Bullet::Bullet() {
	//èâä˙âª
	bulletMax = 10;
	bulletCount = 0;

	for (int i = 0; i < bulletMax; i++) {
		//ï°êîÇÃíeÇÃèâä˙âª
		bullet_[i].posX = -100;
		bullet_[i].posY = -100;
		bullet_[i].radius = 15;
		bullet_[i].speed = 10;
		isShot[i] = false;
		bullet_[i].color = WHITE;
	}
}

void Bullet::Update(char* keys) {
	//ï°êîÇÃíeÇÃèàóù
	for (int i = 0; i < bulletMax; i++) {
		if (isShot[i] == true) {
			if (bullet_[i].posY > (0 - bullet_[i].radius)) {
				bullet_[i].posY -= bullet_[i].speed;
			}
			if (bullet_[i].posY <= 0) {
				bullet_[i].posY = -100;
				isShot[i] = false;
			}
		}
	}
}

void Bullet::Draw() {
	//íeÇÃï`âÊ
	for (int i = 0; i < bulletMax; i++) {
		if (isShot[i] == true) {
			Novice::DrawEllipse(bullet_[i].posX, bullet_[i].posY, bullet_[i].radius, bullet_[i].radius, 0.0f, bullet_[i].color, kFillModeSolid);
		}
	}
}