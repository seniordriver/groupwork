#pragma once
#include "cocos2d.h"
#include "ObjectDefine.h"

USING_NS_CC;

using namespace CocosDenshion;

class Enemy {
protected:
	int speed;
	Sprite* enemy;
	int height;
	MoveBy* moveAction;
	RotateBy* rotateAction;
public:
	Enemy();
	~Enemy();
	virtual Sprite* GetSprite() = 0;
};