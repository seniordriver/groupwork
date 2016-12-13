#pragma once
#include "Enemy.h"  

class EnemyNormal : public Enemy {

public:
	EnemyNormal();
	Sprite* GetSprite();
	~EnemyNormal();

};