#pragma once
#include"cocos2d.h"
#include"Enemy.h"
using namespace std;

class Factory {
public:
	virtual Enemy* create() = 0;
};