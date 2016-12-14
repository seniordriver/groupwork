#pragma once
#include"cocos2d.h"
#include "SimpleAudioEngine.h"
#include "ObjectDefine.h"
#include "MusicControl.h"
#include "StickMan.h"
#include "GameScene.h"
using namespace CocosDenshion;

USING_NS_CC;

class Observer{
public:

	Observer(){}

	void KeyUp();
	void KeyDown();
	void KeyEsc();
	Vector<Sprite*>listener1;
	Vector<Sprite*>listener2;
	//Vector<Sprite*>listener3;
	//Observer* a;
};

//Vector<Sprite*>Observer::listener1;
 //Vector<Sprite*>Observer::listener2;
//Vector<Sprite*>Observer::listener3;