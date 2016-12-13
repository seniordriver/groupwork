#pragma once
#include "Enemy.h"  

class EnemyFast : public Enemy {

public:
	EnemyFast();
	Sprite* GetSprite();
	~EnemyFast();

};