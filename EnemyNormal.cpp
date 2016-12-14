#include "EnemyNormal.h"  

EnemyNormal::~EnemyNormal() {

}

EnemyNormal::EnemyNormal() {
	this->speed = 2.5;
	this->enemy = Sprite::create("enemy.png");
	this->height = rand() % 150 + 280;
	this->moveAction = MoveBy::create(speed, Vec2(-1050, 0));
	this->rotateAction = RotateBy::create(1, 360);
}

Sprite* EnemyNormal::GetSprite() {
	enemy->setPosition(Vec2(1000, height));
	enemy->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	enemy->runAction(Spawn::create(Repeat::create(rotateAction, 4), moveAction, nullptr));
	return enemy;
}