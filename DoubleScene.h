#ifndef __DOUBLESCENE_SCENE_H__
#define __DOUBLESCENE_SCENE_H__
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "ObjectDefine.h"

USING_NS_CC;
using namespace CocosDenshion;


class DoubleScene : public cocos2d::Layer
{
public:
	static Scene* createScene();

	virtual bool init();

	bool checksprite1(cocos2d::Sprite* sprite);
	bool checksprite2(cocos2d::Sprite* sprite);

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

	void menuCloseCallback(cocos2d::Ref* pSender);
	void collide1(float dt);
	void collide2(float dt);
 

	Animate* run();
	Animate* jump();
	Animate* slide();
	MenuItemToggle* paures;
	int count1 = 0;
	int count2 = 0;
	Label *score1;
	Label *score2;
	Label *high1;
	Label *high2;
	void togglemenu(Object* psender);
	CREATE_FUNC(DoubleScene);
	int highscore1;
	int highscore2;
	//bool isHaveSaveFile1();
	//bool isHaveSaveFile2();
protected:
	Sprite* show = Sprite::create("stick man2.png");
	Sprite* show2 = Sprite::create("stick man2.png");
	Sprite* back = Sprite::create("background2.png");
	Sprite* back2 = Sprite::create("background2.png");
	Vector<Sprite*> sprite1;
	Vector<Sprite*> sprite2;
};


#endif