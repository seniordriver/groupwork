#pragma once
#include"cocos2d.h"
#include"Factory.h"
#include"EnemyFast.h"
USING_NS_CC;

using namespace CocosDenshion;

class FactoryFast : public Factory {
public:
	Enemy* create() {
		EnemyFast* a = new EnemyFast();
		return a;
	}
};