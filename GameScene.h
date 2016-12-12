#ifndef __GAMESCENE_SCENE_H__
#define __GAMESCENE_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "ObjectDefine.h"
#include "MusicControl.h"
#include "StickMan.h"

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


	 Animate* run();
	 Animate* jump();
	 Animate* slide();
	 MenuItemToggle* paures;
	 int count =0;
	 Label *score;
	 Label *high;
	 void togglemenu(Object* psender);
    CREATE_FUNC(GameScene);
	int highscore;
	bool isHaveSaveFile();
	static double speed;
private:
	//Sprite* show = Sprite::create("stick man2.png");
	Sprite* show = StickMan::GetInstance();
	Sprite* back = Sprite::create("background.png");
	Vector<Sprite*> sprite;
};




#endif // __GAMESCENE_SCENE_H__
