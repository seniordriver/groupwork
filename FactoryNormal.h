#pragma once
#include"cocos2d.h"
#include"Factory.h"
#include"EnemyNormal.h"
USING_NS_CC;

using namespace CocosDenshion;

class FactoryNormal : public Factory {
public:
	Enemy* create() {
		EnemyNormal* a = new EnemyNormal();
		return a;
	}
};