#ifndef _SettingScene_H_
#define _SettingScene_H_

#include "cocos2d.h"
#include "ObjectDefine.h"
#include "SimpleAudioEngine.h"
#include "WelcomeScene.h"
#include "MusicControl.h"
#include "GameScene.h"
using namespace CocosDenshion;


USING_NS_CC;

class SettingScene :public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(SettingScene);

	void menuMusicCallback(cocos2d::Ref* pSender);
	void menuWelCallback(cocos2d::Ref* psender);
	void menuaddhard(cocos2d::Ref* psender);
	void menuremhard(cocos2d::Ref* psender);
	void set(float dt);
private:
	//static bool isStop;
};

#endif