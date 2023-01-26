#include <Novice.h>
#include "Player.h"

Player::Player() {
	//������
	object.posX = 300;
	object.posY = 600;
	object.radius = 30;
	object.speed = 7;
	object.color = GREEN;

	P_Bullet = new Bullet;
}

void Player::Move(Bullet* P_Bullet, char* keys, char* preKeys) {
	//�v���C���[�̈ړ�����
	if (keys[DIK_UP] || keys[DIK_W]) {
		object.posY -= object.speed;
	};
	if (keys[DIK_DOWN] || keys[DIK_S]) {
		object.posY += object.speed;
	};
	if (keys[DIK_LEFT] || keys[DIK_A]) {
		object.posX -= object.speed;
	};
	if (keys[DIK_RIGHT] || keys[DIK_D]) {
		object.posX += object.speed;
	};

	//�e�̔��ˏ���
	for (int i = 0; i < P_Bullet->bulletMax; i++) {
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && P_Bullet->isShot[i] == false && P_Bullet->bulletCount == 0) {
			P_Bullet->bullet_[i].posX = object.posX;
			P_Bullet->bullet_[i].posY = object.posY - 20;
			P_Bullet->isShot[i] = true;
			P_Bullet->bulletCount = 10;
		}
	}

	P_Bullet->Update(keys);

	P_Bullet->bulletCount--;
	if (P_Bullet->bulletCount <= 0) {
		P_Bullet->bulletCount = 0;
	}
}

void Player::Draw(Bullet* P_Bullet) {
	//�v���C���[�̕`��
	Novice::DrawEllipse(object.posX, object.posY, object.radius, object.radius, 0.0f, object.color, kFillModeSolid);
	
	//�e�̕`��
	P_Bullet->Draw();
}