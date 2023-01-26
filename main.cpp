#include <Novice.h>
#include <math.h>
#define _USE_MATH_DEFINES

#include "Player.h"
#include "EnemyA.h"
#include "EnemyB.h"

const char kWindowTitle[] = "GC1A_05_ウブカタコトハ_タイトル";

int Bullet::bulletMax;
int Bullet::bulletCount;
bool Bullet::isShot[10];
Object Bullet::bullet_[10];

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	EnemyA* enemyA = new EnemyA;
	EnemyB* enemyB = new EnemyB;
	Player* player = new Player;
	Bullet* bullet = new Bullet;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		
		//プレイヤーの移動
		player->Move(bullet, keys, preKeys);

		//敵の移動
		enemyA->Update();
		enemyB->Update();

		//敵のリスポーン
		if (keys[DIK_R]) {
			enemyA->object.isAlive = true;
			enemyB->object.isAlive = true;
		}

		//プレイヤーの撃つ弾と敵の当たり判定
		if (enemyA->object.isAlive == true || enemyB->object.isAlive == true) {
			for (int i = 0; i < Bullet::bulletMax; i++) {
				if (Bullet::isShot[i] == true) {
					float dx = Bullet::bullet_[i].posX - enemyA->object.posX;
					float dy = Bullet::bullet_[i].posY - enemyA->object.posY;
					float d = sqrtf(dx * dx + dy * dy);

					float dx2 = Bullet::bullet_[i].posX - enemyB->object.posX;
					float dy2 = Bullet::bullet_[i].posY - enemyB->object.posY;
					float d2 = sqrtf(dx2 * dx2 + dy2 * dy2);


					if (d <= Bullet::bullet_[i].radius + enemyA->object.radius ||
						d2 <= Bullet::bullet_[i].radius + enemyB->object.radius) {
						Bullet::isShot[i] = 0;
						enemyA->OnCollision();
						enemyB->OnCollision();
					}
				}
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		//プレイヤーの描画
		player->Draw(bullet);

		//敵の描画
		if (enemyA->object.isAlive == true) {
			enemyA->Draw();
		}
		if (enemyB->object.isAlive == true) {
			enemyB->Draw();
		}

		//敵が生きているか・操作説明
		Novice::ScreenPrintf(0, 0, "enemyA isAlive = %d", enemyA->object.isAlive);
		Novice::ScreenPrintf(0, 20, "enemyB isAlive = %d", enemyB->object.isAlive);
		Novice::ScreenPrintf(0, 40, "WASD : player Move");
		Novice::ScreenPrintf(0, 60, "shot : SPACE");
		Novice::ScreenPrintf(0, 80, "respawn : R");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete enemyA;
	delete enemyB;
	delete player;
	delete bullet;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
