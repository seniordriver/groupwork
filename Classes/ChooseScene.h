#ifndef _ChooseScene_H_
#define _ChooseScene_H_

#include "cocos2d.h"
#include "ObjectDefine.h"
#include "GameScene.h"

USING_NS_CC;

class ChooseScene :public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(ChooseScene);
	void normMenuCallback(Ref* pSender);
	void hardMenuCallback(Ref* pSender);

};
#endif