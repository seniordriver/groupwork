#include "EnemyFast.h"  


EnemyFast::~EnemyFast() {

}

EnemyFast::EnemyFast() {
	this->speed = 1.5;
	this->enemy = Sprite::create("enemy2.png");
	this->height = rand() % 150 + 280;
	this->moveAction = MoveBy::create(speed, Vec2(-1050, 0));
	this->rotateAction = RotateBy::create(1, 360);
}

Sprite* EnemyFast::GetSprite() {
	enemy->setPosition(Vec2(1000, height));
	enemy->runAction(Spawn::create(Repeat::create(rotateAction, 4), moveAction, nullptr));
	return enemy;
}