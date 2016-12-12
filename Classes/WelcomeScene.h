#ifndef _WelcomeScene_H_
#define _WelcomeScene_H_

#include "cocos2d.h"
USING_NS_CC;

class WelcomeScene :public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(WelcomeScene);
	void startMenuCallback(Ref* pSender);
	void settingMenuCallback(Ref* pSender);
	void helpMenuCallback(Ref* pSender);
};
Animate* run1();
#endif