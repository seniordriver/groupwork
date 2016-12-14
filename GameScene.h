#ifndef __GAMESCENE_SCENE_H__
#define __GAMESCENE_SCENE_H__
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "ObjectDefine.h"
#include "MusicControl.h"
#include "StickMan.h"
#include "FactoryNormal.h"
#include "FactoryFast.h"
#include "Iterator1.h"
#include "Observer.h"

USING_NS_CC;
using namespace CocosDenshion;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

class GameScene : public cocos2d::Layer
{
public:
    static Scene* createScene();

    virtual bool init();  
    
	bool checksprite(cocos2d::Sprite* sprite);

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

    void menuCloseCallback(cocos2d::Ref* pSender);
	void collide(float dt);


	static Animate* run();
	static Animate* jump();
	static Animate* slide();
	MenuItemToggle* paures;
	int count =0;
	Label *score;
	Label *high;
	void togglemenu(Object* psender);
	CREATE_FUNC(GameScene);
	int highscore;
	bool isHaveSaveFile();
	
	StickMan* show;
	//Sprite* show;
	 //Vector<Sprite*> sprite;
	Sprite * back = Sprite::create("background.png");

private:
	//Sprite* show = Sprite::create("stick man2.png");
	//StickMan* stickMan = StickMan::GetInstance();
	//Sprite* show = stickMan->GetStickMan();
	
	//Sprite* show2 = StickMan::GetInstance()->GetStickMan();
	
	Factory* factoryNormal = new FactoryNormal();
	Factory* factoryFast = new FactoryFast();
	ConcreteAggregate* sprite = new ConcreteAggregate();
};

#endif // __GAMESCENE_SCENE_H__
